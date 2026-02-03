#include <iostream>

int dice () {
  srand(time (0));
  return (rand() % 6) + 1;
}

int main() {

  std::cout << "\nWelcome to the Dice Game!\n";
  std::cout << "\nHere is how to play:\n";
  std::cout << "\nRoll two dice and add the numbers together. Add the total to your overall score. If you roll doubles, your score is instantly wiped to 0. Whichever player, has the most points after three rounds, wins.\n";

  int p1 = 0;
  int p2 = 0;
  int round = 1;

  while (round <= 3) {
    std::cout << "\nRound # " << round << ":\n\n";
    round += 1;
    
    std::string p1_dice1;
    while (p1_dice1 != "1") {
      std::cout << "Player 1, enter '1' to roll the first dice: ";
      std::cin >> p1_dice1;
    }
    int roll1 = dice();
    std::cout << "Player 1 rolled a " << roll1 << ".\n";
    std::string p1_dice2;
    while (p1_dice2 != "2") {
      std::cout << "Player 1, enter '2' to roll the second dice: ";
      std::cin >> p1_dice2;
    }
    int roll2 = dice();
    std::cout << "Player 1 rolled a " << roll2 << ".\n";
    if (roll1 == roll2) {
      std::cout << "Player 1 rolled doubles!\n";
      p1 = 0;
    } else {
      p1 += roll1 + roll2;
    }
    std::cout << "Player 1's new score is " << p1 << "!\n\n";

    std::string p2_dice1;
    while (p2_dice1 != "1") {
      std::cout << "Player 2, enter '1' to roll the first dice: ";
      std::cin >> p2_dice1;
    }
    int roll3 = dice();
    std::cout << "Player 2 rolled a " << roll3 << ".\n";
    std::string p2_dice2;
    while (p2_dice2 != "2") {
      std::cout << "Player 2, enter '2' to roll the second dice: ";
      std::cin >> p2_dice2;
    }
    int roll4 = dice();
    std::cout << "Player 2 rolled a " << roll4 << ".\n";
    if (roll3 == roll4) {
      std::cout << "Player 2 rolled doubles!\n";
      p2 = 0;
    } else {
      p2 += roll3 + roll4;
    }
    std::cout << "Player 2's new score is " << p2 << "!\n"; 
  }

  std::cout << "\nPlayer 1: " << p1 << "\n";
  std::cout << "Player 2: " << p2 << "\n";

  if (p1 > p2) {
    std::cout << "Player 1 wins!\n";
  } else if (p1 < p2) {
    std::cout << "Player 2 wins!\n";
  } else {
    std::cout << "Tie!\n";
  }
    
}
