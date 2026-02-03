#include <iostream>

int main() {

  float mm;
  std::cout << "Enter a measurement in millimeters: ";
  std::cin >> mm;

  std:: cout << mm << " mm is equal to " << (mm / 10) << " cm.\n";  
  std:: cout << mm << " mm is equal to " << (mm / 1000) << " m.\n"; 
  std:: cout << mm << " mm is equal to " << (mm / 1000000) << " km.\n";  
  std:: cout << mm << " mm is equal to " << (mm / 25.4) << " in.\n"; 
  std:: cout << mm << " mm is equal to " << (mm / 304.8) << " ft.\n";  
  std:: cout << mm << " mm is equal to " << (mm / 914.4) << " yd.\n";  
  std:: cout << mm << " mm is equal to " << (mm / 1609344) << " mi.\n";  
  
}
