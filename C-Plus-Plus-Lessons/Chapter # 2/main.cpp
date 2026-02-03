#include <iostream>

int main() {
  
  int age;
  std::cout << "How old are you? ";
  std::cin >> age;

  std::string license;
  std::cout << "Do you have a license? (y/n) ";
  std::cin >> license;

  if (age >= 16 && license == "y") { // or is ||
    std::cout << "You can drive!";
  } else if (age < 16) {
    std::cout << "You are too young to drive!";
  } else if (license == "n") {
    std::cout << "You do not have a license!";
  } else {
    std:: cout << "You entered something incorrect, try again!";
  }

  /*
  Question # 1:

  Create a program that takes three arguments prob, prize, pay and displays true if prob * prize > pay; otherwise display false. Examples:

  0.2, 50, 9 ➞ true
  0.9, 1, 2 ➞ false
  */

  std::cout << "\n\nQuestion # 1:\n";
  double prob, prize, pay;
  std::cout << "prob: ";
  std::cin >> prob;
  std::cout << "prize: ";
  std::cin >> prize;
  std::cout << "pay: ";
  std::cin >> pay;
  if (prob * prize > pay) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }

  /*
  Question # 2:

  Create a program that takes three integer arguments (a, b, c) and displays the amount of integers which are of equal value. Examples:

  3, 4, 3 ➞ 2
  1, 1, 1 ➞ 3
  3, 4, 1 ➞ 0
  */

  std::cout << "\n\nQuestion # 2:\n";
  int a, b, c;
  std::cout << "a: ";
  std::cin >> a;
  std::cout << "b: ";
  std::cin >> b;
  std::cout << "c: ";
  std::cin >> c;
  if (a == b && b == c) {
		std::cout << 3;
	} else if (a != b && b != c && a != c) {
		std::cout << 0;
	} else {
    std::cout << 2;
  }

  /*
  Question # 3:

  A bartender only serves drinks to people 18 and older and when he's not on break. Given the person's age, and whether break time is in session, create a program which displays whether he should serve drinks. Examples:

  20, no break -> true
  50, yes break -> false
  15, no break - > false
  */

  std::cout << "\n\nQuestion # 3:\n";
  int old;
  std::string break_time;
  std::cout << "age: ";
  std::cin >>old;
  std::cout << "on break (y/n): ";
  std::cin >> break_time;
  if (old >= 18 && break_time == "n") {
		std::cout << "yes";
	} else {
    std::cout << "no";
  } 

  /*
  Question # 4:

  Given a year, create a program that displays true if the year is a leap year and false otherwise. A year is a leap year if it is divisible by 4. However, if it is a century, then it must be divisible by 400. Examples:

  1600 ➞ true
  1924 ➞ true
  1900 ➞ false
  */

  std::cout << "\n\nQuestion # 4:\n";
  int year;
  std::cout << "Enter a year: ";
  std::cin >> year;
  if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
    std::cout << "leap year";
  } else {
    std::cout << "not a leap year";
  }

  /*
  Question # 5:

  Create a program that takes three values: hours, minutes and seconds. Display the value that is the longest. Examples:
  
  1, 59, 3598 ➞ 1
  2, 300, 15000 ➞ 300
  15, 955, 59400 ➞ 59400
  */

  std::cout << "\n\nQuestion # 5:\n";
  int h, m, s;
  std::cout << "Enter a time in hours: ";
  std::cin >> h;
  std::cout << "Enter a time in minutes: ";
  std::cin >> m;
  std::cout << "Enter a time in seconds: ";
  std::cin >> s;
  int temp_h = h * 3600;
  int temp_m = m * 60;
  if (temp_h > temp_m && temp_h > s) {
    std::cout << h;
  } else if (temp_m > temp_h && temp_m > s) {
    std::cout << m;
  } else {
    std::cout << s;
  }
  
}
