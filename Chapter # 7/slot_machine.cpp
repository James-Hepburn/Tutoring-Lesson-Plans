#include <iostream>
#include <vector>
#include <unistd.h>

char get_symbol () {
  std::vector <char> symbols = {'@', '&', '*'};
  int n = rand() % 3;
  return symbols[n];
}

bool won_turn (std::vector <char> roll) {
  return roll[0] == roll[1] && roll[1] == roll[2];
}

int get_prize (char symbol, int bet) {
  if (symbol == '@') {
    return bet * 2;
  } else if (symbol == '&') {
    return bet * 5;
  } else if (symbol == '*') {
    return bet * 10;
  }
  return 0;
}

void display_chart () {
  std::cout << "\n@ = 2x bet\n";
  std::cout << "& = 5x bet\n";
  std::cout << "* = 10x bet\n";
}

void display_roll (std::vector <char> roll) {
  std::cout << "\n" << roll[0] << " " << roll[1] << " " << roll[2] << "\n";
}

int main() {

  std::cout << "\nWelcome to the Slot Machine!\n";

  int money;
  std::cout << "\nHow much money do you have to play with? ";
  std::cin >> money;
    
  int original = money;
  std::string decision;
  
  while (decision != "STOP") {
    usleep(3000000); // microseconds
    std::cout << "\033[2J\033[1;1H";

    display_chart();
    std::cout << "\nAvailable money: $ " << money << "\n";
    std::cout << "\nEnter 'SPIN' to spin the slot machine or 'STOP' to stop: ";
    std::cin >> decision;

    if (decision == "STOP") {
      break;
    } else if (decision != "SPIN") {
      std::cout << "Invalid input, no action taken.\n";
    } else {
      int bet;
      std::cout << "How much do you want to bet? ";
      std::cin >> bet;
      if (money >= bet) {
        money -= bet;
        srand (time (0));
        std::vector <char> roll = {get_symbol(), get_symbol(), get_symbol()};
        display_roll(roll);
        bool outcome = won_turn (roll);
        if (outcome) {
          int prize = get_prize (roll[0], bet);
          std::cout << "You won $ " << prize << "!\n";
          money += prize;
        } else {
          std::cout << "You lost $ " << bet << ".\n";
        }
      } else {
        std::cout << "Invalid input, no action taken.\n";
      }
    }
  }

  std::cout << "\nYou started with $ " << original << ".\n";
  std::cout << "You ended with $ " << money << ".\n";
  
}
