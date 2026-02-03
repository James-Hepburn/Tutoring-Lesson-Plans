#include <iostream>
#include <queue>

int main() {

  // queues - a type of container with FIFO (first in first out)
  // useful for when the order of actions is important

  // create a queue

  std::queue <int> q;

  // add elements to the queue

  q.push (1);
  q.push (2);
  q.push (3);
  q.push (4);

  // get but do not remove the front element

  int front = q.front();
  std::cout << "front: " << front << "\n";

  // get but do not remove the back element

  int back = q.back();
  std::cout << "back: " << back << "\n";

  // delete but do not get the front element

  q.pop();
  int new_front = q.front();
  std::cout << "new front: " << new_front << "\n";

  // size of the queue

  int size = q.size();
  std::cout << "size: " << size << "\n";
  
}

/*
Question # 1:

A letter means push and an asterisk means pop in the following sequence.  Give the sequence of values returned by the get operation when this sequence of operations is performed on an initially empty FIFO queue. Examples:

EAS*Y*QUE***ST***IO*N*** ➞ EASYQUESTION
FI*RSTI*N*FIR*ST**OU*T******** ➞ FIRSTINFIRSTOUT
*/

std::string q1 (std::string sequence) {
  std::string result = "";
  std::queue <char> q;
  for (int i = 0; i < sequence.length(); i++) {
    if (sequence[i] == '*') {
      result += q.front();
      q.pop();
    } else {
      q.push (sequence[i]);
    }
  }
  return result;
}

/*
Question # 2:

Given a queue, return its sum. Examples:

[1, 2, 3, 4, 5] ➞ 15
[87, 34, 44, 78] ➞ 243
*/

int q2 (std::queue <int> q) {
  int sum = 0;
  while (q.size() != 0) {
    sum += q.front();
    q.pop();
  }
  return sum;
}

/*
Question # 3:

Given a queue of integers, return the element in the middle. If there is an even amount of numbers, return the left side middle element. Examples:

[1, 2, 3, 4, 5] ➞ 3
[87, 34, 44, 78] ➞ 34
*/

int q3 (std::queue <int> q) {
  int counter;
  if (q.size() % 2 != 0) {
    counter = q.size() / 2;
  } else {
    counter = (q.size() / 2) - 1;
  }
  while (counter > 0) {
    q.pop();
    counter -= 1;
  }
  return q.front();
}
