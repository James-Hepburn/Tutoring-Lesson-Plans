#include <iostream>
#include <stack>

int main() {
  
  // stacks - a type of container with LIFO (last in first out)
  // useful for when the order of actions is important

  // create a stack
  
  std::stack<int> s;

  // add elements to the stack
  
  s.push(1);
  s.push(2);
  s.push(3);

  // get but do not remove the top element

  int top = s.top();
  std::cout << "top: " << top << "\n";

  // delete but do not get the top element

  s.pop(); 
  int new_top = s.top();
  std::cout << "top: " << new_top << "\n";

  // size of the stack
  
  int size = s.size();
  std::cout << "size: " << size << "\n";
  
}

/*
Question # 1:

A letter means push and an asterisk means pop in the following sequence. Give the sequence of values returned by the pop operations when this sequence of operations is performed on an initially empty LIFO stack. Examples:

EAS*Y*QUE***ST***IO*N*** ➞ SYEUQTSAONIE
LA*STI*N*FIR*ST**OU*T****** ➞ AINRTSUTOIFTS
*/

std::string q1 (std::string sequence) {
  std::stack<char> s;
  std::string res;
  for (int i = 0; i < sequence.size(); i++) {
    if (sequence[i] == '*') {
      res += s.top();
      s.pop();
    } else {
      s.push(sequence[i]);
    }
  } 
  return res;
}

/*
Question # 2:

Write a program that reads in a sequence of characters and returns them in reverse order. Use a stack. Examples:

apple ➞ elppa
car ➞ rac
*/

std::string q2 (std::string sequence) {
  std::stack<char> s;
  std::string res;
  for (int i = 0; i < sequence.size(); i++) {
    s.push(sequence[i]);
  }  
  while (!s.empty()) {
    res += s.top();
    s.pop();
  }
  return res;
}

/*
Question # 3:

Given a line of text, reverse the text without reversing the individual words. Examples:

Happy New Year ➞ Year New Happy
Use a stack ➞ stack a Use
*/

std::string q3 (std::string text) {
  std::stack<std::string> s;
  std::string word;
  for (int i = 0; i < text.size(); i++) {
    if (text[i] ==' ') {
      s.push(word);
      word = "";
    } else {
      word += text[i];
    }
  }
  s.push(word);
  std::string res;
  while (!s.empty()) {
    res += s.top() + " ";
    s.pop();
  }
  return res;
}
