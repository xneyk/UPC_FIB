#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Input {
   string subject;
   string teacher;
   string day;
   int h_begin;
   int h_end;
};

bool data_better_than(Input a, Input b) {
   if (a.h_begin != b.h_begin) return a.h_begin < b.h_begin;
   else return a.h_end < b.h_end;
}

int main() {
   vector<Input> data;
   Input i;
   while(cin >> i.subject >> i.teacher >> i.day >> i.h_begin >> i.h_end) {
      data.push_back(i);
   }
   sort(data.begin(), data.end(), data_better_than);

   cout << endl << endl;

   int l = data.size();
   for (int j = 0; j < l; ++j) {
      cout << data[j].subject << ' ' << data[j].teacher << ' ' << data[j].day << ' ' << data[j].h_begin << ' ' << data[j].h_end << endl;
   }
}