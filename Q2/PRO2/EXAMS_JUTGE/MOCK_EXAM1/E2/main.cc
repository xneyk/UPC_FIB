#include <iostream>
#include <list>

using namespace std;

// Pre: l1 i l2 estan ordenades creixentment. Siguin L1 i L2 els seus valors inicials.
// Post: l1 conté la fusió ordenada de L1 i L2.
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor.
void mergeIntoFirstList(list<int> &l1, list<int> l2) {
    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();

    while (it2 != l2.end()) {
        if (it1 != l1.end() && *it1 >= *it2) {
            it1 = l1.insert(it1, *it2);
            ++it2;
        }
        else if (it1 == l1.end()) {
            while (it2 != l2.end()) {
                l1.insert(l1.end(), *it2);
                ++it2;
            }
        }
        ++it1;
    }
}

int main() {
    list<int> l1;
    list<int> l2;
    int n, m;

    while (cin >> n >> m) {
        int k;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            l1.push_back(k);
        }
        for (int i = 0; i < m; ++i) {
            cin >> k;
            l2.push_back(k);
        }
        mergeIntoFirstList(l1, l2);

        for (list<int>::iterator i = l1.begin(); i != l1.end(); ++i) {
            cout << *i << ' ';
        }
        cout << endl;
    }
}