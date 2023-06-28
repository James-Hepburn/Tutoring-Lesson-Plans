#include <iostream>
#include <vector>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

class product {
  protected:
    double price;
    std::string name;
  public:
    void set_price (double p) {
      price = p;
    }
    void set_name (std::string n) {
      name = n;
    }
    double get_price () {
      return price;
    }
};

class pizza : public product {
  protected:
    std::vector <std::string> toppings;
  public:
    void add_topping (std::string t) {
      toppings.push_back (t);
    }
    void topping_options () {
      std::cout << "\n1) pepperoni \n2) bacon \n3) mushrooms \n4) peppers \n";
    }
    std::string display_pizza () {
      std::string result = "cheese pizza with ";
      for (std::string i : toppings) {
        result += i + " ";
      }
      return toppings.size() == 0 ? result + "no toppings" : result;
    }
};

class beverage : public product {
  protected:
    std::string flavour;
    bool size;
  public:
    void set_flavour (std::string f) {
      flavour = f;
    }
    void set_size (bool s) {
      size = s;
    }
    void flavour_options () {
      std::cout << "\n1) juice \n2) soda \n3) milkshake \n4) coffee \n";
    }
    std::string display_beverage () {
      return size ? flavour + " (small)" : flavour + " (large)";
    }
};

double print_order (std::vector <pizza> pizzas, std::vector <beverage> beverages) {
  int counter = 1;
  double total = 0;
  for (pizza i : pizzas) {
    std::cout << counter << ") ";
    std::cout << i.display_pizza() << "\n";
    counter += 1;
    total += i.get_price();
  }
  for (beverage i : beverages) {
    std::cout << counter << ") ";
    std::cout << i.display_beverage() << "\n";
    counter += 1;
    total += i.get_price();
  }
  return total;
}

int main() {

  std::vector <pizza> pizzas;
  std::vector <beverage> beverages;

  while (true) {

    std::cout << "\n1) View menu\n";
    std::cout << "2) Add item to order\n";
    std::cout << "3) Delete item from order\n";
    std::cout << "4) View order\n";
    std::cout << "5) Finish order and pay bill\n";

    int choice;
    std::cout << "\nWhat would you like to select? ";
    std::cin >> choice;

    if (choice == 1) {
      std::cout << "\nPizzas:\n";
      std::cout << "   - Pepperoni\n";
      std::cout << "   - Bacon\n";
      std::cout << "   - Mushrooms\n";
      std::cout << "   - Peppers\n";
      std::cout << "Beverages:\n";
      std::cout << "   - Juice\n";
      std::cout << "   - Soda\n";
      std::cout << "   - Milkshake\n";
      std::cout << "   - Coffee\n";
      erase (3000000);
    }

    else if (choice == 2) {
      std::string which_item;
      std::cout << "\nWould you like to add pizza or a beverage? ";
      std::cin >> which_item;
      if (which_item == "pizza") {
        pizza p;
        double price = 3.5;
        std::cout << "\n1 cheese pizza added to your order.\n";
        while (true) {
          std::string add;
          std::cout << "\nWould you like to add any toppings? (y/n) ";
          std::cin >> add;
          if (add == "y") {
            int options;
            p.topping_options();
            std::cout << "\nWhich topping would you like? ";
            std::cin >> options;
            if (options == 1) {
              p.add_topping ("pepperoni");
              price += 1;
            } else if (options == 2) {
              p.add_topping ("bacon");
              price += 1;
            } else if (options == 3) {
              p.add_topping ("mushrooms");
              price += 0.5;
            } else if (options == 4) {
              p.add_topping ("peppers");
              price += 0.5;
            } else {
              std::cout << "\nInvalid choice. No toppings added.\n";
            }
          } else if (add != "n") {
            std::cout << "\nInvalid choice. No toppings added.\n";
          } else {
            break;
          }
        }
        p.set_price (price);
        pizzas.push_back (p);
      } else if (which_item == "beverage") {
        beverage b;
        bool s;
        double price = 0;
        std::cout << "\nPlease enter 1 to make the drink a small and 0 for large: ";
        std::cin >> s;
        s ? price += 2.5 : price += 4;
        b.set_size (s);
        int options;
        b.flavour_options();
        std::cout << "\nWhich flavour drink would you like? ";
        std::cin >> options;
        if (options == 1) {
          b.set_flavour ("juice");
          price += 2.5;
          b.set_price (price);
          beverages.push_back (b);
        } else if (options == 2) {
          b.set_flavour ("soda");
          price += 3.5;
          b.set_price (price);
          beverages.push_back (b);
        } else if (options == 3) {
          b.set_flavour ("milkshake");
          price += 4.5;
          b.set_price (price);
          beverages.push_back (b);
        } else if (options == 4) {
          b.set_flavour ("coffee");
          price += 3;
          b.set_price (price);
          beverages.push_back (b);
        } else {
          std::cout << "\nInvalid choice. No drink added.\n";
        }
      } else {
        std::cout << "\nInvalid choice. No item added.\n";
      }
    }

    else if (choice == 3) {
      print_order(pizzas, beverages);
      int del;
      std::cout << "\nWhich item would you like to remove from your order? ";
      std::cin >> del;
      if (del > pizzas.size()) {
        beverages.erase (beverages.begin() + (del - 1 - pizzas.size()));
      } else {
        pizzas.erase (pizzas.begin() + (del - 1));
      }
    }

    else if (choice == 4) {
      std::cout << "\n";
      print_order(pizzas, beverages);
    }

    else if (choice == 5) {
      std::cout << "\n";
      double total = print_order (pizzas, beverages);
      std::cout << "Total: $" << total << "\n";
      break;
    }

    else {
      std::cout << "\nInvalid choice.\n";
    }

    erase (3000000);
    
  }
  
}
