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

// /**
//  * PRE:
//  * POST: returns if an element exists in a set or doesn't
// */
// int exists(vector<string> v, string s) {
//    int l = v.size() - 1;
//    for (int i = l; i >= 0; --i) {
//       if (v[i] == s) return true;
//    }
//    return false;
// }

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

void update_hour_interval(int& max, int& min, int begin, int end) {
   if (begin < min) min = begin;
   if (end > max) max = end;
}

bool better_data_than(Raw_Data a, Raw_Data b) {
   if (index_day(a.day) != index_day(b.day)) return index_day(a.day) < index_day(b.day);
   else if (a.teacher != b.teacher) return a.teacher < b.teacher;
   return a.h_begin < b.h_begin;
}

/**
 * PRE:
 * POST: Encuentra la posicion correcta para el nuevo elemento del vector, maneniendolo
 *       asi siempre correctamente ordenado.
*/
void realtime_sorting(vector<Raw_Data>& v, int l) {
   for (int i = (l - 1); i > 0; --i) {
      if (better_data_than(v[i], v[i-1])) {
         Raw_Data aux = v[i];
         v[i] = v[i-1];
         v[i-1] = aux;
      }
   }
}

int main() {
   /**
    * Una unica tabla guarda tanto las asignaturas (Slot.listsubjects) como los profesores 
    * (Slots.listteachers).
   */
   int min_hour = 23;   // Serviran para saber desde donde
   int max_hour = 0;    // Hasta donde hay que imprimir la tabla.
   int teacher_colisions = 0;
   vector<Raw_Data> data_set;
   TableSlots table(24, vector<Slot>(5));
   Raw_Data input;

   // read and sort console input;
   int l = 0;
   while(cin >> input.subject >> input.teacher >> input.day >> input.h_begin >> input.h_end) {
      update_hour_interval(max_hour, min_hour, input.h_begin, input.h_end);
      data_set.push_back(input);
      ++l;
      realtime_sorting(data_set, l);
   }

   for (int i = 0; i < l; ++i) {
      int i_day = index_day(data_set[i].day);
      
      for (int j = data_set[i].h_begin; j < data_set[i].h_end; ++i) {
         // Da igual si se esta dando otra clase de la misma asignatura
         table[data_set[i].h_begin][i_day].listsubjects.push_back(data_set[i].subject);
         
         if (i == 0) {
            table[i][i_day].listteachers.push_back(input.teacher);
         } else { // Cualquier otro caso que no sea el primero de la lista
            if (data_set[i-1].day == data_set[i].day and data_set[i-1].teacher == data_set[i].teacher) {
               if (data_set[i-1].h_begin <= j and j < data_set[i-1].h_end) {
                  ++teacher_colisions;
               }
            }
         }
      }
   }

   cout << "COLISIONES: " << teacher_colisions << endl;

   // // Table header
   // cout << "number of subjects per slot:" << endl;
   // cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
   // for (int i = min_hour; i < max_hour; ++i) {
   //    print_slot(2, i);
   //    print_slot(10, table[i][0].listsubjects.size());
   //    print_slot(10, table[i][1].listsubjects.size());
   //    print_slot(10, table[i][2].listsubjects.size());
   //    print_slot(10, table[i][3].listsubjects.size());
   //    print_slot(10, table[i][4].listsubjects.size());
   //    cout << endl;
   // }

   // // Table header
   // cout << "number of teachers per slot:" << endl;
   // cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
   // for (int i = min_hour; i < max_hour; ++i) {
   //    print_slot(2, i);
   //    print_slot(10, table[i][0].listteachers.size());
   //    print_slot(10, table[i][1].listteachers.size());
   //    print_slot(10, table[i][2].listteachers.size());
   //    print_slot(10, table[i][3].listteachers.size());
   //    print_slot(10, table[i][4].listteachers.size());
   //    cout << endl;
   // }

   for (int i = 0; i < l; ++i) {
      cout << data_set[i].subject << ' ';
      cout << data_set[i].teacher << ' ';
      cout << data_set[i].day << ' ';
      cout << data_set[i].h_begin << ' ';
      cout << data_set[i].h_end << endl;
   }
}