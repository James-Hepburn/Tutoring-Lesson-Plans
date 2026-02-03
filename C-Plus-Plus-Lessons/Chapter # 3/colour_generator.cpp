#include <iostream>

std::string s;
std::string colour;

void red () {
  std::cout << "\n" << s << s << s << s << s << "\n"; 
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << s << "\n";
  std::cout << s << "  " << s << "\n"; 
  std::cout << s << "    " << s << "\n"; 
  std::cout << s << "      " << s << "\n\n"; 

  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n\n"; 

  std::cout << s << s << s << s << "\n"; 
  std::cout << s << "      " << s << "\n"; 
  std::cout << s << "      " << s << "\n"; 
  std::cout << s << "      " << s << "\n"; 
  std::cout << s << "      " << s << "\n";  
  std::cout << s << s << s << s << "\n\n"; 
}

void blue () {
  std::cout << "\n" << s << s << s << s << "\n"; 
  std::cout << s << "      " << s << "\n"; 
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << "\n"; 
  std::cout << s << "      " << s << "\n"; 
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << "\n\n"; 

  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n\n";

  std::cout << s << "      " << s << "\n";
  std::cout << s << "      " << s << "\n";
  std::cout << s << "      " << s << "\n";
  std::cout << s << "      " << s << "\n";
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << s << "\n\n";

  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n\n"; 
}

void green () {
  std::cout << "\n" << s << s << s << s << s << "\n";
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << "  " << s << s << s << "\n";
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << s << "\n\n"; 

  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "      " << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << s << "\n";
  std::cout << s << "  " << s << "\n"; 
  std::cout << s << "    " << s << "\n"; 
  std::cout << s << "      " << s << "\n\n"; 

  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n\n";

  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n"; 
  std::cout << s << "\n";
  std::cout << s << "\n";
  std::cout << s << s << s << s << s << "\n\n";

  std::cout << s << s << "    " << s << "\n";
  std::cout << s << " " << s << "   " << s << "\n";
  std::cout << s << "  " << s << "  " << s << "\n";
  std::cout << s << "   " << s << " " << s << "\n";
  std::cout << s << "    " << s << s << "\n";
  std::cout << s << "      " << s << "\n\n";
  
}

int main() {

  std::cout << "\nEnter a symbol: ";
  std::cin >> s;

  std::cout << "\nBlue, red or green? ";
  std::cin >> colour;

  if (colour == "blue") {
    s = "\033[1;34m" + s + " " + "\033[0m";
    blue ();
  }

  else if (colour == "red") {
    s = "\033[1;31m" + s + " " + "\033[0m";
    red ();
  }

  else if (colour == "green") {
    s = "\033[1;32m\033[38;5;22m" + s + " " + "\033[0m";
    green ();
  }
  
}
