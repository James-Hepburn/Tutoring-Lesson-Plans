#include <iostream>

int main() {

  std::cout << "Welcome to Mad Libs!\n\n";
  std::cout << "Please enter the following information:\n\n";

  std::string name;
  std::cout << "Enter a male name: ";
  std::cin >> name;

  std::string dinosaur;
  std::cout << "Enter a dinosaur: ";
  std::cin >> dinosaur;

  std::string animal;
  std::cout << "Enter an animal: ";
  std::cin >> animal;

  std::string game;
  std::cout << "Enter a game: ";
  std::cin >> game;

  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;

  std::cout << "\n" << name << " was a mighty " << dinosaur << ". The other dinosaurs thought he was good at hunting " << animal << "s. He had " << number << " friend(s) who played " << game << " with him. The end!";
  
}
