#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

void option1 () {
  std::cout << "\nThis program will take a string and will check if the frequency of each character is the same. \n\nExamples: \n";

  std::cout << "\nInput: str = “xxyyzz” \n";
  std::cout << "Output: Yes \n";
  std::cout << "Explanation: Each character has frequency 2. \n";

  std::cout << "\nInput: str = “xxxxyyzz” \n";
  std::cout << "Output: No \n";
  std::cout << "Explanation: The frequency of 'x' is 4 but 2 for 'y' and 'z'. \n";
  
  std::string str;
  std::cout << "\nEnter a string: ";
  std::cin >> str;

  std::map <char, int> freq;
  std::set<int> count;
  
  for (int i = 0; i < str.length(); i++) {
    if (freq.count (str[i]) != 0) {
      freq[str[i]] += 1;
    } else {
      freq[str[i]] = 1;
    }
  }

  std::map <char, int> :: iterator it = freq.begin();
  while (it != freq.end()) {
    count.insert (it->second);
    it ++;
  }

  if (count.size() <= 1) {
    std::cout << "\nAnswer: Yes \n";
  } else {
    std::cout << "\nAnswer: No \n";
  }
  
}

void option2 () {
  std::cout << "\nThis program will take a string and will list all unique substrings of length 'k'. \n\nExamples: \n";

  std::cout << "\nInput: str = “banana” and k = 2 \n";
  std::cout << "Output: an ba na \n";

  std::cout << "\nInput: str = “mississippi” and k = 3 \n";
  std::cout << "Output: ipp iss mis ppi sip sis ssi \n";

  std::string str;
  std::cout << "\nEnter a string: ";
  std::cin >> str;

  int k;
  std::cout << "Enter a value for k: ";
  std::cin >> k;

  std::set <std::string> substrings;

  for (int i = 0; i < str.length() - k + 1; i++) {
    substrings.insert (str.substr (i, k));
  }

  std::cout << "\nSubstrings: ";
  for (std::string i : substrings) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  
}

std::vector <std::string> get_vector (std::string words) {
  std::vector <std::string> list;
  std::string temp = "";
  for (int i = 0; i < words.length(); i++) {
    if (words[i] == ' ') {
      list.push_back (temp);
      temp = "";
    } else {
      temp += words[i];
    }
  }
  list.push_back (temp);
  return list;
}

std::set <char> get_set (std::string str) {
  std::set <char> set;
  for (int i = 0; i < str.length(); i++) {
    set.insert (str[i]);
  }
  return set;
}

void option3 () {
  std::cout << "\nThis program will take 2 strings: a single word and a list of words. It will list all anagrams of the given string that come from the list of words. \n\nExamples: \n";

  std::cout << "\nInput: str = “cat” and words = “act tac bat hat” \n";
  std::cout << "Output: act tac \n";

  std::cout << "\nInput: str = “seat” and words = “teas eats race east care” \n";
  std::cout << "Output: east eats teas \n";

  std::string str;
  std::cout << "\nEnter a word: ";
  std::cin >> str;

  std::string words;
  std::cout << "Enter a list of words: ";
  getline (std::cin, words);
  getline (std::cin, words);

  std::vector <std::string> list = get_vector (words);
  std::set <char> str_set = get_set (str);
  std::set <std::string> answers;

  for (int i = 0; i < list.size(); i++) {
    std::set <char> temp_set = get_set (list[i]);
    bool contains_all = std::includes(temp_set.begin(), temp_set.end(), str_set.begin(), str_set.end());
    if (contains_all) {
      answers.insert (list[i]);
    }
  }

  std::cout << "\nAnagrams: ";
  for (std::string i : answers) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  
}

int main() {

  std::cout << "\nThis program can perform three operations, which would you like to select? \n\n";

  std::cout << "1) frequency counter \n";
  std::cout << "2) unique substrings \n";
  std::cout << "3) anagram pairs \n";

  int choice;
  std::cout << "\nYour choice: ";
  std::cin >> choice;

  if (choice == 1) {
    option1();
  } else if (choice == 2) {
    option2();
  } else if (choice == 3) {
    option3();
  } else {
    std::cout << "\nInvalid option. \n";
  }
  
}
