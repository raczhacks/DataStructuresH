/*
Daniel Racz
CSC331H
Professor Salvati
Large Int Project
/**/

#include "intList.h"


template <class x>          // Default constructor
intList<x>::intList()
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <class x>         // Destructor
intList<x>::~intList()
{
  Node<x>* temp;

  while(head != nullptr)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
}

template <class x>         // Copy Constructor
intList<x>::intList( intList<x> & other){
  head = NULL;
  tail = NULL;
  copy(other);
}

template <class x>       // Copy function
void intList<x>::copy(const intList<x> & other) {
   if(other.head == nullptr){
    return;
  }
  else {
    Node<x> *s = other.head;
    head = new Node<x>;
    head->data = s->data;
    Node<x> *t = head;

    while(s->next != nullptr)
    {
      t->next = new Node<x>;
      t = t->next;
      s = s->next;
      t->data = s->data;
      tail = t;
    }
    t->next = nullptr;

  }
}

template <class x>  // Reverse list
void intList<x>::reverse()
{
    Node<x>* temp = head;
   head = tail;
   tail = temp;

  Node<x>* p = head;

  while(p!=NULL)
    {
      temp=p->next;
      p->next=p->prev;
      p->prev=temp;
      p=p->next;
    }
}



 template <class x>         // = Operator
 intList<x>& intList<x>::operator=(const intList<x> &right){
   if (this != &right){
	    copy(right);
   }
   return *this;
 }

template <class x>
void intList<x>::destroyList() {
    Node<x>* temp;
  while(head != nullptr)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
}

template <class x>      // Remove data from any list
void intList<x>::remove(x data) {
  Node<x> *ptr, *previousNodePtr;

  if (!head) return;   // If null, do nothing

  if (head->data == data)    // If head is data
  {
    ptr = head;
    head = head->next;
    delete ptr;
    length--;
  }
  else
  ptr = head;
  while (ptr != nullptr && ptr->data != data)
  {
    previousNodePtr = ptr;
    ptr = ptr->next;
  }
  if (ptr)                // If rest of nodes are data
  {
    previousNodePtr->next = ptr->next;
    delete ptr;
    length--;
  }
  if (ptr == tail)
  {
    tail = previousNodePtr;
  }

}

template <class x>               // Search specific data
bool intList<x>::search(x data) {
  Node<x>* ptr = head;
  bool isFound = false;
  if(data == head->data || data == tail->data)
  {
  isFound = true;
  }
  else
  {
    while (ptr != nullptr && ptr->data != data)
    {
      ptr = ptr->next;
    }
    if (ptr)
    isFound = true;
  }
  return isFound;
}

template <class x>      // Add data to first Node
void intList<x>::front(x data)  {

   Node<x>* ptr = head;
    Node<x>* newNode = new Node<x>;
    newNode->data = data;

  // Case 1 - Empty Node
  if (head == nullptr) {
  head = newNode;
  tail = newNode;
  length++;
  }
  else {
      // Case 2 - Int is smaller than first node

      head->prev = newNode;
      newNode->next = head;
      head = newNode;
      length++;
  }
}

template <class x>     // Add data to last node
void intList<x>::back(x data) {

   Node<x>* ptr = head;
    Node<x>* newNode = new Node<x>;
    newNode->data = data;

   if (tail == nullptr) {
  head = newNode;
  tail = newNode;
  length++;
   }
  else {
          newNode->prev = tail;
          tail->next = newNode;
          tail = newNode;
          length++;
  }
}

  template <class x>      // Print Nodes
  void intList<x>::printList() {
    Node<x>* p = head;
    std::cout << "-------" << std::endl;
    while (p != nullptr) {
    std::cout << p->data << "\n";
    p = p->next;
    }
  }

  template <class x>  // Check size of list
  int intList<x>::size() {
    return length;
  }

  template <class x>   // Delete last Node
  void intList<x>::deleteLast() {

    Node<x>* temp, *ptr;
    ptr = head;

    if(!head) return;

    if(head->next == NULL)
    {
      head = head->next;
      delete ptr;
      tail = head;
    }
    else {
    while(ptr != NULL && ptr != tail)
    {
      temp = ptr;
      ptr = ptr->next;
    }
    if(ptr){
    temp->next = ptr->next;
   delete ptr;
   tail = temp;
    }
    }
  }

  template <class x>  // Print both from head to tail, tail to head
  void intList<x>::printBoth() {
    Node<x>* ptrFront, *ptrBack;

    ptrFront = head;
    ptrBack = tail;

    if(head == NULL) return;

    else {
      while(ptrFront != NULL) {
        std::cout << ptrFront->data << std::endl;
        ptrFront = ptrFront->next;
      }
      while(ptrBack != NULL) {
        std::cout << ptrBack->data << std::endl;
        ptrBack = ptrBack->prev;
      }
    }
  }

  template <class x>  // Delete all even nodes
  void intList<x>::deleteEven() {
    Node<x>* ptr, *temp;

    if (head == nullptr) std::cout << "Empty" << std::endl;

else
ptr = head;
    while(ptr != nullptr)
  {

    if (ptr->data % 2 == 0) {

    temp = ptr;
    ptr = ptr->next;
    delete temp;
    }
    else {
     temp = ptr;
     ptr = ptr->next;
    }
  }

  }

 template class intList<int>;
