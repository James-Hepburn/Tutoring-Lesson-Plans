#include <iostream>
#include <string>

class node {

  public:

    std::string song;
    std::string artist;
    node* next;
    node* prev;

    node (std::string s, std::string a) {
      song = s;
      artist = a;
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

    void add_node (node* new_node) {
      if (tail == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      }
    }

    void delete_node (int pos) {
      // If the position is 1, delete the head node
      if (pos == 1) {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
          head->prev = NULL;
        }
        delete temp;
        return;
      }
  
      // Traverse the list to find the node to be deleted
      node* current = head;
      int i = 1;
      while (current != NULL && i < pos) {
        current = current->next;
        i++;
      }
  
      // If the node to be deleted is the tail node, update the tail pointer
      if (current->next == NULL) {
        tail = current->prev;
        tail->next = NULL;
        delete current;
        return;
      }
  
      // If the node to be deleted is in the middle of the list, update the pointers of the adjacent nodes
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
    }

    void print() {
      std::cout << "\nHere are your songs: \n";
      node* temp = head;
      int counter = 1;
      while (temp != NULL) {
        std::cout << counter << ") " << temp->song << " - " << temp ->artist << "\n";
        temp = temp->next;
        counter += 1;
      }
    }

    int size () {
      node* temp = head;
      int counter = 0;
      while (temp != NULL) {
        temp = temp->next;
        counter += 1;
      }
      return counter;
    }

    node* get_node(int pos) {
      if (head == NULL) {
        return NULL;
      }
      node* temp = head;
      int i = 1;
      while (temp != NULL && i < pos) {
        temp = temp->next;
        i += 1;
      }
      if (i == pos) {
        return temp;
      }
      return NULL;
    }

};

int main() {

  std::cout << "\nWelcome to the Music Playlist!\n";

  linked_list list;

  while (true) {

    std::cout << "\nWould you like to \n";
    std::cout << "1) view your entire playlist \n";
    std::cout << "2) view your playlist individually \n";
    std::cout << "3) add a song \n";
    std::cout << "4) delete a song \n";
    std::cout << "5) exit \n\n";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
      list.print();
    }

    else if (choice == 2) {
      int pos = 1;
      while (true) {
        node* current = list.get_node(pos);
        std::cout << "\nYour current song is " << current->song << " - " << current->artist << "\n";
        std::cout << "\nWould you like to\n";
        std::cout << "1) see next song \n";
        std::cout << "2) see previous song \n";
        std::cout << "3) go back to the main menu \n\n";
        int option;
        std::cin >> option;
        if (option == 1) {
          pos += 1;
          if (pos > list.size()) {
            pos = 1;
          }
        } else if (option == 2) {
          pos -= 1;
          if (pos == 0) {
            pos = list.size();
          }
        } else {
          break;
        }
      }
    }

    else if (choice == 3) {
      std::cin.ignore();
      std::string song;
      std::cout << "\nWhat song would you like to add? ";
      getline(std::cin, song);
      std::string artist;
      std::cout << "What artist created this song? ";
      getline(std::cin, artist);
      node* new_node = new node (song, artist);
      list.add_node(new_node);
    }

    else if (choice == 4) {
      list.print();
      int pos;
      std::cout << "\nWhich would you like to delete? ";
      std::cin >> pos;
      if (pos < 1 || pos > list.size()) {
        std::cout << "\nInvalid selection.\n";
      } else {
        list.delete_node(pos);
      }
    }

    else if (choice == 5) {
      std::cout << "\nGoodbye!\n";
      break;
    }
    
  }

}
