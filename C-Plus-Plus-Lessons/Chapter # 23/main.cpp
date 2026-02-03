#include <iostream>
#include <queue>

class node {

  public:

    int data;
    node* right;
    node* left;

    node (int d) {
      data = d;
    }

};

class binary_tree {

  public:

    node* root;

    binary_tree () {
      root = NULL;
    }

    void insert_node (int data) { 
      node* new_node = new node (data);
      if (root == NULL) {
        root = new_node;
        return;
      }
      std::queue <node*> q;
      q.push (root);
      while (!q.empty()) {
        node* current = q.front();
        q.pop();
        if (current->left == NULL) {
          current->left = new_node;
          return;
        } else if (current->right == NULL) {
          current->right = new_node;
          return;
        } else {
          q.push (current->left);
          q.push (current->right);
        }
      }
    }

};

int main() {

  // a binary tree is a tree where each node has 0, 1 or 2 children

  binary_tree t1;

  t1.insert_node (1);
  t1.insert_node (2);
  t1.insert_node (3);
  t1.insert_node (5);
  t1.insert_node (6);

  binary_tree t2;

  t2.insert_node (2);
  t2.insert_node (4);
  t2.insert_node (10);
  t2.insert_node (6);
  t2.insert_node (5);
  t2.insert_node (11);
  
}

/*
Question # 1:

Given the root of a binary tree and an integer value, create a method that returns the position of that node in the tree. Examples:

tree # 1 and 2 -> left
tree # 2 and 5 -> right
tree # 2 and 2 -> root
*/

std::string q1 (node* root, int value) {
  if (root->data == value) {
    return "root";
  }
  std::queue <node*> q;
  q.push (root);
  while (!q.empty()) {
    node* current = q.front();
    q.pop(); 
    if (current->left->data == value) {
      return "left";
    } else if (current->right->data == value) {
      return "right";
    } else {
      q.push (current->left);
      q.push (current->right);
    }
  }
}

/*
Question # 2:

Given the root of a binary tree, return the value that is the biggest in the tree. Examples: 

tree # 1 -> 6
tree # 2 -> 11
*/

int q2 (node* root) {
  int biggest = 0;
  std::queue <node*> q;
  q.push (root);
  while (!q.empty()) {
    node* current = q.front();
    q.pop();
    if (current->data > biggest) {
      biggest = current->data;
    }
    if (current->left != NULL) {
      q.push (current->left);
    }
    if (current->right != NULL) {
      q.push (current->right);
    }
  }
  return biggest;
}

/*
Question # 3:

Given the root of a binary tree, create a method that returns the sum of all the values in the tree multiplied by each node's level in the tree. Examples:

tree # 1 -> 44 because (1 * 1) + (2 * 2) + (3 * 2) + (5 * 3) + (6 * 3) = 44
tree # 2 -> 96 because (2 * 1) + (4 * 2) + (10 * 2) + (6 * 3) + (5 * 3) + (11 * 3) = 96
*/

int q3 (node* root) {
  int sum = 0;
  int level = 1;
  std::queue <node*> q;
  q.push (root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      node* current = q.front();
      q.pop();
      sum += current->data * level;
      if (current->left != NULL) {
        q.push (current->left);
      }
      if (current->right != NULL) {
        q.push (current->right);
      }
    }
    level += 1;
  }
  return sum;
}
