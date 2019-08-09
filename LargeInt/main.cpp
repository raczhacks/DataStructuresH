/*
Daniel Racz
CSC331H
Professor Salvati
Large Int Project
/**/


#include <iostream>
#include <string>
#include <sstream>
#include "intList.h"
#include "LargeInt.h"

using namespace std;


int main() {

  LargeInt a, b, c;
  char op;

    cout << "Enter first number: " << endl;

    cin >> a;

    cout << "Enter second number: " << endl;

    cin >> b;

  cout << "-----Entries-----" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << "-----------------" << endl;

  cout << "Enter an operator (+,-,*,/,%)" << endl;

    cin >> op;

    if(op == '+')
    c = a + b;
    else if(op == '-')
    c = a - b;
    else if(op == '*')
    c = a * b;
    else if(op == '/')
    c = a / b;
    else if(op == '%')
    c = a % b;
    else
    exit(0);

cout << "-----Result------" << endl;
 cout << c;

return 0;
}
