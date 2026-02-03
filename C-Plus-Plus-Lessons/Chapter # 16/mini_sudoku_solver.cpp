#include <iostream>
#include <set>  

bool valid (std::set <int> s) {
  return s.size() == 4 && s.count (1) == 1 && s.count (2) == 1 && s.count (3) == 1 && s.count (4) == 1; 
}

int main() {

  std::cout << "\nEnter the 4x4 board row by row:\n";

  int r1c1, r1c2, r1c3, r1c4;
  std::cout << "\nRow # 1: ";
  std::cin >> r1c1 >> r1c2 >> r1c3 >> r1c4;

  int r2c1, r2c2, r2c3, r2c4;
  std::cout << "\nRow # 2: ";
  std::cin >> r2c1 >> r2c2 >> r2c3 >> r2c4;

  int r3c1, r3c2, r3c3, r3c4;
  std::cout << "\nRow # 3: ";
  std::cin >> r3c1 >> r3c2 >> r3c3 >> r3c4;

  int r4c1, r4c2, r4c3, r4c4;
  std::cout << "\nRow # 4: ";
  std::cin >> r4c1 >> r4c2 >> r4c3 >> r4c4;

  std::set <int> row1 = {r1c1, r1c2, r1c3, r1c4};
  std::set <int> row2 = {r2c1, r2c2, r2c3, r2c4};
  std::set <int> row3 = {r3c1, r3c2, r3c3, r3c4};
  std::set <int> row4 = {r4c1, r4c2, r4c3, r4c4};

  std::set <int> column1 = {r1c1, r2c1, r3c1, r4c1};
  std::set <int> column2 = {r1c2, r2c2, r3c2, r4c2};
  std::set <int> column3 = {r1c3, r2c3, r3c3, r4c3};
  std::set <int> column4 = {r1c4, r2c4, r3c4, r4c4};

  std::set <int> quadrant1 = {r1c1, r1c2, r2c1, r2c2};
  std::set <int> quadrant2 = {r1c3, r1c4, r2c3, r2c4};
  std::set <int> quadrant3 = {r3c1, r3c2, r4c1, r4c2};
  std::set <int> quadrant4 = {r3c3, r3c4, r4c3, r4c4};

  if (valid (row1) && valid (row2) && valid (row3) && valid (row4) && valid (column1) && valid (column2) && valid (column3) && valid (column4) && valid (quadrant1) && valid (quadrant2) && valid (quadrant3) && valid (quadrant4)) {
    std::cout << "\nSolved correctly!\n";
  } else {
    std::cout << "\nSolved incorrectly.\n";
  }
  
}
