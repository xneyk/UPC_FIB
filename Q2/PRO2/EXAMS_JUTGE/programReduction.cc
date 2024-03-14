#include <iostream>
#include <vector>
using namespace std;

void multipop_back(vector<char> &s, int amount, int &last_elem) {
   s.resize(last_elem + 1 - amount);
   last_elem -= amount;
}

bool reachable(int last_elem, int size) {
   return (last_elem - (size - 1)) >= 0;
}

bool next_not_eq(const string &s, int length, int i, char c) {
   bool no_more_elems = i == length - 1;

   return no_more_elems or s[i+1] != c;
}

bool next_not_eq(const string &s, int length, int i, char c1, char c2) {
   bool no_more_elems = i == length - 1;

   return no_more_elems or (s[i+1] != c1 and s[i+1] != c2);
}

int main() {
   string program; // l'entrada es l'equema d'un programa
   while (cin >> program) {   // Tractament secuencial
      vector<char> s; // Vector que simula l'stack

      int program_length = program.size();
      for (int i = 0; i < program_length; ++i) { // Tractament de cada caracter del input
         s.push_back(program[i]); // Simulem el push a l'stack

         bool has_changed = true;
         // Iniciem amb la hipotesi que s'han fet canvis, ja que hem afegit un caracter
         int l_e = s.size() - 1; // Index de l'actual ultim element de la "pila"
         while (has_changed) { 

            if (s[l_e] == 'n') {
               // n -> E
               s[l_e] = 'E';
            }
            else if (s[l_e] == 'v' and (i == program_length - 1 or program[i+1] != '=')) {
               // v --> E no es pot aplicar si ve seguida de '='
               s[l_e] = 'E';
            }
            else if (reachable(l_e, 3) and s[l_e-2] == 'E' and s[l_e-1] == '*' and s[l_e] == 'E') {
               // E*E --> E
               multipop_back(s, 2, l_e);
               // s[l_e] = 'E'; Ja esta fet!
            }
            else if (reachable(l_e, 3) and s[l_e-2] == 'E' and s[l_e-1] == '+' and s[l_e] == 'E' and next_not_eq(program, program_length, i, '*')) {
               // E+E --> E no es pot aplicar si ve seguida de *
               multipop_back(s, 2, l_e);
               // s[l_e] = 'E'; Ja esta fet!
            }
            else if (reachable(l_e, 3) and s[l_e-2] == 'E' and s[l_e-1] == '<' and s[l_e] == 'E' and next_not_eq(program, program_length, i, '*', '+')) {
               // E<E --> E no es pot aplicar si ve seguida de * o +
               multipop_back(s, 2, l_e);
               // s[l_e] = 'E'; Ja esta fet!
            }
            else if (reachable(l_e, 4) and s[l_e-3] == 'v' and s[l_e-2] == '=' and s[l_e-1] == 'E' and s[l_e] == ';') {
               // v=E; --> I
               multipop_back(s, 3, l_e);
               s[l_e] = 'I';
            }
            else if ((reachable(l_e, 3) and s[l_e-2] == '(' and s[l_e-1] == 'E' and s[l_e] == ')') and ((not reachable(l_e, 4)) or (s[l_e-3] != 'i' and  s[l_e-3] != 'w'))) {
               // (E) --> E no es pot aplicar si ve precedida de i o w
               multipop_back(s, 2, l_e);
               s[l_e] = 'E';
            }
            else if (reachable(l_e, 5) and s[l_e-4] == 'i' and s[l_e-3] == '(' and s[l_e-2] == 'E' and s[l_e-1] == ')' and s[l_e] == 'I' and next_not_eq(program, program_length, i, 'e')) {
               // i(E)I --> I no es pot aplicar si ve seguida de e
               multipop_back(s, 4, l_e);
               s[l_e] = 'I';
            }
            else if (reachable(l_e, 7) and s[l_e-6] == 'i' and s[l_e-5] == '(' and s[l_e-4] == 'E' and s[l_e-3] == ')' and s[l_e-2] == 'I' and s[l_e-1] == 'e' and s[l_e] == 'I') {
               // i(E)IeI --> I
               multipop_back(s, 6, l_e);
               s[l_e] = 'I';
            }
            else if (reachable(l_e, 5) and s[l_e-4] == 'w' and s[l_e-3] == '(' and s[l_e-2] == 'E' and s[l_e-1] == ')' and s[l_e] == 'I') {
               // w(E)I--> I
               multipop_back(s, 4, l_e);
               s[l_e] = 'I';
            }
            else if (reachable(l_e, 2) and s[l_e-1] == 'L' and s[l_e] == 'I') {
               // LI--> L
               multipop_back(s, 1, l_e);
               // s[l_e] = 'L'; Ja esta fet!
            }
            else if (s[l_e] == 'I' and ((not reachable(l_e, 2)) or (s[l_e-1] != ')' and  s[l_e-1] != 'L'))) {
               // I--> L no es pot aplicar si ve precedida de ) o L
               s[l_e] = 'L';
            }
            else if (reachable(l_e, 3) and s[l_e-2] == '{' and s[l_e-1] == 'L' and s[l_e] == '}') {
               // {L}--> I
               multipop_back(s, 2, l_e);
               s[l_e] = 'I';
            }
            else if (i == program_length-1 and l_e == 0 and s[0] == 'L') {
               // L -> P  només es pot aplicar si aquest L és l’únic caràcter que queda, és a dir, si tot l’string inicial ha estat reduït a exactament L.
               s[0] = 'P';
            } else {
               has_changed = false;
            }
         }
      }

      // ESCRIPTURA DEL RESULTAT
      int result_length = s.size();
      for (int i = 0; i < result_length; ++i) {
         cout << s[i];
      }
      cout << endl;
   }
}