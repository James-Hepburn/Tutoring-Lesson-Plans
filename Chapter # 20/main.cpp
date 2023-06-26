#include <iostream>

class node {

  public:

    int data;
    node* next; // pointer to the next node in the list

    // default constructor
    node () {
      data = 0;
      next = NULL;
    }

    // normal constructor
    node (int d) {
      data = d;
      next = NULL;
    }

};

class linked_list {

  private:

    node* head;

  public:

    linked_list () {
      head = NULL;
    }

    // method to get head
    node* get_head() {
      return head;
    }

    // method to insert a node at the end of the linked list
    void insert_node (int data) {
      node* new_node = new node (data);

      if (head == NULL) {
        head = new_node;
        return;
      }

      node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = new_node;
    }

    // method to delete a node given the previous node
    void delete_node (node* prev){
      node* temp = prev->next;
      prev->next = temp->next;
      delete temp;
    }

    // method to delete head
    void delete_head () {
      if (head == NULL) {
        return;
      }

      node* temp = head;
      head = head->next;
      delete temp;
    }

    // method to print linked list
    void print_list () {
      if (head == NULL) {
        return;
      }

      node* temp = head;
      while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << "\n";
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

  list.insert_node(1);
  list.insert_node(2);
  list.insert_node(3);
  list.insert_node(4);

  list.print_list();

  list.delete_node(list.get_head());

  list.print_list();

  list.delete_head();

  list.print_list();

}

/*
Definition for singly-linked list:
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
*/

/*
Question # 1:

Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node. Examples:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

/*
Solution: https://leetcode.com/problems/middle-of-the-linked-list/
  
ListNode* middleNode(ListNode* head) {
  int size = 0;
  ListNode* temp = head;
  while (temp != NULL) {
      temp = temp->next;
      size += 1;
  }
  size /= 2;
  temp = head;
  for (int i = 0; i < size; i++) {
      temp = temp->next;
  }
  return temp;
}
*/

/*
Question # 2:

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head. Examples:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []

Input: head = [7,7,7,7], val = 7
Output: []
*/

/*
Solution: https://leetcode.com/problems/remove-linked-list-elements/

ListNode* removeElements(ListNode* head, int val) {
  if (head == NULL) {
    return NULL;
  }
  ListNode* temp = head;
  while (temp->next != NULL) {
    if (temp->next->val == val) {
      temp->next = temp->next->next;
    } else {
      temp = temp->next;
    }
  }
  if (head->val == val) {
    head = head->next;
  }
  return head;
}
*/

/*
Question # 3:

You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list. Examples:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]
*/

/*
Solution: https://leetcode.com/problems/merge-two-sorted-lists/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == NULL) {
    return list2;
  } else if (list2 == NULL) {
    return list1;
  }
  ListNode* temp;
  if (list1->val < list2->val) {
    temp = list1;
    list1 = list1->next;
  } else {
    temp = list2;
    list2 = list2->next;
  }
  ListNode* head = temp;
  while (list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      temp->next = list1;
      list1 = list1->next;
    } else {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  if (list1 == NULL) {
    temp->next = list2;
  } else {
    temp->next = list1;
  }
  return head;
}
*/
