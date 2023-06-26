#include <iostream>
#include <vector>
#include <fstream> // class for reading and writing to files

/*
Question # 1:

Create a method that reads a list of integers from a file and returns the sum of the even numbers.
*/

int even_sum (std::string file_name) {
  int total = 0;
  std::ifstream file;
  file.open (file_name);
  if (file.is_open()) { 
    int number;
    while (file >> number) {
      if (number % 2 == 0) {
        total += number;
      }
    }
  }
  return total;
}

/*
Question # 2:

Create a method that reads a list of strings from a file and returns the longest string.
*/

std::string longest_string (std::string file_name) {
  std::string answer = "";
  std::ifstream file;
  file.open (file_name);
  if (file.is_open()) { 
    std::string str;
    while (file >> str) {
      if (str.length() > answer.length()) {
        answer = str;
      }
    }
  }
  return answer;
}

/*
Question # 3:

Create a method that reads a list of student names and their grades from a file. Output the names of the students who scored above 90%.
*/

void above_90 (std::string file_name) {
  std::string temp;
  int index = 0;
  std::ifstream file;
  file.open (file_name);
  std::ofstream file2; 
  file2.open ("question3_answer.txt");
  if (file.is_open()) { 
    std::string str;
    while (file >> str) {
      if (index % 2 == 0) {
        temp = str;
      } else if (std::stoi (str) > 90) {
        file2 << temp << "\n";
      }
      index += 1;
    }
  }
  file2.close();
}

/*
Question # 4:

Create a method that reads a list of numbers from a file and outputs the numbers in reverse order to a file.
*/

void reverse (std::string file_name) {
  std::vector <int> list;
  std::ifstream file;
  file.open (file_name);
  std::ofstream file2; 
  file2.open ("question4_answer.txt");
  if (file.is_open()) { 
    int number;
    while (file >> number) {
      list.push_back (number);
    }
  }
  for (int i = list.size() - 1; i >= 0; i--) {
    file2 << list[i] << "\n";
  }
  file2.close();
}

/*
Question # 5:

Create a method that reads a list of words from a file and outputs the number of vowels in each word to another file.
*/

void count_vowels (std::string file_name) {
  std::string temp;
  std::ifstream file;
  file.open (file_name);
  std::ofstream file2; 
  file2.open ("question5_answer.txt");
  if (file.is_open()) { 
    std::string str;
    while (file >> str) {
      int count = 0;
      for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
          count += 1;
        }
      }
      file2 << count << "\n";
    }
  }
  file2.close();
}

int main() {

  // reading from a file

  std::ifstream file1; // std::ifstream = reading from a file
  file1.open ("example1.txt");
  if (file1.is_open()) { // checks if the file exists
    int number;
    while (file1 >> number) {
      std::cout << number << "\n";
    }
  }

  std::ifstream file2;
  file2.open ("example2.txt");
  if (file2.is_open()) { 
    std::string line;
    while (getline (file2, line)) {
      std::cout << line << '\n';
    }
  }

  // file2 >> line -> each word one by one
  // getline (file2, line) -> each line

  // writing to a file

  std::ofstream file3; // std::ofstream = writing to a file
  file3.open ("example3.txt");
  file3 << "Writing\n";
  file3 << "to\n";
  file3 << "a\n";
  file3 << "file.\n";
  file3.close();

  std::ofstream q1;
  q1.open ("question1_answer.txt");
  q1 << even_sum ("question1.txt"); // 24
  q1.close();

  std::ofstream q2;
  q2.open ("question2_answer.txt");
  q2 << longest_string ("question2.txt"); // strawberry
  q2.close();

  above_90 ("question3.txt"); // Samantha and John

  reverse ("question4.txt"); // 5 4 3 2 1

  count_vowels ("question5.txt"); // 1, 2, 5, 3, 4

}
