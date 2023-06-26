#include <iostream>

class node {

  public:

    int data;
    node* next;
    node* prev;

    node (int d) {
      data = d;
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

    // method to add to end of list
    void push_back(int data) {
      node* new_node = new node(data);
      if (tail == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      }
    }

    // method to add to start of list
    void push_front(int data) {
      node* new_node = new node(data);
      if (head == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
      }
    }

    // method to delete from end of list
    void pop_back() {
      if (tail != NULL) {
        node* prev_node = tail->prev;
        delete tail;
        tail = prev_node;
        // check if only one node in list
        if (tail != NULL) {
          tail->next = NULL;
        } else {
          head = NULL;
        }
      }
    }

    // method to delete from start of list
    void pop_front() {
      if (head != NULL) {
        node* next_node = head->next;
        delete head;
        head = next_node;
        // check if only one node in list
        if (head != NULL) {
          head->prev = NULL;
        } else {
          tail = NULL;
        }
      }
    }
    
    void print() {
      node* temp = head;
      while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << "\n";
    }

    // exercise question 1

    int length () {
      int size = 0;
      node* temp = head;
      while (temp != NULL) {
        size += 1;
        temp = temp->next;
      }
      return size;
    }

    // exercise question 2 

    linked_list reverse () {
      linked_list rev;
      node* temp = tail;
      while (temp != NULL) {
        rev.push_back(temp->data);
        temp = temp->prev;
      }
      return rev;
    }

    // exercise question 3

    bool palindrome (linked_list list) {
      linked_list rev = list.reverse();
      node* temp1 = rev.head;
      node* temp2 = list.head;
      while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2 -> data) {
          return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
      return true;
    }

};

int main() {

  /* 
  - a linked list consists of nodes where each node contains a data field and a reference (link) to the next node in the list

  - linked lists are useful for situations where you need a dynamic, ordered collection of elements that can grow or shrink in size

  - there are two types of linked lists:
    * singly linked list
      ^ can only access the next node
    * doubly linked list
      ^ can access the previous and the next node
  */

  linked_list list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.print();

  list.push_front(0);
  list.push_front(-1);
  list.push_front(-2);

  list.print();

  list.pop_back();

  list.print();

  list.pop_front();

  list.print();

  linked_list l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(2);
  l1.push_back(1);

  linked_list l2;
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(9);

  /*
  Question # 1:
  
  Write a method to find the length of a doubly linked lsit. Examples:
  
  1, 2, 3, 2, 1 -> 5
  1, 1, 9 -> 3
  */

  std::cout << "\nQuestion # 1:\n";
  std::cout << l1.length() << "\n";
  std::cout << l2.length() << "\n";

  /*
  Question # 2:

  Write a method to return the reverse of a given linked list. Examples:

  1, 2, 3, 2, 1 -> 1, 2, 3, 2, 1
  1, 1, 9 -> 9, 1, 1
  */

  std::cout << "\nQuestion # 2:\n";
  l1.reverse().print();
  l2.reverse().print();

  /*
  Question # 3:

  Write a method to check if a linked list is a palindrome. Examples:

  1, 2, 3, 2, 1 -> true
  1, 1, 9 -> false
  */

  std::cout << "\nQuestion # 3:\n";
  std::cout << l1.palindrome(l1) << "\n";
  std::cout << l2.palindrome(l2) << "\n";

}
