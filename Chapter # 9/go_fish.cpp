#include <iostream>
#include <vector>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

class card {

  private:

    std::string value;
    std::string suit;

  public:

    card (std::string v, std::string s) {
      value = v;
      suit = s;
    }

    std::string get_value () {
      return value;
    }

    std::string display_card () {
      return value + " of " + suit;
    }

    bool check_pair (std::string v) {
      return value == v;
    }

};

class deck {

  private:

    std::vector <card> cards;
    std::vector <std::string> suits = {"diamonds", "hearts", "spades", "clubs"};
    std::vector <std::string> values = {"ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};

  public:

    deck () {
      for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
          card c = card (values[i], suits[j]);
          cards.push_back (c);
        }
      }
    }

    void shuffle () {
      srand (time (0));
      for (int i = 0; i < 100; i++) {
        int index1 = rand() % 52;
        int index2 = rand() % 52;
        card c1 = cards[index1];
        card c2 = cards[index2];
        cards[index1] = c2;
        cards[index2] = c1;
      }
    }

    card deal () {
      card c = cards.back();
      cards.pop_back();
      return c;
    }

};

class player {

  private:

    std::string name;
    std::vector <card> cards;

  public:

    player (std::string n, std::vector <card> c) {
      name = n;
      cards = c;
    }

    std::string get_name () {
      return name;
    }

    int cards_left () {
      return cards.size();
    }

    void diplay_hand () {
      for (int i = 0; i < cards.size(); i++) {
        std::cout << i+1 << ") " << cards[i].display_card() << "\n"; 
      }
    }

    card get_card (int index) {
      return cards[index];
    }

    bool check_card (std::string ask) {
      for (int i = 0; i < cards.size(); i++) {
        if (ask == cards[i].get_value()) {
          return true;
        }
      }
      return false;
    }

    card give_card (std::string ask) {
      card temp = card ("", "");
      for (int i = 0; i < cards.size(); i++) {
        if (ask == cards[i].get_value()) {
          temp = cards[i];
          cards.erase (cards.begin() + i);
          break;
        }
      }
      return temp;
    }

    void add_card (card c) {
      cards.push_back(c);
    }

    bool has_pairs () {
      for (int i = 0; i < cards.size(); i++) {
        for (int j = i+1; j < cards.size(); j++) {
          if (cards[i].get_value() == cards[j].get_value()) {
            return true;
          }
        }
      }
      return false;
    }

    void remove_pairs () {
      for (int i = 0; i < cards.size(); i++) {
        for (int j = i+1; j < cards.size(); j++) {
          if (cards[i].get_value() == cards[j].get_value()) {
            cards.erase (cards.begin() + j);
            cards.erase (cards.begin() + i);
            return;
          }
        }
      }
    }

};

int main() {

  deck cards = deck();
  cards.shuffle();

  std::cout << "\nWelcome to Go Fish!\n\n";

  std::vector <card> p1_cards = {cards.deal(), cards.deal(), cards.deal(), cards.deal(), cards.deal()};
  std::string name1;
  std::cout << "Player one, what is your name? ";
  std::cin >> name1;
  player p1 = player (name1, p1_cards);

  std::vector <card> p2_cards = {cards.deal(), cards.deal(), cards.deal(), cards.deal(), cards.deal()};
  std::string name2;
  std::cout << "Player two, what is your name? ";
  std::cin >> name2;
  player p2 = player (name2, p2_cards);

  std::cout << "\nGreat! Let's begin!\n";

  while (true) {

    erase (3000000);
    std::cout << "\n" << p1.get_name() << "'s turn!\n";
    p1.diplay_hand();

    std::string ask;
    std::cout << "\nWhich card are you asking " << p2.get_name() << " for? ";
    std::cin >> ask;

    bool has_card = p2.check_card(ask);
    if (has_card) {
      card given = p2.give_card(ask);
      p1.add_card(given);
      std::cout << p2.get_name() << " gave you the " << given.display_card() << "\n";
    } else {
      card given = cards.deal();
      p1.add_card(given);
      std::cout << "Go fish! You were dealt the " << given.display_card() << "\n";
    }

    int count = 0;
    while (p1.has_pairs()) {
      p1.remove_pairs();
      count += 1;
    }
    std::cout << "\n" << count << " pair(s) were removed from your hand\n";

    if (p1.cards_left() == 0) {
      std::cout << "\n" << p1.get_name() << " won!\n";
      break;
    }

    erase (3000000);
    std::cout << "\n" << p2.get_name() << "'s turn!\n";
    p2.diplay_hand();

    std::string ask2;
    std::cout << "\nWhich card are you asking " << p1.get_name() << " for? ";
    std::cin >> ask2;

    bool has_card2 = p1.check_card(ask2);
    if (has_card2) {
      card given = p1.give_card(ask2);
      p2.add_card(given);
      std::cout << p1.get_name() << " gave you the " << given.display_card() << "\n";
    } else {
      card given = cards.deal();
      p2.add_card(given);
      std::cout << "Go fish! You were dealt the " << given.display_card() << "\n";
    }

    int count2 = 0;
    while (p2.has_pairs()) {
      p2.remove_pairs();
      count2 += 1;
    }
    std::cout << "\n" << count2 << " pair(s) were removed from your hand\n";

    if (p2.cards_left() == 0) {
      std::cout << "\n" << p2.get_name() << " won!\n";
      break;
    }

  }
}
