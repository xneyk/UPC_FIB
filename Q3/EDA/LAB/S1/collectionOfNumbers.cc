// P50709 - Collection of numbers
#include <iostream>
#include <queue>

int main() {
   char cmd;
   int number;

   std::priority_queue<int> collection; // an ordered queue by T::<operator()

   while (std::cin >> cmd) {
      if (cmd == 'S') { // Stores a copy of the given number x.
         std::cin >> number;
         collection.push(number);
      } else if (cmd == 'A') { // Asks for the greatest number.
         if (collection.empty()) {
            std::cout << "error!" << std::endl;
         } else {
            std::cout << collection.top() << std::endl;
         }
      } else if (cmd == 'R') { // Removes the greatest number (one of them, if it is repeated).
         if (collection.empty()) {
            std::cout << "error!" << std::endl;
         } else {
            collection.pop();
         }
      } else if (cmd == 'I') { // Increases the greatest number (one of them, if it is repeated) in x units.
         std::cin >> number;
         if (collection.empty()) {
            std::cout << "error!" << std::endl;
         } else {
            int current_greatest = collection.top();
            collection.pop();
            current_greatest += number;
            collection.push(current_greatest);
         }
      } else if (cmd == 'D') { // Decreases the greatest number (one of them, if it is repeated) in x units.
         std::cin >> number;
         if (collection.empty()) {
            std::cout << "error!" << std::endl;
         } else {
            int current_greatest = collection.top();
            collection.pop();
            current_greatest -= number;
            collection.push(current_greatest);
         }
      } else { // Asks for the greatest number.
         std::cerr << "The operator " << cmd << "is not defined" << std::endl;
      }
   }
}