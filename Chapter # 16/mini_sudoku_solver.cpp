#include <ctype.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<int> get_row(std::string line) {
  std::vector<int> row;
  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      row.push_back(line[i] - '0');
    }
  }
  return row;
}

std::vector<std::vector<int>> get_board() {
  std::vector<std::vector<int>> board;
  std::cout << "\nEnter the 4x4 board row by row: \n";
  for (int i = 1; i <= 4; i++) {
    std::string line;
    std::cout << "\nRow # " << i << ": ";
    std::getline(std::cin, line);
    board.push_back(get_row(line));
  }
  return board;
}

bool check_rows(std::vector<std::vector<int>> board) {
  for (int i = 0; i < 4; i++) {
    std::set<int> row_set;
    for (int j = 0; j < 4; j++) {
      int num = board[i][j];
      if (num < 1 || num > 4 || row_set.count(num) > 0) {
        return false;
      }
      row_set.insert(num);
    }
  }
  return true;
}

bool check_columns(std::vector<std::vector<int>> board) {
  for (int i = 0; i < 4; i++) {
    std::set<int> column_set;
    for (int j = 0; j < 4; j++) {
      int num = board[j][i];
      if (num < 1 || num > 4 || column_set.count(num) > 0) {
        return false;
      }
      column_set.insert(num);
    }
  }
  return true;
}

bool check_quadrant1(std::vector<std::vector<int>> board) {
  for (int i = 0; i < 2; i++) {
    std::set<int> quadrant_set;
    for (int j = 0; j < 2; j++) {
      int num = board[i][j];
      if (num < 1 || num > 4 || quadrant_set.count(num) > 0) {
        return false;
      }
      quadrant_set.insert(num);
    }
  }
  return true;
}

bool check_quadrant2(std::vector<std::vector<int>> board) {
  for (int i = 0; i < 2; i++) {
    std::set<int> quadrant_set;
    for (int j = 2; j < 4; j++) {
      int num = board[i][j];
      if (num < 1 || num > 4 || quadrant_set.count(num) > 0) {
        return false;
      }
      quadrant_set.insert(num);
    }
  }
  return true;
}

bool check_quadrant3(std::vector<std::vector<int>> board) {
  for (int i = 2; i < 4; i++) {
    std::set<int> quadrant_set;
    for (int j = 0; j < 2; j++) {
      int num = board[i][j];
      if (num < 1 || num > 4 || quadrant_set.count(num) > 0) {
        return false;
      }
      quadrant_set.insert(num);
    }
  }
  return true;
}

bool check_quadrant4(std::vector<std::vector<int>> board) {
  for (int i = 2; i < 4; i++) {
    std::set<int> quadrant_set;
    for (int j = 2; j < 4; j++) {
      int num = board[i][j];
      if (num < 1 || num > 4 || quadrant_set.count(num) > 0) {
        return false;
      }
      quadrant_set.insert(num);
    }
  }
  return true;
}

int main() {

  std::vector<std::vector<int>> board = get_board();

  bool a = check_rows(board);
  bool b = check_columns(board);
  bool c = check_quadrant1(board);
  bool d = check_quadrant2(board);
  bool e = check_quadrant3(board);
  bool f = check_quadrant4(board);

  if (a && b && c && d && e && f) {
    std::cout << "\nSolved correctly! \n";
  } else {
    std::cout << "\nSolved incorrectly. \n";
  }
}
