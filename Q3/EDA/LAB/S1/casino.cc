#include <iostream>
#include <map>

typedef std::map<std::string,int>::iterator It;

int main() {
   std::string customer;
   std::string cmd;

   std::map<std::string,int> database; // [customer_name, profit]

   while (std::cin >> customer >> cmd) {
      if (cmd == "wins") {
         int amount;
         std::cin >> amount;
         It selected_customer = database.find(customer);
         if (selected_customer == database.end()) {
            std::cout << customer << " is not in the casino" << std::endl;
         } else {
            database[customer] += amount;
         }
      } else if (cmd == "leaves") {
         It selected_customer = database.find(customer);
         if (selected_customer == database.end()) {
            std::cout << customer << " is not in the casino" << std::endl;
         } else {
            std::cout << customer << " has won " << database[customer] << std::endl;
            database.erase(selected_customer);
         }
      } else if (cmd == "enters") {
         It selected_customer = database.find(customer);
         if (selected_customer != database.end()) {
            std::cout << customer << " is already in the casino" << std::endl;
         } else {
            database[customer] = 0;
         }
      }
   }
   // program ended ==> need to resume

   It selected_customer = database.begin();
   std::cout << "----------" << std::endl;
   while (selected_customer != database.end()) {
      std::cout << selected_customer->first << " is winning " << selected_customer->second << std::endl;
      ++selected_customer;
   }
}