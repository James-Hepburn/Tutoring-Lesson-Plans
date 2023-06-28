#include <iostream>
#include <vector>
#include <unistd.h>

void view (std::vector <std::string> contacts) {
  std::cout << "\n";
  for (int i = 0; i < contacts.size(); i++) {
    std::cout << " - " << contacts[i] << "\n";
  }
}

std::string add_name () {
  std::string name;
  std::cout << "\nName: ";
  std::cin >> name;
  return name;
}

std::string add_number () {
  std::string number;
  std::cout << "Phone number: ";
  std::cin >> number;
  return number;
}

int del (std::vector <std::string> contacts, std::vector <std::string> names) {
  std::string name;
  std::cout << "\nName: ";
  std::cin >> name;
  for (int i = 0; i < names.size(); i++) {
    if (name == names[i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  
  std::cout << "\nWelcome to the Contact Book!\n";

  std::string decision;
  std::vector <std::string> contacts;
  std::vector <std::string> names;
  
  while (decision != "EXIT") {
    usleep(3000000); // microseconds
    std::cout << "\033[2J\033[1;1H";

    std::cout << "\nWould you like to \n - VIEW your contacts \n - ADD a new contact \n - DELETE an exisiting contact \n - EXIT\n";
    std::cin >> decision;

    if (decision == "VIEW") {
      view (contacts);
    } else if (decision == "ADD") {
      std::string name = add_name ();
      std::string number = add_number ();
      names.push_back(name);
      contacts.push_back (name + " " + number);
    } else if (decision == "DELETE") {
      int i = del (contacts, names);
      if (i == -1) {
        std::cout << "\nInvalid input, no action taken.\n";
      } else {
        names.erase (names.begin() + i);
        contacts.erase (contacts.begin() + i);
      }
    } else if (decision == "EXIT") {
      std::cout << "\nGoodbye!\n";
      break;
    } else {
      std::cout << "\nInvalid input, no action taken.\n";
    }
  }
  
}
