/*
Daniel Racz
CSC331H
Professor Salvati
Large Int Project
/**/

#ifndef INTLIST_h
#define INTLIST_h

#include <iostream>


template <class x>
struct Node {
  x data;
  Node<x>* next;        // Pointing to next node
  Node<x>* prev;        // Pointing to previous node
};

template <class x>
class intList {

  public:
  intList();         // Constructor
  ~intList();        // Destructor
  intList(intList<x> & other);  // Copy Constructor

   class iterator {
      // iterator class
   friend class intList;
   iterator(Node<x> *newPtr) : current(newPtr) {}
   public:
   iterator() : current(nullptr) {}    // iterator constructor
   iterator operator++(x) {             // iterator increment
        iterator temp = *this;
       current = current->next;
        return temp;
      }
      iterator operator--(x) {         // iterator decement
        iterator temp = *this;
        current = current->prev;
        return temp;
      }


   bool operator ==(const iterator& itr) const {   // iterator == operator
      return current == itr.current;
  }
   bool operator!=(const iterator& itr) const {    // iterator != operator
      return current != itr.current;
      }

  x& operator*() const {              // iterator * operator
      return current->data;
      }

   private:
   Node<x>* current;

};

  iterator begin() const {return iterator(head);} // Iterator begin
  iterator end() const {return iterator(NULL);}   // Iterator end


  void copy(const intList<x> & other);  // Copy Function
  intList<x>& operator=(const intList<x> &right);   // = Operator
  void destroyList();   // 2nd Destructor to call
  void remove(x data); // Remove data
  bool search(x data);  // Search for specific data
  void printList();         // Print Nodes
  void front(x data);        // Add data to first node
  void back(x data);         // Add data to last node
  int size();            // Attains length of list
  void deleteLast();   // deleteLast node
  void printBoth();   // Print both head to tail and tail to head
  void deleteEven();  // Delete all even numbers
  void reverse();     // Reverse order


  protected:
  Node<x>* head;            // First Node
  Node<x>* tail;            // Last Node
  int length;          // size of list

};

#endif
