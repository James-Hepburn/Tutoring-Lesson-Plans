#include <iostream>
#include <unistd.h>

void erase_and_wait (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

char random_number () {
  std::string str = "0123456789";
  return str.at(rand() % 10);
}

int main() {

  srand(0);
  
  std::cout << "\nWelcome to the pattern guesser!\n";
  std::cout << "\nEvery round, a number will be added to the pattern. You must enter the pattern correctly to move on to the next round.\n";

  std::string ready;
  while (ready != "yes") {
    std::cout << "Ready? (yes/no) ";
    std::cin >> ready;
  }

  erase_and_wait(3000000); 

  int round = 1;
  std::string pattern;
  while (true) {
    std::cout << "\nRound # " << round << ":\n";
    round += 1;
    pattern += random_number();
    std::cout << "The pattern is ... " << pattern << "\n";
    std::cout << "Memorize this! You have 5 seconds!\n";
    erase_and_wait(5000000);
    std::string answer;
    std::cout << "What was the pattern? ";
    std::cin >> answer;
    if (answer == pattern) {
      std::cout << "Correct! The next round begins in 3 seconds.\n";
    } else {
      std::cout << "Incorrect! You survived " << (round - 1) << " rounds.\n";
      break;
    }
    erase_and_wait(3000000);
  }
  
}
