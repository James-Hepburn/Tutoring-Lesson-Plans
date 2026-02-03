#include <iostream>

int main() {
  
  int grade1;
  std::cout << "Enter your first grade: ";
  std::cin >> grade1;

  int grade2;
  std::cout << "Enter your second grade: ";
  std::cin >> grade2;

  int grade3;
  std::cout << "Enter your third grade: ";
  std::cin >> grade3;

  int grade4;
  std::cout << "Enter your fourth grade: ";
  std::cin >> grade4;

  std::string year;
  std::cout << "Are you in [e]lementary, [m]iddle or [h]igh school? ";
  std::cin >> year;

  float average = (grade1 + grade2 + grade3 + grade4) / 4;

  int count = 0;

  if (grade1 >= 50) {
    std::cout << "\nYou passed the first class.\n";
    count += 1;
  } else {
    std::cout << "\nYou failed the first class.\n";
  }

  if (grade2 >= 50) {
    std::cout << "You passed the second class.\n";
    count += 1;
  } else {
    std::cout << "You failed the second class.\n";
  }

  if (grade3 >= 50) {
    std::cout << "You passed the third class.\n";
    count += 1;
  } else {
    std::cout << "You failed the third class.\n";
  }

  if (grade4 >= 50) {
    std::cout << "You passed the fourth class.\n";
    count += 1;
  } else {
    std::cout << "You failed the fourth class.\n";
  }

  std::cout << "\nYou passed " << count << " out of 4 classes.\n";
  std::cout << "Your average was " << average << ".\n\n";

  if (year == "e") {
    std::cout << "Since you are in elemenetary school, you need an average of 50 to continue.\n";
    if (average >= 50) {
      std::cout << "You were successful!\n";
    } else {
      std::cout << "You were not successful.\n";
    }
  }

  if (year == "m") {
    std::cout << "Since you are in middle school, you need an average of 60 to continue.\n";
    if (average >= 60) {
      std::cout << "You were successful!\n";
    } else {
      std::cout << "You were not successful.\n";
    }
  }

  if (year == "h") {
    std::cout << "Since you are in high school, you need an average of 70 to continue.\n";
    if (average >= 70) {
      std::cout << "You were successful!\n";
    } else {
      std::cout << "You were not successful.\n";
    }
  }

}
