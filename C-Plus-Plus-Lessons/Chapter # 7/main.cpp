#include <iostream>
#include <vector>

int main() {

  // vectors - resizable arrays, cannot be printed

  // making a vector 

  std::vector <int> empty; // empty vector
  std::vector <std::string> letters = {"a", "b", "c", "d"};

  // getting elements

  std::string b = letters[1];
  std::cout << b << "\n";

  // adding elements

  letters.push_back ("e");
  std::string e = letters[4];
  std::cout << e << "\n";

  // changing elements

  letters[0] = "A";
  std::string a = letters[0];
  std::cout << a << "\n";

  // deleting elements

  letters.erase (letters.begin() + 1);
  std::string second = letters[1];
  std::cout << second << "\n";

  // getting size

  int len = letters.size();
  std::cout << len << "\n";

  // going through elements
  
  for (int i = 0; i < letters.size(); i++) {
    std::string current = letters[i];
    std::cout << current << " ";
  }
  
}

/*
Question # 1:

Create a method that takes a vector of numbers and returns an inverted vector. Examples:

[1, 2, 3, 4, 5] ➞ [-1, -2, -3, -4, -5]
[1, -2, 3, -4, 5] ➞ [-1, 2, -3, 4, -5]
*/

std::vector <int> invert (std::vector <int> arr) {
  std::vector <int> list;
  for (int i = 0; i < arr.size(); i++) {
    list.push_back (arr[i] * -1);
  }
  return list;
}

/*
Question # 2:

Take a vector of integers and return the sum of the absolute value of each element. Examples:

[2, -1, 4, 8, 10] ➞ 25
[-3, -4, -10, -2, -3] ➞ 22
*/

int absolute (std::vector <int> arr) {
  int total = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < 0) {
      arr[i] *= -1;
    }
    total += arr[i];
  }
  return total;
}

/*
Question # 3:

Create a method that takes in a vector and returns true if all elements in the vector are identical, and false otherwise. Examples:

["@", "@", "@", "@"] ➞ true
["&&", "&", "&&&"] ➞ false
*/

bool identical (std::vector <std::string> arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] != arr[i+1]) {
      return false;
    }
  }
  return true;
}

/*
Question # 4:

A vector is special if every even index contains an even number and every odd index contains an odd number. Create a method that returns true if a vector is special, and false otherwise. Examples:

[2, 7, 4, 9, 6, 1, 6, 3] ➞ true
[2, 7, 9, 1, 6, 1, 6, 3] ➞ false
*/

bool special (std::vector <int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] % 2 == 0 && i % 2 != 0) {
      return false;
    } else if (arr[i] % 2 != 0 && i % 2 == 0) {
      return false;
    }
  }
  return true;
}

/*
Question # 5:

Given a vector of directions to spin, "left" or "right", return an integer of how many full 360° rotations were made. Note that each word in the vector counts as a 90° rotation in that direction. Examples:

["right", "right", "right", "right", "left", "right"] ➞ 1
["left", "right", "left", "right"] ➞ 0
*/

int spins (std::vector <std::string> arr) {
  int total = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == "left") {
      total -= 90;
    } else {
      total += 90;
    }
  }
  return total / 360;
}
