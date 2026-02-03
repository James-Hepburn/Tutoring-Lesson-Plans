#include <iostream>
#include <vector>

class Bird {
  protected:
    std::string location;
  public:
    void set_location(std::string l) {
      location = l;
    }
    void display () {
      std::cout << "Uknown bird spotted at " << location << ".\n";
    }
};

class BlueJay : public Bird {
  protected:
    std::string gender;
  public:
    void set_gender(std::string g) {
      gender = g;
    }
    void display () {
      std::cout << "Blue Jay spotted at " << location << ". Gender: " << gender << ".\n";
    }
};

class Parrot : public Bird {
  protected:
    std::string colour;
  public:
    void set_colour(std::string c) {
      colour = c;
    }
    void display () {
      std::cout << "Parrot spotted at " << location << ". Colour: " << colour << ".\n";
    }
};

class Duck : public Bird {
  protected:
    std::string age;
  public:
    void set_age(std::string a) {
      age = a;
    }
    void display () {
      std::cout << "Duck spotted at " << location << ". Age: " << age << ".\n";
    }
};

int main() {

  std::vector <Bird> unknown;
  std::vector <BlueJay> bluejay;
  std::vector <Parrot> parrot;
  std::vector <Duck> duck;

  while (true) {
    std::cout << "\n1) add a bird \n";
    std::cout << "2) view all birds \n";
    std::cout << "3) exit \n";
    int selection;
    std::cout << "\nWhich option do you want to select? ";
    std::cin >> selection;

    if (selection == 1) {
      std::string location;
      std::cout << "\nWhat is the bird's location? ";
      std::cin >> location;
      std::string species;
      std::cout << "\nWhat is the bird's species? (Unknown, BlueJay, Parrot or Duck) ";
      std::cin >> species;
      if (species == "Unknown") {
        Bird b;
        b.set_location(location);
        unknown.push_back(b);
      } else if (species == "BlueJay") {
        BlueJay b;
        b.set_location(location);
        std::string gender;
        std::cout << "\nWhat is the bird's gender? ";
        std::cin >> gender;
        b.set_gender(gender);
        bluejay.push_back(b);
      } else if (species == "Parrot") {
        Parrot b;
        b.set_location(location);
        std::string colour;
        std::cout << "\nWhat is the bird's colour? ";
        std::cin >> colour;
        b.set_colour(colour);
        parrot.push_back(b);
      } else if (species == "Duck") {
        Duck b;
        b.set_location(location);
        std::string age;
        std::cout << "\nWhat is the bird's age? ";
        std::cin >> age;
        b.set_age(age);
        duck.push_back(b);
      } else {
        std::cout << "\nInvalid bird species. Please try again.\n";
      }
    } else if (selection == 2) {
      std::cout << "\nUnknown Species:\n";
      for (int i = 0; i < unknown.size(); i++) {
        unknown[i].display();
      }
      std::cout << "\nBlue Jay Species:\n";
      for (int i = 0; i < bluejay.size(); i++) {
        bluejay[i].display();
      }
      std::cout << "\nParrot Species:\n";
      for (int i = 0; i < parrot.size(); i++) {
        parrot[i].display();
      }
      std::cout << "\nDuck Species:\n";
      for (int i = 0; i < duck.size(); i++) {
        duck[i].display();
      }
    } else if (selection == 3) {
      std::cout << "\nGoodbye.\n";
      break;
    } else {
      std::cout << "Invalid input. Please try again.\n";
    }
  } 
    
}
