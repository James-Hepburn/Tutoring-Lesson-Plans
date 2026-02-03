#include <iostream>
#include <vector>

class node {

  public:

    std::string first_name;
    std::string last_name;
    std::vector <node*> children;

    node (std::string fn, std::string ln) {
      first_name = fn;
      last_name = ln;
    }

};

class tree {

  public:

    node* root;

    tree () {
      root = NULL;
    }

    node* find_node (node* current, std::string first_name, std::string last_name) {
      if (current == NULL) {
        return NULL;
      } else if (current->first_name == first_name && current->last_name == last_name) {
        return current;
      } else {
        for (int i = 0; i < current->children.size(); i++) {
          node* found_node = find_node (current->children[i], first_name, last_name);
          if (found_node != NULL) {
            return found_node;
          }
        }
        return NULL;
      }
    }

    void add_node (std::string parent_first, std::string parent_last, std::string child_first, std::string child_last) {
      node* parent = new node (parent_first, parent_last);
      node* child = new node (child_first, child_last);
      if (root == NULL) {
        root = parent;
        root->children.push_back (child);
      } else {
        node* parent_node = find_node (root, parent_first, parent_last);
        parent_node->children.push_back (child);
      }
    }

    void print_tree (node* current, int spaces) {
      for (int i = 0; i < spaces; i++) {
        std::cout << "  ";
      }
      std::cout << current->first_name << " " << current->last_name << "\n";
      for (int i = 0; i < current->children.size(); i++) {
        print_tree (current->children[i], spaces + 1);
      }
    }

};

int main() {

  tree t;

  while (true) {
  
    std::cout << "\nFamily Tree! \n\n";
  
    std::cout << "1) Add family member to tree \n";
    std::cout << "2) View family tree \n";
    std::cout << "3) Exit \n";
  
    int option;
    std::cout << "\nWhich option? ";
    std::cin >> option;
  
    if (option == 1) {
      std::string parent_first_name;
      std::cout << "\nParent first name: ";
      std::cin >> parent_first_name;
      std::string parent_last_name;
      std::cout << "Parent last name: ";
      std::cin >> parent_last_name;
      std::string child_first_name;
      std::cout << "Child first name: ";
      std::cin >> child_first_name;
      std::string child_last_name;
      std::cout << "Child last name: ";
      std::cin >> child_last_name;
      t.add_node (parent_first_name, parent_last_name, child_first_name, child_last_name);
    } 
  
    else if (option == 2) {
      std::cout << "\n";
      t.print_tree (t.root, 0);
    }
  
    else if (option == 3) {
      std::cout << "\nGoodbye. \n";
      break;
    }

    else {
      std::cout << "\nInvalid option. \n";
    }
    
  }
  
}
