#include <iostream>

std::string get_word () {
  std::string words [] = {"accept", "action", "artist", "broken", "battle", "border", "camera", "coffee", "church", "doctor", "double", "device", "empire", "energy", "engine", "family", "finger", "future", "guilty", "global", "garden", "health", "honest", "hidden", "import", "island", "income", "junior", "letter", "lights", "minute", "memory", "normal", "number", "online", "orange", "people", "public", "random","rescue", "school", "sister", "talent", "travel", "unique", "update", "volume", "window", "winter", "yellow"};
  srand (time (0));
  return words [rand() % 50];
}

std::string print (char board []) {
  return std::string(1, board[0]) + " " + std::string(1, board[1]) + " " + std::string(1, board[2]) + " " + std::string(1, board[3]) + " " + std::string(1, board[4]) + " " + std::string(1, board[5]);
}

void hair () {
  std::cout << "\n  \\ | /";
}

void head () {
  std::cout << "\n -------\n";
  std::cout << " | o o |\n";
  std::cout << " | --- |\n";
  std::cout << " -------\n";
}

void arms () {
  std::cout << "    |\n";
  std::cout << " ---|---\n";

}

void legs () {
  std::cout << "    |\n";
  std::cout << "    |\n";
  std::cout << "   /\\\n";
  std::cout << "  /  \\\n";
}

void feet () {
  std::cout << "--    --\n";
}

void hang_man (int lives) {
  if (lives < 1) {
    hair ();
  }
  if (lives < 5) {
    head ();
  }
  if (lives < 4) {
    arms ();
  }
  if (lives < 3) {
    legs ();
  }
  if (lives < 2) {
    feet ();
  }
}

bool correct_letter (char letter, std::string word) {
  for (int i = 0; i < 6; i++) {
    if (word.at (i) == letter) {
      return true;
    }
  }
  return false;
}

void update (char board [], char letter, std::string word) {
  for (int i = 0; i < 6; i++) {
    if (word.at(i) == letter) {
      board[i] = letter;
    }
  }
}

bool already_guessed (char prev [], char letter) {
  for (int i = 0; i < 26; i++) {
    if (prev [i] == letter) {
      return true;
    }
  }
  return false;
}

bool won (char board []) {
  for (int i = 0; i < 6; i++) {
    if (board[i] == '_') {
      return false;
    }
  }
  return true;
}

std::string get_prev (char prev [], int guess_count) {
  std::string result;
  for (int i = 0; i < guess_count; i++) {
    result = result + std::string (1, prev[i]) + " ";
  }
  return result;
}

int main() {
  
  std::string word = get_word();
  char board [] = {'_', '_', '_', '_', '_', '_'};
  char prev [26];
  int guess_count = 0;
  int lives = 5;

  while (lives > 0 && not won (board)) {
    hang_man (lives);
    std::cout << "\n" << print (board) << "\n\n";

    std::cout << "\nPreviously guessed letters: " << get_prev (prev, guess_count) << "\n";
    std::cout << "Number of lives: " << lives << "\n\n";

    char letter = '-';
    while (letter == '-' || already_guessed(prev, letter)) {
      std::cout << "Guess a letter: ";
      std::cin >> letter;
    }

    prev [guess_count] = letter;
    guess_count += 1;
  
    if (not correct_letter (letter, word)) {
      lives -= 1;
    } else {
      update (board, letter, word);
    }
  }

  if (lives == 0) {
    hang_man (lives);
    std::cout << "\nYou failed! The word was '" << word << "'.\n";
  } else {
    std::cout << "\n" << print (board) << "\n\n";
    std::cout << "You got it!\n";
  }
  
}
