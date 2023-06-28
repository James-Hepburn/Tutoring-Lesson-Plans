#include <iostream>
#include <map>
#include <vector>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

int main() {

  std::vector <std::string> words = {"come", "dark", "far", "first", "go", "good", "home", "light", "near", "stand"};
  std::vector <std::string> definitions = {"move or travel toward or into a place thought of as near or familiar to the speaker", "with little or no light", "at, to, or by a great distance", "coming before all others in time or order", "move from one place to another", "to be desired or approved of", "the place where one lives permanently, especially as a member of a family or household", "the natural agent that stimulates sight and makes things visible", "at or to a short distance away", "have or maintain an upright position, supported by one's feet"};
  std::map <std::string, std::string> dict;

  for (int i = 0; i < 10; i++) {
    dict [words[i]] = definitions [i];
  }

  while (true) {
    erase (3000000);
    std::map<std::string, std::string>::iterator it = dict.begin();
    int count = 0;
    std::cout << "\nHere are the words:\n\n";
    while (it != dict.end()) {
      count += 1;
      std::cout << count << ") " << it->first << "\n";
      it ++;
    }
    int chosen;
    std::cout << "\nWhich word would you like to see the definition of? ";
    std::cin >> chosen;
    if (chosen > 10 || chosen < 1) {
      std::cout << "\nInvalid.\n";
    } else {
      std::cout << words[chosen-1] << ": " << dict [words[chosen-1]] << "\n";
    }

    char c;
    std::cout << "\nWould you like to continue using the dictioanry? (y/n) ";
    std::cin >> c;

    if (c == 'n') {
      std::cout << "\nGoodbye!\n";
      break;
    }
  }

}
