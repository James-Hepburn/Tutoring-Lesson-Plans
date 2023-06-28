#include <iostream>
#include <stack>

/*
steps:

1. make a stack to store the characters of the statement
2. iterate through the statement
3. if you see an open bracket, add it to the stack
4. if you see a closed bracket, get the top value of the stack and see if they are a match.
  a. if match -> continue
  b. if not match -> statement is not balanced
5. at the end of the iteration, check if the stack is empty
  a. if empty -> statement is balanced
  b. if not empty -> statement is not balanced
*/

bool check_balanced (std::string exp) {
  std::stack <char> s;
  for (int i = 0; i < exp.size(); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      s.push(exp[i]);
    } else {
      char t = s.top();
      if (t == '(' && exp[i] != ')') {
        return false;
      } else if (t == '{' && exp[i]!= '}') {
        return false;
      } else if (t == '[' && exp[i]!= ']') {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}

/*
steps:

1. make a stack to store the characters of the statement
2. iterate through the statement
3. if you see anything other than a closed bracket, add it to the stack
4. if you see a closed bracket, iterate through the stack and count how long it takes to see an open bracket
  a. if found immediately -> statement contains duplicates
5. at the end of the iteration -> statement does not contain duplicates
*/

bool check_duplicate (std::string exp) {
  std::stack <char> s;
  for (int i = 0; i < exp.length(); i++) {
    if (exp[i] == ')') {
      char top = s.top();
      s.pop();
      int num_of_elements = 0;
      while (top != '(') {
        num_of_elements += 1;
        top = s.top();
        s.pop();
      }
      if (num_of_elements < 1) {
        return true;
      }
    } else {
      s.push (exp[i]);
    }
  }
  return false;
}

int main() {

  std::cout << "\nWelcome to the Statement Checker!\n";

  std::string exp;
  std::cout << "\nEnter a statement: ";
  std::cin >> exp;

  int choice;
  std::cout << "\nWould you like to to check if a statement \n(1) is balanced, or \n(2) contains duplicate parenthesis? \n";
  std::cin >> choice;

  if (choice == 1) {
    if (check_balanced(exp)) {
      std::cout << "\nStatement is balanced!\n";
    } else {
      std::cout << "\nStatement is not balanced!\n";
    }
  } else if (choice == 2) {
    if (check_duplicate(exp)) {
      std::cout << "\nStatement does contain duplicates!\n";
    } else {
      std::cout << "\nStatement does not contain duplicates!\n";
    }
  } else {
    std::cout << "\nInvalid choice.\n";
  }
   
}
