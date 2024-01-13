//X09467 ramps
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: n is vector lenght
 * POST: reads and inizialize a given vector
*/
void ini_v(vector<int>& v, int n) {
   for (int i = 0; i < n; ++i) cin >> v[i];
}

/**
 * PRE:
 * POST: returns a vector, with the same dimension, of boolean values, where the position i holds the value true if and only if the vector V has a ramp a position i.
*/
vector<bool> ramps_pos(const vector <int>& V) {
   int l = V.size();
   vector<bool> result(l, false);
   for (int i = 0; i < l - 2; ++i) {
      if (V[i] < V[i+1] and V[i+1] < V[i+2]) result[i] = true; //goes up
      if (V[i] > V[i+1] and V[i+1] > V[i+2]) result[i] = true; // goes down
   }
   return result;
}

/**
 * PRE: B is a vector indicating the positions with a ramp
 * POST: returns the number of pairs of positions (i,j), i < j, with a ramp and potentially conflictive.
*/
int pot_conflictive(const vector <bool>& B) {
   int l = B.size();
   int result = 0;
   for (int i = 0; i < l - 2; ++i) {
      if (B[i] and B[i+1]) ++result;
      if (B[i] and B[i+2]) ++result;
   }
   return result;
}

int main() {
   int n;

   while (cin >> n) {
      vector<int> v(n);
      ini_v(v, n);
      vector<bool> positions = ramps_pos(v);
      int n_conflict = pot_conflictive(positions);

      //print result
      cout << "positions with a ramp:";
      for (int i = 0; i < n; ++i) {
         if (positions[i]) cout << ' ' << i;
      }
      cout << endl;
      cout << "potentially conflictive: " << n_conflict << endl;
      cout << "---" << endl;
   }
}