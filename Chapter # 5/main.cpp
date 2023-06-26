#include <iostream>

int main() {

  // example 1 - while a condition is true

  std::string input;
  while (input != "yes") {
    std::cout << "Enter 'yes' to continue: ";
    std::cin >> input;
  }

  // example 2 - until break

  while (true) {
    int answer;
    std::cout << "What is 2 + 1? ";
    std::cin >> answer;
    if (answer == 3) {
      std::cout << "Correct!\n";
      break;
    } else {
      std::cout << "Incorrect.\n";
    }
  }
  
}

/*
Question # 1:

Create a method that uses a while loop to sum all of the square numbers up to and including the number you are given. Examples

3 ➞ 14 because 1² + 2² + 3² = 14
12 ➞ 650 because 1² + 2² + 3² + 4² + 5² + 6² + 7² + 8² + 9² + 10² + 11² + 12² = 650
13 ➞ 819 because 1² + 2² + 3² + 4² + 5² + 6² + 7² + 8² + 9² + 10² + 11² + 12² + 13² = 819
*/

int sum_squared (int n) {
  int total = 0;
  while (n > 0) {
    total += (n * n);
    n -= 1;
  }
  return total;
}

/*
Question # 2:

Create a method, that will for a given a, b, c, do the following:
  ^ Add a to itself b times.
  ^ Check if the result is divisible by c.
Examples:

42, 5, 10 ➞ false because 42+42 = 84, 84+84 = 168, 168+168 = 336, 336+336 = 672, 672+672 = 1344 and 1344 is not divisible by 10
5, 2, 1 ➞ true because 5+5 = 10, 10+10 = 20 and 20 is divisible by 1
1, 2, 3 ➞ false 1+1 = 2, 2+2 = 4 and 4 is not divisible by 3
*/

bool abc_math (int a , int b, int c) {
  while (b > 0) {
    a += a;
    b -= 1;
  }
  return a % c == 0;
}

/*
Question # 3:

Consider the following operations:
  ^ If n is even -> n / 2
  ^ If n is odd -> n * 3 + 1
Create a method to repeatedly evaluate these operations, until reaching 1. Return the number of steps it took. Examples:

2 ➞ 1 because 
  ^ 2 is even and 2 / 2 = 1 -> 1 step
3 ➞ 7 because 
  ^ 3 is odd and 3 * 3 + 1 = 10
  ^ 10 is even and 10 / 2 = 5
  ^ 5 is odd and 5 * 3 + 1 = 16
  ^ 16 is even and 16 / 2 = 8
  ^ 8 is even and 8 / 2 = 4
  ^ 4 is even and 4 / 2 = 2
  ^ 2 is even and 2 / 2 = 1 -> 7 step
10 ➞ 6
  ^ 10 is even and 10 / 2 = 5
  ^ 5 is odd and 5 * 3 + 1 = 16
  ^ 16 is even and 16 / 2 = 8
  ^ 8 is even and 8 / 2 = 4
  ^ 4 is even and 4 / 2 = 2
  ^ 2 is even and 2 / 2 = 1 -> 6 step
*/

int steps (int n) {
  int count = 0;
  while (n != 1) {
    count += 1;
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
  }
  return count;
}

/*
Question 4:

Create a method that uses a while loop to compute the nth number in the fibonacci sequence. Examples:

3 ➞ 2
7 ➞ 13 
12 ➞ 144
*/

int fib (int n) {
  int total = 0;
  int a = 1;
  int b = 1;
  if (n == 1 || n == 2) {
    return 1;
  }
  while (n > 2) {
    total = a + b;
    a = b;
    b = total;
    n -= 1;
  }
  return total;
}
