//P6
#include <iostream>
#include <map>

using namespace std;

struct Ali {
   long int profit;
   int carried_jewels;
   int capacity;
   map<int,int> bag;
};

void handleInsertion(Ali &ali, int value) {
   if (ali.carried_jewels < ali.capacity) {
      ++ali.bag[value];
      ++ali.carried_jewels;
      ali.profit += value;
   } else {
      map<int,int>::iterator i = ali.bag.begin(); // beginning has the minium jewel cost
      // i == ali.bag.end() ==> bag is empty; and we also checked that it is not.
      if (i->first < value) {
         // add new jewel to ali's bag
         ++ali.bag[value];
         // take off minor jewel
         --i->second;
         ali.profit += (value - i->first);
         if (i->second <= 0) ali.bag.erase(i);
      }
   }
}

void handleDelete(Ali &ali, int value, const map<int,int> &cave) {
   if (ali.bag.find(value) != ali.bag.end()) { // value was at ali's bag
      ali.profit = 0;
      ali.carried_jewels = 0;
      ali.bag = map<int,int>();
      map<int,int>::const_iterator i = cave.end();
      while (i != cave.begin() && ali.carried_jewels < ali.capacity) {
         --i;
         // i->second: jewel amount if can pick it all ==> pick it all, else fill up the bag
         int picking_amount = min(i->second, ali.capacity - ali.carried_jewels);
         ali.bag[i->first] = picking_amount;

         ali.profit += picking_amount*(i->first);
         ali.carried_jewels += picking_amount;
      }
   }
}

int main() {
   Ali ali;

   ali.profit = 0;
   ali.carried_jewels = 0;
   ali.capacity = 0;
   cin >> ali.capacity;
   ali.bag = map<int,int>();
   
   string cmd; int cost;
   // key: value of the jewel
   // value: amount of jewels with this value
   map<int, int> cave; 
   while (cin >> cmd) {
      if (cmd == "leave") {
         cin >> cost;
         ++cave[cost];
         handleInsertion(ali, cost);
      } else if (cmd == "take") {
         cin >> cost;
         --cave[cost];
         if (cave[cost] <= 0) cave.erase(cost);
         handleDelete(ali, cost, cave);
      } else {
         cout << cmd << " is not a valid command" << endl;
      }

      cout << ali.profit << endl;
   }
}
