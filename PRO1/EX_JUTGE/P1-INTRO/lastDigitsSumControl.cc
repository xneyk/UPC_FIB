#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  
/*
    (n % 10) --> Primer digit començant per la dreta
    ((n / 10) % 10) --> Segon digit començant per la dreta
    ((n / 100) % 10) --> Tercer digit començant per la dreta
*/
    cout << (n % 10) + ((n / 10) % 10) + ((n / 100) % 10) << endl;
}