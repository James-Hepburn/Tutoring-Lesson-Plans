import java.util.Stack;

public class AP_Chapter_1 {
  
  public static void main(String[] args) {

    // stacks - a type of container with LIFO (last in first out)
    // useful for when the order of actions is important
    
    // create a stack 
    
    Stack <Integer> stack = new Stack<>();

    // push elements to the stack
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    // print the top element
    
    System.out.println("Top element: " + stack.peek());

    // pop elements from the stack
    
    System.out.println("Popped element: " + stack.pop());
    System.out.println("Popped element: " + stack.pop());
    
    // print the top element
    
    System.out.println("Top element: " + stack.peek());

    // check if the stack is empty
    
    System.out.println("Is stack empty? " + stack.isEmpty());

    // check the size of a stack
    
    System.out.println("Stack size: " + stack.size());

    // go through elements of a stack
    
    Stack <String> temp = new Stack<>();
    temp.push("a");
    temp.push("b");
    temp.push("c");

    while (temp.isEmpty() == false) {
      String top = temp.peek();
      System.out.println ("Element: " + top);
      temp.pop();
    }

    /*
    projects:

      - prefix and postfix calculator
      - statement checker
    */
    
  }

  /*
  Question # 1:
  
  A letter means push and an asterisk means pop in the following sequence. Give the sequence of values returned by the pop operations when this sequence of operations is performed on an initially empty LIFO stack. Examples:
  
  EAS*Y*QUE***ST***IO*N*** ➞ SYEUQTSAONIE
  LA*STI*N*FIR*ST**OU*T****** ➞ AINRTSUTOIFTS
  */
  
  public static String q1 (String sequence) {
    Stack<Character> s = new Stack<>();
    String res = "";
    for (int i = 0; i < sequence.length(); i++) {
      if (sequence.charAt(i) == '*') {
        res += s.peek();
        s.pop();
      } else {
        s.push(sequence.charAt(i));
      }
    } 
    return res;
  }
  
  /*
  Question # 2:
  
  Write a program that reads in a sequence of characters and returns them in reverse order. Use a stack. Examples:
  
  apple ➞ elppa
  car ➞ rac
  */
  
  public static String q2 (String sequence) {
    Stack<Character> s = new Stack<>();
    String res = "";
    for (int i = 0; i < sequence.length(); i++) {
      s.push(sequence.charAt(i));
    }  
    while (!s.isEmpty()) {
      res += s.peek();
      s.pop();
    }
    return res;
  }
  
  /*
  Question # 3:
  
  Given a line of text, reverse the text without reversing the individual words. Examples:
  
  Happy New Year ➞ Year New Happy
  Use a stack ➞ stack a Use
  */
  
  public static String q3 (String text) {
    Stack<String> s = new Stack<>();
    String word = "";
    for (int i = 0; i < text.length(); i++) {
      if (text.charAt(i) ==' ') {
        s.push(word);
        word = "";
      } else {
        word += text.charAt(i);
      }
    }
    s.push(word);
    String res = "";
    while (!s.isEmpty()) {
      res += s.peek() + " ";
      s.pop();
    }
    return res;
  }
  
}
