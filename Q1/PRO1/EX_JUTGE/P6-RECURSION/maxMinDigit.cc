//P71398 Procediment per al dígit màxim i mínim
#include <iostream>
using namespace std;

void digit_maxim_i_minim(int n, int& maxim, int& minim);

int main() {
   int x;
   int max, min;
   cin >> x;
   digit_maxim_i_minim(x, max, min);
   cout << x << ' ' << max << ' ' << min << endl;
}

void digit_maxim_i_minim(int n, int& maxim, int& minim) {
   maxim = minim = n%10;
   if (n/10 > 0) {
      digit_maxim_i_minim(n/10, maxim, minim);
      if (n%10 >= maxim) maxim = n%10;
      if (n%10 <= minim) minim = n%10;
   }
}