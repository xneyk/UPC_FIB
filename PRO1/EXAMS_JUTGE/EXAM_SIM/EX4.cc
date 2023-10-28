#include <iostream>
using namespace std;

void print_solid_line(int side);
void print_box_line(int side);

int main() {
   int n, m, side;

   while (cin >> n >> m >> side) {
      

      for (int i = 0; i < n; i++) {
         for(int j = 0; j < m; ++j) print_solid_line(side);
         cout << '#' << endl;
         
         for (int k = 0; k < side; ++k){
            for(int l = 0; l < m; ++l) print_box_line(side);
            cout << '#' << endl;
         }
      }

      for(int i = 0; i < m; ++i) print_solid_line(side);
      cout << '#' << endl;
   }
}

void print_solid_line(int side) {
   for (int i = 0; i <= side; ++i) cout << '#';
}

void print_box_line(int side) {
   for (int i = 0; i <= side; ++i) {
      if(i == 0) cout << '#';
      else cout << ' ';
   }
}