#include <iostream>
#include <unistd.h>

void printBoard (char board []) {
  usleep(3000000); // microseconds
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n" << board [0] << " | " << board [1] << " | " << board [2] << "\n";
  std::cout << "---------\n";
  std::cout << board [3] << " | " << board [4] << " | " << board [5] << "\n";
  std::cout << "---------\n";
  std::cout << board [6] << " | " << board [7] << " | " << board [8] << "\n";
}

bool wonGame (char board [], char turn) {
  if (board[0] ==  turn && board[1] == turn && board[2] == turn) {
    return true;
  } else if (board[3] == turn && board[4] == turn && board[5] == turn) {
    return true;
  } else if (board[6] == turn && board[7] == turn && board[8] == turn) {
    return true;
  } else if (board[0] == turn && board[3] == turn && board[6] == turn) {
    return true;
  } else if (board[1] == turn && board[4] == turn && board[7] == turn) {
    return true;
  } else if (board[2] == turn && board[5] == turn && board[8] == turn) {
    return true;
  } else if (board[0] == turn && board[4] == turn && board[8] == turn) {
    return true;
  } else if (board[2] == turn && board[4] == turn && board[6] == turn) {
    return true;
  } 
  return false;
}

int computerMove (char board []) {
  while (true) {
    srand (time (0));
    int index = rand() % 9;
    if (board[index] != 'X' && board[index] != 'O') {
      board[index] = 'O';
      return index + 1;
    }
  }
  return -1;
}

bool isValid (char board [], int spot) {
  if (spot > 9 || spot < 1) {
    std::cout << "\nInvalid number.\n";
    return false;
  } else if (board[spot - 1] == 'X') {
    std::cout << "\nX is already in that spot.\n";
    return false;
  } else if (board[spot - 1] == 'O') {
    std::cout << "\nO is already in that spot.\n";
    return false;
  }
  return true;
}

bool isTie (char board []) {
  return board [0] != '1' && board [1] != '2' && board [2] != '3' && board [3] != '4' && board [4] != '5' && board [5] != '6' && board [6] != '7' && board [7] != '8' && board [8] != '9';
}
 
int main() {
  
  char board [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  while (true) {

    printBoard (board);

    while (true) {
      int spot;
      std::cout << "\nEnter a spot: ";
      std::cin >> spot;
      if (isValid (board, spot)) {
        board [spot - 1] = 'X';
        break;
      }
    }

    printBoard (board);

    if (wonGame (board, 'X')) {
      std::cout << "\nYou win!\n";
      break;
    } else if (isTie (board)) {
      std::cout << "\nTie!\n";
      break;
    }

    int computer = computerMove (board);

    std::cout << "\nThe computer selected " << computer << "\n";

    printBoard (board);

    if (wonGame (board, 'O')) {
      std::cout << "\nYou lose!\n";
      break;
    } else if (isTie (board)) {
      std::cout << "\nTie!\n";
      break;
    }
    
  }
  
}
