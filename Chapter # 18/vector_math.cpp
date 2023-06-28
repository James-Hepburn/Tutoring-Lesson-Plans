#include <iostream>

class vector {

  private:

    double x;
    double y;
    double z;

  public:

    vector (double X, double Y, double Z) {
      x = X;
      y = Y;
      z = Z;
    }

    std::string print () {
      std::string result = "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
      return result;
    }

    vector operator + (vector v) {
      double new_x = x + v.x;
      double new_y = y + v.y;
      double new_z = z + v.z;
      return vector (new_x, new_y, new_z);
    }

    vector operator - (vector v) {
      double new_x = x - v.x;
      double new_y = y - v.y;
      double new_z = z - v.z;
      return vector (new_x, new_y, new_z);
    }

    vector operator * (vector v) {
      double new_x = (y * v.z) - (z * v.y);
      double new_y = (z * v.x) - (x * v.z); 
      double new_z = (x * v.y) - (y * v.x); 
      return vector (new_x, new_y, new_z);
    }

};

int main() {

  int choice;
  double x1, y1, z1, x2, y2, z2;
  
  std::cout << "\nWelcome to 'Vector Math'! Here are the choices: \n\n";
  std::cout << "1. Addition (+) \n";
  std::cout << "2. Subtraction (-) \n";
  std::cout << "3. Cross Product (*) \n";

  std::cout << "\nWhich operation would you like to perform? ";
  std::cin >> choice;

  if (choice == 1) {
    std::cout << "\nVector # 1 information: \n";
    std::cout << "x value: ";
    std::cin >> x1;
    std::cout << "y value: ";
    std::cin >> y1;
    std::cout << "z value: ";
    std::cin >> z1;
    vector v1 = vector (x1, y1, z1);
    std::cout << "\nVector # 2 information: \n";
    std::cout << "x value: ";
    std::cin >> x2;
    std::cout << "y value: ";
    std::cin >> y2;
    std::cout << "z value: ";
    std::cin >> z2;
    vector v2 = vector (x2, y2, z2);
    vector result = v1 + v2;
    std::cout << "\nResult: " << result.print() << "\n";
  }

  else if (choice == 2) {
    std::cout << "\nVector # 1 information: \n";
    std::cout << "x value: ";
    std::cin >> x1;
    std::cout << "y value: ";
    std::cin >> y1;
    std::cout << "z value: ";
    std::cin >> z1;
    vector v1 = vector (x1, y1, z1);
    std::cout << "\nVector # 2 information: \n";
    std::cout << "x value: ";
    std::cin >> x2;
    std::cout << "y value: ";
    std::cin >> y2;
    std::cout << "z value: ";
    std::cin >> z2;
    vector v2 = vector (x2, y2, z2);
    vector result = v1 - v2;
    std::cout << "\nResult: " << result.print() << "\n";
  }

  else if (choice == 3) {
    std::cout << "\nVector # 1 information: \n";
    std::cout << "x value: ";
    std::cin >> x1;
    std::cout << "y value: ";
    std::cin >> y1;
    std::cout << "z value: ";
    std::cin >> z1;
    vector v1 = vector (x1, y1, z1);
    std::cout << "\nVector # 2 information: \n";
    std::cout << "x value: ";
    std::cin >> x2;
    std::cout << "y value: ";
    std::cin >> y2;
    std::cout << "z value: ";
    std::cin >> z2;
    vector v2 = vector (x2, y2, z2);
    vector result = v1 * v2;
    std::cout << "\nResult: " << result.print() << "\n";
  }

  else {
    std::cout << "\nInvalid option. \n";
  }

}
