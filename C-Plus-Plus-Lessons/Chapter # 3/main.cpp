#include <iostream>

// example 1 - void method

void print_animals () {
  std::cout << "\ngiraffee\n";
  std::cout << "tiger\n";
  std::cout << "hippo\n";
}

// example 2 - non void method

bool same_information (std::string name1, std::string name2, int age1, int age2) {
  if (name1 == name2 && age1 == age2) {
    return true;
  } else {
    return false;
  }
}

int main() {

  // calling example 1

  print_animals ();

  // calling example 2

  // 1 == true and 0 == false

  std::cout << same_information("John", "John", 32, 32) << "\n";
  std::cout << same_information("John", "Alex", 32, 32) << "\n";
  std::cout << same_information("John", "John", 14, 32) << "\n";

}

/*
Question # 1:

Given the number of chickens, cows and pigs a farmer owns, create a method that returns the total number of legs for the animals. Examples:

2, 3, 5 ➞ 36
1, 2, 3 ➞ 22
5, 2, 8 ➞ 50
*/

int animals (int chickens, int cows, int pigs) {
  return (chickens * 2) + (cows * 4) + (pigs * 4);
}

/*
Question # 2:

Create a method that takes the number of wins, draws and losses and calculates the number of points a football team has obtained so far if wins get 3 points, draws get 1 point and losses get 0 points. Examples:

3, 4, 2 ➞ 13
5, 0, 2 ➞ 15
0, 0, 1 ➞ 0
*/

int football (int wins, int draws, int losses) {
  return (wins * 3) + draws;
}

/*
Question # 3:

Given the total number of slices of a pie, the number of people and the number of slices each person gets, create a method that returns one of the three possibilities:

^ "perfect" if there are exactly enough slices
^ "plenty" if there are more than enough slices
^ "insufficient" if there are not enough slices

Examples:

11, 5, 2 ➞ "plenty" because 5 people x 2 slices each = 10 slices < 11 slices
11, 5, 3 ➞ "insufficient" because 5 people x 3 slices each = 15 slices > 11 slices
8, 4, 2 ➞ "perfect" because 4 people x 2 slices each = 8 slices = 8 slices
*/

std::string slices (int total, int people, int slices) {
  if (total == people * slices) {
    return "perfect";
  } else if (total < people * slices) {
    return "insufficient";
  } else {
    return "plenty";
  }
}

/*
Question # 4:

Given three numbers in a random order - a father's age, a mother's age and a child's age, create a method that returns true if the difference between the father's and mother's age is less than  or equal to 5 years. Examples:

45, 39, 4 ➞ false
2, 25, 22 ➞ true
60, 23, 55 ➞ true
*/

bool ages (int a, int b, int c) {
  if (a >= b && a >= c) {
    if (b > c && a - b <= 5) {
      return true;
    } else if (c > b && a - c <= 5) {
      return true;
    } else {
      return false;
    }
  } else if (b >= a && b >= c) {
    if (a > c && b - a <= 5) {
      return true;
    } else if (c > a && b - c <= 5) {
      return true;
    } else {
      return false;
    }
  } else {
    if (a > b && c - a <= 5) {
      return true;
    } else if (b > a && c - b <= 5) {
      return true;
    } else {
      return false;
    }
  }
}
