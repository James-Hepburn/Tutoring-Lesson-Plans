#include <iostream>

class Location {

  public:

    std::string name;
    double area;

    void set_name (std::string n) {
      name = n;
    }

    void set_area (double a) {
      area = a;
    }

    void display_information () {
      std::cout << "\nLocation: " << name << "\n";
      std::cout << "  Area: " << area << "\n";
    }

};

class Continent : public Location {

  public:

    int countries_count;

    void set_countries_count (int cc) {
      countries_count = cc;
    }

    void display_information () {
      Location :: display_information();
      std::cout << "  Number of Countries: " << countries_count << "\n";
    }
    
};

class Country : public Location {

  public:

    std::string continent;

    void set_continent (std::string c) {
      continent = c;
    }

    void display_information () {
      Location :: display_information();
      std::cout << "  Continent: " << continent << "\n";
    }

};

class City : public Location {

  public:

    int population;

    void set_population (int p) {
      population = p;
    }

    void display_information () {
      Location :: display_information();
      std::cout << "  Population: " << population << "\n";
    }

};

int main() {

  Continent asia;
  asia.set_name ("Asia");
  asia.set_area (44580000);
  asia.set_countries_count (49);

  Continent africa;
  africa.set_name ("Africa");
  africa.set_area (30370000);
  africa.set_countries_count (54);

  Continent northAmerica;
  northAmerica.set_name ("North America");
  northAmerica.set_area (24709000);
  northAmerica.set_countries_count (23);
  
  Country china;
  china.set_name ("China");
  china.set_area (9596961);
  china.set_continent ("Asia");

  Country egypt;
  egypt.set_name ("Egypt");
  egypt.set_area (1001450);
  egypt.set_continent ("Africa");

  Country canada;
  canada.set_name ("Canada");
  canada.set_area (9984670);
  canada.set_continent ("North America");

  City beijing;
  beijing.set_name ("Beijing");
  beijing.set_area (16411);
  beijing.set_population (21707000);

  City cairo;
  cairo.set_name ("Cairo");
  cairo.set_area (606);
  cairo.set_population (20000000);

  City toronto;
  toronto.set_name ("Toronto");
  toronto.set_area (630.2);
  toronto.set_population (2731571);

  std::cout << "\nGeographical Information!\n\n";
  std::cout << "1) View Continent Information\n";
  std::cout << "2) View Country Information\n";
  std::cout << "3) View City Information\n";

  int selection;
  std::cout << "\nYour selection: ";
  std::cin >> selection;

  if (selection == 1) {
    std::cout << "\nContinent Information:\n\n";
    std::cout << "1) Asia\n";
    std::cout << "2) Africa\n";
    std::cout << "3) North America\n";
    
    int continent;
    std::cout << "\nYour selection: ";
    std::cin >> continent;

    if (continent == 1) {
      asia.display_information ();
    } else if (continent == 2) {
      africa.display_information ();
    } else if (continent == 3) {
      northAmerica.display_information ();
    } else {
      std::cout << "\nInvalid selection.\n";
    }
  } else if (selection == 2) {
    std::cout << "\nCountry Information:\n\n";
    std::cout << "1) China\n";
    std::cout << "2) Egypt\n";
    std::cout << "3) Canada\n";

    int country;
    std::cout << "\nYour selection: ";
    std::cin >> country;

    if (country == 1) {
      china.display_information ();
    } else if (country == 2) {
      egypt.display_information ();
    } else if (country == 3) {
      canada.display_information ();
    } else {
      std::cout << "\nInvalid selection.\n";
    }
  } else if (selection == 3) {
    std::cout << "\nCity Information:\n\n";
    std::cout << "1) Beijing\n";
    std::cout << "2) Cairo\n";
    std::cout << "3) Toronto\n";
    
    int city;
    std::cout << "\nYour selection: ";
    std::cin >> city;

    if (city == 1) {
      beijing.display_information ();
    } else if (city == 2) {
      cairo.display_information ();
    } else if (city == 3) {
      toronto.display_information ();
    } else {
      std::cout << "\nInvalid selection.\n";
    }
  } else {
    std::cout << "\nInvalid selection.\n";
  }

}
