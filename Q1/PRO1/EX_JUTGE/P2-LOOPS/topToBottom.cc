#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if(n > m) {
        for (int i = n; i >= m; --i){
            cout << i << endl;
        }
    } else {
        for (int i = m; i >= n; --i){
            cout << i << endl;
        }
    }
}