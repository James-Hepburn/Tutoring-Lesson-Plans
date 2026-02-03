#include <iostream>
#include <stack>

/*
prefix:

1. Scan the given prefix expression from right to left character by character.

2. If the character is an operand, push it into the stack.

3. But if the character is an operator, pop the top two values from stack.

4. Concatenate this operator with these two values (1st top value+operator+2nd top value) to get a new string.

5. Now push this resulting string back into the stack.

6. Repeat this process untill the end of prefix expression. Now the value in the stack is the desired infix expression.
*/

double prefix (std::string exp) { // +9*26 becomes 21
  std::stack <double> s;
  for (int i = exp.size() - 1; i >= 0; i--) {
    if (isdigit(exp[i])) {
      s.push (exp[i] - '0');
    } else {
      double x = s.top();
      s.pop();
      double y = s.top();
      s.pop();
      if (exp[i] == '+') {
        s.push (x + y);
      } else if (exp[i] == '-') {
        s.push (x - y);
      } else if (exp[i] == '*')  {
        s.push (x * y);
      } else if (exp[i] == '/')  {
        s.push (x / y);
      }
    }
  }
  return s.top();
}

/*
postfix:

1. Scan the given postfix expression from left to right character by character.

2. If the character is an operand, push it into the stack.

3. But if the character is an operator, pop the top two values from stack.

4. Concatenate this operator with these two values (2nd top value+operator+1st top value) to get a new string.

5. Now push this resulting string back into the stack.

6. Repeat this process untill the end of postfix expression. Now the value in the stack is the infix expression.
*/

double postfix (std::string exp) { // 231*+9- becomes -4
  std::stack <double> s;
  for (int i = 0; i < exp.length(); i++) {
    if (isdigit(exp[i])) {
      s.push (exp[i] - '0');
    } else {
      double x = s.top();
      s.pop();
      double y = s.top();
      s.pop();
      if (exp[i] == '+') {
        s.push (x + y);
      } else if (exp[i] == '-') {
        s.push (y - x);
      } else if (exp[i] == '*')  {
        s.push (x * y);
      } else if (exp[i] == '/')  {
        s.push (y / x);
      }
    }
  }
  return s.top();
}

int main() {

  std::cout << "\nWelcome to the Prefix and Postfix Calculator!\n";

  while (true) {
    std::cout << "\n1) Prefix\n";
    std::cout << "2) Postfix\n";
    std::cout << "3) Exit\n";
    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
  
    if (choice == 1) {
      std::string exp;
      std::cout << "\nEnter an expression: ";
      std::cin >> exp;
      std::cout << "Prefix: " << prefix (exp) << "\n";
    } else if (choice == 2) {
      std::string exp;
      std::cout << "\nEnter an expression: ";
      std::cin >> exp;
      std::cout << "Postfix: " << postfix (exp) << "\n";
    } else if (choice == 3) {
      std::cout << "\nGoodbye!\n";
      break;
    } else {
      std::cout << "\nInvalid choice!\n";
    }

  }
  
}
