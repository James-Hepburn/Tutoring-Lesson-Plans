#include <iostream>
#include <queue>

class node {

  public:

    int data;
    node* left;
    node* right;

    node (int d) {
      data = d;
    }

};

class binary_search_tree {

  public:

    node* root;

    binary_search_tree () {
      root = NULL;
    }

    void insert_node(int data) {
      node* new_node = new node(data);
      if (root == NULL) {
        root = new_node;
        return;
      }
      std::queue<node*> q;
      q.push(root);
      while (!q.empty()) {
        node* current = q.front();
        q.pop();
        if (data < current->data) {
          if (current->left == NULL) {
            current->left = new_node;
            return;
          }
          q.push(current->left);
        } else {
          if (current->right == NULL) {
            current->right = new_node;
            return;
          }
          q.push(current->right);
        }
      }
    }

    void find_node(int data) {
      node* current = root;
      while (current != NULL) {
        if (current->data == data) {
          std::cout << "Node found. \n";
          return;
        } else if (data < current->data) {
          current = current->left;
        } else {
          current = current->right;
        }
      }
      std::cout << "Node not found. \n";
    }

    void display_tree (node* root) {
      std::queue <node*> q;
      q.push (root);
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
          node* current = q.front();
          q.pop();
          std::cout << current->data << " ";
          if (current->left != NULL) {
            q.push (current->left);
          }
          if (current->right != NULL) {
            q.push (current->right);
          }
        }
        std::cout << "\n";
      }
    }

};

int main() {

  binary_search_tree bst;
  int option;

  std::cout << "\nWelcome to the Binary Search Tree program! \n";

  while (option != 4) {
    std::cout << "\n1) insert node \n";
    std::cout << "2) find node \n";
    std::cout << "3) display tree \n";
    std::cout << "4) exit \n\n";
    std::cout << "Which option would you like to select? ";
    std::cin >> option;
    std::cout << "\n";

    if (option == 1) {
      int data;
      std::cout << "What data would you like to insert into the tree? ";
      std::cin >> data;
      bst.insert_node (data);
    } else if (option == 2) {
      int data;
      std::cout << "What data would you like to search for in the tree? ";
      std::cin >> data;
      bst.find_node (data);
    } else if (option == 3) {
      bst.display_tree (bst.root);
    } else if (option == 4) {
      std::cout << "Goodbye! \n";
      break;
    } else {
      std::cout << "Invalid option. \n";
    }
  }
  
}
