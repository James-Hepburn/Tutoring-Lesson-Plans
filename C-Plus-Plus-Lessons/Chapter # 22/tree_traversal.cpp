#include <iostream>
#include <vector>
#include <queue>

class node {

  public:

    char data;
    std::vector <node*> children;

    node (char d) {
      data = d;
    }

};

class tree {

  public:

    node* root;

    tree () {
      root = NULL;
    }

    node* find_node (node* current_node, char data) {
      if (current_node == NULL) {
        return NULL;
      } else if (current_node->data == data) {
        return current_node;
      } else {
        for (int i = 0; i < current_node->children.size(); i++) {
          node* found_node = find_node (current_node->children[i], data);
          if (found_node != NULL) {
            return found_node;
          }
        }
        return NULL;
      }
    }

    void insert_node (char parent_data, char child_data) {
      node* new_node = new node (child_data);
      if (root == NULL) {
        root = new_node;
        return;
      }
      node* parent_node = find_node (root, parent_data);
      if (parent_node != NULL) {
        parent_node->children.push_back(new_node);
      }
    }

};

void pre_order (node* current_node) {
  if (current_node == NULL) {
    return;
  }
  std::cout << current_node->data << " ";
  for (int i = 0; i < current_node->children.size(); i++) {
    pre_order (current_node->children[i]);
  }
}

void post_order (node* current_node) {
  if (current_node == NULL) {
    return;
  }
  for (int i = 0; i < current_node->children.size(); i++) {
    post_order (current_node->children[i]);
  }
  std::cout << current_node->data << " ";
}

void breadth_first (node* root) {
  std::queue <node*> q;
  q.push (root);
  while (q.size() != 0) {
    node* current_node = q.front();
    q.pop();
    std::cout << current_node->data << " ";
    for (int i = 0; i < current_node->children.size(); i++) {
      q.push (current_node->children[i]);
    }
  }
}

int main() {

  tree t1;
  t1.insert_node (NULL, 'X');
  t1.insert_node ('X', 'Q');
  t1.insert_node ('X', 'F');
  t1.insert_node ('X', 'D');
  t1.insert_node ('Q', 'C');
  t1.insert_node ('Q', 'N');
  t1.insert_node ('Q', 'R');
  t1.insert_node ('F', 'S');
  t1.insert_node ('F', 'M');
  t1.insert_node ('D', 'H');
  t1.insert_node ('M', 'L');

  tree t2;
  t2.insert_node (NULL, 'A');
  t2.insert_node ('A', 'B');
  t2.insert_node ('A', 'C');
  t2.insert_node ('A', 'D');
  t2.insert_node ('A', 'E');
  t2.insert_node ('C', 'F');
  t2.insert_node ('E', 'G');
  t2.insert_node ('E', 'H');
  t2.insert_node ('E', 'I');

  std::cout << "\nWelcome to the Tree Traversal program! \n";
  
  std::cout << "\n1) Pre-Order \n";
  std::cout << "2) Post-Order \n";
  std::cout << "3) Breadth-First Search \n";
  
  int choice;
  std::cout << "\nWhich type of tree traversal would you like to see? ";
  std::cin >> choice;

  if (choice == 1) {
    std::cout << "\nPre-order traversal is a recursive algorithm that starts at the root node of a tree, processes it, and then recursively visits and processes all of its children from left to right before moving on to the next level of the tree. \n";
    std::cout << "\nTree # 1 -> ";
    pre_order (t1.root);
    std::cout << "\n\nTree # 2 -> ";
    pre_order (t2.root);
    std::cout << "\n";
  } 
  
  else if (choice == 2) {
    std::cout << "\nPost-order traversal is a recursive algorithm that visits every node in a tree by recursively visiting all of the children of a parent node first, and then processing the parent node itself after all of its children have been visited. \n";
    std::cout << "\nTree # 1 -> ";
    post_order (t1.root);
    std::cout << "\n\nTree # 2 -> ";
    post_order (t2.root);
    std::cout << "\n";
  } 
  
  else if (choice == 3) {
    std::cout << "\nBreadth First Search is an algorithm that helps to visit all the nodes of a tree in a level-wise manner, starting from the root node and moving to the next level only when all the nodes at the current level have been visited. \n";
    std::cout << "\nTree # 1 -> ";
    breadth_first (t1.root);
    std::cout << "\n\nTree # 2 -> ";
    breadth_first (t2.root);
    std::cout << "\n";
  } 

  else {
    std::cout << "\nInvalid choice. \n";
  }
  
}
