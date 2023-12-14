//P63414 Counting frequences
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n, input;
   cin >> n;
   
   vector<int> counter(1001, 0);
   for (int i = 0; i < n; ++i) {
      cin >> input;
      ++counter[input%10000];
   }

   for (int i = 0; i <= 1000; ++i) {
      if (counter[i] > 0) cout << 1000000000 + i << " : " << counter[i] << endl;
   }
}