#include <iostream>

class matrix {

  private:

    double a, b, c, d;

  public:

    matrix (double A, double B, double C, double D) {
      a = A;
      b = B;
      c = C;
      d = D;
    }

    void print () {
      std::cout << "[" << a << ", " << b << "] \n";
      std::cout << "[" << c << ", " << d << "] \n";
    }

    matrix operator + (matrix m) {
      return matrix (a + m.a, b + m.b, c + m.c, d + m.d);
    }

    matrix operator - (matrix m) {
      return matrix (a - m.a, b - m.b, c - m.c, d - m.d);
    }

    matrix operator * (matrix m) {
      double new_a = (a * m.a) + (b * m.c);
      double new_b = (a * m.b) + (b * m.d);
      double new_c = (c * m.a) + (d * m.c);
      double new_d = (c * m.b) + (d * m.d);
      return matrix (new_a, new_b, new_c, new_d);
    }

};

int main() {

  int choice;
  double a1, b1, c1, d1, a2, b2, c2, d2;

  std::cout << "\nWelcome to 'Matrix Math'! Here are the choices: \n";
  std::cout << "1. Addition (+) \n";
  std::cout << "2. Subtraction (-) \n";
  std::cout << "3. Multiplication (*) \n";

  std::cout << "\nWhich operation do you want to perform? ";
  std::cin >> choice;

  if (choice == 1) {
    std::cout << "\nMatrix # 1 information: \n";
    std::cout << "a value: ";
    std::cin >> a1;
    std::cout << "b value: ";
    std::cin >> b1;
    std::cout << "c value: ";
    std::cin >> c1;
    std::cout << "d value: ";
    std::cin >> d1;
    matrix m1 = matrix (a1, b1, c1, d1);
    std::cout << "\nMatrix # 2 information: \n";
    std::cout << "a value: ";
    std::cin >> a2;
    std::cout << "b value: ";
    std::cin >> b2;
    std::cout << "c value: ";
    std::cin >> c2;
    std::cout << "d value: ";
    std::cin >> d2;
    matrix m2 = matrix (a2, b2, c2, d2);
    matrix result = m1 + m2;
    std::cout << "\nResult: \n";
    result.print();
  }

  else if (choice == 2) {
    std::cout << "\nMatrix # 1 information: \n";
    std::cout << "a value: ";
    std::cin >> a1;
    std::cout << "b value: ";
    std::cin >> b1;
    std::cout << "c value: ";
    std::cin >> c1;
    std::cout << "d value: ";
    std::cin >> d1;
    matrix m1 = matrix (a1, b1, c1, d1);
    std::cout << "\nMatrix # 2 information: \n";
    std::cout << "a value: ";
    std::cin >> a2;
    std::cout << "b value: ";
    std::cin >> b2;
    std::cout << "c value: ";
    std::cin >> c2;
    std::cout << "d value: ";
    std::cin >> d2;
    matrix m2 = matrix (a2, b2, c2, d2);
    matrix result = m1 - m2;
    std::cout << "\nResult: \n";
    result.print();
  }

  else if (choice == 3) {
    std::cout << "\nMatrix # 1 information: \n";
    std::cout << "a value: ";
    std::cin >> a1;
    std::cout << "b value: ";
    std::cin >> b1;
    std::cout << "c value: ";
    std::cin >> c1;
    std::cout << "d value: ";
    std::cin >> d1;
    matrix m1 = matrix (a1, b1, c1, d1);
    std::cout << "\nMatrix # 2 information: \n";
    std::cout << "a value: ";
    std::cin >> a2;
    std::cout << "b value: ";
    std::cin >> b2;
    std::cout << "c value: ";
    std::cin >> c2;
    std::cout << "d value: ";
    std::cin >> d2;
    matrix m2 = matrix (a2, b2, c2, d2);
    matrix result = m1 * m2;
    std::cout << "\nResult: \n";
    result.print();
  }

  else {
    std::cout << "\nInvalid option. \n";
  }
  
}
