/*
Daniel Racz
CSC331H
Professor Salvati
Large Int Project
/**/


#ifndef LARGEINT_h
#define LARGEINT_h
#include "intList.h"
#include "intList.cpp"
#include <iostream>

using namespace std;

class LargeInt {

  public:
  LargeInt();

  // Input & Output Operators
  friend ostream& operator<<(ostream& out, LargeInt&);
  friend istream& operator>>(istream& in, LargeInt&);

  // Arithmetic Operators
  LargeInt operator+(LargeInt& b);
  LargeInt operator-(LargeInt& b);
  LargeInt operator/(LargeInt& b);
  LargeInt operator*(LargeInt& b);
  LargeInt operator%(LargeInt& b);

  // Comparison Operators
  bool operator==(LargeInt& b);
  bool operator>=(LargeInt& b);
  bool operator<=(LargeInt& b);
  bool operator>(LargeInt& b);
  bool operator<(LargeInt& b);

  // Check if negative sign is entered
  int negativeCheck(bool num1, bool num2);

  private:
   intList<int> add(LargeInt& a, LargeInt& b);
  int size;
  bool isNeg;
  intList<int> list1;

};

#endif
