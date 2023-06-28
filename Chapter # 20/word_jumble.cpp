#include <iostream>
#include <vector>

class Node {

  public:

    char letter;
    Node* next;

    Node (char l) {
      letter = l;
      next = NULL;
    }

};

class LinkedList {

  private:

    Node* head;

  public:

    LinkedList () {
      head = NULL;
    }

    void insert_node (char letter) {
      Node* new_node = new Node (letter);

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
      std::cout << "\nWord: ";
      while (temp != NULL) {
        std::cout << temp->letter << " ";
        temp = temp->next;
      }
      std::cout << "\n";
    }

    void shuffle (int length) {
      for (int i = 0; i < 100; i++) {
        int index1 = rand() % length;
        int index2 = rand() % length;
        if (index1 != index2) {
          Node* node1 = head;
          Node* node2 = head;
          for (int j = 0; j < index1; j++) {
            node1 = node1->next;
          }
          for (int j = 0; j < index2; j++) {
            node2 = node2->next;
          }
          char temp = node1->letter;
          node1->letter = node2->letter;
          node2->letter = temp;
        }
      }
    }

};

int main() {

  std::string words [] = {"award", "constant", "terminal", "surprise", "sensation"};

  srand (time (0));
  int index = rand() % 5;

  std::string original_word = words[index];

  LinkedList list;
  for (int i = 0; i < original_word.length(); i++) {
    list.insert_node(original_word[i]);
  }

  list.shuffle(original_word.length());

  while (true) {
    list.print_list();

    std::string guess;
    std::cout << "Guess: ";
    std::cin >> guess;

    if (guess == original_word) {
      std::cout << "Correct!\n";
      break;
    } else {
      std::cout << "Wrong.\n";
    }
  }

}
