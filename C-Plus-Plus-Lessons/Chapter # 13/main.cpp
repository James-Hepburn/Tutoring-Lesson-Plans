#include <iostream>
#include <map>
#include <cctype> // due to exercise questions
#include <vector> // due to exercise questions

int main() {

  // map -> list where each element has a key and a value
  // a key is unique and a value is not
  // can't be printed out

  // how to make a map

  std::map <std::string, int> grades;

  // how to add elements to a map

  grades ["math"] = 78;
  grades ["french"] = 99;
  grades ["science"] = 85;

  // how to get values from a map

  int science_grade = grades ["science"];
  std::cout << science_grade << "\n";

  // how to change a value of a key

  grades ["french"] = 97;
  
  // how to delete an element from a map

  grades.erase ("math");

  // how to find the length

  int length = grades.size();
  std::cout << length << "\n";

  // how to go through the keys and values of a map

  std::map<std::string, int>::iterator it = grades.begin();
  while (it != grades.end()) {
    std::cout << "Key: " << it->first << "\n";
    std::cout << "Value: " << it->second << "\n";
    it ++;
  }

}

/*
Question # 1:

Write a method that creates a map with each (key, value) pair being the (lower case, upper case) versions of a letter, respectively. Examples:

["p", "s"] ➞ {"p": "P", "s": "S"}
["a", "b", "c"] ➞ {"a": "A", "b": "B", "c": "C"}
*/

std::map <char, char> q1 (char list [], int len) {
  std::map <char, char> map;
  for (int i = 0; i < len; i++) {
    map [list[i]] = toupper (list[i]);
  }
  return map;
}

/*
Question # 2:

Write a method that converts a map into a 2D list of keys-values. Examples:

{"D": 1, "B": 2, "C": 3} ➞ [["B", 2], ["C", 3], ["D", 1]]
{"likes": 2, "dislikes": 3, "followers": 10} ➞ [["dislikes", 3], ["followers", 10], ["likes", 2]]
*/

std::vector <std::vector <char>> q2 (std::map <char, int> map) {
  std::vector <std::vector <char>> list;
  std::map<char, int>::iterator it = map.begin();
  while (it != map.end()) {
    char c = it->second;
    std::vector <char> temp = {it->first, c};
    list.push_back(temp);
    it ++;
  }
  return list;
}

/*
Question # 3:

Create a method that takes a map of groceries and calculates the total price. A grocery map has a product as a key and a vector with a quantity and a price. Examples:

{"Milk": [3, 1.5]} ➞ 4.5
{"Milk": [1, 1.5], "Eggs": [12, 0.1]} ➞ 2.7
{"Chocolate": [1, 0.1], "Lollipop": [1, 0.2]} ➞ 0.3
*/

float q3 (std::map <std::string, std::vector <int>> map) {
  float total = 0;
  std::map<std::string, std::vector <int>>::iterator it = map.begin();
  while (it != map.end())  {
    std::vector <int> list  = it -> second;
    total += list [0] * list [1];
    it ++;
  }
  return total;
}

/*
Question # 4:

You will be given a map with various products and their respective prices. Return a list of the products with a minimum price of 500 in descending order. Examples:

{"Computer" : 600, "TV" : 800, "Radio" : 50} ➞ ["TV", "Computer"]
{"Bike1" : 510, "Bike2" : 401, "Bike3" : 501} ➞ ["Bike1", "Bike3"]
{"Loafers" : 50, "Vans" : 10, "Crocs" : 20} ➞ []
*/

std::vector <std::string> q4 (std::map <std::string, int> map) {
  std::vector <std::string> list;
  int min = 1000;
  std::string item;
  int count = map.size();
  while (true) {
    count -= 1;
    std::map<std::string, int>::iterator it = map.begin();
    while (it != map.end()) {
      if (min > it->second && it->second >= 500) {
        min = it->second;
        item = it->first;
      }
    }
    list.push_back (item);
    if (count == 0) {
      break;
    }
  }
  return list;
}

// method to test q1 

void print_q1 (std::map <char, char> map) {
  std::map<char, char>::iterator it = map.begin();
  while (it != map.end()) {
    std::cout << it->first << " = " << it->second << "\n";
  }
}

// method to test q2

void print_q2 (std::vector <std::vector <char>> list) {
  for (int i = 0; i < list.size(); i++) {
    std::cout << "[" << list[i][0] << ", " << list[i][1] << "], ";
  }
  std::cout << "\n";
}

// method to test q4

void print_q4 (std::vector <std::string> list) {
  std::cout << "[";
  for (int i = 0; i < list.size(); i++) {
    std::cout << list[i] << ", ";
  }
  std::cout << "]\n";
}
