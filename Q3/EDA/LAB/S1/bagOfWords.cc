#include <iostream>
#include <map>

typedef std::map<std::string, int>::iterator Bag_It;

int main() {
   std::string cmd;
   std::map<std::string, int> bag; // word -> ocurrences

   while (std::cin >> cmd) {
      
      if (cmd == "store") { // STORE WORD CASE
         std::string word;
         std::cin >> word;

         bag[word] = bag[word] + 1;
      } else if (cmd == "delete") { // DELETE WORD CASE
         std::string word;
         std::cin >> word;

         Bag_It target = bag.find(word);
         if (target != bag.end()) { // found it!
            if (bag[word] > 1) --bag[word];
            else bag.erase(target);
         }
      } else if (cmd == "maximum?") { // ASKING MAXIMUM CASE
         if (bag.empty()) std::cout << "indefinite maximum" << std::endl;
         else std::cout << "maximum: " << bag.rbegin()->first << ", " << bag.rbegin()->second << " time(s)" << std::endl;
      } else if (cmd == "minimum?") { // ASKING MINIMUM CASE
         if (bag.empty()) std::cout << "indefinite minimum" << std::endl;
         else std::cout << "minimum: " << bag.begin()->first << ", " << bag.begin()->second << " time(s)" << std::endl;
      }
   }
}