#include <iostream>
#include <vector>
#include <unistd.h>

void print_board (std::vector <std::vector <char>> board) {
  std::cout <<"\n    1   2   3   4   5   6   7   8\n";
  std::cout <<"  ---------------------------------\n";
  for (int i = 0; i < 8; i++) {
    std::cout << (i+1) << " | ";
    for (int j = 0; j < 8; j++) {
      std::cout << board[i][j] << " | ";
    }
    std::cout <<"\n  ---------------------------------\n";
  }
}

bool valid_boat (std::vector <std::vector <int>> boats, int x, int y) {
  for (int i = 0; i < boats.size(); i++) {
    if (boats[i][0] == x && boats[i][1] == y) {
      return false;
    }
  }
  return true;
}

std::vector <std::vector <int>> get_boats () {
  std::vector <std::vector <int>> boats;
  while (boats.size() < 5) {
    int x = (rand() % 8) + 1;
    int y = (rand() % 8) + 1;
    while (valid_boat (boats, x, y) == false) {
      int x = (rand() % 8) + 1;
      int y = (rand() % 8) + 1;
    }
    std::vector <int> new_boat = {x, y};
    boats.push_back(new_boat);
  }
  return boats;
}

bool invalid_input (int row, int column, std::vector <std::vector <char>> board) {
  return row < 1 || row > 8 || column < 1 || column > 8 || board[row-1][column-1] != '~';
}

bool hit_boat (int row, int column, std::vector <std::vector <int>> boats) {
  for (int i = 0; i < 5; i++) {
    if (boats[i][0] == row && boats[i][1] == column) {
      return true;
    }
  }
  return false;
}

int main() {
  
  std::vector <std::vector <char>> board = {
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}, 
  {'~', '~', '~', '~', '~', '~', '~', '~'}
  };

  std::vector <std::vector <int>> boats = get_boats();

  int counter = 0;

  while (counter < 5) {
    print_board (board);
    
    int row;
    std::cout << "\nrow: ";
    std::cin >> row;
  
    int column;
    std::cout << "column: ";
    std::cin >> column;
  
    if (invalid_input (row, column, board)) {
      std::cout << "\nInvalid input.\n";
    } else {
      if (hit_boat (row, column, boats)) {
        board[row-1][column-1] = 'B';
        counter += 1;
      } else {
        board[row-1][column-1] = 'X';
      }
    }
  
    usleep(3000000); // microseconds
    std::cout << "\033[2J\033[1;1H";
  }
  
}
