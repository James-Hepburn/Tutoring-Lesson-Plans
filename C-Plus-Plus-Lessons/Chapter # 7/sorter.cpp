#include <iostream>
#include <vector>

std::vector <int> increasing (std::vector <int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] > arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  return arr;
}

std::vector <int> decreasing (std::vector <int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] < arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  return arr;
}

void display (std::vector <int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
}

bool isdigit (std::string s) {
  for (int i = 0; i < s.length(); i++) {
    if (isdigit (s.at(i)) == false) {
      return false;
    }
  }
  return true;
}

int main() {

  std::cout << "\nWelcome to the Sorter!\n\n";
  
  std::vector <int> org;

  while (true) {
    std::string input;
    std::cout << "Enter a number or 'f' to finish: ";
    std::cin >> input;
  
    if (input == "f") {
      break;
    } else if (isdigit (input)) {
      org.push_back (std::stoi(input));
    } else {
      std::cout << "\nInvalid input, no action taken.\n";
    }  
  }

  std::vector <int> arr = org;

  char order;
  std::cout << "\n[I]ncreasing or [D]ecreasing? ";
  std::cin >> order;

  if (order == 'I') {
    arr = increasing (org);
  } else if (order == 'D') {
    arr = decreasing (org);
  } else {
    std::cout << "\nInvalid input, no action taken.\n";
  }

  std::cout << "Original vector: ";
  display (org);
  std::cout << "\nFinal vector: ";
  display (arr);
  
}
