#include <iostream>
#include <cmath>

class new_math {

  private:

    double value;

  public:

    new_math (double v) {
      value = v;
    }

    double get_value () {
      return value;
    }

    new_math operator + (new_math number) {
      double result = (value + number.value) * (value + number.value);
      return new_math (result);
    }

    new_math operator - (new_math number) {
      double result = abs (value - number.value);
      return new_math (result);
    }

    new_math operator * (new_math number) {
      double result = sqrt (value * number.value);
      return new_math (result);
    }

    new_math operator / (new_math number) {
      double result = (value / number.value) * (value / number.value) * (value / number.value);
      return new_math (result);
    }

    void operator ++ () {
      double result = pow (value + 1, value + 1);
      value = result;
    }

    void operator -- () {
      double result = value - 1;
      for (int i = result - 1; i >= 1; i--) {
        result *= i;
      }
      value = result;
    }

};

int main() {

  int choice;
  double num1;
  double num2;

  std::cout << "\nWelcome to 'New Math'! Here are the rules: \n\n";
  std::cout << "1. addition (+): add the two numbers and then square the result. \n";
  std::cout << "2. subtraction (-): subtract the second number from the first and then take the absolute value of the result. \n";
  std::cout << "3. multiplication (*): multiply the two numbers and then take the square root of the result. \n";
  std::cout << "4. division (/): divide the first number by the second and then cube the result. \n";
  std::cout << "5. increment (++): add 1 to the number and then raise it to the power of itself. \n";
  std::cout << "6. decrement (--): subtract 1 from the number and then calculate the factorial of the result. \n";

  std::cout << "\nWhich operation would you like to perform? ";
  std::cin >> choice;

  if (choice == 1) {
    std::cout << "\nEnter the first number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    new_math m2 = new_math (num2);
    new_math result = m1 + m2;
    std::cout << "\nResult: " << result.get_value() << "\n";
  }

  else if (choice == 2) {
    std::cout << "\nEnter the first number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    new_math m2 = new_math (num2);
    new_math result = m1 - m2;
    std::cout << "\nResult: " << result.get_value() << "\n";
  }

  else if (choice == 3) {
    std::cout << "\nEnter the first number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    new_math m2 = new_math (num2);
    new_math result = m1 * m2;
    std::cout << "\nResult: " << result.get_value() << "\n";
  }

  else if (choice == 4) {
    std::cout << "\nEnter the first number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    new_math m2 = new_math (num2);
    new_math result = m1 / m2;
    std::cout << "\nResult: " << result.get_value() << "\n";
  }

  else if (choice == 5) {
    std::cout << "\nEnter a number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    ++ m1;
    std::cout << "\nResult: " << m1.get_value() << "\n";
  }

  else if (choice == 6) {
    std::cout << "\nEnter a number: ";
    std::cin >> num1;
    new_math m1 = new_math (num1);
    -- m1;
    std::cout << "\nResult: " << m1.get_value() << "\n";
  }

  else {
    std::cout << "\nInvalid option. \n";
  }
  
}
