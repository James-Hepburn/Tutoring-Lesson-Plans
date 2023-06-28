#include <iostream>
#include <vector>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

void print_board (std::vector <std::vector <std::string>> board) {
  std::cout << "\n  1   2   3   4   5   6   7\n";
  std::cout << "-----------------------------\n";
  for (int i = 0; i < 6; i++) {
    std::cout << "| ";
    for (int j = 0; j < 7; j++) {
      std::cout << board[i][j] << " | ";
    }
    std::cout << "\n-----------------------------\n";
  }
  std::cout << "\n";
}

int get_input (std::vector <std::string> row1) {
  while (true) {
    int column;
    std::cout << "Enter the column: ";
    std::cin >> column;
    if (column <= 7 && column >= 1 && row1[column-1] == " ") {
      return column;
    } else {
      std::cout << "Invalid input, try again.\n";
    }
  } 
}

int get_index (std::vector <std::vector <std::string>> board, int column) {
  for (int i = 5; i >= 0; i--) {
    if (board[i][column-1] == " ") {
      return i;
    }
  }
}

int computer_move (std::vector <std::string> row1) {
  srand (time (0));
  while (true) {
    int column = rand() % 7;
    if (row1[column] == " ") {
      return column;
    }
  }
}

bool vertical (std::vector <std::vector <std::string>> board, std::string piece) {
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 3; i++) {
      if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j] && board[i+3][j] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool horizontal (std::vector <std::vector <std::string>> board, std::string piece) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j+3] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool bottom_to_top (std::vector <std::vector <std::string>> board, std::string piece) {
  for (int i = 3; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3] && board[i-3][j+3] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool top_to_bottom (std::vector <std::vector <std::string>> board, std::string piece) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] && board[i+3][j+3] == piece) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  
  std::vector <std::vector <std::string>> board = {
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
  };

  while (true) {

    print_board (board);
    if (horizontal (board, "o") || vertical (board, "o") || bottom_to_top (board, "o") || top_to_bottom (board, "o")) {
      std::cout << "The computer wins!\n";
      break;
    }
    
    int column = get_input (board[0]);
    int row = get_index(board, column);
    board[row][column-1] = "x";
    erase (3000000);

    print_board (board);
    if (horizontal (board, "x") || vertical (board, "x") || bottom_to_top (board, "x") || top_to_bottom (board, "x")) {
      std::cout << "You win!\n";
      break;
    }
    
    int col = computer_move(board[0]);
    int r = get_index(board, col + 1);
    board[r][col] = "o";
    std::cout << "The computer chose column # " << col + 1<< "\n";
    erase (3000000);
    
  }
  
}
