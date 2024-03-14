#include <iostream>
#include <list>
using namespace std;

void remove_elem(list<int> &l, int num, int min, int max) {
   bool found = false;
   list<int>::iterator it = l.begin();
   
   while (not found and it != l.end()) {
      if (*it == num) {
         // if (num == min) //Recalc min
         // else if (num == max) //Recalc max
      }
   }
}

int main() {
   int code, num, max, min, med;
   list<int> l;

   cin >> code >> num; 
   max = min = num;
   while (code != 0) {
      //recalc min max
      if (code == -1) l.push_back(num);
      else remove_elem(l, num, max, min);

      //calc med

      cin >> code >> num;
   }
}