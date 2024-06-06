node_arbre* findNode(node_arbre *n, const T &x, int current_depth, int &depth_found) {
   if (n != nullptr) {
      if (n->info == x) {
         depth_found = current_depth;
         return n;
      }
      node_arbre *left = findNode(n->segE, x, current_depth + 1, depth_found);
      int left_depth_found = depth_found;
      node_arbre *right = findNode(n->segD, x, current_depth + 1, depth_found);
      
      if (left != nullptr and right != nullptr) {
         if (left_depth_found > depth_found) return right;
         else return left;
      }
      else if (left == nullptr) return right;
      else return left;
   }
   
   return nullptr;
}

/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
   si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
   node_arbre *searching;
   if (primer_node != nullptr) {
      int found_depth = -1;
      searching = findNode(primer_node, x, 0, found_depth);
      if (searching != nullptr) { // found
         asub.primer_node = copia_node_arbre(searching);
      }
   }
}