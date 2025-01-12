// X20680
#include <iostream>
#include <vector>

using namespace std;

vector<char> letter = {'x', 'y', 'z'};

void print_words(int i, const int size, const int max_times, vector<int> &times, vector<int> &solution) {
   if (i == size) {
      for (int x : solution) {
         cout << letter[x];
      }
      cout << endl;
   } else {
      for (int j = 0; j < 3; ++j) {
         if (times[j] > 0) {
            solution[i] = j;
            --times[j];
            // if new letter is diferent than the past one ==> past one consecutive characters are 0
            if (i > 0 && solution[i-1] != solution[i]) {
               int k = times[solution[i-1]];
               times[solution[i-1]] = max_times;
               
               print_words(i+1, size, max_times, times, solution);
               // backtrack max consecutive times
               times[solution[i-1]] = k;
            } else {
               print_words(i+1, size, max_times, times, solution);
            }
            ++times[j];
         }
      }
   }
}

void print_words(int n, int c) {
   // times save how much times can apear each letter
   vector<int> times(3, c);
   vector<int> solution(n);
   print_words(0, n, c, times, solution);
}

int main() {
   int n, c;
   while (cin >> n >> c) {
      print_words(n, c);
      cout << string(20, '-') << endl;
   }
}