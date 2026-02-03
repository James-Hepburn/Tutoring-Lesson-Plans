#include <iostream>
#include <chrono>

std::string get_sentence () {
  std::string sentence1 = "I caught my squirrel rustling through my gym bag.";
  std::string sentence2 = "There should have been a time and a place, but this wasn't it.";
  std::string sentence3 = "A suit of armor provides excellent sun protection on hot days.";
  srand(time (0));
  int n = std::rand() % 3;
  if (n == 0) {
    return sentence1;
  } else if (n == 1) {
    return sentence2;
  } else {
    return sentence3;
  }
}

int main() {
  
  std::cout << "\nRules:\n";
  std::cout << "  * Type the sentence you are given. \n";
  std::cout << "  * Every correct character earns you 1 point. \n";
  std::cout << "  * If you do not finish typing after 10 seconds, you lose. \n";

  std::string ready;
  std::cout << "\nEnter 'play' to begin: ";
  std::cin >> ready;

  if (ready == "play") {
    auto begin = std::chrono::high_resolution_clock::now();
    std::string sentence = get_sentence();
    std::cout << "\n" << sentence << "\n";
    std::string input;
    std::cout << "\nType here: ";
    getline (std::cin,input);
    getline (std::cin,input);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

    if (elapsed.count() > 10) {
      std::cout << "\nYou took too long, you lose!\n";   
    } else {
      int points = 0;
      int len = sentence.length() > input.length() ? input.length() : sentence.length();
      for (int i = 0; i < len; i++) {
        if (sentence.at(i) == input.at (i)) {
          points += 1;
        }
      }
      std::cout << "\nYou earned " << points << " points\n";   
    }
    
  }

}
