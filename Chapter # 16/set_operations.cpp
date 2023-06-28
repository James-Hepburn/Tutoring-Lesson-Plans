#include <iostream>
#include <set>

std::set <int> get_set () {
  std::set <int> s;
  while (true) {
    std::string input;
    std::cin >> input;
    if (input == "f") {
      break;
    }
    s.insert (std::stoi (input));
  }
  return s;
}

std::set <int> intersection_operation (std::set <int> set1, std::set <int> set2) {
  std::set <int> result;
  for (int i : set1) {
    if (set2.count (i) == 1) {
      result.insert (i);
    }
  }
  return result;
}

std::set <int> union_operation (std::set <int> set1, std::set <int> set2) {
  for (int i : set2) {
    set1.insert (i);
  }
  return set1;
}

std::set <int> difference_operation (std::set <int> set1, std::set <int> set2) {
  std::set <int> result;
  for (int i : set1) {
    if (set2.count (i) == 0) {
      result.insert (i);
    }
  }
  return result;
}

void print_set (std::set <int> s) {
  for (int i : s) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main() {

  std::cout << "\nSet Operations!\n";

  std::cout << "\nEnter the information for the first set ('f' to finish):\n\n";
  std::set <int> set1 = get_set();

  std::cout << "\nEnter the information for the second set ('f' to finish):\n\n";
  std::set <int> set2 = get_set();

  std::cout << "\nIntersection: Only the common elements in both sets:\n\n";
  std::set <int> intersection_set = intersection_operation(set1, set2);
  print_set (intersection_set);

  std::cout << "\nUnion: All elements from both sets:\n\n";
  std::set <int> union_set = union_operation(set1, set2);
  print_set (union_set);

  std::cout << "\nDifference: Elements in the first set but not the second:\n\n";
  std::set <int> difference_set = difference_operation(set1, set2);
  print_set (difference_set);
  
}
