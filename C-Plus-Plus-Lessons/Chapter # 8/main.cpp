#include <iostream>
#include <vector>

int main() {
  
  // making a 2d vector

  std::vector <std::vector <int>> empty;
  std::vector <std::vector <std::string>> list = {{"a", "b", "c"}, {"d", "e"}, {"f"}};

  // adding inner list

  std::vector <std::string> temp = {"g", "h"};
  list.push_back (temp);

  // adding element to specific innner list

  list[3].push_back ("i");

  // changing elements

  list[0][2] = "z"; // c to z

  // getting size

  int len1 = list.size(); // 4 inner lists
  int len2 = list[2].size(); // size of list[2]

  // iterating through elements

  for (int i = 0; i < list.size(); i++) {
    std::vector <std::string> current_list = list[i];
    for (int j = 0; j < current_list.size(); j++) {
      std::string current_element = current_list[j];
      std::cout << current_element << "\n";
    }
  }
  
}

/*
Question # 1:

Create a method to calculate the determinant of a 2 * 2 vector. The determinant of the following vector is: ad - bc where vector = [[a, b], [c, d]]. Examples:

[[1, 2], [3, 4]] ➞ -2
[[5, 3], [3, 1]] ➞ -4
*/

int determinant (std::vector <std::vector<int>> matrix) {
  return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

/*
Question # 2:

Create a method to count the number of 1s in a 2D vector. Examples:

[[1, 0], [0, 0]] ➞ 1
[[1, 1, 1], [0, 0, 1], [1, 1, 1]] ➞ 7
*/

int ones (std::vector <std::vector<int>> list) {
  int count = 0;
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].size(); j++) {
      if (list[i][j] == 1) {
        count += 1;
      }
    }
  }
  return count;
}

/*
Question # 3:

Suppose an image can be represented as a 2D array of 0s and 1s. Write a method to reverse an image. Replace the 0s with 1s and vice versa. Examples:

[[1, 0, 0], [0, 1, 0], [0, 0, 1]] ➞ [[0, 1, 1], [1, 0, 1], [1, 1, 0]]
[[1, 1, 1], [0, 0, 0]] ➞ [[0, 0, 0], [1, 1, 1]]
*/

std::vector <std::vector<int>> rev (std::vector <std::vector<int>> list) {
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].size(); j++) {
      if (list[i][j] == 1) {
        list[i][j] = 0;
      } else {
        list[i][j] = 1;
      }
    }
  }
  return list;
}

/*
Question # 4:

Given a square matrix, its trace is the sum of the entries in the main diagonal (i.e. the diagonal line from the top left to the bottom right). Write a method that takes a square matrix and computes its trace. Examples:

[[1, 4], [4, 1]] ➞ 2 because 1 + 1 = 2
[[1, 2, 3], [4, 5, 6], [7, 8, 9]] ➞ 15 because 1 + 5 + 9 = 15
*/

int trace (std::vector <std::vector<int>> list) {
  int count = 0;
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].size(); j++) {
      if (i == j) {
        count += list[i][j];
      }
    }
  }
  return count;
}

/*
Question # 5:

Two sisters are eating chocolate, whose pieces are represented as inner vectors of [l x w]. Write a method that returns true if the total area of chocolate is the same for each sister. Examples:

[[1, 2], [2, 1]] and [[2, 2]] ➞ true because 1*2 + 2*1 = 4 and 2*2 = 4 
[[1, 2], [2, 1]] and [[2, 2], [4, 4]] ➞ false because 1*2 + 2*1 = 4 and 2*2 + 4*4 = 18
*/

bool chocolate (std::vector<std::vector<int>> sis1, std::vector<std::vector<int>> sis2) {
  int count1 = 0;
  for (int i = 0; i < sis1.size(); i++) {
    count1 += sis1[i][0] * sis1[i][1];
  }
  int count2 = 0;
  for (int i = 0; i < sis2.size(); i++) {
    count2 += sis2[i][0] * sis2[i][1];
  }
  return count1 == count2;
}
