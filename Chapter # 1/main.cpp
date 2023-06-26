#include <iostream> // allows us to get input and output, similar to importing

int main() {

  // printing 
  
  std::cout << "This is how to print\n";

  // variables

  std::string colour = "green";
  std::cout << colour + "\n";
  std::cout << "I like the colour " + colour + "\n";

  int age = 19;
  std::cout << age << "\n";
  std::cout << "I am " << age << " years old\n";

  double decimal_1 = 1.23;
  std::cout << decimal_1 << "\n";
  std::cout << "Here is the first decimal number: " << decimal_1 << "\n";

  float decimal_2 = 4.56;
  std::cout << decimal_2 << "\n";
  std::cout << "Here is the first decimal number: " << decimal_2 << "\n";

  bool isTuesday = true;
  bool isSnowing = false;
  std::cout << isTuesday << "\n"; // 1 for true
  std::cout << "Is it Snowing? " << isSnowing << "\n"; // 0 for false

  // input 

  std::string name; // or name = "";
  std::cout << "Enter a name: ";
  std::cin >> name;
  std::cout << "You entered " + name + "\n";

  int year; // or year = 0;
  std::cout << "Enter a year: ";
  std::cin >> year;
  std::cout << "You entered " << year << "\n";
  
}
