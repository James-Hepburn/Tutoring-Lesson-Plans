#include <iostream>

int main() {

  /*
  rules:

  - no adding elements
  - no deleting elements
  - fixed size
  - no printing array
  - issues when passing an array to a method 
  */

  // making an array

  int empty [5]; // empty array of size 5
  std::string languages [] = {"Python", "Java", "C++"};

  // getting elements

  std::string python = languages [0];

  // changing elements

  languages [1] = "JavaScript";

  // getting size

  int len1 = sizeof(languages); // number of bytes -> incorrect
  int len2 = sizeof(languages) / sizeof (std::string); // divided by type

  // going through all the elements

  for (int i = 0; i < len2; i++) {
    std::string current = languages [i];
    std::cout << current << "\n";
  }
  
}

/*
Question # 1:

Create a method that return the sum of all items in an array, where each item is multiplied by its index. Examples:

[1, 2, 3, 4, 5] ➞ 40 because 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 40
[-3, 0, 8, -6] ➞ -2 because -3*0 + 0*1 + 8*2 + -6*3 = -2
*/

int multiplier (int arr [], int len) {
  int total = 0;
  for (int i = 0; i < len; i++) {
    total += (i * arr[i]);
  }
  return total;
}

/*
Question # 2:

Create a method that takes a char array of either Ts or Fs. For every T, add "1" to a string. For every F, add "0" to a string. Return the resulting string. Examples:

['T', 'F'] ➞ "10"
['F', 'F', 'T'] ➞ "001"
*/

std::string bit (char arr [], int len) {
  std::string s;
  for (int i = 0; i < len; i++) {
    if (arr[i] == 'T') {
      s += "1";
    } else {
      s += '0';
    }
  }
  return s;
}

/*
Question # 3:

Write a method that returns true if there exists at least one number that is larger than n. Examples:

[5, 3, 15, 22, 4], 10 ➞ true
[1, 2, 3, 4, 5], 8 ➞ false
*/

bool larger (int arr [], int n, int len) {
  for (int i = 0; i < len; i++) {
    if (arr[i] > n) {
      return true;
    }
  }
  return false;
}

/*
Question # 4:

Create a method that takes an array of numbers and return the maximum minus the minimum. Examples:

[1, 2, 3, 4, 5] ➞ 4 because 5 - 1 = 4
[200, 5] ➞ 195 because 200 - 5
*/

int min_max (int arr [], int len) {
  int min = arr[0];
  int max = arr[0];
  for (int i = 0; i < len; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return max - min;
}
