#include <iostream>

int main() {

  int n1; 
  std::cout << "Enter the first number: ";
  std::cin >> n1;

  int n2; 
  std::cout << "Enter the second number: ";
  std::cin >> n2;

  std::cout << n1 << " + " << n2 << " = " << (n1 + n2) << "\n";
  std::cout << n1 << " - " << n2 << " = " << (n1 - n2) << "\n";
  std::cout << n1 << " * " << n2 << " = " << (n1 * n2) << "\n";
  std::cout << n1 << " / " << n2 << " = " << (n1 / n2) << "\n";

}
