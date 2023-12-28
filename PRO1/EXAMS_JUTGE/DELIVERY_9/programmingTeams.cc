#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Programmer {
   string name;
   int skill;
};

/**
 * PRE:
 * POST: fill the vector with all the members in the input order.
*/
void read_members(vector<Programmer>& v, int l){
   for (int i = 0; i < l; ++i) {
      cin >> v[i].name >> v[i].skill;
   }
}

bool lexicografic_order(Programmer a, Programmer b) {
   return a.name < b.name;
}

/**
 * PRE: a_counter represent how many a Programmers we add to the team. b_counter means the same for b.
 * POST: returns true if we need to take 'a' Programmer and false if we need to take 'b' Programmer.
*/
bool btr_prog(Programmer a, Programmer b, int a_counter, int b_counter) {
   if (a.skill != b.skill) return a.skill > b.skill;
   else if (a_counter != b_counter) return a_counter < b_counter; 
   else return a.name < b.name;
}

int main() {
   int k; // number of members/team
   while (cin >> k) {
      /**
       * n_i: number of israelians members
       * n_p: number of palestinian members
      */
      int n_i, n_p;
      
      cin >> n_i; // Reading israelians programmers
      vector<Programmer> i_list(n_i);
      read_members(i_list, n_i);
      
      cin >> n_p; // Reading palestinian programmers
      vector<Programmer> p_list(n_p);
      read_members(p_list, n_p);

      vector <vector<Programmer> > teams((n_i+n_p)/k, vector<Programmer>(k));
      int i_index = 0, p_index = 0;
      for (int i = 0; i < (n_i+n_p)/k; ++i) {
         int i_mem = 0, p_mem = 0;
         for (int j = 0; j < k; ++j) {
            if (not(p_index < n_p) or (i_index < n_i and btr_prog(i_list[i_index], p_list[p_index], i_mem, p_mem))) {
               teams[i][j] = i_list[i_index];
               ++i_index;
               ++i_mem;
            } else {
               teams[i][j] = p_list[p_index];
               ++p_index;
               ++p_mem;
            }
         }
      }

      for (int i = 0; i < (n_i+n_p)/k; ++i) {
         sort(teams[i].begin(), teams[i].end(), lexicografic_order);
         for (int j = 0; j < k; ++j) {
            cout << teams[i][j].name;
            if (j < k - 1) cout << ' ';
         }
         cout << endl;
      }
      cout << endl;
   }
}