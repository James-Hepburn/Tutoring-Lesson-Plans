#include <iostream>
#include <vector>
#include <stdexcept>

int divide (int number1, int number2) {
  if (number2 == 0) {
    throw std::runtime_error ("You can't divide by 0");
  } else if (number1 < 0 || number2 < 0) {
    throw std::logic_error ("You can't use negative numbers");
  }
  return number1 / number2;
}

int main() {

  /*
  types of errors:

    - run time error = errors that are detectable only during runtime, such as logical errors or external conditions (division by 0, accessing invalid memory, file input / output errors, etc) (detected by program)
    
    - logic error = errors that are caused by mistakes in the program's logic or flow (incorrect calculations, wrong conditions in if statements, incorrect loops, etc) (detected by user)
    
    - invalid argument = errors caused by providing invalid arguments to a function or constructor
    
    - out of range = errors caused by accessing elements out of the valid range, such as indices of arrays or containers
  */

  // 1. throwing an exception - when an error occurs, you can throw an exception
  // 2. catching an exception - to handle an exception, you use a try-catch block
  // 3. handling different exceptions - you can use multiple catch blocks

  int number1;
  std::cout << "Enter the first number: ";
  std::cin >> number1;

  int number2;
  std::cout << "Enter the second number: ";
  std::cin >> number2;

  try {
    int result = divide (number1, number2);
    std::cout << number1 << " / " << number2 << " = " << result << "\n";
  } catch (const std::runtime_error& e) {
    std::cout << "Runtime error: " << e.what() << "\n";
  } catch (const std::logic_error& e) {
    std::cout << "Logic error: " << e.what() << "\n";
  }
  
}

/*
Question # 1:

Create a method that calculates the factorial of a number. If the input is negative, throw an exception. Examples:

factorial (4) = 24 because 4 * 3 * 2 * 1
factorial (3) = 6 because 3 * 2 * 1
factorial (-2) = error
*/

int factorial (int n) {
  if (n < 0) {
    throw std::runtime_error ("You can't use negative numbers");
  }
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

/*
Question # 2:

Create a method that checks if a word is a palindrome. If the input is empty, throw an exception. Examples:

palindrome ("racecar") -> true because racecare backwards is racecar
palindrome ("cat") -> false because cat backwards is tac
palindrome ("") -> error
*/

bool palindrome (std::string word) {
  if (word.length() == 0) {
    throw std::logic_error ("You can't use empty strings");
  }
  std::string reverse;
  for (int i = word.length() - 1; i >= 0; i--) {
    reverse += word[i];
  }
  return reverse == word;
}

/*
Question # 3:

Given a vector of different ages, create a method that returns the average. If the vector is empty or any of the ages are negative, throw an error. Examples:

average ([10, 45, 50, 20]) -> 31.25 because (10 + 45 + 50 + 20) / 4 = 31.25
average ([]) -> error
average ([23, 90, 56, -3, 8]) -> error
*/

double average (std::vector <int> ages) {
  if (ages.size() == 0) {
    throw std::logic_error ("You can't use empty vectors"); 
  }
  int total = 0;
  for (int i = 0; i < ages.size(); i++) {
    if (ages[i] <= 0) {
      throw std::out_of_range ("You can't use negative ages");
    }
    total += ages[i];
  }
  return static_cast<double> (total) / ages.size();
}
