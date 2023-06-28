#include <iostream>
#include <vector>

int main() {

  std::cout << "\nWelcome to the Vector Implementation of a Queue!\n";

  std::vector <int> queue;

  while (true) {
    std::cout << "\n1) view queue\n";
    std::cout << "2) push an element\n";
    std::cout << "3) pop an element\n";
    std::cout << "4) view front element\n";
    std::cout << "5) view back element\n";
    std::cout << "6) size\n";
    std::cout << "7) exit\n";
  
    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
      std::cout << "\nFront\n";
      for (int i = 0; i < queue.size(); i++) {
        std::cout << queue[i] << "\n";
      }
      std::cout << "Back\n";
    } else if (choice == 2) {
      int element;
      std::cout << "\nEnter an element: ";
      std::cin >> element;
      queue.push_back(element);
      std::cout << "Added element: " << element << "\n";
    } else if (choice == 3) {
      int pop = queue[0];
      queue.erase (queue.begin());
      std::cout << "\nPopped element: " << pop << "\n";
    } else if (choice == 4) {
      std::cout << "\nFront element: " << queue[0] << "\n";
    } else if (choice == 5) {
      std::cout << "\nBack element: " << queue[queue.size() - 1] << "\n";
    } else if (choice == 6) {
      std::cout << "\nStack size: " << queue.size() << "\n";
    } else if (choice == 7) {
      std::cout << "\nGoodbye!\n";
      break;
    } else {
      std::cout << "\nInvalid choice!\n";
    }
    
  }

}
