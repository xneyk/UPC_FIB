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
   while (cin >> command) {

      int minor_index = 0;
      int data_length = 0;
      int max_index = 0;


      if (command == "v.push_back(") {
         int val;
         cin >> val;
         string ending;
         cin >> ending; // Això consumeix el ");"
          
         if (!data.empty()){
            data[max_index+1] = val; // Quan no existeix es fa un insert
         } else {
            data[0] = val;
         }
         ++max_index;
      }
      else if (command == "v.push_front(") {
         int val;
         cin >> val;
         string ending;
         cin >> ending; // Això consumeix el ");"
         
         if (!data.empty()) {
            data[minor_index - 1] = val;
         } else {
            data[0] = val;
         }
         --minor_index;
      }
      else if (command == "v.pop_front();") {
         data.erase(minor_index);
         ++minor_index;
      }
      else if (command == "v.pop_back();") {
         data.erase(max_index); // si data[max_index] no esta asignat no pasa res
         --max_index
      }
      else if (command == "v.resize(") {
         int newsize;
         cin >> newsize;
         string ending;
         cin >> ending; // Això consumeix el ");"

         if (newsize >= data_length) {
            data_length = newsize;
         } else {

         }
      }
      else if (command == "cout<<v[") {
         int index;
         cin >> index;
         string ending;
         cin >> ending; // Això consumeix el "];"
         
         c_it = data.find(minor_index + index);
         if (c_it != data.end()) cout << c_it->second << endl;
      }
      else if (command == "cout<<v;") {
         for (int i = minor_index; i < (data_length - minor_index); ++i){
            c_it = data.find(i);
            
            if (c_it != data.end()) cout << c_it->second << endl;
            else cout << 0;

            if (i+1 < (data_length - minor_index)) cout << ',';
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