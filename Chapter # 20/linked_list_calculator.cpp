#include <iostream>

class node {

  public:    

    char data;
    node* next;

    node (char data, node* next) {
      this->data = data;
      this->next = next;
    }

};

class linked_list {

  private:

    node* head;

  public:

    linked_list () {
      head = NULL;
    }

    void push (char data) {
      node* new_node = new node(data, head);
      head = new_node;
    }

    char pop () {
      node* temp = head;
      head = head->next;
      char data = temp->data;
      delete temp;
      return data;
    }

    double evaluate () {
      while (head->next != NULL) {
        double a = pop() - '0';
        char value = pop();
        double b = pop() - '0';
        if (value == '+') {
          double result = a + b;
          push(result + '0');
        } else if (value == '-') {
          double result = a - b;
          push(result + '0');
        } else if (value == '*') {
          double result = a * b;
          push(result + '0');
        } else if (value == '/') {
          double result = a / b;
          push(result + '0');
        } 
      }
      return pop() - '0';
    }

};

int main() {

  std::string expression;
  std::cout << "Enter an expression: ";
  std::cin >> expression;

  linked_list list;
  
  for (int i = expression.length() - 1; i >= 0; i--) {
    list.push (expression[i]);
  }
  
  int result = list.evaluate();
  std::cout << "\nResult: " << result << "\n";
  
}
