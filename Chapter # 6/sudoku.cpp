#include <iostream>
#include <unistd.h>

bool rowIsCorrect (char row [], char answer []) {
  for (int i = 0; i < 9; i++) {
    if (row[i] != answer[i]) {
      return false;
    }
  }
  return true;
}

void printRow (char row [], bool addLine) {
  for (int i = 0; i < 9; i++) {
    if (i == 2 || i == 5) {
      std::cout << row[i] << " | ";
    } else {
      std::cout << row[i] << " ";
    }
  }
  if (addLine) {
    std::cout << "\n---------------------\n";
  } else {
    std::cout << "\n";
  }
}

bool isValid (int row, int column, int number) {
  if (row < 1 || row > 9) {
    std::cout << "\nInvalid row.\n";
    return false;
  } else if (column < 1 || column > 9) {
    std::cout << "\nInvalid column.\n";
    return false;
  } else if (number < 1 || number > 9) {
    std::cout << "\nInvalid number.\n";
    return false;
  } else if (row == 1) {
    if (column == 2 || column == 3 || column == 6) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 2) {
    if (column == 1 || column == 2 || column == 4 || column == 9) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 3) {
    if (column == 2 || column == 3 || column == 4 || column == 6 || column == 7 || column == 8) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 4) {
    if (column == 1 || column == 7) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 5) {
    if (column == 2 || column == 3 || column == 4 || column == 6 || column == 7 || column == 8) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 6) {
    if (column == 3 || column == 9) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 7) {
    if (column == 2 || column == 3 || column == 4 || column == 6 || column == 7 || column == 8) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 8) {
    if (column == 1 || column == 6 || column == 8 || column == 9) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  } else if (row == 9) {
    if (column == 4 || column == 7 || column == 8) {
      std::cout << "\nInvalid selection, this spot cannot be changed.\n";
      return false;
    }
  }
  return true;
}

char intToChar (int x) {
  if (x == 1) {
    return '1';
  } else if (x == 2) {
    return '2';
  } else if (x == 3) {
    return '3';
  } else if (x == 4) {
    return '4';
  } else if (x == 5) {
    return '5';
  } else if (x == 6) {
    return '6';
  } else if (x == 7) {
    return '7';
  } else if (x == 8) {
    return '8';
  } else {
    return '9';
  }
}

int main() {
  
  char row1 [] = {' ', '5', '2', ' ', ' ', '6', ' ', ' ', ' '};
  char row2 [] = {'1', '6', ' ', '9', ' ', ' ', ' ', ' ', '4'};
  char row3 [] = {' ', '4', '9', '8', ' ', '3', '6', '2', ' '};
  char row4 [] = {'4', ' ', ' ', ' ', ' ', ' ', '8', ' ', ' '};
  char row5 [] = {' ', '8', '3', '2', ' ', '1', '5', '9', ' '};
  char row6 [] = {' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '2'};
  char row7 [] = {' ', '9', '7', '3', ' ', '5', '2', '4', ' '};
  char row8 [] = {'2', ' ', ' ', ' ', ' ', '9', ' ', '5', '6'};
  char row9 [] = {' ', ' ', ' ', '1', ' ', ' ', '9', '7', ' '};

  char answer1 [] = {'3', '5', '2', '4', '7', '6', '1', '8', '9'};
  char answer2 [] = {'1', '6', '8', '9', '5', '2', '7', '3', '4'};
  char answer3 [] = {'7', '4', '9', '8', '1', '3', '6', '2', '5'};
  char answer4 [] = {'4', '2', '5', '6', '9', '7', '8', '1', '3'};
  char answer5 [] = {'6', '8', '3', '2', '4', '1', '5', '9', '7'};
  char answer6 [] = {'9', '7', '1', '5', '3', '8', '4', '6', '2'};
  char answer7 [] = {'8', '9', '7', '3', '6', '5', '2', '4', '1'};
  char answer8 [] = {'2', '1', '4', '7', '8', '9', '3', '5', '6'};
  char answer9 [] = {'5', '3', '6', '1', '2', '4', '9', '7', '8'};

  while (true) {

    // prints board
    printRow (row1, false);
    printRow (row2, false);
    printRow (row3, true);
    printRow (row4, false);
    printRow (row5, false);
    printRow (row6, true);
    printRow (row7, false);
    printRow (row8, false);
    printRow (row9, false);
  
    std::string quit;
    std::cout << "\nEnter 'yes' to quit or anything else to continue: ";
    std::cin >> quit;
  
    if (quit == "yes") {
      if (rowIsCorrect(row1, answer1) && rowIsCorrect(row2, answer2) && rowIsCorrect(row3, answer3) && rowIsCorrect(row4, answer4) && rowIsCorrect(row5, answer5) && rowIsCorrect(row6, answer6) && rowIsCorrect(row7, answer7) && rowIsCorrect(row8, answer8) && rowIsCorrect(row9, answer9)) {
        std::cout << "\nYou got it all correct!\n";
        break;
      } else {
        std::cout << "\nIncorrect, here is the solution: \n\n";
        printRow (answer1, false);
        printRow (answer2, false);
        printRow (answer3, true);
        printRow (answer4, false);
        printRow (answer5, false);
        printRow (answer6, true);
        printRow (answer7, false);
        printRow (answer8, false);
        printRow (answer9, false);
        break;
      }
    }
  
    int row;
    std::cout << "\nEnter a row: ";
    std::cin >> row;
  
    int column;
    std::cout << "Enter a column: ";
    std::cin >> column;
  
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
  
    if (isValid (row, column, number)) {
      //update board
      if (row == 1) {
        row1[column - 1] = intToChar (number);
      } else if (row == 2) {
        row2[column - 1] = intToChar (number);
      } else if (row == 3) {
        row3[column - 1] = intToChar (number);
      } else if (row == 4) {
        row4[column - 1] = intToChar (number);
      } else if (row == 5) {
        row5[column - 1] = intToChar (number);
      } else if (row == 6) {
        row6[column - 1] = intToChar (number);
      } else if (row == 7) {
        row7[column - 1] = intToChar (number);
      } else if (row == 8) {
        row8[column - 1] = intToChar (number);
      } else {
        row9[column - 1] = intToChar (number);
      } 
    } 
  
    usleep(3000000); // microseconds
    std::cout << "\033[2J\033[1;1H";
  }
  
}
