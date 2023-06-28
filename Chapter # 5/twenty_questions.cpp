#include <iostream>

int main() {

  std::string object;
  std::cout << "\nPlayer 1, enter an object: ";
  std::cin >> object;

  int questions_asked = 1;
  while (questions_asked <= 20) {
    std::string question;
    std::cout << "\nPlayer 2, enter question # " << questions_asked << ": ";
    getline (std::cin,question);
    getline (std::cin,question);

    std::string answer;
    std::cout << "Player 1, enter 'yes' or 'no': ";
    std::cin >> answer;

    std::cout << question << " = " << answer << "\n";

    std::string guess;
    std::cout << "Player 2, enter your guess: ";
    std::cin >> guess;
    if (guess == object) {
      std::cout << "Player 2 guessed the object correctly!\n";
      break;
    } else {
      std::cout << "Player 2 did not guess the object correctly.\n";
    }

    questions_asked += 1;
    if (questions_asked == 21) {
      std::cout << "Player 2 lost!\n";
      std::cout << "The object was " << object << "\n";
    }
  }
  
}
