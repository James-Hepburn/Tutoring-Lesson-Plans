#include <iostream>

char get_character () {
  std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@$%^&*()-+_";
  int n = std::rand() % 74;
  return characters.at(n);
}

int main() {
  
  int length;
  std::cout << "\nHow long do you want your password to be? ";
  std::cin >> length;

  std::string password = "";
  srand(time (0));
  
  for (int i = 0; i < length; i++) {
    password += get_character();
  }

  std::cout << "\nYour password is ... " << password << "\n";
  
}
