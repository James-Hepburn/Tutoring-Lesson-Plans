#include <iostream>
#include <map>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

int get_choice () {
  int choice = 0;
  std::cout << "\n1) Add item\n";
  std::cout << "2) Delete item\n";
  std::cout << "3) Edit item\n";
  std::cout << "4) View insurance claim\n";
  std::cout << "5) Submit insurance claim\n";
  std::cout << "\nWhich option would you like to select? ";
  std::cin >> choice;
  while (choice < 1 || choice > 5) {
    std::cout << "\nInvalid option. Try again: ";
    std::cin >> choice;
  }
  return choice;
}

int main() {

  erase (0);
  
  std::cout << "\nYour house has been robbed! To file an insurance claim, please fill out information about the stolen items. Thank you.\n";

  char ready;
  std::cout << "\nAre you ready to continue? (y/n) ";
  std::cin >> ready;

  if (ready == 'y') {
    std::map <std::string, int> map;
    while (true) {
      erase (3000000);
      int choice = get_choice();
      erase (3000000);
      if (choice == 1) {
        int value;
        std::string name;
        std::cout << "\nEnter the name of the item: ";
        std::cin >> name;
        if (map.count (name) == 0) {
          std::cout << "\nEnter the value of the item: ";
          std::cin >> value;
          map [name] = value;
        } else {
          std::cout << "\nItem with this name already exists.\n";
        }
      } else if (choice == 2) {
        std::string name;
        std::cout << "\nEnter the name of the item you would like to delete: ";
        std::cin >> name;
        if (map.count (name) == 1) {
          map.erase (name);
        } else {
          std::cout << "\nNo item with this name exists.\n";
        }
      } else if (choice == 3) {
        std::string name;
        std::cout << "\nEnter the name of the item you would like to edit: ";
        std::cin >> name;
        if (map.count (name) == 1) {
          int current = map[name];
          int updated;
          std::cout << "\nThe item is currently valued at $" << current << ". What would you like to set the value to? ";
          std::cin >> updated;
          map [name] = updated;
        } else {
          std::cout << "\nNo item with this name exists.\n";
        }
      } else if (choice == 4) {
        std::map<std::string, int>::iterator it = map.begin();
        int count = 1;
        while (it != map.end()) {
          std::cout << "Item # " << count << ": " << it->first << " - $" << it->second << "\n";
          it ++;
          count += 1;
        }
      } else {
        std::cout << "\nYour insurance claim has been submitted. Thank you.\n";
        break;
      }
    }
  }
  
}
