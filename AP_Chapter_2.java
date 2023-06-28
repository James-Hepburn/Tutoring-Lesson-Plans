import java.util.LinkedList;
import java.util.Queue;

class AP_Chapter_2 {
  
  public static void main(String[] args) {

    // queues - a type of container with FIFO (first in first out)
    // useful for when the order of actions is important

    // create a queue

    Queue <Integer> q = new LinkedList <>();

    // add elements to the queue

    q.add (1);
    q.add (2);
    q.add (3);
    q.add (4);

    System.out.println (q);

    // get but do not remove the front element

    int front = q.peek();
    System.out.println ("front: " + front);

    // delete but do not get the front element

    q.poll();

    int new_front = q.peek();
    System.out.println ("new front: " + new_front);

    // size of the queue

    int size = q.size();
    System.out.println("size: " + size);
    
    // going through the elements of a queue

    while (q.size() != 0) {
      int current = q.peek();
      System.out.println ("current element: " + current);
      q.poll();
    }

    /*
    projects:

      - movie theatre
      - time needed
    */

    System.out.println ("\nQuestion # 1:");
    System.out.println (q1 ("EAS*Y*QUE***ST***IO*N***"));
    System.out.println (q1 ("FI*RSTI*N*FIR*ST**OU*T********"));

    Queue <Integer> test1 = new LinkedList <>();
    test1.add (1);
    test1.add (2);
    test1.add (3);
    test1.add (4);
    test1.add (5);

    Queue <Integer> test2 = new LinkedList <>();
    test2.add (87);
    test2.add (34);
    test2.add (44);
    test2.add (78);
    
    System.out.println ("\nQuestion # 2:");
    System.out.println (q2 (test1));
    System.out.println (q2 (test2));

    Queue <Integer> test3 = new LinkedList <>();
    test3.add (1);
    test3.add (2);
    test3.add (3);
    test3.add (4);
    test3.add (5);

    Queue <Integer> test4 = new LinkedList <>();
    test4.add (87);
    test4.add (34);
    test4.add (44);
    test4.add (78);

    System.out.println ("\nQuestion # 3:");
    System.out.println (q3 (test3));
    System.out.println (q3 (test4));

  }

  /*
  Question # 1:
  
  A letter means push and an asterisk means pop in the following sequence.  Give the sequence of values returned by the get operation when this sequence of operations is performed on an initially empty FIFO queue. Examples:
  
  EAS*Y*QUE***ST***IO*N*** ➞ EASYQUESTION
  FI*RSTI*N*FIR*ST**OU*T******** ➞ FIRSTINFIRSTOUT
  */

  public static String q1 (String s) {
    Queue <Character> q = new LinkedList<>();
    String res = "";
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '*') {
        res += q.peek();
        q.poll();
      } else {
        q.add (s.charAt(i));
      }
    }
    return res;
  }

  /*
  Question # 2:
  
  Given a queue, return its sum. Examples:
  
  [1, 2, 3, 4, 5] ➞ 15
  [87, 34, 44, 78] ➞ 243
  */

  public static int q2 (Queue <Integer> q) {
    int sum = 0;
    while (q.size() != 0) {
      sum += q.peek();
      q.poll();
    }
    return sum;
  }

  /*
  Question # 3:
  
  Given a queue of integers, return the element in the middle. If there is an even amount of numbers, return the left side middle element. Examples:
  
  [1, 2, 3, 4, 5] ➞ 3
  [87, 34, 44, 78] ➞ 34
  */

  public static int q3 (Queue <Integer> q) {
    int middle;
    if (q.size() % 2 == 0) {
      middle = q.size() / 2 - 1;
    } else {
      middle = q.size() / 2;
    }
    for (int i = 0; i < middle; i++) {
      q.poll();
    }
    return q.peek();
  }
  
}
