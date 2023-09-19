#include <iostream>
using namespace std;

int main() {
	int n;
   int s = 0;
	cin >> n;

   cout << "La suma de los digitos de " << n << " resulta: ";
	while(n > 0) {
      s = s + (n % 10);
      n = n / 10;
   }
   cout << s << endl;
}