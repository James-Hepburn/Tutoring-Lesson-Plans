#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string get_element(int index, std::string line) {
  std::vector<std::string> output;
  std::stringstream ss(line);
  std::string token;
  while (std::getline(ss, token, ',')) {
    token.erase(0, token.find_first_not_of(" "));
    token.erase(token.find_last_not_of(" ") + 1);
    output.push_back(token);
  }
  return output[index];
}

void print_list(std::vector<std::string> list) {
  for (int i = 0; i < list.size(); i++) {
    std::cout << i + 1 << ") " << list[i] << "\n";
  }
}

std::vector<std::string> get_info(int index) {
  std::ifstream file;
  file.open("information.txt");
  std::string line;
  std::vector<std::string> info;
  while (getline(file, line)) {
    std::string temp = get_element(index, line);
    if (std::find(info.begin(), info.end(), temp) != info.end()) {
      continue;
    } else {
      info.push_back(temp);
    }
  }
  return info;
}

std::vector<std::string> option123(std::string element, int index) {
  std::ifstream file;
  file.open("information.txt");
  std::string line;
  std::vector<std::string> movies;
  while (getline(file, line)) {
    std::string temp = get_element(index, line);
    if (element == temp) {
      movies.push_back(line);
    }
  }
  return movies;
}

std::vector<std::string> option456(std::string element1, int index1,
                                   std::string element2, int index2) {
  std::ifstream file;
  file.open("information.txt");
  std::string line;
  std::vector<std::string> movies;
  while (getline(file, line)) {
    std::string temp1 = get_element(index1, line);
    std::string temp2 = get_element(index2, line);
    if (element1 == temp1 && element2 == temp2) {
      movies.push_back(line);
    }
  }
  return movies;
}

std::vector<std::string> option7(std::string director, std::string genre,
                                 std::string rating) {
  std::ifstream file;
  file.open("information.txt");
  std::string line;
  std::vector<std::string> movies;
  while (getline(file, line)) {
    std::string temp1 = get_element(1, line);
    std::string temp2 = get_element(2, line);
    std::string temp3 = get_element(3, line);
    if (director == temp1 && genre == temp2 && rating == temp3) {
      movies.push_back(line);
    }
  }
  return movies;
}

int main() {

  std::cout << "\nWelcome to the Movie Recommender! \n";
  std::cout << "\nPlease enter the following information: \n";

  std::cout << "\nPlease select a director: \n\n";
  std::vector<std::string> directors = get_info(1);
  print_list(directors);
  int choice1;
  std::cout << "\nSelection: ";
  std::cin >> choice1;

  std::cout << "\nPlease select a genre: \n\n";
  std::vector<std::string> genres = get_info(2);
  print_list(genres);
  int choice2;
  std::cout << "\nSelection: ";
  std::cin >> choice2;

  std::cout << "\nPlease select an age rating: \n\n";
  std::vector<std::string> ratings = get_info(3);
  print_list(ratings);
  int choice3;
  std::cout << "\nSelection: ";
  std::cin >> choice3;

  std::vector<std::string> op1 = option123(directors[choice1 - 1], 1);
  std::vector<std::string> op2 = option123(genres[choice2 - 1], 2);
  std::vector<std::string> op3 = option123(ratings[choice3 - 1], 3);
  std::vector<std::string> op4 =
      option456(directors[choice1 - 1], 1, genres[choice2 - 1], 2);
  std::vector<std::string> op5 =
      option456(directors[choice1 - 1], 1, ratings[choice3 - 1], 3);
  std::vector<std::string> op6 =
      option456(genres[choice2 - 1], 2, ratings[choice3 - 1], 3);
  std::vector<std::string> op7 = option7(
      directors[choice1 - 1], genres[choice2 - 1], ratings[choice3 - 1]);
  std::vector<std::vector<std::string>> options = {op1, op2, op3, op4,
                                                   op5, op6, op7};

  while (true) {
    std::cout << "\nPlease select an option: \n\n";
    std::cout << "1) Recommendations by director \n";
    std::cout << "2) Recommendations by genre \n";
    std::cout << "3) Recommendations by age rating \n";
    std::cout << "4) Recommendations by director and genre \n";
    std::cout << "5) Recommendations by director and age rating \n";
    std::cout << "6) Recommendations by genre and age rating \n";
    std::cout << "7) Recommendations by director, genre and age rating \n";
    std::cout << "8) Exit \n";

    int rec;
    std::cout << "\nSelection: ";
    std::cin >> rec;

    if (rec == 8) {
      std::cout << "\nGoodbye! \n";
      break;
    } else {
      std::vector<std::string> chosen = options[rec - 1];
      if (chosen.size() == 0) {
        std::cout
            << "\nSorry, there are no recommendations for this selection. \n";
      } else {
        std::cout << "\nHere are your recommendations: \n";
        std::cout << "Format: movie, director, genre, age rating \n\n";
        print_list(chosen);
      }
    }
  }
}
