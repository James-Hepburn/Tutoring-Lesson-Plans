import java.util.Set;
import java.util.HashSet;

class AP_Chapter_3 {
  
  public static void main(String[] args) {

    // sets are a container of elements, where each element is unique
    // in increasing order by default
    // do not have indexes

    // making a set

    Set <Integer> s = new HashSet <>();

    // adding elements

    s.add (4);
    s.add (3);
    s.add (2);
    s.add (1);
    s.add (1);

    System.out.println (s);

    // deleting elements

    s.remove (3);

    System.out.println (s);

    // finding if set contains an element

    boolean found = s.contains (3);

    System.out.println (found);

    // size

    int length = s.size();

    System.out.println (length);

    // going through all the elements

    for (int current : s) {
      System.out.println (current);
    }

    /*
    projects:
  
      - set operations
      - mini sudoku solver
      - strings and sets 
    */
    
  }

  /*
  Question # 1:
  
  Given a set, return the largest number in the set multiplied by the smallest number in the set. Assume the set has at least one number and that all numbers within the set are in the range 1 to 100. Examples:
  
  {1, 2, 3, 4, 5} ➞ 5 because 1 x 5 = 5
  {10, 20, 30} ➞ 300 because 10 x 30 = 300
  */

  public static int q1 (Set <Integer> s) {
    int largest = 1;
    int smallest = 100;
    for (int i : s) {
      if (i > largest) {
        largest = i;
      }
      if (i < smallest) {
        smallest = i;
      }
    }
    return largest * smallest;
  }

  /*
  Question # 2:
  
  Given a set, return the sum of all the even numbers subtracted by the sum of all the odd numbers in the set. Examples: 
  
  {4, 7, 12, 9, 17} ➞ -17 because (4 + 12) - (7 + 9 + 17) = 16 - 33 = -17
  {38, 72, 43} ➞ 67 because because (38 + 72) - 43 = 110 - 43 = 67
  */

  public static int q2 (Set <Integer> s) {
    int even = 0;
    int odd = 0;
    for (int i : s) {
      if (i % 2 == 0) {
        even += i;
      } else {
        odd += i;
      }
    }
    return even - odd;
  }

  /*
  Question # 3:
  
  Given a set of strings, delete all strings that contain the letter 'a' and return the resulting strings. Examples:
  
  {apple, car, door, english, crab} ➞ {door, english}
  {pebble, max, notebook, coins} ➞ {pebble, notebook, coins}
  */

  public static Set <String> q3 (Set <String> s) {
    Set <String> result = new HashSet <>();
    for (String i : s) {
      boolean has_a = false;
      for (int j = 0; j < i.length(); j++) {
        if (i.charAt(j) == 'a') {
          has_a = true;
        }
      }
      if (has_a == false) {
        result.add (i);
      }
    }
    return result;
  }

  /*
  Question # 4:
  
  Assume a set must have the numbers from 1 to 10. In this question, you will be given a set and must return a set with the missing numbers. Examples:
  
  {1, 2, 3, 4, 5} ➞ {6, 7, 8, 9, 10}
  {1, 3, 5, 6, 7, 8, 9} ➞ {2, 4, 10}
  */

  public static Set <Integer> q4 (Set <Integer> s) {
    Set <Integer> result = new HashSet <>();
    for (int i = 1; i <= 10; i++) {
      if (s.contains(i) == false) {
        result.add (i);
      }
    }
    return result;
  }
  
}
