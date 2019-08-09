/*
Daniel Racz
CSC331H
Professor Salvati
Large Int Project
/**/


#include "LargeInt.h"
#include "intList.h"
#include <sstream>
#include <string>

LargeInt::LargeInt() {    // Constructor

  size = 0;
  isNeg = false;

}


istream& operator>>(istream& in, LargeInt& number) {   //Overload of input stream to attain numbers
string input;
getline(in,input);
number.size = input.size();
number.isNeg = false;


for (int i = 0; i < number.size; i++){
  if(input[i] == '-') {

	  number.isNeg = true;

	 number.list1.front(input[i+1] - '0');
	  i++;
	 }
	  else
	     number.list1.front(input[i] - '0');
	 }
return in;

}


ostream& operator<<(ostream& out, LargeInt& number) {  // Overload of output operator to output result.

if(number.isNeg == true){
  out << "-";
}
else
out << "";

for(auto itr = number.list1.begin();itr != number.list1.end();itr++)
    std::cout << *itr;

return out;

}


bool LargeInt::operator==(LargeInt& b) {  // Equal overload operator to check if numbers are equivalent.

  bool isTrue = true;
  int count = 0;

  if(size != b.size)
  isTrue = false;
  else {
    auto itr = list1.begin();
    auto itr2 = b.list1.begin();

    while (count < b.size) {
      if(itr != itr2)
      isTrue = false;
      break;
      itr++;itr2++;
    }

  }
  return isTrue;
}

bool LargeInt::operator<(LargeInt& b) {     // Less than operator

  bool isTrue = true;

  auto itr = list1.begin();
  auto itr2 = b.list1.begin();

  if (this->list1.size() < b.list1.size()){
    isTrue = true;

  } else if (this->list1.size() > b.list1.size()){
    isTrue = false;

  }
  else {
    for(int i = 0; i < list1.size(); i++){
      if(*itr < *itr2){
        isTrue = true;
        break;
      } else if (*itr == *itr2){
        isTrue = true;
      } else if (*itr > *itr2){
        isTrue = false;
        break;
      }
      itr++;itr2++;
    }
  }
  return isTrue;
}

bool LargeInt::operator>(LargeInt& b) {        // Greater than operator

  bool isTrue = true;

  auto itr = list1.begin();
  auto itr2 = b.list1.begin();

  if(this->list1.size() < b.list1.size()){
    isTrue = false;
  } else if (this->list1.size() > b.list1.size()){
    isTrue = true;
  } else if (*this == b) {
    isTrue = false;
  }

  else {
    for(int i = 0; i < list1.size(); i++){
      if(*itr == *itr2){
        isTrue = true;

      } else if (*itr < *itr2){
        isTrue = false;
        break;
      } else if (*itr > *itr2){
        isTrue = false;
        break;
      }
      itr++;itr2++;
    }
  }
  return isTrue;

  }

  bool LargeInt::operator>=(LargeInt& b) {     //Greater than or equal operator

    bool isTrue = false;

    if(*this > b || *this == b)
    isTrue = true;

    return isTrue;

  }

  bool LargeInt::operator<=(LargeInt& b) {   //Less than or equal operator

    bool isTrue = false;

    if(*this < b || *this == b)
    isTrue = true;

    return isTrue;
  }


int LargeInt::negativeCheck(bool num1, bool num2) {

  int combo;

  if(num1 && num2)  // Both numbers are negative
  combo = 1;

  if(!num1 && num2)  // Number 2 is positive, Number 1 is negative
  combo = 2;

  if(num1 && !num2)  // Number 1 is positive, Number 2 is negative
  combo = 3;

  return combo;

}

intList<int> LargeInt::add(LargeInt& a, LargeInt& b) {  // Addition function to assist in multiplication method.
  intList<int> c;

  int count = 0;
  int carry = 0;
  int total = 0;
  int num = 0;
  int bigger = b.list1.size();


// Check sizes of lists are equal.  If not - will distribute 0's to even out addition on operands.
if(a.list1.size() != b.list1.size()) {

  if(b.list1.size() > a.list1.size())
  {
    num = b.list1.size() - a.list1.size();

    while(num > 0)
    {
      a.list1.back(0);
      num--;
    }
  }
  else
   num = a.list1.size() - b.list1.size();
   bigger = a.list1.size();
    while(num > 0)
    {
      b.list1.back(0);
      num--;
    }
}

auto itr = a.list1.begin();
auto itr2 = b.list1.begin();


while (count < bigger ) {
total = (*itr + *itr2);
if (total > 9)
{
  total += carry;
  total -= 10;
  carry = 1;
  c.front(total);
  if(b.size == 1 && size == 1)
  {
    c.front(carry);
  }
}
else{
total += carry;
c.front(total);
carry = 0;
}
count++; itr++; itr2++;
}
    return c;

}

LargeInt LargeInt::operator+(LargeInt& b) {  // Addition Operator to add two large integers together.
  LargeInt c;

  int count = 0;
  int carry = 0;
  int total = 0;
  int num = 0;
  int bigger = b.list1.size();

auto itr = list1.begin();
auto itr2 = b.list1.begin();

  int combo = negativeCheck(this->isNeg, b.isNeg);

  if(combo == 1){
    total = (*itr + *itr2);
   c.isNeg = true;
  }
  if(combo == 2){
    total = (*itr2 - *itr);
    c.isNeg = true;

    if(*itr <= *itr2)
    c.isNeg = false;
    else
    c.isNeg = true;
  }
  if(combo == 3){
    c.isNeg = false;
    total = (*itr - *itr2);

  }
  else
  total = (*itr + *itr2);


// Check sizes of lists are equal.  If not - will distribute 0's to even out addition on operands.
if(list1.size() != b.list1.size()) {

  if(b.list1.size() > list1.size())
  {
    num = b.list1.size() - list1.size();

    while(num > 0)
    {
      list1.back(0);
      num--;
    }
  }
  else
   num = list1.size() - b.list1.size();
   bigger = list1.size();
    while(num > 0)
    {
      b.list1.back(0);
      num--;
    }
}

while (count < bigger) {
    if(combo == 1){
        total = (*itr + *itr2);
        c.isNeg = true;
    }
    if(combo == 2){
        total = (*itr2 - *itr);
        c.isNeg = true;

        if(*itr <= *itr2)
        c.isNeg = false;
        else
        c.isNeg = true;
    }
    if(combo == 3){
        c.isNeg = false;
        total = (*itr - *itr2);
    } else
    total = (*itr + *itr2);
    if(total > 9){
        total += carry;
        total -= 10;
        carry = 1;
        c.list1.front(total);
        if((b.size == 1 && size == 1)){
            c.list1.front(carry);
        }
    }
    else {
        total += carry;
        c.list1.front(total);
        carry = 0;
    }
    count++; itr++; itr2++;
}
if(carry == 1)
c.list1.front(carry);

return c;

}


LargeInt LargeInt::operator-(LargeInt& b) {  // Subtraction operator to subtract two large integers together
  LargeInt c;

  int count = 0;
  int carry = 0;
  int total = 0;
  int num = 0;
  int bigger = b.list1.size();

  int combo = negativeCheck(this->isNeg, b.isNeg);

  if(list1.size() != b.list1.size()) {

  if(b.list1.size() > list1.size())
  {
    num = b.list1.size() - list1.size();

    while(num > 0)
    {
      list1.back(0);
      num--;
    }
  }
  else
   num = list1.size() - b.list1.size();
   bigger = list1.size();
    while(num > 0)
    {
      b.list1.back(0);
      num--;
    }
}

auto itr = list1.begin();
auto itr2 = b.list1.begin();

while (count < bigger) {

  if(combo == 1){
    total = (*itr - *itr2);
   c.isNeg = true;
  }
  if(combo == 2){
    total = (*itr2 + *itr);
    c.isNeg = false;
  }
  if(combo == 3){
    c.isNeg = false;
    total = (*itr + *itr2);

  }
  else
  total = (*itr - *itr2);
if (total < 0)
{
  total += carry;
  total += 10;
  carry = -1;
  c.list1.front(total);
}

else{

total += carry;
if(total < 0){
  total += 10;
  carry = -1;
  c.list1.front(total);
}
else {
c.list1.front(total);
carry = 0;
}
}
count++; itr++; itr2++;
}
    return c;

}

LargeInt LargeInt::operator*(LargeInt& b) {  // Multiplication operator to multiply two large integers together.



  LargeInt c;
  LargeInt d, e;

  int count = 0;
  int count2 = 0;
  int count3 = 0;
  int carry = 0;
  int total = 0;
  int zero = 0;

  int combo = negativeCheck(this->isNeg, b.isNeg);

  if(combo == 1)
  {
    c.isNeg = false;
  }
  if(combo == 2 || combo == 3)
  {
    c.isNeg = true;
  }

auto itr = list1.begin();
auto itr2 = b.list1.begin();


while(count2 < b.list1.size()){
  carry = 0;

    while(count < list1.size()){
    total += carry + (*itr2 * *itr);
    if (total > 9)
    {
      carry = (total / 10);
      total = (total % 10);
      if(count3 == 0){
      d.list1.front(total);
      total = 0;
      if(count + 1 == list1.size() && size != 1)
      d.list1.front(carry);}
      else
      {
        e.list1.front(total);
        total = 0;
        if(count + 1 == list1.size() && size != 1)
      e.list1.front(carry);
      }
      if(b.size == 1 && size == 1)
      {
        d.list1.front(carry);
      }
    }
    else
    {
      total += carry;
      if(count3 == 0){
      d.list1.front(total);
      carry = 0;
      total = 0;
      }
      else{

      e.list1.front(total);
      carry = 0;
      total = 0;

    }
    }
    count++;itr++;
  }

count2++;itr2++;count3++; itr = list1.begin();count = 0;

}
 for(int i = 0; i < 1; i++){
          e.list1.back(0);
        }
        zero++;

        e.list1.reverse();
        if(b.list1.size() <= 2)
        d.list1.reverse();

 c.list1 = add(d,e);
  d.list1 = c.list1;
  d.list1.reverse();
  e.list1.destroyList();


return c;


}

  LargeInt LargeInt::operator/(LargeInt& b) {  // Division operator to divide two large integers from each other.

    LargeInt c;

    int count = 0;
    int carry = 0;
    int total = 0;
    int start = 0;

  int combo = negativeCheck(this->isNeg, b.isNeg);

  if(combo == 1)
  {
    c.isNeg = false;
  }
  if(combo == 2 || combo == 3)
  {
    c.isNeg = true;
  }

    auto itr = list1.begin();
    auto itr2 = b.list1.begin();


    while(count < list1.size()){
      total = (carry + *itr) / *itr2;
      if(total % 2 == 1)
      carry = 10;
      else
      carry = 0;

      if(count + 1 == list1.size())
      {
        total = (carry + *itr) / *itr2;
        c.list1.front(total);
        break;
      }

      c.list1.front(total);
      count++; itr++;
      //total = 0;
    }

    return c;

  }

   LargeInt LargeInt::operator%(LargeInt& b) {  // Modulus operator to attain modulus from two large integers.

     LargeInt c;

     int total = 0;

    auto itr = list1.begin();
    auto itr2 = b.list1.begin();


    int count = *itr;

    total = *itr / *itr2;

   for (int i = 0; i < total; i++)
  {
    count -= *itr2;
  }
  c.list1.front(count);

  return c;
   }
