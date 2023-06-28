#include <iostream>

std::string get_country () {
  srand(time (0));
  int n = rand() % 5;
  if (n == 0) {
    return "Canada";
  } else if (n == 1) {
    return "America";
  } else if (n == 2) {
    return "Italy";
  } else if (n == 3) {
    return "Ireland";
  } else {
    return "Mexico";
  }
}

std::string canada_facts (int hint) {
  if (hint == 1) {
    return "The flag of this country has a maple leaf.";
  } else if (hint == 2) {
    return "This country is well known for Tim Hortons.";
  }
}

std::string america_facts (int hint) {
  if (hint == 1) {
    return "This country has 50 states.";
  } else if (hint == 2) {
    return "The flag of this country has 50 stars and 13 stripes.";
  }
}

std::string italy_facts (int hint) {
  if (hint == 1) {
    return "The flag of this country is red, white and green.";
  } else if (hint == 2) {
    return "The outline of this country on a map looks like a boot.";
  }
}

std::string ireland_facts (int hint) {
  if (hint == 1) {
    return "The flag of this country is green, white and orange.";
  } else if (hint == 2) {
    return "The nickname of this country is 'The Emerald Isle'.";
  }
}

std::string mexico_facts (int hint) {
  if (hint == 1) {
    return "The flag of this country has an eagle standing on a cactus with a snake in its beak.";
  } else if (hint == 2) {
    return "This country is situated below the USA.";
  }
}

int main() {

  std::string country = get_country();
  std::string hint1;
  std::string hint2;
  std::string guess1;
  std::string guess2;

  if (country == "Canada") {
    hint1 = canada_facts(1);
    hint2 = canada_facts(2);
  } else if (country == "America") {
    hint1 = america_facts(1);
    hint2 = america_facts(2);
  } else if (country == "Italy") {
    hint1 = italy_facts(1);
    hint2 = italy_facts(2);
  } else if (country == "Ireland") {
    hint1 = ireland_facts(1);
    hint2 = ireland_facts(2);
  } else {
    hint1 = mexico_facts(1);
    hint2 = mexico_facts(2);
  }
  
  std::cout << "\nWelcome to the Country Guesser!\n";
  std::cout << "\nI have selected a random country, can you guess which?\n";
  std::cout << "\nHere is a hint: " << hint1 << "\n";

  std::cout << "\nYour guess: ";
  std::cin >> guess1;

  if (guess1 == country) {
    std::cout << "\nYou got it!\n";
  } else {
    std::cout << "\nSorry, that wasn't it.\n";
    std::cout << "\nHere is one last hint: " << hint2 << "\n";
    std::cout << "\nYour guess: ";
    std::cin >> guess2;
    if (guess2 == country) {
      std::cout << "\nYou got it!\n";
    } else {
      std::cout << "\nSorry, the country actually was " << country << ".\n";
    }
  }

}
