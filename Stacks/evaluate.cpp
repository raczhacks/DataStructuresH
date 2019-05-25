/*Daniel Racz
  CSC 331H
  Stack Evaluation Program
*/

#include <stack>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int evaluate(istream& inputStream);
float operate(char ch, float x, float y);
int order(char op);


int main() {
    string input;

    cout << "Enter equation: " << endl;

    getline(cin,input);

    while(input.size() != 0)
    {
        try {
            istringstream inputExpr(input);
            cout << evaluate(inputExpr) << endl;
        }
        catch (string exceptionString)      // Catch if number is divided by zero
        {
            cout << exceptionString << endl;
        }
        cout << "Enter another Equation" << endl;
        getline(cin,input);
    }
    return 0;
}

int order(char op) {                     // function to keep track order of operations
  if(op == '+' || op == '-') return 1;
  if(op == '*' || op == '/') return 2;
  return 0;
}

float operate(char ch, float x, float y) {    // function to combine digits with operator and return its action
    switch (ch)
    {
      case '+': return x+y;
      case '-': return x-y;
      case '*': return x*y;
      case '/': if (y == 0)
                throw string("Error");
                else
                return x/y;
    }
    return 0;
}

int evaluate(istream & in){
    stack<char> operators;
    stack<float> digits;
    bool negFlag = true;          // flag to determine if negative digit is added to stack

    char ch, op;
    int num = 0, res = 0, left = 0, right = 0;

    ch = in.peek();
    while (ch != EOF)
    {
        if(isspace(ch))
        {
            ch = in.get();
            ch = in.peek();
            continue;
        }

        if(ch == '(')
        {
            negFlag = true;
            in >> ch;
            operators.push(ch);
            ch = in.peek();
            continue;
        }
        if (isdigit(ch))
        {
            negFlag = false;
            in >> num;
            digits.push(num);
            ch = in.peek();
            continue;
        }

            if (ch == '-')
            {
                ch = in.get();
                ch = in.peek();

                if (isdigit(ch) && digits.empty())    // Case for first digit being negative
                {
                    negFlag = false;
                    in >> num;
                    digits.push(num *= -1);
                    ch = in.peek();
                    continue;
                }

                if(!isdigit(ch) && negFlag == false && !digits.empty() && !operators.empty() && ch != '(' && ch != '-')    // Case if after negative and next character is an operator
                {
                    in >> num;
                    digits.push(num *= -1);
                    ch = in.peek();
                    continue;
                    negFlag = false;
                }

                if(isdigit(ch) && negFlag == true && operators.top() == '(' )             // Case if negative is within ()
                {
                    in >> num;
                    digits.push(num *= -1);
                    ch = in.peek();
                    continue;
                    negFlag = false;
                }

                if(isdigit(ch) && negFlag == true && !operators.empty() && operators.top() != '(')   // Case if negative is used after operator and spaces
                {
                    in >> num;
                    digits.push(num *= -1);
                    ch = in.peek();
                    continue;
                    negFlag = true;
                }

                else                                    // All other cases where number must be negated.
                {
                    negFlag = true;
                    while(!operators.empty() && order('-') <= order(operators.top()))
                    {
                        right = digits.top();
                        digits.pop();
                        left = digits.top();
                        digits.pop();

                        digits.push(operate(operators.top(), left, right));
                        res = digits.top();
                        operators.pop();
                    }
                    operators.push('-');
                    ch = in.peek();
                    continue;
                }
            }
            else if (ch == '+' || ch == '*' || ch == '/')
            {
                negFlag = true;
                in >> ch;
                while(!operators.empty() && order(ch) <= order(operators.top()))     // Compares operator order when two or more are entered
                {
                    right = digits.top();
                    digits.pop();
                    left = digits.top();
                    digits.pop();

                    digits.push(operate(operators.top(), left, right));
                    res = digits.top();
                    operators.pop();
                }
                operators.push(ch);
                ch = in.peek();
                continue;
            }
            else if (ch == ')'){

                in >> ch;
                while(!operators.empty() && operators.top() != '(')
                {
                    right = digits.top();
                    digits.pop();
                    left = digits.top();
                    digits.pop();
                    op = operators.top();
                    operators.pop();

                    digits.push(operate(op, left, right));
                }
                operators.pop();
                ch = in.peek();
                continue;
            }
            else {        // Error if misc. operators are entered
                cout << "Error" << endl;
                exit(1);
            }

    }
    if(operators.empty() == 1)   // condition to return single digit if string is only a single number
    {
        res = digits.top();
    }

    while(!operators.empty())     // evaluates remaining stack digits at end of string
    {
        right = digits.top();
        digits.pop();
        left = digits.top();
        digits.pop();
        op = operators.top();
        operators.pop();

        digits.push(operate(op, left, right));
        res = digits.top();
    }
    return res;
}
