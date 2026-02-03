#include <iostream>
#include <vector>
#include <unistd.h>

bool invalid_number (std::string number, std::vector <std::string> column) {
  for (int i = 0; i < column.size(); i++) {
    if (number == column[i]) {
      return true;
    }
  }
  return false;
}

std::string generate_char (int low, int high) {
  int num = low + (rand() % (high - low + 1));
  return std::to_string (num);
}

std::vector <std::string> generate_column (int low, int high) {
  std::vector <std::string> column;
  while (column.size() < 5) {
    while (true) {
      std::string c = generate_char (low, high);
      if (invalid_number (c, column) == false) {
        column.push_back(c);
        break;
      }
    }
  }
  return column;
}

int generate_number () {
  return (rand() % 75) + 1;
}

void print_board (std::vector <std::vector <std::string>> board) {
  std::cout << "\nB   I   N   G   O\n";
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[j][i].length() == 2) {
        std::cout << board[j][i] << "  ";
      } else {
        std::cout << board[j][i] << "   ";
      }
    }
    std::cout << "\n";
  }
}

std::string display_number (int number) {
  if (number < 16) {
    return "B " + std::to_string(number);
  } else if (number < 31) {
    return "I " + std::to_string(number);
  } else if (number < 46) {
    return "N " + std::to_string(number);
  } else if (number < 61) {
    return "G " + std::to_string(number);
  } else {
    return "O " + std::to_string(number);
  }
}

std::vector <std::vector <std::string>> cross_off (int number, std::vector <std::vector <std::string>> board) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == std::to_string (number)) {
        board[i][j] = "X";
      }
    }
  }
  return board;
}

bool check_win (std::vector <std::vector <std::string>> board) {
  // columns
  for (int i = 0; i < 5; i++) {
    if (board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X" && board[i][3] == "X" && board[i][4] == "X") {
      return true;
    }
  }
  // rows
  for (int i = 0; i < 5; i++) {
    if (board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X" && board[3][i] == "X" && board[4][i] == "X") {
      return true;
    }
  }
  // diagonals
  if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X" && board[3][3] == "X" && board[4][4] == "X") {
    return true;
  } else if (board[0][4] == "X" && board[1][3] == "X" && board[2][2] == "X" && board[3][1] == "X" && board[4][0] == "X") {
    return true;
  }
  return false;
}

int main() {

  srand (time (0));
  
  std::vector <std::string> B = generate_column(1, 15);
  std::vector <std::string> I = generate_column(16, 30);
  std::vector <std::string> N = generate_column(31, 45);
  N [2] = "X";
  std::vector <std::string> G = generate_column(46, 60);
  std::vector <std::string> O = generate_column(61, 75);
  std::vector <std::vector <std::string>> board = {B, I, N, G, O};

  for (int i = 0; i < 101; i++) {
    print_board (board);
    if (check_win(board)) {
      std::cout << "\nBINGO!\n";
      break;
    } else if (i == 100) {
      std::cout << "\nGAME OVER!\n";
      break;
    }
    int number = generate_number();
    std::string call = display_number (number);
    std::cout << "\nCalled Number = " << call << "\n";
    board = cross_off (number, board);
    usleep(3000000); // microseconds
    std::cout << "\033[2J\033[1;1H";
  }
  
}
