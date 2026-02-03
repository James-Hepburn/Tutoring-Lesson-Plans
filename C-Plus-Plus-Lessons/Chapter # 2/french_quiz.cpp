#include <iostream>

int main() {

  int score = 0;

  std::cout << "\n\nQuestion # 1:\n";
  std::string q1;
  std::cout << "What is 'bleu' in English? ";
  std::cin >> q1;
  if (q1 == "blue") {
    score += 1;
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect. The answer was 'blue'.\n";
  }

  std::cout << "\n\nQuestion # 2:\n";
  std::string q2;
  std::cout << "What is 'blanc' in English? ";
  std::cin >> q2;
  if (q2 == "white") {
    score += 1;
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect. The answer was 'white'.\n";
  }

  std::cout << "\n\nQuestion # 3:\n";
  std::string q3;
  std::cout << "What is 'rouge' in English? ";
  std::cin >> q3;
  if (q3 == "red") {
    score += 1;
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect. The answer was 'red'.\n";
  }

  std::cout << "\n\nQuestion # 4:\n";
  std::string q4;
  std::cout << "What is 'jaune' in English? ";
  std::cin >> q4;
  if (q4 == "yellow") {
    score += 1;
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect. The answer was 'yellow'.\n";
  }

  std::cout << "\n\nQuestion # 5:\n";
  std::string q5;
  std::cout << "What is 'vert' in English? ";
  std::cin >> q5;
  if (q5 == "green") {
    score += 1;
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect. The answer was 'green'.\n";
  }
  
  std::cout << "\n\nGood job! You got " << score << " out of 5 correct!\n";
  
}
