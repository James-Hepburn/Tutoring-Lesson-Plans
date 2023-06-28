#include <iostream>
#include <vector>
#include <unistd.h>

class Node {

  public:

    char letter;
    Node* left;
    Node* right;
  
    Node (char l) {
      letter = l;
      left = NULL;
      right = NULL;
    }

};

class LinkedList {

  public:

    Node* head;
    Node* tail;

    LinkedList () {
      head = NULL;
      tail = NULL;
    }

    void add_row (char letter) {
      Node* new_node = new Node(letter);
      if (tail == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->left = tail;
        tail->right = new_node;
        tail = new_node;
      }
    }

    void create_row (std::string row) {
      for (int i = 0; i < row.length(); i++) {
        add_row (row[i]);
      }
    }

    void print() {
      Node* temp = head;
      std::cout << "\n";
      while (temp != NULL) {
        std::cout << temp->letter << " ";
        temp = temp->right;
      }
      std::cout << "\n";
    }

    std::string check_row (int start, int end) {
      Node* temp = head;
      std::string found = "";
      int counter = 1;
      while (temp != NULL) {
        if (counter >= start && counter <= end) {
          found += temp->letter;
        }
        temp = temp->right;
        counter += 1;
      }
      return found;
    }
    
};

void print_board (std::vector <LinkedList> rows, std::vector <std::string> words) {
  for (int i = 0; i < rows.size(); i++) {
    rows[i].print();
  }
  for (int i = 0; i < words.size(); i+=4) {
    if (i < words.size() - 3) {
      std::cout << "\n" << words[i] << " " << words[i+1] << " " << words[i+2] << " " << words[i+3] << "\n";
    } else if (i < words.size() - 2) {
      std::cout << "\n" << words[i] << " " << words[i+1] << " " << words[i+2] << "\n";
    } else if (i < words.size() - 1) {
      std::cout << "\n" << words[i] << " " << words[i+1] << "\n";
    } else {
      std::cout << "\n" << words[i] << "\n";
    }
  }
}

bool game_over (std::vector <std::string> words) {
  int count = 0;
  for (int i = 0; i < words.size(); i++) {
    if (words[i][0] == '-') {
      count += 1;
    }
  }
  return count == 16;
}

std::vector <std::string> mark_word (std::vector<std::string> words, std::string found) {
  for (int i = 0; i < words.size(); i++) {
    if (found == words[i]) {
      words[i] = std::string(words[i].length(), '-');
    }
  }
  return words;
}

std::string check_column (int start, int end, int column, std::vector <LinkedList> rows) {
  std::string found = "";
  for (int i = start - 1; i < end; i++) {
    LinkedList current = rows[i];
    Node* temp = current.head;
    int counter = 1;
    while (counter != column) {
      temp = temp->right;
      counter += 1;
    }
    found += temp->letter;
  }
  return found;
}

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

int main() {

  std::vector <std::string> words = {"BELT", "BEAR", "SHOE", "HAND", "BALL", "MICE", "TOYS", "BAT", "DOG", "TOP", "HAT", "COW", "ZAP", "GAL", "BOY", "CAT"};

  LinkedList row1;
  LinkedList row2;
  LinkedList row3;
  LinkedList row4;
  LinkedList row5;
  LinkedList row6;
  LinkedList row7;
  LinkedList row8;

  row1.create_row("JLIBPNZQOAJD");
  row2.create_row("KBFAMZSBEARO");
  row3.create_row("OAKTMICECTQG");
  row4.create_row("YLLSHOEDAOGU");
  row5.create_row("SLHCOWZBTYAH");
  row6.create_row("MHANDSAOISLA");
  row7.create_row("TOPIFYPYAGJT");
  row8.create_row("EZTBELTEATAH");

  while (game_over (words) == false) {
    erase (3000000);

    std::vector <LinkedList> rows = {row1, row2, row3, row4, row5, row6, row7, row8};
    print_board (rows, words);

    char c_r;
    std::cout << "\nFound a word in a (C)olumn or a (R)ow? ";
    std::cin >> c_r;

    if (c_r == 'R' || c_r == 'r') {
      int row;
      std::cout << "\nWhich row? ";
      std::cin >> row;

      int column_start;
      std::cout << "\nWhich column does the word start in? ";
      std::cin >> column_start;

      int column_end;
      std::cout << "\nWhich column does the word end in? ";
      std::cin >> column_end;

      if (column_start < 1 || column_start > 12 || column_end < 1 || column_end > 12 || column_start > column_end || row < 1 || row > 8) {
        std::cout << "\nInvalid information. \n";
      } else {
        if (row == 1) {
          words = mark_word (words, row1.check_row(column_start, column_end));
        } else if (row == 2) {
          words = mark_word (words, row2.check_row(column_start, column_end));
        } else if (row == 3) {
          words = mark_word (words, row3.check_row(column_start, column_end));
        } else if (row == 4) {
          words = mark_word (words, row4.check_row(column_start, column_end));
        } else if (row == 5) {
          words = mark_word (words, row5.check_row(column_start, column_end));
        } else if (row == 6) {
          words = mark_word (words, row6.check_row(column_start, column_end));
        } else if (row == 7) {
          words = mark_word (words, row7.check_row(column_start, column_end));
        } else {
          words = mark_word (words, row8.check_row(column_start, column_end));
        }
      }
    } else if (c_r == 'C' || c_r == 'c') {
      int column;
      std::cout << "\nWhich column? ";
      std::cin >> column;

      int row_start;
      std::cout << "\nWhich row does the word start in? ";
      std::cin >> row_start;

      int row_end;
      std::cout << "\nWhich row does the word end in? ";
      std::cin >> row_end;

      if (row_start < 1 || row_start > 8 || row_end < 1 || row_end > 8 || row_start > row_end || column < 1 || column > 12) {
        std::cout << "\nInvalid information. \n";
      } else {
        words = mark_word(words, check_column (row_start, row_end, column, rows));
      }
    } else {
      std::cout << "\nInvalid information. \n";
    }
  }

  erase (3000000);
  std::cout << "\nYou found all of the words! \n";

}
