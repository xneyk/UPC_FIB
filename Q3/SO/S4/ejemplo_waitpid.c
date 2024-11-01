#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * VARIABLE GLOBAL A LA QUE ACCEDE TANTO MAIN COMO TRATA_SIGCHLD COMO TRATA_ALARMA_PADRE
*/
const int MAX_CHILDS = 10;
int pid[MAX_CHILDS];
int not_alarmed = 1;
int children_alive = 0;

void error_y_exit(char *msg, int exit_status) {
   perror(msg);
   exit(exit_status);
}

void trata_alarma(int s) {
}

void trata_sigchld(int s) {
   int res;
   char buff[256];

   int died_pid = waitpid(-1, &res, WNOHANG);
   while(died_pid > 0) {
      alarm(2); // ha muerto un hijo por lo que debe resetearse la alarma de 2 segundos.
      --children_alive;
      // la causa de la muerte se encuentra en res.
      int i = 0, child_not_found = 1;
      while (child_not_found && i < MAX_CHILDS) { // busca el pid y lo marca como muerto.
         if (pid[i] == died_pid) {
            pid[i] = -1; // marca hijo como muerto
            child_not_found = 0;
         }
         ++i;
      }
      if (WIFEXITED(res)) {
         sprintf(buff, "El proceso %d ha terminado a causa de exit(%d)\n", died_pid, WEXITSTATUS(res));
      } else if (WIFSIGNALED(res)) {
         sprintf(buff, "El proceso %d ha terminado a causa del signal: %d\n", died_pid, WEXITSTATUS(res));
      } else {
         sprintf(buff, "Termina el proceso %d\n", died_pid);
      }
      write(1, buff, strlen(buff));
      died_pid = waitpid(-1, &res, WNOHANG);
   }
}

void trata_alarma_padre(int s) {
   not_alarmed = 0;
   char buff[256];
   sprintf(buff, "Empezando a matar a todos los hijos que queden vivos...\n");
   write(1, buff, strlen(buff));
   for (int i = 0; i < MAX_CHILDS; ++i) {
      if (pid[i] != -1) {
         kill(pid[i], SIGKILL); // mata a todos sus hijos no muertos (zombie)
         sprintf(buff, "Orden de muerte a %d\n", pid[i]);
         write(1, buff, strlen(buff));
      }
   }
   int collected_pid = waitpid(-1, NULL, 0);
   while(collected_pid > 0) { // los mata definitivamente
      sprintf(buff, "Muerto el proceso %d\n", collected_pid);
      write(1, buff, strlen(buff));
      collected_pid = waitpid(-1, NULL, 0);
   }
}

int main(int argc, char *argv[]) {
   int res;
   char buff[256];
   int hijos = 0;
   struct sigaction sa;
   sigset_t mask;

   /* Evitamos recibir el SIGALRM fuera del sigsuspend */

   sigemptyset(&mask);
   sigaddset(&mask, SIGALRM);
   sigprocmask(SIG_BLOCK, &mask, NULL);
   
   /* Reprogramacion del signal SIGCHLD*/
   sigemptyset(&mask);
   sigaddset(&mask, SIGCHLD);
   sigprocmask(SIG_UNBLOCK, &mask, NULL); // la desbloqueamos por si a caso
   
   sa.sa_handler = &trata_sigchld;
   sa.sa_flags = SA_RESTART;
   sigfillset(&sa.sa_mask);
   if (sigaction(SIGCHLD, &sa, NULL) < 0) error_y_exit("sigaction SIGCHLD", 1);
   
   sa.sa_handler = &trata_alarma_padre;
   sa.sa_flags = SA_RESTART;
   sigfillset(&sa.sa_mask);
   if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction SIGCHLD", 1);

   for (hijos = 0; hijos < MAX_CHILDS; hijos++) {
      sprintf(buff, "Creando el hijo numero %d\n", hijos);
      write(1, buff, strlen(buff));

      pid[hijos] = fork();
      if (pid[hijos] == 0) /* Esta linea la ejecutan tanto el padre como el hijo */
      {
         sa.sa_handler = &trata_alarma;
         sa.sa_flags = SA_RESTART;
         sigfillset(&sa.sa_mask);
         if (sigaction(SIGALRM, &sa, NULL) < 0)
            error_y_exit("sigaction", 1);

         /* Escribe aqui el codigo del proceso hijo */
         sprintf(buff, "Hola, soy %d\n", getpid());
         write(1, buff, strlen(buff));

         alarm(1);
         sigfillset(&mask);
         sigdelset(&mask, SIGALRM);
         sigdelset(&mask, SIGINT);
         sigsuspend(&mask);

         /* Termina su ejecución */
         exit(0);
      } else if (pid[hijos] < 0) {
         /* Se ha producido un error */
         error_y_exit("Error en el fork", 1);
      }
      ++children_alive;
   }

   /* Esperamos que acaben los hijos */
   alarm(2);
   while (children_alive > 0 && not_alarmed) {
      sigfillset(&mask);
      sigdelset(&mask, SIGCHLD);
      sigdelset(&mask, SIGALRM);
      sigdelset(&mask, SIGINT);
      sigsuspend(&mask); // se queda esperando a tener que matar a un hijo suyo o a recibir la alarma. 
   }

   return 0;
}
