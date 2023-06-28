#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

int main() {

  while (true) {
    erase (1000000);
    
    std::cout << "\nSecret Journal! \n\n"; 
    std::cout << "1) Add an entry \n";
    std::cout << "2) View an entry \n";
    std::cout << "3) Exit \n\n";

    int option;
    std::cout << "Enter an option: ";
    std::cin >> option;

    if (option == 1) {
      erase (1000000);
      std::string year;
      std::cout << "Year? ";
      std::cin >> year;
      std::string month;
      std::cout << "Month? ";
      std::cin >> month;
      std::string day;
      std::cout << "Day? ";
      std::cin >> day;
      std::string file_name = year + "-" + month + "-" + day + ".txt";
      std::string entry;
      std::cout << "\nType entry here (type 'EXIT' to finish): \n\n";
      std::ofstream file; 
      file.open (file_name);
      while (true) {
        getline (std::cin, entry);
        if (entry == "EXIT") {
          break;
        }
        file << entry << "\n";
      }
      file.close();
    } else if (option == 2) {
      erase (1000000);
      std::string year;
      std::cout << "Year? ";
      std::cin >> year;
      std::string month;
      std::cout << "Month? ";
      std::cin >> month;
      std::string day;
      std::cout << "Day? ";
      std::cin >> day;
      std::string file_name = year + "-" + month + "-" + day + ".txt";
      std::ifstream file;
      file.open (file_name);
      if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
          std::cout << line << "\n";
        }
        std::cout << "\nPress enter to continue: ";
        std::cin.get();
        std::cin.get();
      } else {
        std::cout << "\nThis entry does not exist. \n";
      }
    } else if (option == 3) {
      std::cout << "\nGoodbye! \n";
      break;
    } else {
      std::cout << "\nInvalid option. \n";
    }
  }
  
}
