#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

void ini_queues(vector<queue<string>> &queues, int n) {
   string people_list;
   getline(cin, people_list); 
   // ^-- Consumeix una linea en blanc que no entenc perque :(
   // Penso que pot ser que consumeix el "\n" del final de linea que
   // ve despres de consumir el nombre n des del main
   
   for (int i = 0; i < n; ++i) { // ini every queue
      getline(cin, people_list);
      istringstream iss_people_list(people_list); // converts a string to an input stream object to collect its data

      string person;
      while (iss_people_list >> person) queues[i].push(person);
   }
}

int main() {
   int n;
   cin >> n; //number of queues
   vector<queue<string>> queues(n); // n queues
   queue<string> departs;

   ini_queues(queues, n);

   string command;
   while (cin >> command) {
      int queue_id;
      if (command == "LEAVES") {
         cin >> queue_id;
         --queue_id;
         if (0 <= queue_id && queue_id < n) {
            if (!queues[queue_id].empty()) {
               departs.push(queues[queue_id].front());
               queues[queue_id].pop();
            }
         }
      }
      else if (command == "ENTERS") {
         string person;
         cin >> person >> queue_id;
         --queue_id;
         if (0 <= queue_id && queue_id < n) queues[queue_id].push(person);
      }
   }

   // PRINTING THE OUTPUT
   cout << "DEPARTS" << endl << "-------" << endl;
   while (!departs.empty()) {
      cout << departs.front() << endl;
      departs.pop();
   }
   cout << endl;
   cout << "FINAL CONTENTS" << endl << "--------------" << endl;
   for (int i = 0; i < n; ++i) {
      cout << "queue " << (i+1) << ':';
      while (!queues[i].empty()) {
         cout << ' ' << queues[i].front();
         queues[i].pop();
      }
      cout << endl;
   }
}