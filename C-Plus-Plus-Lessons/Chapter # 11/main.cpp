#include <iostream>
#include <vector>

// example 1 - factorial

int factorial (int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// example 2 - fibonacci

int fibonacci (int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci (n - 1) + fibonacci (n - 2);
  }
}

int main() {

  // recurssion: a method that calls itself

  /*
  factorial example:

  n = 5 then factorial (5) = 5*4*3*2*1 = 120
  n = 3 then factorial (3) = 3*2*1 = 6
  n = 1 then factorial (1) = 1
  n = 0 then factorial (0) = 1
  */

  std::cout << "\nexample 1 - factorial\n";
  std::cout << factorial (5) << "\n";
  std::cout << factorial (3) << "\n";
  std::cout << factorial (1) << "\n";
  std::cout << factorial (0) << "\n";

  /*
  fibonacci example:

  n = 1 then fibonacci (1) = 1
  n = 2 then fibonacci (2) = 1
  n = 6 then fibonacci (6) = 8
  n = 4 then fibonacci (4) - 3
  */

  std::cout << "\nexample 2 - factorial\n";
  std::cout << fibonacci (1) << "\n";
  std::cout << fibonacci (2) << "\n";
  std::cout << fibonacci (6) << "\n";
  std::cout << fibonacci (4) << "\n";

  /*
  tracing:

  factorial (5) = 5 * factorial (4) = 5 * 24 = 120
  factorial (4) = 4 * factorial (3) = 4 * 6 = 24
  factorial (3) = 3 * factorial (2) = 3 * 2 = 6
  factorial (2) = 2 * factorial (1) = 2 * 1 = 2
  factorial (1) = 1

  fibonacci (6) = fibonacci (5) + fibonacci (4) = 5 + 3 = 8
  fibonacci (5) = fibonacci (4) + fibonacci (3) = 3 + 2 = 5
  fibonacci (4) = fibonacci (3) + fibonacci (2) = 2 + 1 = 3
  fibonacci (3) = fibonacci (2) + fibonacci (1) = 1 + 1 = 2
  fibonacci (2) = 1
  fibonacci (1) = 1
  */

}
