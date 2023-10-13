#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	bool found = false;
	cin >> a >> b >> c;
	
	while (not found and c != 0) {
		if ((b > 3143) and (a < b) and (b > c)) {
			cout << "YES" << endl;
			found = true;
		} else {
         a = b;
         b = c;
         cin >> c;
      }
	}
   if (not found) cout << "NO" << endl;
}