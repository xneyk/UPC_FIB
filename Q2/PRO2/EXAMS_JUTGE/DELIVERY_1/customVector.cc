#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<int,int>::iterator It;
typedef map<int,int>::const_iterator C_It;

int main() {
   map<int,int> data;
   /**
    * first --> index
    * second --> value
   */
   map<int,int>::iterator it;
   map<int,int>::const_iterator c_it;

   string command;
   
   int max_index = 0;
   int minor_index = 0;

   while (cin >> command) {
      if (command == "v.push_back(") {
         int val;
         cin >> val;
         string ending;
         cin >> ending; // Això consumeix el ");"
         
         data[max_index] = val; // Quan no existeix es fa un insert
         ++max_index;
      }
      else if (command == "v.push_front(") {
         int val;
         cin >> val;
         string ending;
         cin >> ending; // Això consumeix el ");"
         
         --minor_index;
         data[minor_index] = val;
      }
      else if (command == "v.pop_front();") {
         data.erase(minor_index);
         ++minor_index;
      }
      else if (command == "v.pop_back();") {
         data.erase(max_index); // si data[max_index] no esta asignat no pasa res
         --max_index;
      }
      else if (command == "v.resize(") {
         int newsize;
         cin >> newsize;
         string ending;
         cin >> ending; // Això consumeix el ");"

         if (newsize < (max_index - minor_index)) {
            // Caldra eliminar tots aquells elements explicitament definits fins l'index
            It new_last = data.lower_bound(newsize + minor_index); // aconsegueix el ultim que m'haig de quedar
            data.erase(new_last, data.end());
         }
         max_index = newsize + minor_index;

      }
      else if (command == "cout<<v[") {
         int index;
         cin >> index;
         string ending;
         cin >> ending; // Això consumeix el "];"

         c_it = data.find(minor_index + index);
         if (c_it != data.end()) cout << c_it->second << endl;
         else cout << 0 << endl;
      }
      else if (command == "cout<<v;") {
         c_it = data.begin();
         for (int i = minor_index; i < max_index; ++i){
            if (c_it != data.end() and c_it->first == i) {
               cout << c_it->second;
               ++c_it;
            }
            else cout << 0;

            if (i+1 < max_index) cout << ',';
            else cout << endl;
         }
      }
      else if (command == "v[") {
         int index;
         cin >> index;
         string mid;
         cin >> mid; // Això consumeix el "]="
         int val;
         cin >> val;
         string ending;
         cin >> ending; // Això consumeix el ";"

         data[minor_index + index] = val;
      }
      else if (command == "//") {
         string comment;
         getline(cin, comment);
         cout << "//" << comment << endl;
      }
      else {
         cout << "Wrong command '" << command << "'" << endl;
         string discard;
         getline(cin, discard);
      }
   }
}