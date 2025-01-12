// P67329
#include <iostream>
#include <vector>

using namespace std;

const vector<char> letter = {'A', 'C', 'G', 'T'};

void combinations(int idx, const int n, vector<int> &solution) {
   if (idx == n) {
      for (int i : solution) cout << letter[i];
      cout << endl;
   } else {
      for (int i = 0; i < 4; ++i) {
         solution[idx] = i;
         combinations(idx+1, n, solution);
      }
   }
}

void combinations(int n) {
   vector<int> solution(n);
   combinations(0, n, solution);
}

int main() {
   int n;
   cin >> n;
   combinations(n);
}