#include <iostream>

bool win (std::string player, std::string computer) {
  if (player == "rock" && computer == "scissors") {
    return true;
  } else if (player == "paper" && computer == "rock") {
    return true;
  } else if (player == "scissors" && computer == "paper") {
    return true;
  } else {
    return false;
  }
}

bool lose (std::string player, std::string computer) {
  if (computer == "rock" && player == "scissors") {
    return true;
  } else if (computer == "paper" && player == "rock") {
    return true;
  } else if (computer == "scissors" && player == "paper") {
    return true;
  } else {
    return false;
  }
}

bool tie (std::string player, std::string computer) {
  if (computer == player) {
    return true;
  }  else {
    return false;
  }
}

std::string get_computer () {
  srand(time (0));
  int n = rand() % 3;
  if (n == 0) {
    return "rock";
  } else if (n == 1) {
    return "paper";
  } else {
    return "scissors";
  }
}

bool valid (std::string move) {
  if (move == "paper" || move == "scissors" || move == "rock") {
    return true;
  } else {
    return false;
  }
}

int main() {
  
  std::cout << "\nWelcome to Rock, Paper, Scissors!\n";

  std::string move;
  std::cout << "\nYour move: ";
  std::cin >> move;

  if (valid (move)) {
    std::string computer = get_computer();
    std::cout << "Computer move: " << computer;
    if (win (move, computer)) {
      std::cout << "\nYou win!\n";
    } else if (tie (move, computer)) {
      std::cout << "\nYou tie!\n";
    } else {
      std::cout << "\nYou lost!\n";
    }
  } else {
    std::cout << "\nInvalid move.\n";
  }

}
