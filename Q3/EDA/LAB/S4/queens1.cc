#include <iostream>
#include <vector>

using namespace std;

int queens(int n, int n_current, vector<int> &row) {
   if (n_current == n) {
      int n_ways;
      return n_ways;
   }


}

int queens(int n) {
   // if row[i] != -1 there is a queen at row "i" column "row[i]"
   vector<int> row(n, -1);
   
}

int main() {
   int n;
   cin >> n;
   cout << queens(n) << endl;
}