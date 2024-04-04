#include <iostream>
#include <queue>
using namespace std;

void update_min_max(int n, int &old_min, int &min, int &old_max, int &max) {
   if (n > max) {
      old_max = max;
      max = n;
   }
   else if (n < min) {
      old_min = min;
      min = n;
   }
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
   int n, max, old_max, old_min, min;
   int poped_element;
   queue<int> q;
   
   cin >> n;
   old_max = max = old_min = min = n;
   while (-1001 <= n && n <= 1000) {
      if (n != -1001) q.push(n);
      else if (!q.empty()) {
         poped_element = q.front();
         q.pop();

         if (poped_element == max) max = old_max;
         else if (poped_element == min) min = old_min;
      }

      if (!q.empty()) {
         if (n != -1001) update_min_max(n, old_min, min, old_max, max);
         print_data(min, max, calc_average(q));
      }
      else cout << 0;

      cout << endl;
      cin >> n;
   }
}