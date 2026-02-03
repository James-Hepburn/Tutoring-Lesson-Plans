#include <iostream>
#include <vector>

class node {

  public:

    int data;
    std::vector <node*> children;

    node (int d) {
      data = d;
    }

};

class tree {

  public:

    node* root;

    tree () {
      root = NULL;
    }

    node* find_node (node* current_node, int data) {
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

    void insert_node (int parent_data, int child_data) {
      node* new_node = new node (child_data);
      if (root == NULL) {
        root = new_node;
        return;
      }
      node* parent_node = find_node (root, parent_data);
      if (parent_node != NULL) {
        parent_node->children.push_back (new_node);
      }
    }

    void delete_subtree (node* n) {
      for (int i = 0; i < n->children.size(); i++) {
        delete_subtree (n->children[i]);
      }
      delete n;
    }

    void delete_node (int parent_data, int child_data) {
      node* del_node = find_node (root, child_data);
      if (del_node == NULL) {
        return;
      } else if (del_node == root) {
        delete root;
        root = NULL;
      } else {
        node* parent_node = find_node (root, parent_data);
        for (int i = 0; i < parent_node->children.size(); i++) {
          if (parent_node->children[i]->data == child_data) {
            parent_node->children.erase (parent_node->children.begin() + i);
            break;
          }
        }
        for (int i = 0; i < del_node->children.size(); i++) {
          delete_subtree (del_node->children[i]);
        }
        delete del_node;
      }
    } 

};

int main() {

  tree t1;

  t1.insert_node (NULL, 1);

  t1.insert_node (1, 2);
  t1.insert_node (1, 3);

  t1.insert_node (2, 4);
  t1.insert_node (2, 5);

  t1.insert_node (5, 6);
  t1.insert_node (5, 7);
  t1.insert_node (5, 8);

  tree t2;

  t2.insert_node (NULL, 1);

  t2.insert_node (1, 2);
  t2.insert_node (1, 3);

  t2.insert_node (3, 7);
  t2.insert_node (3, 8);

  t2.insert_node (2, 4);
  t2.insert_node (2, 5);
  t2.insert_node (2, 6);

  t2.insert_node (5, 9);
  t2.insert_node (5, 10);

}

/*
Question # 1:

Given the root of a tree, create a method that calulates its size (i.e. how many nodes it has). Examples:

tree # 1 -> 8
tree # 2 -> 10
*/

int q1 (node* root) {
  if (root == NULL) {
    return 0;
  } else {
    int size = 1;
    for (int i = 0; i < root->children.size(); i++) {
      size += q1 (root->children[i]);
    }
    return size;
  }
}

/*
Question # 2:

Given the root of a tree, create a method that calculates the height of a tree (i.e. the length of the longest path from the root to any node). Examples:

tree # 1 -> 4
tree # 2 -> 4
*/

int q2 (node* root) {
  if (root == NULL) {
    return 0;
  } else {
    int max_height = 0;
    for (int i = 0; i < root->children.size(); i++) {
      int height = q2 (root->children[i]);
      if (height > max_height) {
        max_height = height;
      }
    }
    return max_height + 1;
  }
}

/*
Question # 3:

Given the root of a tree, create a method that calculates the sum of all the nodes with exactly 1 other sibling. Examples:

tree # 1 -> 14 because 2 + 3 + 4 + 5 = 14
tree # 2 -> 39 because 2 + 3 + 7 + 8 + 9 + 10 = 39
*/

int q3 (node* root) {
  if (root == NULL) {
    return 0;
  } else {
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++) {
      if (root->children.size() == 2) {
        sum += root->children[i]->data;
      }
      sum += q3 (root->children[i]);
    }
    return sum;
  }
}

/*
Question # 4:

Given a the root of a tree and a node, create a method that returns its parent node. Examples:

tree # 1 node 2 -> 1
tree # 2 node 9 -> 5
*/

node* q4 (node* root, node* child) {
  if (root == NULL || child == NULL || root == child) {
    return NULL;
  } else {
    for (int i = 0; i < root->children.size(); i++) {
      if (root->children[i] == child) {
        return root;
      } else {
        node* parent = q4 (root->children[i], child);
        if (parent != NULL) {
          return parent;
        }
      }
    }
    return NULL;
  }
}
