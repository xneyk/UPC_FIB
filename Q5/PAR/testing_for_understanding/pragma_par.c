#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv) {
   #pragma omp parallel
   {
      #pragma omp single
      {
         for (int i = 0; i < 4; ++i) {
            #pragma omp task firstprivate(i)
            printf("Iteració %d executada pel thread: %d\n", i, omp_get_thread_num());
         }
      }
   }

   exit(EXIT_SUCCESS);
}