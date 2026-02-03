#include <iostream>
#include <vector>

// method to display vector

void print (std::vector <int> list) {
  for (int i = 0; i < list.size(); i++) {
    std::cout << list [i] << " ";
  }
  std::cout << "\n";
}

/*
Searching algorithm # 1 - sequential search

Sequentially checking each element of the list until a match is found or the whole list has been searched.
*/

int sequentialSearch (std::vector <int> list, int target) {
  for (int i = 0; i < list.size(); i++) {
    if (list[i] == target) {
      return i;
    }
  }
  return -1;
}

/*
Searching algorithm # 2 - binary search

Comparing the target value to the middle element of the list continously until the target is found or has been determined to not be inside the list.
*/

int binarySearch (std::vector <int> list, int target, int low, int high) {
  if (low > high) {
    return -1;
  } else {
    int mid_index = low + (high - low) / 2;
    if (list[mid_index] == target) {
      return mid_index;
    } else if (list[mid_index] > target) {
      return binarySearch (list, target, low, mid_index - 1);
    } else {
      return binarySearch (list, target, mid_index + 1, high);
    }
  }
}

/*
Sorting algorithm # 1 - bubble sort

Repeatedly swapping adjacent elements if they are in the wrong order.
*/

std::vector <int> bubbleSort (std::vector <int> list) {
  for (int i = 0; i < list.size() - 1; i++) {
    for (int j = 0; j < list.size() - 1; j++) {
      if (list[j] > list[j+1]) {
        int temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
  return list;
}

/*
Sorting algorithm # 2 - insertion sort

Split the vector into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
*/

std::vector <int> insertionSort (std::vector <int> list) {
  for (int i = 1; i < list.size(); i++) {
    int key = list [i];
    int j = i - 1;
    while (j >= 0 && list [j] > key) {
      list [j+1] = list[j];
      j -= 1;
    }
    list [j+1] = key;
  }
  return list;
}

/*
Sorting algorithm # 3 - selection sort

Repeatedly finding the minimum element from the unsorted part and putting it at the beginning. 
*/

std::vector <int> selectionSort (std::vector <int> list) {
  for (int i = 0; i < list.size() - 1; i++) {
    int min_index = i;
    for (int j = i+1; j < list.size(); j++) {
      if (list [j] < list [min_index]) {
        min_index = j;
      }
    }
    int temp = list [min_index];
    list [min_index] = list [i];
    list [i] = temp;
  }
  return list;
}

int main() {

  std::vector <int> list_1 = {3, 7, 90, -4, 5, -100};
  std::vector <int> list_2 = {-100, -4, 3, 5, 7, 90};
  std::vector <int> list_3 = {7, 6, 5, 4};

  std::cout << "\nSearching algorithm # 1 - sequential search\n";
  std::cout << sequentialSearch (list_1, 90) << "\n";
  std::cout << sequentialSearch (list_1, 0) << "\n";

  std::cout << "\nSearching algorithm # 2 - binary search\n";
  std::cout << binarySearch (list_2, -100, 0, 5) << "\n";
  std::cout << binarySearch (list_2, 7, 0, 5) << "\n";
  std::cout << binarySearch (list_2, 65, 0, 5) << "\n";

  std::cout << "\nSorting algorithm # 1 - bubble sort\n";
  std::vector <int> sorted_1 = bubbleSort (list_3);
  print (sorted_1);

  std::cout << "\nSorting algorithm # 2 - insertion sort\n";
  std::vector <int> sorted_2 = insertionSort (list_3);
  print (sorted_2);

  std::cout << "\nSorting algorithm # 3 - selection sort\n";
  std::vector <int> sorted_3 = selectionSort (list_3);
  print (sorted_3);
  
}

/*
Question # 1: https://edabit.com/challenge/XkuhSLuuoknJPK3yr

Create a method that takes an array of numbers. Return the largest number in the array by first sorting the array. Examples:

[4, 5, 1, 3] ➞ [1, 3, 4, 5] ➞ 5
[300, 200, 600, 150] ➞ [150, 200, 300, 600] ➞ 600
[1000, 1001, 857, 1] ➞ [1, 857, 1000, 1001] ➞ 1001
*/

int findLargestNum (int arr[], int length) {
	for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return arr[length - 1];
}

/*
Question # 2: https://edabit.com/challenge/S8GJQhbGAkEXRpvmK

Create a method that determines the age difference between spouses in a household. If there is no difference, return "No age difference between spouses.". Otherwise, return the difference in years. Examples:

[29, 1, 6, 8, 28] ➞ "1 year"
[43, 86, 49, 86] ➞ "No age difference between spouses."
[2, 4, 6, 32, 27] ➞ "5 years"
*/

std::string ageDifference(std::vector<int> ages) {
  std::vector <int> sorted = insertionSort (ages);
  int difference = sorted[sorted.size() - 1] - sorted[sorted.size() - 2];
  if (difference == 0) {
    return "No age difference between spouses.";
  } else if (difference == 1) {
    return "1 year";
  }
  return std::to_string(difference) + "years";
}

/*
Question # 3: https://edabit.com/challenge/J3heQdX8zwaNZWaj9

Given an unsorted array, create a method that returns the nth smallest integer. Examples:

[1, 3, 5, 7], 1 ➞ 1
[7, 3, 5, 1], 2 ➞ 3
*/

int nthSmallest(std::vector<int> arr, int n) {
	std::vector <int> sorted = insertionSort(arr);
  return sorted [n - 1];
}

/*
Question # 4: https://edabit.com/challenge/aR45RpXY7YHdfEQWa

Create a method that takes any non-negative number as an argument and return it with its digits in descending order. Examples:

123 ➞ 321
2619805 ➞ 9865210
73065 ➞ 76530
*/

long long sortDescending(long long num) {
	std::vector <int> list;
  std::string temp = std::to_string (num);
  for (int i = 0; i < temp.length(); i++) {
    list.push_back (temp.at(i) - '0');
  }
  for (int i = 0; i < list.size() - 1; i++) {
    for (int j = 0; j < list.size() - 1; j++) {
      if (list[j] < list[j+1]) {
        int temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
  std::string result = "";
  for (int i = 0; i < list.size(); i++) {
    result += std::to_string(list[i]);
  }
  return std::stoll (result);
}

/*
Question # 5: https://edabit.com/challenge/LDNzJS27GY7aWNcBv

Create a method that returns an array of strings sorted by length in ascending order. Examples:

["a", "ccc", "dddd", "bb"] ➞ ["a", "bb", "ccc", "dddd"]
["apple", "pie", "shortcake"] ➞ ["pie", "apple", "shortcake"]
*/

std::vector<std::string> sortByLength(std::vector<std::string> arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - 1; j++) {
      if (arr[j].length() > arr[j+1].length()) {
        std::string temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return arr;
}

/*
Question # 6: https://edabit.com/challenge/kpc4XCxPhDtaBC6tY

Create a method that takes an array of numbers and a string and returns an array of numbers as per the following rules:
  - "Asc" returns a sorted array in ascending order.
  - "Des" returns a sorted array in descending order.
  - "None" returns an array without any modification.
Examples:

[4, 3, 2, 1], "Asc"  ➞ [1, 2, 3, 4]
[7, 8, 11, 66], "Des" ➞ [66, 11, 8, 7]
[1, 2, 3, 4], "None" ➞ [1, 2, 3, 4]
*/

std::vector<int> AscDesNone(std::vector<int> arr, std::string s) {
	if (s == "None") {
    return arr;
  } else if (s == "Asc") {
    return selectionSort (arr);
  }
  for (int i = 0; i < arr.size() - 1; i++) {
    int min_index = i;
    for (int j = i+1; j < arr.size(); j++) {
      if (arr [j] > arr [min_index]) {
        min_index = j;
      }
    }
    int temp = arr [min_index];
    arr [min_index] = arr [i];
    arr [i] = temp;
  }
  return arr;
}

/*
Question # 7: https://edabit.com/challenge/xRYSAT5uAhPHhvp6d

Create a sorting method which sorts numbers not by numerical order, but by number length. This means sorting numbers with the least amount of digits first, up to the numbers with the most digits. Examples:

[1, 54, 1, 2, 463, 2] ➞ [1, 1, 2, 2, 54, 463]
[999, 421, 22, 990, 32] ➞ [22, 32, 999, 421, 990]
*/

std::vector<int> numberLenSort(std::vector<int> arr) {
	int criteria = 1;
	std::vector<int> result;
	for(int i=0 ; i<7 ; i++){
		for(int j=0 ; j<arr.size() ; j++){
			std::string temp = std::to_string(arr[j]);
			if(temp.size()==criteria){
				result.push_back(arr[j]);
			}
		}
		criteria++;
	}
	return result;
}

/*
Question # 8: https://edabit.com/challenge/NGD8wv2rKoFDKzmEu

Create a method that accepts a string of space separated numbers and returns the highest and lowest number (as a string). Examples:

"1 2 3 4 5" ➞ "5 1"
"1 2 -3 4 5" ➞ "5 -3"
*/

std::string highLow(std::string str) {
	std::vector <int> list;
  for (int i = 0; i < str.length(); i++) {
    if (str.at(i) != ' ') {
      list.push_back(str.at(i) - '0');
    }
  }
  std::vector <int> sorted = insertionSort(list);
  return std::to_string (sorted[sorted.size() - 1]) + " " + std::to_string (sorted[0]);
}

/*
Question # 9: https://edabit.com/challenge/xwCz78P2chsEdKrr7

Write a method that sorts the positive numbers in ascending order, and keeps the negative numbers untouched. Examples:

[6, 3, -2, 5, -8, 2, -2] ➞ [2, 3, -2, 5, -8, 6, -2]
[6, 5, 4, -1, 3, 2, -1, 1] ➞ [1, 2, 3, -1, 4, 5, -1, 6]
*/

std::vector<int> posNegSort(std::vector<int> arr) {
  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr.size();j++){
      if(arr[i] > 0 && arr[j]>0 && arr[i]>arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  return arr;
}
