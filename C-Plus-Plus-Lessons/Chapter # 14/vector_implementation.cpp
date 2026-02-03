#include <iostream>
#include <vector>

int main() {
  
  std::cout << "\nWelcome to the Vector Implementation of a Stack!\n";

  std::vector <int> stack;

  while (true) {
    std::cout << "\n1) view stack\n";
    std::cout << "2) push an element\n";
    std::cout << "3) pop an element\n";
    std::cout << "4) view top element\n";
    std::cout << "5) is empty?\n";
    std::cout << "6) size\n";
    std::cout << "7) exit\n";
  
    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
      std::cout << "\nStack: \n";
      for (int i = 0; i < stack.size(); i++) {
        std::cout << stack[i] << "\n";
      }
    } else if (choice == 2) {
      int element;
      std::cout << "\nEnter an element: ";
      std::cin >> element;
      stack.insert(stack.begin(), element);
      std::cout << "Added element: " << element << "\n";
    } else if (choice == 3) {
      int pop = stack[0];
      stack.erase (stack.begin());
      std::cout << "\nPopped element: " << pop << "\n";
    } else if (choice == 4) {
      int top = stack[0];
      std::cout << "Top element is: " << top << "\n";
    } else if (choice == 5) {
      if (stack.empty()) {
        std::cout << "\nStack is empty!\n";
      } else {
        std::cout << "\nStack is not empty!\n";
      }
    } else if (choice == 6) {
      std::cout << "\nStack size: " << stack.size() << "\n";
    } else if (choice == 7) {
      std::cout << "\nGoodbye!\n";
      break;
    } else {
      std::cout << "\nInvalid choice!\n";
    }
    
  }
 
}
