#include <iostream>
#include <stack>

#define MAXCOLS 80

using namespace std;

string infixToPostfix(string);
bool isOperand(char);
bool isOperator(char);
int precedence(char);

int main() {
  string infix, postfix;
  cout << "Enter a infix expression: " << endl;
  cin >> infix;

  cout << "Original Infix expression: " << infix << endl;
  postfix = infixToPostfix(infix);

  cout << "Postfix Expression: " << postfix << endl;

  return 0;
};

string infixToPostfix(string infix) {
  stack<char> s;
  string postfix;

  for (int i = 0; i < infix.length(); i++) {

    char symb = infix[i];

    if (isOperand(symb)) {
      postfix += symb;
    } else if (symb == '(') {
      s.push(symb);
    } else if (symb == ')') {

      while (s.top() != '(' && !s.empty()) {
        postfix += s.top();
        s.pop();
      }
      s.pop();
    } else if (isOperator(symb)) {
      if (s.empty()) {
        s.push(symb);
      } else {
        if (precedence(symb) > precedence(s.top())) {
          s.push(symb);
        } else if (precedence(symb) == precedence(s.top()) && symb == '^') {
          s.push(symb); // right to left associativity reason
        } else {
          while (!s.empty() && precedence(symb) <= precedence(s.top())) {
            postfix += s.top();
            s.pop();
          }
        }
      }
    }
  }
  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  // operand ho vane just
  return postfix;
}

bool isOperand(char a) {
  return (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z');
}
bool isOperator(char a) {
  return (a == '+' || a == '-' || a == '/' || a == '*' || a == '^');
}
int precedence(char a) {
  if (a == '^')
    return 3;
  else if (a == '*' || a == '/')
    return 2;
  else if (a == '+' || a == '-')
    return 1;
  else
    return -1;
}
