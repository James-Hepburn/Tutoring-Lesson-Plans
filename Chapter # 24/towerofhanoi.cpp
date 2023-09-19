#include <iostream>
#include <algorithm> 
#include <stack>
#include <queue>

std::stack <int> tower1;
std::stack <int> tower2;
std::stack <int> tower3;

std::queue <std::string> moves;

int current, future, disk;

void print_tower() {
  std::stack<int> t1_copy = tower1;
  std::stack<int> t2_copy = tower2;
  std::stack<int> t3_copy = tower3;
  std::cout << "\nTower 1 | Tower 2 | Tower 3\n";
  int max_height = std::max({t1_copy.size(), t2_copy.size(), t3_copy.size()});
  for (int i = max_height - 1; i >= 0; i--) {
    std::string line = "   ";
    if (!t1_copy.empty() && t1_copy.size() > i) {
      line += std::to_string(t1_copy.top());
      t1_copy.pop();
    } else {
      line += " ";
    }
    line += "    |    ";
    if (!t2_copy.empty() && t2_copy.size() > i) {
      line += std::to_string(t2_copy.top());
      t2_copy.pop();
    } else {
      line += " ";
    }
    line += "    |    ";
    if (!t3_copy.empty() && t3_copy.size() > i) {
      line += std::to_string(t3_copy.top());
      t3_copy.pop();
    } else {
      line += " ";
    }
    std::cout << line << "\n";
  }
}


void move_disk () {
  if (current == 1) {
    disk = tower1.top();
    tower1.pop();
  } else if (current == 2) {
    disk = tower2.top();
    tower2.pop();
  } else if (current == 3) {
    disk = tower3.top();
    tower3.pop();
  }
  if (future == 1) {
    tower1.push (disk);
  } else if (future == 2) {
    tower2.push (disk);
  } else if (future == 3) {
    tower3.push (disk);
  }
}

int main() {

  std::cout << "\nWelcome to the Tower of Hanoi! \n";

  int disks;
  std::cout << "\nEnter the number of disks: ";
  std::cin >> disks;

  for (int i = disks; i >= 1; i--) {
    tower1.push (i);
  }

  while (true) {
    print_tower ();

    if (tower3.size() == disks) {
      std::cout << "\nYou solved it! \n";
      std::cout << "\nHere are your moves: \n\n";
      int order = 1;
      while (!moves.empty()) {
        std::cout << order << " - " << moves.front() << "\n";
        order += 1;
        moves.pop();
      }
      break;
    }
  
    std::cout << "\nEnter the current tower: ";
    std::cin >> current;
  
    std::cout << "Enter the future tower: ";
    std::cin >> future;
  
    move_disk ();
    moves.push ("from " + std::to_string(current) + " to " + std::to_string(future)); 
  }
  
}
