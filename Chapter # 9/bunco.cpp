#include <iostream>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

class player {

  private:
  
    std::string name;
    int points;

  public:

    player (std::string n, int p) {
      name = n;
      points = p;
    }

    std::string get_name () {
      return name;
    }

    int get_points () {
      return points;
    }

    int roll_dice () {
      return (rand() % 6) + 1;
    }

    void increase () {
      points += 1;
    }

};

int main() {

  srand(time (0));
  
  std::cout << "\nWelcome to Bunco!\n\n";

  std::string name1;
  std::cout << "Player one, what is your name? ";
  std::cin >> name1;
  player p1 = player (name1, 0);

  std::string name2;
  std::cout << "Player two, what is your name? ";
  std::cin >> name2;
  player p2 = player (name2, 0);

  int rounds;
  std::cout << "How many rounds will you both be playing? ";
  std::cin >> rounds;

  std::cout << "\nGreat! Let's begin!\n";
  std::cin.get();

  for (int i = 1; i <= rounds; i++) {
    erase (3000000);
    std::cout << "\nRound # " << i << ":\n";

    std::cout << "\n" << p1.get_name() << "'s turn!\n";
    for (int j = 0; j < 3; j++) {
      std::cout << "\nPress enter to roll the dice: ";
      std::cin.get();
      int dice = p1.roll_dice();
      std::cout << "You rolled a " << dice << ".\n";
      if (dice == i) {
        std::cout << "You earned 1 point because it is round # " << i << ".\n";
        p1.increase();
      }
    }

    erase (3000000);
    std::cout << "\nRound # " << i << ":\n";

    std::cout << "\n" << p2.get_name() << "'s turn!\n";
    for (int j = 0; j < 3; j++) {
      std::cout << "\nPress enter to roll the dice: ";
      std::cin.get();
      int dice = p2.roll_dice();
      std::cout << "You rolled a " << dice << ".\n";
      if (dice == i) {
        std::cout << "You earned 1 point because it is round # " << i << ".\n";
        p2.increase();
      }
    }
     
  }

  erase (3000000);
  std::cout << "\n" << p1.get_name() << "'s points: " << p1.get_points() << "\n";
  std::cout << p2.get_name() << "'s points: " << p2.get_points() << "\n";

  if (p1.get_points() > p2.get_points()) {
    std::cout << "\n" << p1.get_name() << " has won!\n";
  } else if (p2.get_points() > p1.get_points()) {
    std::cout << "\n" << p2.get_name() << " has won!\n";
  } else {
    std::cout << "\nIt is a tie!\n";
  }

}
