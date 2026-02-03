#include <iostream>
#include <vector>
#include <stdexcept>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

std::vector<std::vector<char>> maze = {{'S', '#', '#', '#', '#'}, {'.', '.', '.', '.', '#'}, {'#', '#', '#', '.', '#'}, {'#', '.', '.', '.', '.'}, {'#', '#', '#', '#', 'E'}};

int x = 0;
int y = 0;

char direction;

void print_maze () {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == y && j == x) {
        std::cout << "\033[1;31m" << maze[i][j] << "\033[0m ";
      } else {
        std::cout << maze[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}

void move () {
  std::cout << "\nWhich direction? (U, D, L, R) ";
  std::cin >> direction;

  if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R') {
    throw std::runtime_error ("Invalid direction.");
  }

  int temp_x = x;
  int temp_y = y;

  if (direction == 'U') {
    temp_y -= 1;
  } else if (direction == 'D') {
    temp_y += 1;
  } else if (direction == 'L') {
    temp_x -= 1;
  } else if (direction == 'R') {
    temp_x += 1;
  }

  if (temp_x > 4 || temp_x < 0 || temp_y > 4 || temp_y < 0) {
    throw std::runtime_error ("Out of bounds.");
  }

  else if (maze [temp_y][temp_x] == '#') {
    throw std::runtime_error ("Hit a wall.");
  }

  x = temp_x;
  y = temp_y;
}

int main() {

  erase (0);

  while (true) {
    print_maze ();

    if (x == 4 && y == 4) {
      std::cout << "\nYou win! \n";
      break;
    }

    try {
      move ();
    }

    catch (const std::runtime_error& e) {
      std::cout << "\nError: " << e.what() << "\n";
    }

    erase (3000000);
  }

}
