#include <iostream>
#include <queue>
using namespace std;

void update_min_max(int n, int &min, int &max) {
   if (n > max) max = n;
   else if (n < min) min = n;
}

double calc_average(queue<int> q) {
   double summation = 0;
   int amount = 0;

   while (!q.empty()) {
      summation += q.front();
      ++amount;
      q.pop();
   }

   return summation/amount;
}

void print_data(int min, int max, double average) {
   cout << "min " << min << "; ";
   cout << "max " << max << "; ";
   cout << "media " << average;
}

int main() {
   int n, max, min;
   queue<int> q;
   
   cin >> n;
   max = min = n;
   while (-1001 <= n && n <= 1000) {
      if (n != -1001) q.push(n);
      else if (!q.empty()) q.pop();
      // !Veure si he eliminat el minim o el maxim!

      if (!q.empty()) {
         if (n != -1001) update_min_max(n, min, max);
         print_data(min, max, calc_average(q));
      }
      else cout << 0;

      cout << endl;
      cin >> n;
   }
}