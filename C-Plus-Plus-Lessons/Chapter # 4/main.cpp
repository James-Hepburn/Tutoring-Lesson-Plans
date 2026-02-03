#include <iostream>

int main() {
  
  // example 1 - range of numbers

  for (int i = 1; i < 6; i++) {
    std::cout << "Repeat # " << i << "\n";
  }

  // example 2 - strings

  std::string word = "hello";
  for (int i = 0; i < word.length(); i++) {
    std::cout << word.at(i) << "\n";
  }
  
}

/*
Question # 1:

Create a method that takes a string and returns the car that's in first place. The road will be made of "=", and cars will be represented by letters in the alphabet. Examples:

"====b===O===e===U=A==" ➞ 'A'
"e==B=Fe" ➞ 'e'
"=n==fl" ➞ 'l'
*/

char first_place (std::string str) {
  for (int i = str.length() - 1; i > -1; i--) {
    if (str.at(i) != '=') {
      return str.at(i);
    }
  }
  return '=';
}

/*
Question # 2:

Create a method that takes a number n and returns the first 10 multiples of n with 1 added to it, separated by commas.Examples:

7 ➞ "8,15,22,29,36,43,50,57,64,71"
1 ➞ "2,3,4,5,6,7,8,9,10,11"
3 ➞ "4,7,10,13,16,19,22,25,28,31"
*/

std::string n_plus_one (int n) {
  std::string str = "";
  int temp = n + 1;
  for (int i = 1; i < 11; i++) {
    str += std::to_string(temp);
    temp += n;
    if (i != 10) {
      str += ",";
    }
  }
  return str;
}

/*
Question # 3:

Create a method that takes a character and returns its order in the alphabet. Examples:

"a" -> 1
"z" -> 26
"e" -> 5  
*/

int alphabet (char c) {
  std::string letters = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    if (c == letters.at(i)) {
      return i + 1;
    }
  }
  return -1;
}

/*
Question # 4:

Imagine a messaging device with only one button. For the letter A, you press the button one time, for E, you press it five times, for G, it's pressed seven times, etc. Write a method that takes a string and returns the total number of times the button is pressed. Examples:

"abde" ➞ 12
"azy" ➞ 52
"qudusayo" ➞ 123
*/

int button (std::string str) {
  int total = 0;
  for (int i = 0; i < str.length(); i++) {
    total += alphabet (str.at(i));
  }
  return total;
}

/*
Question # 5:

Create a method that takes a base number and an exponent number and returns the calculation. Examples:

5, 4 ➞ 625
10, 2 ➞ 100
3, 3 ➞ 27
*/

int power (int base, int exponent) {
  int total = 1;
  for (int i = 0; i < exponent; i++) {
    total *= base;
  }
  return total;
}
