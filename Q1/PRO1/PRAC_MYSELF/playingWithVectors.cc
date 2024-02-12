#include <iostream>
#include <vector>

using namespace std;

int last_odd(const vector<int>& v) { //Paso por ref. const.
	int n = v.size() - 1; // último índice del vector
	bool found  = false;
	
	while (not found and 0 <= n) { // 0 --> primer índice
		if (v[n]%2 != 0) {
         found = true;
		   return n;
      }
      --n;
	}
	
	return -1;
}

int main() {
   // {5,7,10,4,2,-1}
   vector<int> my_numbers (6);
   my_numbers[0] = 5;
   my_numbers[1] = 7;
   my_numbers[2] = 10;
   my_numbers[3] = 4;
   my_numbers[4] = 2;
   my_numbers[5] = -1;
   cout << last_odd(my_numbers) << endl;
}