#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

void option123 (std::string file_name) {
  std::vector <std::string> names;
  std::ifstream file1;
  file1.open ("names.txt");
  if (file1.is_open()) { 
    std::string name;
    while (file1 >> name) {
      names.push_back(name);
    }
  }
  std::vector <int> grades;
  std::ifstream file2;
  file2.open (file_name);
  if (file2.is_open()) { 
    int grade;
    while (file2 >> grade) {
      grades.push_back(grade);
    }
  }
  double avg = 0;
  for (int i = 0; i < names.size(); i++) {
    std::cout << "Name: " << names[i] << " - Grade: " << grades[i] << "\n"; 
    avg += grades[i];
  }
  avg /= names.size();
  std::cout << "\nClass average: " << avg << "\n";
}

void display_names () {
  int counter = 1;
  std::ifstream file;
  file.open ("names.txt");
  if (file.is_open()) { 
    std::string line;
    while (file >> line) {
      std::cout << counter << ") " << line << '\n';
      counter += 1;
    }
  }
}

void option4 (int index) {
  int counter = 1;
  double avg = 0;
  std::ifstream file;
  file.open ("english_grades.txt");
  if (file.is_open()) { 
    int grade;
    while (file >> grade) {
      if (counter == index) {
        std::cout << "English grade: " << grade << "\n";
        avg += grade;
      }
      counter += 1;
    }
  }
  counter = 1;
  std::ifstream file2;
  file2.open ("math_grades.txt");
  if (file2.is_open()) { 
    int grade;
    while (file2 >> grade) {
      if (counter == index) {
        std::cout << "Math grade: " << grade << "\n";
        avg += grade;
      }
      counter += 1;
    }
  }
  counter = 1;
  std::ifstream file3;
  file3.open ("science_grades.txt");
  if (file3.is_open()) { 
    int grade;
    while (file3 >> grade) {
      if (counter == index) {
        std::cout << "Science grade: " << grade << "\n";
        avg += grade;
      }
      counter += 1;
    }
  }
  avg /= 3;
  std::cout << "Student average: " << avg << "\n";
}

int main() {

  while (true) {
    erase (1000000);
    
    std::cout << "Grade Book - Class of 2023: \n\n";
    std::cout << "1) View grades: English \n";
    std::cout << "2) View grades: Math \n";
    std::cout << "3) View grades: Science \n";
    std::cout << "4) View student grade report \n";
    std::cout << "5) Exit \n\n";
  
    int option;
    std::cout << "Enter an option: ";
    std::cin >> option;
  
    if (option == 1) {
      erase (1000000);
      std::cout << "Here are the English grades: \n\n";
      option123 ("english_grades.txt");
    } else if (option == 2) {
      erase (1000000);
      std::cout << "Here are the Math grades: \n\n";
      option123 ("math_grades.txt");
    } else if (option == 3) {
      erase (1000000);
      std::cout << "Here are the Science grades: \n\n";
      option123 ("science_grades.txt");
    } else if (option == 4) {
      erase (1000000);
      std::cout << "Here are the students: \n\n";
      display_names();
      int index;
      std::cout << "\nWhich student? ";
      std::cin >> index;
      std::cout << "\n";
      option4 (index);
    } else if (option == 5) {
      std::cout << "Goodbye! \n";
      break;
    } else {
      std::cout << "Invalid option. \n";
    }

    std::cout << "\nPress enter to continue: ";
    std::cin.get();
    std::cin.get();
    
  }
  
}
