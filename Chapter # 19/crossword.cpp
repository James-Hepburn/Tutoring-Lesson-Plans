#include <iostream>
#include <vector>
#include <stdexcept>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

std::vector <std::vector <std::string>> board = {{"⬛", "🟥", "⬛", "⬛", "🟦", "⬛", "⬛", "⬛", "⬛", "⬛"}, {"⬛", "⬜", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬛", "⬛"}, {"🟩", "⬜", "⬜", "⬜", "⬜", "⬜", "⬜", "⬜", "🟨", "⬜"}, {"⬛", "⬜", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬜", "⬛"}, {"⬛", "⬜", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬜", "⬛"}, {"⬛", "⬛", "⬛", "⬛", "🟪", "⬜", "⬜", "⬜", "⬜", "⬜"}, {"🟧", "⬜", "⬜", "⬜", "⬜", "⬛", "⬛", "⬛", "⬜", "⬛"}, {"⬛", "⬛", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬜", "⬛"}, {"⬛", "⬛", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬛", "⬛"}, {"⬛", "⬛", "⬛", "⬛", "⬜", "⬛", "⬛", "⬛", "⬛", "⬛"}};

std::string direction;
std::string colour;
std::string word;
int words_found = 0;

std::string red = "???";
std::string blue = "???";
std::string green = "???";
std::string purple = "???";
std::string yellow = "???";
std::string orange = "???";

void print_board () {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << board[i][j];
    }
    std::cout << "\n";
  }

  std::cout << "\nAcross: \n";
  std::cout << "🟩 A big fruit you eat in the summer = " << green << "\n";
  std::cout << "🟪 Fruit that monkeys like = " << purple << "\n";
  std::cout << "🟧 A red fruit = " << orange << "\n";

  std::cout << "\nDown: \n";
  std::cout << "🟥 Purple fruit = " << red << "\n";
  std::cout << "🟦 A small red fruit = " << blue << " \n";
  std::cout << "🟨 ______ juice = " << yellow << " \n";
}

void valid_input () {
  std::cout << "\nWhich direction? ";
  std::cin >> direction;
  if (direction != "across" && direction != "down") {
    throw std::runtime_error ("Invalid direction.");
  }

  std::cout << "Which colour? ";
  std::cin >> colour;
  if (direction == "across" && colour != "green" && colour != "purple" && colour != "orange") {
    throw std::runtime_error ("Invalid colour.");
  } else if (direction == "down" && colour != "red" && colour != "blue" && colour != "yellow") {
    throw std::runtime_error ("Invalid colour.");
  } 

  std::cout << "Which word? ";
  std::cin >> word;
  if (colour == "red" && word == "grape") {
    words_found += 1;
    red = word;
    board[0][1] = "🟥";
    board[1][1] = "🟥";
    board[2][1] = "🟥";
    board[3][1] = "🟥";
    board[4][1] = "🟥";
  } else if (colour == "blue" && word == "strawberry") {
    words_found += 1;
    blue = word;
    board[0][4] = "🟦";
    board[1][4] = "🟦";
    board[2][4] = "🟦";
    board[3][4] = "🟦";
    board[4][4] = "🟦";
    if (purple != "???") {
      board[5][4] = "🟦";
    }
    board[6][4] = "🟦";
    board[7][4] = "🟦";
    board[8][4] = "🟦";
    board[9][4] = "🟦";
  } else if (colour == "yellow" && word == "orange") {
    words_found += 1;
    yellow = word;
    board[2][8] = "🟨";
    board[3][8] = "🟨";
    board[4][8] = "🟨";
    board[5][8] = "🟨";
    board[6][8] = "🟨";
    board[7][8] = "🟨";
  } else if (colour == "green" && word == "watermelon") {
    words_found += 1;
    green = word;
    board[2][0] = "🟩";
    board[2][1] = "🟩";
    board[2][2] = "🟩";
    board[2][3] = "🟩";
    board[2][4] = "🟩";
    board[2][5] = "🟩";
    board[2][6] = "🟩";
    board[2][7] = "🟩";
    if (yellow != "???") {
      board[2][8] = "🟩";
    }
    board[2][9] = "🟩";
  } else if (colour == "orange" && word == "apple") {
    words_found += 1;
    orange = word;
    board[6][0] = "🟧";
    board[6][1] = "🟧";
    board[6][2] = "🟧";
    board[6][3] = "🟧";
    board[6][4] = "🟧";
  } else if (colour == "purple" && word == "banana") {
    words_found += 1;
    purple = word;
    board[5][4] = "🟪";
    board[5][5] = "🟪";
    board[5][6] = "🟪";
    board[5][7] = "🟪";
    board[5][8] = "🟪";
    board[5][9] = "🟪";
  } else {
    throw std::runtime_error ("Wrong word.");
  }
}

int main() {

  erase (0);

  while (words_found < 6) {
    print_board ();

    try {
      valid_input ();
    }

    catch (const std::runtime_error& e) {
      std::cout << "\nError: " << e.what() << "\n";
    }

    erase (3000000);
  }

  print_board ();
  
  std::cout << "\nYou win! \n";
  
}
