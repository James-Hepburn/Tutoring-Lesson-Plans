#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector <std::string> get_card (std::vector <std::string> used) {
  std::vector <std::string> suits = {"Diamonds", "Hearts", "Clubs", "Spades"};
  std::vector <std::string> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  std::vector <std::string> card;
  while (true) {
    int n = rand() % 4;
    int m = rand() % 13;
    std::string c = values[m] + " of " + suits[n];
    if (!std::count(used.begin(), used.end(), c)) {
      used.push_back (c);
      return used;
    }
  }
}

int get_score (std::string card, std::map <std::string, int> values) {
  std::string v = card.substr(0, card.find(" of ")); 
  return values[v];
}

bool is_ace (std::string card) {
  return card.substr(0, card.find(" of ")) == "Ace"; 
}

int main() {

  srand (time (0));

  std::map <std::string, int> values;
  values ["Ace"] = 1;
  values ["2"] = 2;
  values ["3"] = 3;
  values ["4"] = 4;
  values ["5"] = 5;
  values ["6"] = 6;
  values ["7"] = 7;
  values ["8"] = 8;
  values ["9"] = 9;
  values ["10"] = 10;
  values ["Jack"] = 10;
  values ["Queen"] = 10;
  values ["King"] = 10;

  std::vector <std::string> used;

  int p1 = 0;
  int p2 = 0;
  
  std::cout << "\nIt is player 1's turn! You were dealt: \n\n";
  
  used = get_card(used);
  std::string card1 = used[used.size() - 1];
  std::cout << card1 << "\n";
  p1 += get_score(card1, values);
  while (is_ace (card1)) {
    char value;
    std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
    std::cin >> value;
    if (value == 'y') {
      p1 += 10;
      break;
    } else if (value == 'n') {
      break;
    }
  }
  
  used = get_card(used);
  std::string card2 = used[used.size() - 1];
  std::cout << card2 << "\n";
  p1 += get_score(card2, values);
  while (is_ace (card2)) {
    char value;
    std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
    std::cin >> value;
    if (value == 'y') {
      p1 += 10;
      break;
    } else if (value == 'n') {
      break;
    }
  }
  
  std::cout << "\nYour score is " << p1 << "\n";

  if (p1 > 21) {
    std::cout << "\nPlayer 1 bust! Player 2 wins!\n";
    return 0;
  }

  std::cout << "\nIt is player 2's turn! You were dealt: \n\n";
  
  used = get_card(used);
  std::string card3 = used[used.size() - 1];
  std::cout << card3 << "\n";
  p2 += get_score(card3, values);
  while (is_ace (card3)) {
    char value;
    std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
    std::cin >> value;
    if (value == 'y') {
      p2 += 10;
      break;
    } else if (value == 'n') {
      break;
    }
  }
  
  used = get_card(used);
  std::string card4 = used[used.size() - 1];
  std::cout << card4 << "\n";
  p2 += get_score(card4, values);
  while (is_ace (card4)) {
    char value;
    std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
    std::cin >> value;
    if (value == 'y') {
      p2 += 10;
      break;
    } else if (value == 'n') {
      break;
    }
  }
  
  std::cout << "\nYour score is " << p2 << "\n";

  if (p2 > 21) {
    std::cout << "\nPlayer 2 bust! Player 1 wins!\n";
    return 0;
  }

  std::cout << "\nIt is player 1's turn! \n";
  while (true) {
    std::string hs;
    std::cout << "\nWould you like to 'hit' or 'stand'? ";
    std::cin >> hs;
    if (hs == "stand") {
      break;
    } else if (hs == "hit") {
      used = get_card(used);
      std::string card5 = used[used.size() - 1];
      std::cout << "\n" << card5 << "\n";
      p1 += get_score(card5, values);
      while (is_ace (card5)) {
        char value;
        std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
        std::cin >> value;
        if (value == 'y') {
          p1 += 10;
          break;
        } else if (value == 'n') {
          break;
        }
      }
      std::cout << "\nYour score is " << p1 << "\n";
    }
    if (p1 > 21) {
      std::cout << "\nPlayer 1 bust! Player 2 wins!\n";
      return 0;
    }
  }

  std::cout << "\nIt is player 2's turn! \n";
  while (true) {
    std::string hs;
    std::cout << "\nWould you like to 'hit' or 'stand'? ";
    std::cin >> hs;
    if (hs == "stand") {
      break;
    } else if (hs == "hit") {
      used = get_card(used);
      std::string card6 = used[used.size() - 1];
      std::cout << "\n" << card6 << "\n";
      p2 += get_score(card6, values);
      while (is_ace (card6)) {
        char value;
        std::cout << "Would you like your Ace to have a value of 11? (y/n) ";
        std::cin >> value;
        if (value == 'y') {
          p2 += 10;
          break;
        } else if (value == 'n') {
          break;
        }
      }
      std::cout << "\nYour score is " << p2 << "\n";
    }
    if (p2 > 21) {
      std::cout << "\nPlayer 2 bust! Player 1 wins!\n";
      return 0;
    }
  }

  std::cout << "\nResults: \n\n";
  std::cout << "Player 1: " << p1 << "\n";
  std::cout << "Player 2: " << p2 << "\n";
  if (p1 > p2) {
    std::cout << "\nPlayer 1 wins!\n";
  } else if (p1 < p2) {
    std::cout << "\nPlayer 2 wins!\n";
  } else {
    std::cout << "\nIt is a tie!\n";
  }
  
}
