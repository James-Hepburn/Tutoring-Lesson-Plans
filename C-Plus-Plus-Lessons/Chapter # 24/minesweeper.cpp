#include <iostream>

class node {
  public:
    char value;
    bool hit;
    node* next;

  node (char v) {
    value = v;
    hit = false;
    next = NULL;
  }
};

class linked_list {
  public:
    node* head;

    linked_list () {
      head = NULL;
    }

    void add_node (char value) {
      node* new_node = new node (value);
      if (head == NULL) {
        head = new_node;
      } else {
        node* current = head;
        while (current->next != NULL) {
          current = current->next;
        }
        current->next = new_node;
      }
    }

    void show_list (int row) {
      if (row == 1) {
        std::cout << "\n    1  2  3  4  5 \n";
        std::cout << "  ----------------\n";
      }
      std::cout << row << " | ";
      node* current = head;
      while (current != NULL) {
        if (current->hit == false) {
          std::cout << "🟩 ";
        } else {
          std::cout << current->value << "  ";
        }
        current = current->next;
      }
      std::cout << "\n";
    }

};

void print_board (linked_list board []) {
  for (int i = 0; i < 5; i++) {
    board[i].show_list(i + 1);
  }
}

bool reveal_spot (linked_list board [], int row, int column) {
  if (row > 5 || row < 1 || column > 5 || column < 1) {
    std::cout << "\nInvalid location. \n";
    return true;
  } 

  node* current = board[row - 1].head;
  for (int i = 1; i < column; i++) {
    current = current->next;
  }

  if (current->hit == true) {
    std::cout << "\nInvalid location. \n";
    return true;
  }

  current->hit = true;

  if (current->value == 'X') {
    std::cout << "\nHit mine. \n";
    return false;
  }

  return true;
}

bool won_game (linked_list board []) {
  for (int i = 0; i < 5; i ++) {
    node* current = board[i].head;
    for (int j = 0; j < 5; j++) {
      if (current->hit == false && current->value != 'X') {
        return false;
      }
      current = current->next;
    }
  }
  std::cout << "\nYou won!\n";
  return true;
}

int main() {

  linked_list row1;
  row1.add_node ('1');
  row1.add_node ('1');
  row1.add_node ('1');
  row1.add_node (' ');
  row1.add_node (' ');
  
  linked_list row2;
  row2.add_node ('1');
  row2.add_node ('X');
  row2.add_node ('2');
  row2.add_node ('1');
  row2.add_node ('1');
  
  linked_list row3;
  row3.add_node ('1');
  row3.add_node ('1');
  row3.add_node ('3');
  row3.add_node ('X');
  row3.add_node ('2');
  
  linked_list row4;
  row4.add_node (' ');
  row4.add_node (' ');
  row4.add_node ('2');
  row4.add_node ('X');
  row4.add_node ('2');
  
  linked_list row5;
  row5.add_node (' ');
  row5.add_node (' ');
  row5.add_node ('1');
  row5.add_node ('1');
  row5.add_node ('1');

  linked_list board [] = {row1, row2, row3, row4, row5};

  while (true) {
    print_board (board);
  
    int row;
    std::cout << "\nWhich row? ";
    std::cin >> row;
  
    int column;
    std::cout << "Which column? ";
    std::cin >> column;
  
    if (reveal_spot (board, row, column) == false) {
      print_board (board);
      break;
    } else if (won_game (board) == true) {
      print_board (board);
      break;
    }
  }
  
}
