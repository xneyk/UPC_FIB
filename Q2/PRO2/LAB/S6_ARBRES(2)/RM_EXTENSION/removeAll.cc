#include "removeAll.hh"

bool is_leave(const BT &t) {
   return t.left().empty() && t.right().empty();
} 

BT removeAll(const string &extension, const BT &t) {
   if (!t.empty()) {
      string supposed_file = t.value();
      int supposed_file_size = supposed_file.size();
      int ext_size = extension.size();

      if (supposed_file_size > ext_size) {
         string supposed_extension = supposed_file.substr(supposed_file_size - ext_size);
         if (is_leave(t) && supposed_extension == extension) return BT ();
      }

      return BT (t.value(), removeAll(extension, t.left()), removeAll(extension, t.right()));
   }

   return t;
}