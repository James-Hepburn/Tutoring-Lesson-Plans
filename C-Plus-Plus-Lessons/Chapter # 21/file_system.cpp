#include <iostream>
#include <vector>

class node {

  public:

    std::string firstName;
    std::string lastName;
    node* next;
    node* prev;

    node (std::string f, std::string l) {
      firstName = f;
      lastName = l;
      next = NULL;
      prev = NULL;
    }

};

class linked_list {

  private:

    node* head;
    node* tail;

  public:

    linked_list () {
      head = NULL;
      tail = NULL;
    }

    void push_back (std::string firstName, std::string lastName) {
      node* new_node = new node(firstName, lastName);
      if (tail == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      }
    }

    void alphabetically_last () {
      bool swapped = true;
      while (swapped) {
        swapped = false;
        node* temp = head;
        while (temp->next != NULL) {
          if (temp->lastName > temp->next->lastName) {
            std::string temp_first = temp->firstName;
            std::string temp_last = temp->lastName;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->firstName = temp_first;
            temp->next->lastName = temp_last;
            swapped = true;
          }
          temp = temp->next;
        }
      }
    }

    void alphabetically_first () {
      bool swapped = true;
      while (swapped) {
        swapped = false;
        node* temp = head;
        while (temp->next != NULL) {
          if (temp->firstName > temp->next->firstName) {
            std::string temp_first = temp->firstName;
            std::string temp_last = temp->lastName;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->firstName = temp_first;
            temp->next->lastName = temp_last;
            swapped = true;
          }
          temp = temp->next;
        }
      }
    }

    void length_last () {
      bool swapped = true;
      while (swapped) {
        swapped = false;
        node* temp = head;
        while (temp->next != NULL) {
          if (temp->lastName.length() > temp->next->lastName.length()) {
            std::string temp_first = temp->firstName;
            std::string temp_last = temp->lastName;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->firstName = temp_first;
            temp->next->lastName = temp_last;
            swapped = true;
          }
          temp = temp->next;
        }
      }
    }

    void length_first () {
      bool swapped = true;
      while (swapped) {
        swapped = false;
        node* temp = head;
        while (temp->next != NULL) {
          if (temp->firstName.length() > temp->next->firstName.length()) {
            std::string temp_first = temp->firstName;
            std::string temp_last = temp->lastName;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->firstName = temp_first;
            temp->next->lastName = temp_last;
            swapped = true;
          }
          temp = temp->next;
        }
      }
    }

    void random () {
      // length, add to vector, delete
      int length = 0;
      std::vector <node*> nodes;
      node* temp = head;
      while (temp != NULL) {
        nodes.push_back(temp);
        temp = temp->next;
        length += 1;
      }

      // shuffle vector
      for (int i = 0; i < 100; i++) {
        int index1 = rand() % length;
        int index2 = rand() % length;
        node* node1 = nodes[index1];
        node* node2 = nodes[index2];
        nodes[index1] = node2;
        nodes[index2] = node1;
      }

      // add to list
      node* prev = NULL;
      for (int i = 0; i < nodes.size(); i++) {
        node* current = nodes[i];
        current->prev = prev;
        if (i == nodes.size() - 1) {
          current->next = NULL;
        } else {
          current->next = nodes[i+1];
        }
        prev = current;
      }
      head = nodes[0];
    }

    void print_list () {
      node* temp = head;
      std::cout << "\nHere are the files: \n\n";
      while (temp != NULL) {
        std::cout << "- " << temp->firstName << " " << temp->lastName << "\n";
        temp = temp->next;
      }
    }
    
};

int main() {
  
  linked_list list;
  list.push_back ("Jeremy", "Bennett");
  list.push_back ("Cheyenne", "Dixon");
  list.push_back ("Daniel", "Abbott");
  list.push_back ("Katherine", "Jordan");
  list.push_back ("Rachel", "Wilson");

  int choice;

  while (choice != 6) {
    std::cout << "\nWelcome to the File System!\n\n";
    std::cout << "1) Sort alphabetically (last name) \n";
    std::cout << "2) Sort alphabetically (first name) \n";
    std::cout << "3) Sort by length (last name) \n";
    std::cout << "4) Sort by length (first name) \n";
    std::cout << "5) Random order \n";
    std::cout << "6) Exit \n\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    if (choice == 1) {
      list.alphabetically_last();
      list.print_list();
    } else if (choice == 2) {
      list.alphabetically_first();
      list.print_list();
    } else if (choice == 3) {
      list.length_last();
      list.print_list();
    } else if (choice == 4) {
      list.length_first();
      list.print_list();
    } else if (choice == 5) {
      list.random();
      list.print_list();
    } else if (choice == 6) {
      std::cout << "\nGoodbye. \n";
      break;
    } else {
      std::cout << "\nInvalid selection. \n";
    }
  }
  
}
