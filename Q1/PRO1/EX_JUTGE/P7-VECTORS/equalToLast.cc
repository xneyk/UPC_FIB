//P14130 Equal to the last one
#include <iostream>
#include <vector>
using namespace std;

void read_vector(vector<int>& v, int length) {
   for (int i = 0; i < length; ++i) cin >> v[i];
}

int main() {
   int lenght;
   cin >> lenght;
   vector<int> v(lenght);
   read_vector(v, lenght);

   int r = 0;
   for (int i = 0; i < (lenght - 1); ++i) if (v[i] == v[lenght - 1]) ++r;
   cout << r << endl;
}