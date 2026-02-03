#include <iostream>

int main() {
  
  std::cout << "Can you beat the computer?\n";

  int number;
  std::cout << "\nEnter a number from 1 to 100: ";
  std::cin >> number;

  std::cout << "\nThe computer has 10 chances to guess your number. After each guess, answer either 'higher', 'lower' or 'correct'.\n";

  int low = 1;
  int high = 100;

  for (int i = 1; i <= 10; i++) {
    std::cout << "\nRound # " << i << ":\n";
    srand(time (0));
    int guess = low + (rand() % (high - low + 1));
    std::cout << "The computer guesses " << guess << ".\n";
    std::string answer;
    std::cout << "Your answer: ";
    std::cin >> answer;
    if (answer == "higher" && guess < number) {
      if (i == 10) {
        std::cout << "The computer ran out of chances, you win!\n";
      } else {
        std::cout << "The computer has " << (10 - i) << " more chances left.\n";
        low = guess + 1;
      }
    } else if (answer == "lower" && guess > number) {
      if (i == 10) {
        std::cout << "The computer ran out of chances, you win!\n";
      } else {
        std::cout << "The computer has " << (10 - i) << " more chances left.\n";
        high = guess - 1;
      }
    } else if (answer == "correct" && guess == number) {
      std::cout << "The computer wins!\n";
      break;
    }  else {
      std::cout << "You entered something invalid, the computer wins.\n";
      break;
    }
  }
  
}
