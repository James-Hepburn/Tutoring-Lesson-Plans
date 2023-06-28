#include <iostream>

class two_dimensional {
  protected:
    std::string name;
  public:
    void set_name (std::string n) {
      name = n;
    }
    void area () {
      std::cout << "\nThe area of " << name << " is unknown.\n";    
    }
    void perimeter () {
      std::cout << "The perimeter of " << name << " is unknown.\n";    
    }
};

class square : public two_dimensional {
  protected:
    int side;
  public:
    void set_side (int s) {
      side = s;
    }
    void area () {
      std::cout << "\nThe area of " << name << " is " << side * side << ".\n";    
    }
    void perimeter () {
      std::cout << "The perimeter of " << name << " is " << side * 4 << ".\n";    
    }
};

class circle : public two_dimensional {
  protected:
    int radius;
  public:
    void set_radius (int r) {
      radius = r;
    }
    void area () {
      std::cout << "\nThe area of " << name << " is " << 3.14 * radius * radius << ".\n";    
    }
    void perimeter () {
      std::cout << "The perimeter of " << name << " is " << 2 * 3.14 * radius << ".\n";    
    }
};

class three_dimensional {
  protected:
    std::string name;
  public:
    void set_name (std::string n) {
      name = n;
    }
    void volume () {
      std::cout << "\nThe volume of " << name << " is unknown.\n";    
    }
};

class cube : public three_dimensional {
  protected:
    int side;
  public:
    void set_side (int s) {
      side = s;
    }
    void volume () {
      std::cout << "\nThe volume of " << name << " is " << side * side * side << ".\n";    
    }
};

class sphere : public three_dimensional {
  protected:
    int radius;
  public:
    void set_radius (int r) {
      radius = r;
    }
    void volume () {
      std::cout << "\nThe volume of " << name << " is " << 1.3 * 3.14 * radius * radius * radius << ".\n";    
    }
};

int main() {

  std::string dimension;
  std::cout << "Would you like to calculate a 2D or 3D shape? ";
  std::cin >> dimension;

  if (dimension == "2D") {
    std::string shape;
    std::cout << "\nWould you like to use a square or a circle? ";
    std::cin >> shape;
    if (shape == "square") {
      square s;
      std::string name;
      std::cout << "\nWhat is the name of the square? ";
      std::cin >> name;
      s.set_name (name);
      int side;
      std::cout << "What is the side length of the square? ";
      std::cin >> side;
      s.set_side (side);
      s.area ();
      s.perimeter ();
    } else if (shape == "circle") {
      circle c;
      std::string name;
      std::cout << "\nWhat is the name of the circle? ";
      std::cin >> name;
      c.set_name (name);
      int radius;
      std::cout << "What is the radius of the circle? ";
      std::cin >> radius;
      c.set_radius (radius);
      c.area ();
      c.perimeter ();
    } else {
      std::cout << "\nInvalid choice.\n";
    }
  } else if (dimension == "3D") {
    std::string shape;
    std::cout << "\nWould you like to use a sphere or a cube? ";
    std::cin >> shape;
    if (shape == "sphere") {
      sphere s;
      std::string name;
      std::cout << "\nWhat is the name of the sphere? ";
      std::cin >> name;
      s.set_name (name);
      int radius;
      std::cout << "What is the radius of the sphere? ";
      std::cin >> radius;
      s.set_radius (radius);
      s.volume ();
    } else if (shape == "cube") {
      cube c;
      std::string name;
      std::cout << "\nWhat is the name of the cube? ";
      std::cin >> name;
      c.set_name (name);
      int side;
      std::cout << "What is the side length of the circle? ";
      std::cin >> side;
      c.set_side (side);
      c.volume ();
    } else {
      std::cout << "\nInvalid choice.\n";
    }
  } else {
    std::cout << "\nInvalid choice.\n";
  }
   
}
