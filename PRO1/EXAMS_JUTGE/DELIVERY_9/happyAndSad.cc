#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE:  s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
 * POST: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
*/
void numberOccurrences(const string &s, int &n1, int &n2, int &n3) {
   int k = s.size();
   // We don't know where is c2, so we need to search c2 != c1 and != c3
   char c1 = s[0], c3 = s[k-1];
   bool found_1 = false, found_2 = false;
   int l1, r1, l2, r2, m1, m2;
   l1 = l2 = 0;
   r1 = r2 = (k - 1);
   m1 = m2 = (l1 + r1)/2;

   while (not (found_1 and found_2)) { // we always will found what we search
      if (not found_1) { // binary search of transition c1...c2
         if (s[m1] == c3) r1 = m1; // move to the left part
         else if (s[m1] == c1) l1 = m1; // move to the right part
         else if (s[m1-1] == s[m1]) r1 = m1; // looking c2 --> move left
         else found_1 = true;
         
         m1 = (l1 + r1)/2; // recalc new middle
      }
      if (not found_2) { // binary search of transition c2...c3
         if (s[m2] == c3) r2 = m2; // move to the left part
         else if (s[m2] == c1) l2 = m2; // move to the right part
         else if (s[m2+1] == s[m2]) l2 = m2; // looking c2 --> move right
         else found_2 = true;

         m2 = (l2 + r2)/2; // recalc new middle
      }

      n1 = m1;
      n2 = (m2 + 1) - n1;
      n3 = k - (n2 + n1);
   }
}

/**
 * PRE:  s begins with one or more occurrences of a character c1, followed by one or more
 *       occurrences of a character c2, followed by one or more occurrences of a character c3,
 *       and there are no more characters in s.
 *       moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
 * POST: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
 *       If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
*/
int numberHappyOrSadSubsequences(const string &s) {
   int n1, n2, n3;
   n1 = n2 = n3 = 0;
   
   numberOccurrences(s, n1, n2, n3);
   
   return n1*n2*n3;
}

int main () {
   string s;

   while (cin >> s) {
      cout << numberHappyOrSadSubsequences(s) << endl;
   }
}