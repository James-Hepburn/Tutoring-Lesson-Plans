#include <iostream>
#include <map>
#include <set>
#include <unistd.h>

void erase (int seconds) {
  usleep(seconds * 1000000); 
  std::cout << "\033[2J\033[1;1H";
}

class Product {

  public:

    std::string name;
    std::set <std::string> attributes;

    void set_name (std::string n) {
      name = n;
    }

    void add_attribute (std::string attribute) {
      attributes.insert (attribute);
    }

    void delete_attribute (std::string attribute) {
      auto element = attributes.find (attribute);
      attributes.erase (element);
    }

    void display_product () {
      std::cout << "\nProduct: " << name << "\n";
      for (std::string i : attributes) {
        std::cout << "  - " << i << "\n";
      }
    }

};

std::map <std::string, Product> products;

void view_inventory () {
  std::map<std::string, Product>::iterator it = products.begin();
  std::cout << "\nInventory: \n";
  while (it != products.end()) {
    it->second.display_product();
    it++;
  }
}

bool search_inventory (std::string product_name) {
  std::map<std::string, Product>::iterator it = products.begin();
  while (it != products.end()) {
    if (it->first == product_name) {
      return true;
    }
    it++;
  }
  return false;
}

int main() {

  while (true) {

    erase (3);

    std::cout << "\nWelcome to the Inventory System! \n\n";
  
    std::cout << "1) View inventory \n";
    std::cout << "2) Search inventory \n";
    std::cout << "3) Add product \n";
    std::cout << "4) Delete product \n";
    std::cout << "5) Add attribute to product \n";
    std::cout << "6) Delete attribute from product \n";
    std::cout << "7) Exit \n";
  
    int selection;
    std::cout << "\nYour selection: ";
    std::cin >> selection;
  
    if (selection == 1) {
      view_inventory();
    } else if (selection == 2) {
      std::string product_name;
      std::cout << "\nWhat is the product name? ";
      std::cin >> product_name;
      bool found = search_inventory (product_name);
      if (found) {
        std::cout << "\nItem found. \n";
      } else {
        std::cout << "\nItem not found. \n";
      }
    } else if (selection == 3) {
      std::string product_name;
      std::cout << "\nWhat is the product name? ";
      std::cin >> product_name;
      Product product;
      product.set_name (product_name);
      products[product_name] = product;
    } else if (selection == 4) {
      std::string product_name;
      std::cout << "\nWhat is the product name? ";
      std::cin >> product_name;
      products.erase (product_name);
    } else if (selection == 5) {
      std::string product_name;
      std::cout << "\nWhat is the product name? ";
      std::cin >> product_name;
      std::string attribute;
      std::cout << "\nWhat is the attribute? ";
      std::cin >> attribute;
      std::string value;
      std::cout << "\nWhat is the value of the attribute? ";
      std::cin >> value;
      products[product_name].add_attribute (attribute + " = " + value);
    } else if (selection == 6) {
      std::string product_name;
      std::cout << "\nWhat is the product name? ";
      std::cin >> product_name;
      std::string attribute;
      std::cout << "\nWhat is the attribute? ";
      std::cin >> attribute;
      std::string value;
      std::cout << "\nWhat is the value of the attribute? ";
      std::cin >> value;
      products[product_name].delete_attribute (attribute + " = " + value);
    } else {
      std::cout << "\nGoodbye. \n";
      break;
    }

  }
  
}
