#include <iostream>
#include <set>

int main() {

  // sets are a container of elements, where each element is unique
  // in increasing order by default
  // cannot be printed
  // do not have indexes

  // making a set

  std::set <char> letters = {'a', 'b', 'c'};
  std::set <int> s;

  // adding elements

  s.insert (4);
  s.insert (3);
  s.insert (2);
  s.insert (1);
  s.insert (1);

  // deleting elements

  auto element = s.find (3); // if found, position. if not found, s.end()
  s.erase (element);

  // counting occurence / finding if set contains

  int three = s.count (3);
  std::cout << "how many 3s? " << three << "\n";

  // size

  int length = s.size();
  std::cout << "size: " << length << "\n";

  // going through all the elements

  for (int i : s) {
    std::cout << i << "\n";
  }
  
}

/*
Question # 1:

Given a set, return the largest number in the set multiplied by the smallest number in the set. Assume the set has at least one number and that all numbers within the set are in the range 1 to 100. Examples:

{1, 2, 3, 4, 5} ➞ 5 because 1 x 5 = 5
{10, 20, 30} ➞ 300 because 10 x 30 = 300
*/

int q1 (std::set <int> s) {
  int big = 1;
  int small = 100;
  for (int i : s) {
    if (i > big) {
      big = i;
    } 
    if (i < small) {
      small = i;
    }
  }
  return big * small;
}

/*
Question # 2:

Given a set, return the sum of all the even numbers subtracted by the sum of all the odd numbers in the set. Examples: 

{4, 7, 12, 9, 17} ➞ -17 because (4 + 12) - (7 + 9 + 17) = 16 - 33 = -17
{38, 72, 43} ➞ 67 because because (38 + 72) - 43 = 110 - 43 = 67
*/

int q2 (std::set <int> s) {
  int even = 0;
  int odd = 0;
  for (int i : s) {
    if (i % 2 == 0) {
      even += i;
    } else {
      odd += i;
    }
  }
  return even - odd;
}

/*
Question # 3:

Given a set of strings, delete all strings that contain the letter 'a' and return the resulting strings. Examples:

{apple, car, door, english, crab} ➞ {door, english}
{pebble, max, notebook, coins} ➞ {pebble, notebook, coins}
*/

std::set <std::string> q3 (std::set <std::string> s) {
  std::set <std::string> result;
  for (std::string i : s) {
    bool a = false;
    for (int j = 0; j < i.length(); j++) {
      if (i[j] == 'a') {
        a = true;
        break;
      }
    }
    if (a == false) {
      result.insert(i);
    }
  }
  return result;
}

/*
Question # 4:

Assume a set must have the numbers from 1 to 10. In this question, you will be given a set and must return a set with the missing numbers. Examples:

{1, 2, 3, 4, 5} ➞ {6, 7, 8, 9, 10}
{1, 3, 5, 6, 7, 8, 9} ➞ {2, 4, 10}
*/

std::set <int> q4 (std::set <int> s) {
  std::set <int> result;
  for (int i = 1; i <= 10; i++) {
    bool found = false;
    for (int j : s) {
      if (j == i) {
        found = true;
        break;
      }
    }
    if (found == false) {
      result.insert (i);
    }
  }
  return result;
}
