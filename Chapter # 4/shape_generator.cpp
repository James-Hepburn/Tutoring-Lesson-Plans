#include <iostream>

void square (int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      std::cout << "* ";
    }
    std::cout << "\n";
  }
}

void triangle (int rows) {
  int count = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < count; j++) {
      std:: cout << "* ";
    }
    std::cout << "\n";
    count += 1;
  }
}

void diamond (int rows) {
  int half = rows / 2;
  int count = 1;
  int spaces = half;
  for (int i = 0; i < half; i++) {
    for (int j = 0; j < spaces; j++) {
      std::cout << "  ";
    }
    for (int j = 0; j < count; j++) {
      std::cout << "* ";
    }
    std::cout << "\n";
    spaces -= 1;
    count += 2;
  }
  if (rows % 2 != 0) {
    half += 1;
  }
  for (int i = 0; i < half; i++) {
    for (int j = 0; j < spaces; j++) {
      std::cout << "  ";
    }
    for (int j = 0; j < count; j++) {
      std::cout << "* ";
    }
    std::cout << "\n";
    spaces += 1;
    count -= 2;
  }
}

int main() {

  std::cout << "\n1) Square \n";
  std::cout << "2) Triangle \n";
  std::cout << "3) Diamond \n";
  
  int shape;
  std::cout << "\nWhich shape do you want to see? ";
  std::cin >> shape;

  if (shape == 1) {
    int rows;
    std::cout << "\nHow many rows do you want for this square? ";
    std::cin >> rows;
    std::cout << "\n";
    square (rows);
  } else if (shape == 2) {
    int rows;
    std::cout << "\nHow many rows do you want for this triangle? ";
    std::cin >> rows;
    std::cout << "\n";
    triangle (rows);
  } else if (shape == 3) {
    int rows;
    std::cout << "\nHow many rows (odd number) do you want for this diamond? ";
    std::cin >> rows;
    std::cout << "\n";
    diamond (rows);
  } else {
    std::cout << "\nInvalid selection. \n";
  }

}
