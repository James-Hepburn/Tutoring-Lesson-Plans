#include <iostream>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

class Node {

  public:

    bool flip;
    char symbol;
    Node* next;

    Node (char s) {
      symbol = s;
      next = NULL;
      flip = false;
    }

};

class LinkedList {

  private:

    Node* head;

  public:

    LinkedList () {
      head = NULL;
    }

    void insert_node (char symbol) {
      Node* new_node = new Node (symbol);

      if (head == NULL) {
        head = new_node;
        return;
      }

      Node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = new_node;
    }

    void print_list () {
      Node* temp = head;
      std::cout << "\n";
      while (temp != NULL) {
        if (temp->flip == false) {
          std::cout << "🟥 ";
        } else {
          std::cout << temp->symbol << " ";
        }
        temp = temp->next;
      }
      std::cout << "\n";
    }

    void print_list_flipped (int card1, int card2) {
      Node* temp = head;
      std::cout << "\n";
      int count = 1;
      while (temp != NULL) {
        if (count == card1 || count == card2) {
          std::cout << temp->symbol << " ";
        } else {
          if (temp->flip == false) {
            std::cout << "🟥 ";
          } else {
            std::cout << temp->symbol << " ";
          }
        }
        count += 1;
        temp = temp->next;
      }
      std::cout << "\n";
    }

    Node* get_node (int card) {
      Node* temp = head;
      for (int i = 0; i < card; i++) {
        temp = temp->next;
      }
      return temp;
    }

    bool check_match (Node* n1, Node* n2) {
      return n1->symbol == n2->symbol;
    }

    void shuffle () {
      for (int i = 0; i < 100; i++) {
        int index1 = rand() % 8;
        int index2 = rand() % 8;
        if (index1 != index2) {
          Node* node1 = head;
          Node* node2 = head;
          for (int j = 0; j < index1; j++) {
            node1 = node1->next;
          }
          for (int j = 0; j < index2; j++) {
            node2 = node2->next;
          }
          char temp = node1->symbol;
          node1->symbol = node2->symbol;
          node2->symbol = temp;
        }
      }
    }

    int get_size () {
      int length = 0;
      Node* temp = head;
      while (temp != NULL) {
        if (temp->flip == false) {
          length += 1;
        }
        temp = temp->next;
      }
      return length;
    }

    void flip_card (Node* node) {
      node->flip = true;
    }

};


int main() {

  std::string symbols = "aabbccdd";

  LinkedList list;
  for (int i = 0; i < 8; i++) {
    list.insert_node(symbols[i]);
  }

  list.shuffle();

  while (list.get_size() != 0) {

    erase (2000000);
    
    list.print_list();

    int card1;
    std::cout << "\nwhich card would you like to select first? ";
    std::cin >> card1;

    int card2;
    std::cout << "which card would you like to select second? ";
    std::cin >> card2;

    if (card1 == card2 || card1 < 1 || card2 < 1 || card1 > 8 || card2 > 8) {
      std::cout << "\ninvalid selection.\n";
    } else {
      list.print_list_flipped(card1, card2);
      Node* node1 = list.get_node(card1 - 1);
      Node* node2 = list.get_node(card2 - 1);
      if (list.check_match(node1, node2)) {
        std::cout << "\nMatch found!\n";
        list.flip_card(list.get_node(card1 - 1));
        list.flip_card(list.get_node(card2 - 1));
      }
    }

    if (list.get_size() == 0) {
      std::cout << "\nAll matches found!\n";
      break;
    }
    
  }
  
}
