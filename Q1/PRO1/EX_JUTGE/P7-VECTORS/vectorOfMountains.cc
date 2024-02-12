//X41120 Vector of mountains
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: |v| >= 3
 * POST: retorna un vector amb l’alçada de tots els cims de v (en el mateix ordre)
*/
vector<int> obtain_peaks(const vector<int>& v) {
   int l = v.size();
   vector<int> peaks;
   for (int i = 1; i < (l - 1); ++i) {
      if (v[i - 1] < v[i] and v[i] > v[i + 1]) peaks.push_back(v[i]);
   }
   return peaks;
}

/**
 * PRE: |v| > 0
 * POST: retorna un vector amb tots els pics que son mes alts a l'ultim del perfil.
*/
vector<int> higher_than_last(const vector<int>& v) {
   int l = v.size();
   const int LAST_PEAK = v[l - 1];

   vector<int> higher_peaks;
   for (int i = 0; i < l; ++i) {
      if (v[i] > LAST_PEAK) higher_peaks.push_back(v[i]);
   }
   return higher_peaks;
}

/**
 * PRE:
 * POST: llegeix i inicialitza el vector amb els valors entrats per consola
*/
void ini_v(vector<int>& v, int n) {
   for (int i = 0; i < n; ++i) {
      cin >> v[i];
   }
}

int main() {
   int n;
   cin >> n;
   vector<int> mountain(n);
   ini_v(mountain, n);

   vector<int> peaks = obtain_peaks(mountain);
   int total_peaks = peaks.size();
   vector<int> higher_peaks; 
   if (total_peaks > 0) higher_peaks = higher_than_last(peaks);
   int total_higher_picks = higher_peaks.size();

   // imprimim els pics
   cout << total_peaks << ':';
   for (int i = 0; i < total_peaks; ++i) {
      cout << ' ' << peaks[i];
   }
   cout << endl;

   // imprimim els pics mes alts a l'ultim del perfil.
   if (total_higher_picks > 0) {
      for (int i = 0; i < total_higher_picks; ++i) {
         if (i > 0) cout << ' ';
         cout << higher_peaks[i];
      }
      cout << endl;
   } else {
      cout << '-' << endl;
   }
}