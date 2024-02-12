#include <iostream>
#include <vector>
#include <algorithm> // Potser necesitem endreçar un vector segons les hores.
using namespace std;

struct Slot {
   vector<string> listsubjects;
   vector<string> listteachers;
};

typedef vector<vector<Slot> > TableSlots;

struct Raw_Data {
   string subject;
   string teacher;
   string day;
   int h_begin;
   int h_end;
};

/**
 * PRE: day is a valid day: {"monday","tuesday","wednesday","thursday","friday"}.
 * POST: returns the index of it related to table slot.
*/
int index_day(string day) {
   if (day == "monday") return 0;
   else if (day == "tuesday") return 1;
   else if (day == "wednesday") return 2;
   else if (day == "thursday") return 3;
   else return 4; // (day == "friday")
}

/**
 * PRE:
 * POST: returns if an element exists in a set or doesn't
*/
int exists(vector<string> v, string s) {
   int l = v.size() - 1;
   for (int i = l; i >= 0; --i) {
      if (v[i] == s) return true;
   }
   return false;
}

/**
 * PRE:
 * POST: returns the number of digits of the given n.
*/
int n_digits(int n) {
   if (n <= 9) return 1;
   else return 1 + n_digits(n/10);
}

/**
 * PRE: 
 * POST: prints the slot of lenght n with content right-justified
*/
void print_slot(int n, int data) {
   int spaces = n - n_digits(data);
   for (int i = 0; i < spaces; ++i) cout << ' ';
   cout << data;
}

int main() {
   /**
    * Una unica tabla guarda tanto las asignaturas (Slot.listsubjects) como los profesores 
    * (Slots.listteachers).
   */
   TableSlots table(24, vector<Slot>(5));
   int min_hour = 23;   // Serviran para saber desde donde
   int max_hour = 0;    // Hasta donde hay que imprimir la tabla.
   int teacher_colisions = 0;
   Raw_Data input;
   while(cin >> input.subject >> input.teacher >> input.day >> input.h_begin >> input.h_end) {
      if (input.h_begin < min_hour) min_hour = input.h_begin;
      if (input.h_end > max_hour) max_hour = input.h_end;
      
      int i_day = index_day(input.day);
      
      for (int i = input.h_begin; i < input.h_end; ++i) {
         // Da igual si se esta dando otra clase de la misma asignatura
         table[i][i_day].listsubjects.push_back(input.subject);
         
         if (not exists(table[i][i_day].listteachers, input.teacher)) {
            table[i][i_day].listteachers.push_back(input.teacher);
         } else {
            // El profesor ya esta dando otra clase en esa hora, por lo que deberemos recordar que hay
            // que reubicar a un profesor mas.
            ++teacher_colisions;
         }
      }
   }

   // Table header
   cout << "number of subjects per slot:" << endl;
   cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
   for (int i = min_hour; i < max_hour; ++i) {
      print_slot(2, i);
      print_slot(10, table[i][0].listsubjects.size());
      print_slot(10, table[i][1].listsubjects.size());
      print_slot(10, table[i][2].listsubjects.size());
      print_slot(10, table[i][3].listsubjects.size());
      print_slot(10, table[i][4].listsubjects.size());
      cout << endl;
   }
   cout << "number of teachers per slot:" << endl;
   cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
   for (int i = min_hour; i < max_hour; ++i) {
      print_slot(2, i);
      print_slot(10, table[i][0].listteachers.size());
      print_slot(10, table[i][1].listteachers.size());
      print_slot(10, table[i][2].listteachers.size());
      print_slot(10, table[i][3].listteachers.size());
      print_slot(10, table[i][4].listteachers.size());
      cout << endl;
   }
   cout << "number of replacements needed to avoid conflicts:" << endl;
   cout << teacher_colisions << endl;
}