#include <iostream>
#include <set>

void showCollectionStatus(const std::multiset<std::string>& c, std::multiset<std::string>::iterator& m) {
   std::multiset<std::string>::iterator i = c.begin();
   std::cout << "\n--- COLLECTION ---\n";
   while (i != c.end()) {
      std::cout << *i;
      if (&*i == &*m) std::cout << " <--";
      std::cout << std::endl;

      ++i;
   }
   std::cout << "------------------\n";
}

int main() {
   std::string word;
   std::multiset<std::string> collection;
   std::multiset<std::string>::iterator middle = collection.begin();

   while (std::cin >> word and word != "END") {
      collection.insert(word);
      if (collection.size() > 1) {
         if (word > *middle) {
            ++middle;
         } else {
            --middle;
         }
      }
      else middle = collection.begin();

      // std::cout << *middle << std::endl;
      showCollectionStatus(collection, middle);
   }
}