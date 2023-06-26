#include <iostream>

class new_math {

  private:

    int value;

  public:

    new_math (int v) {
      value = v;
    }

    new_math operator + (new_math number) { 
      return new_math ((value + number.value) * 2);
    }

    new_math operator - (new_math number) {
      return new_math ((value - number.value) / 3);
    }

    int get_value () {
      return value;
    }

};

int main() {

  // operating overloading allows you to redefine the behaviour of an operator

  new_math m1 = new_math (9);
  new_math m2 = new_math (3);
  
  new_math sum = m1 + m2;
  std::cout << "The 'sum' is " << sum.get_value() << "\n";

  new_math difference = m1 - m2;
  std::cout << "The 'difference' is " << difference.get_value() << "\n";

  // exercise: try coding multiplication so that the two numbers are multiplied together and then subtract 5
  // exercise: try coding division so that the two numbers are divided together and then add 7
}
