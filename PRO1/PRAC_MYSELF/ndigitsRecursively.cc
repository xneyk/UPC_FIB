#include <iostream>
using namespace std;

int ndigits(int n);

int main(){
   int x;
   cin >> x;
   cout << ndigits(x) << endl;
}

int ndigits(int n){
   if(n <= 9) return 1;
   else return 1 + ndigits(n/10);
}