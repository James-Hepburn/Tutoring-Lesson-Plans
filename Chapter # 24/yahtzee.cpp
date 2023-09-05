#include <iostream>
#include <vector>
#include <unistd.h>

std::vector <std::vector <std::string>> board = {
  {"One", "Count and add only ones", "--"},
  {"Two", "Count and add only twos", "--"},
  {"Three", "Count and add only threes", "--"},
  {"Four", "Count and add only fours", "--"},
  {"Five", "Count and add only fives", "--"},
  {"Six", "Count and add only sixes", "--"}
};

int final_score, dice1, dice2, dice3, dice4, dice5, spot;

std::string get_spaces (int amount) {
  std::string spaces = "";
  for (int i = 0; i < amount; i++) {
    spaces += " ";
  }
  return spaces;
}

void print_board () {
  for (int i = 0; i < board.size(); i++) {
    std::cout << "\n------------------------------------------------\n";
    int length1 = 11 - board[i][0].length();
    int length2 = 25 - board[i][1].length();
    int length3 = 2 - board[i][2].length();
    std::cout << "| " << board[i][0] << get_spaces (length1) << " | "<< board[i][1] << get_spaces (length2) << " | " << board[i][2] << get_spaces (length3) << " | ";
  }
  std::cout << "\n------------------------------------------------\n";
  std::cout << "\nFinal Score: " << final_score << "\n\n";
}

void roll_dice () {
  dice1 = 1 + rand() % 6;
  dice2 = 1 + rand() % 6;
  dice3 = 1 + rand() % 6;
  dice4 = 1 + rand() % 6;
  dice5 = 1 + rand() % 6;
  std::cout << "Your turn! You rolled " << dice1 << " " << dice2 << " " << dice3 << " " << dice4 << " " << dice5 << "\n";
}

int check_score (int value) {
  int score = 0;
  if (dice1 == value) {
    score += 1;
  }
  if (dice2 == value) {
    score += 1;
  }
  if (dice3 == value) {
    score += 1;
  }
  if (dice4 == value) {
    score += 1;
  }
  if (dice5 == value) {
    score += 1;
  }
  return score * value;
}

bool update_board () {
  std::cout << "\nWhich spot are you adding your score to? ";
  std::cin >> spot;

  if (spot > 6 || spot < 1) {
    return false;
  }

  final_score += check_score (spot);
  board [spot - 1][2] = std::to_string (check_score (spot));
  return true;
}

void wait_and_erase (int seconds) {
  usleep (seconds * 1000000); 
  std::cout << "\033[2J\033[1;1H";
}

int main() {

  srand (time (0));

  for (int i = 0; i < 6; i++) {
    wait_and_erase (3);
    print_board ();
    roll_dice ();

    while (update_board () == false) {
      std::cout << "Invalid. Try again. \n";
    }
  }

  wait_and_erase (3);
  print_board ();
  
}
