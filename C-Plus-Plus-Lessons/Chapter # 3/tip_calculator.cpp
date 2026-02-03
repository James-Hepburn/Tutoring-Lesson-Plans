#include <iostream>

float ten (float total) {
  return total * 0.1;
}

float fifteen (float total) {
  return total * 0.15;
}

float twenty (float total) {
  return total * 0.2;
}

int main() {

  float total;
  std::cout << "\nEnter your total: ";
  std::cin >> total;

  int tip;
  std::cout << "\nDo you want to tip 10%, 15%, 20%? ";
  std::cin >> tip;

  if (tip == 10) {
    std::cout << "\nTotal without tip: $" << total;
    std::cout << "\nTotal with tip: $" << (total + ten(total));
  } else if (tip == 15) {
    std::cout << "\nTotal without tip: $" << total;
    std::cout << "\nTotal with tip: $" << (total + fifteen(total));
  } else if (tip == 20) {
    std::cout << "\nTotal without tip: $" << total;
    std::cout << "\nTotal with tip: $" << (total + twenty(total));
  }

}
