#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
private:

  // Items:
  
  struct Item {
    T value;
    Item* next;
  };

  // Data:
  
  int _size;
  Item* ptopitem;

  // Helpers:
  
  Item* copyItems(Item *pitem) {
    if (pitem == NULL) return NULL;
    Item *pfirstitem = new Item();
    Item *pcurrentitem = pfirstitem;
    while (pitem != NULL) {
      pcurrentitem->value = pitem->value;
      if (pitem->next != NULL) pcurrentitem->next = new Item();
      else pcurrentitem->next = NULL;
      pcurrentitem = pcurrentitem->next;
      pitem = pitem->next;
    }
    return pfirstitem;
  }
  
  void deleteItems()
  {
    Item *pitem = ptopitem;
    while (pitem != NULL) {
      Item *pitemaux = pitem;
      pitem = pitem->next;
      delete pitemaux;
    }
    _size = 0;
  }
  
  void printRec(ostream &os, const Item *pitem) const
  {
    if (pitem == NULL) return;
    printRec(os, pitem->next);
    os << " ";
    os << pitem->value;
  }
  
public:

  // Constructors/destructors.
  Stack() {
    ptopitem = NULL;
    _size = 0;
  }
  
  Stack(const Stack<T> &s) {
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
  }
  
  ~Stack() {
    deleteItems();
  }

  // Assignment:
  
  Stack<T> &operator=(const Stack<T> &s) {
    if (this != &s) {
      deleteItems();
      ptopitem = copyItems(s.ptopitem);
      _size = s._size;
    }
    return *this;
  }

  // Standard functions:
  
  int size() {
    return _size;
  }

  bool empty() const {
    return ptopitem == NULL;
  }

  void push(T value) {
    Item *pnewitem = new Item();
    pnewitem->value = value;
    pnewitem->next = ptopitem;
    ptopitem = pnewitem;
    _size++;
  }
  
  void pop() {
    if (ptopitem == NULL) {
      cerr << "Error: pop on empty stack" << endl;
      exit(1);
    }
    Item *paux = ptopitem;
    ptopitem = ptopitem->next;
    delete paux;
    _size--;
  }
    
  T top() {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }
    
  const T top() const {
    if (ptopitem == NULL) {
      cerr << "Error: accessing top of empty stack" << endl;
      exit(1);
    }
    return ptopitem->value;
  }

  // Read and write:
  
  template <typename U> friend ostream &operator<<(ostream &os, const Stack<U> &s);
  template<typename U> friend istream &operator>>(istream &is, Stack<U> &s);
    
  // Pre:
  // Post: La primera ocurrència de 'value' en la pila implícita ha estat esborrada.
  //       Si no hi havia cap ocurrència de 'value', llavors no ha canviat res.
  // Descomenteu les següents dues linies i implementeu la funció:
  void removeFirstOccurrence(T value) {
    bool found = false;
    Item *current = ptopitem;
    Item *prev_current = nullptr; // prev_current = null => there is no nodes behind current node. => current = top.
    while (not found and current != nullptr) {
      if (current->value == value) {
        if (prev_current == nullptr) {
          ptopitem = current->next;
        } else {
          prev_current->next = current->next;
        }

        delete current;
        found = true;
      }

      prev_current = current;
      current = current->next;
    }

    if (found) --_size;
  }
  
};

// Implementation of read and write:

template <typename U> ostream &operator<<(ostream &os, const Stack<U> &s)
{
  os << s._size;
  s.printRec(os, s.ptopitem);
  return os;
}

template <typename U> istream &operator>>(istream &is, Stack<U> &s)
{
  int n;
  is >> n;
  s = Stack<U> ();
  for (int i = 0; i < n; i++) {
    U u;
    is >> u;
    s.push(u);
  }
  return is;
}
