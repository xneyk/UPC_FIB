#include <iostream>
using namespace std;

int main() {
	int x, y;
	int r = 0;
	cin >> x >> y;

	for(int i = 0; i < y; ++i) {
		r = r + x;
	}

	cout << r << endl;
}