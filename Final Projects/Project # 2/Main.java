import java.util.Scanner;
import java.util.ArrayList;

class Main {

  public static Scanner input = new Scanner (System.in);
  public static ArrayList <Book> books = new ArrayList <>();
  
  public static void main(String[] args) {

    books.add (new Book ("To Kill a Mockingbird", "Harper Lee"));
    books.add (new Book ("1984", "George Orwell"));
    books.add (new Book ("The Great Gatsby", "F. Scott Fitzgerald"));
    books.add (new Book ("Pride and Prejudice", "Jane Austen"));
    books.add (new Book ("The Catcher in the Rye", "J.D. Salinger"));

    while (true) {
      clear ();
      
      System.out.println ("\nWelcome to your local library! \n");
      System.out.println ("1) View all books");
      System.out.println ("2) View all available books");
      System.out.println ("3) Sign out a book");
      System.out.println ("4) Sign in a book");
      System.out.println ("5) Exit");
  
      System.out.print ("\nWhich option would you like to select? ");
      int option = input.nextInt ();
  
      if (option == 1) {
        view_all();
      } else if (option == 2) {
        view_available();
      } else if (option == 3) {
        sign_out();
      } else if (option == 4) {
        sign_in();
      } else if (option == 5) {
        System.out.println ("\nGoodbye. ");
        break;
      }
    }
    
  }

  public static void clear () {
    try {
      Thread.sleep(1500);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.print("\033[H\033[2J");
    System.out.flush();
  }

  public static void stay () {
    try {
      Thread.sleep(5000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  public static void view_all () {
    System.out.println ("\nHere are all the books in the library:");
    for (int i = 0; i < books.size(); i++) {
      books.get(i).print_information();
    }
    stay ();
  }

  public static void view_available () {
    System.out.println ("\nHere are all the books that are available in the library currently:");
    for (int i = 0; i < books.size(); i++) {
      if (books.get(i).get_reader().equals ("in library")) {
        books.get(i).print_information();
      }
    }
    stay ();
  }

  public static Book find_book (String title, String author) {
    for (int i = 0; i < books.size(); i++) {
      if (books.get(i).get_title().equals (title) && books.get(i).get_author().equals (author)) {
        return books.get(i);
      }
    }
    return null;
  }

  public static void sign_out () {
    input.nextLine();
    System.out.print ("\nWhat is the title of the book you would like to sign out? ");
    String title = input.nextLine ();
    System.out.print ("Who is the author of the book you would like to sign out? ");
    String author = input.nextLine ();

    Book b = find_book (title, author);
    if (b == null) {
      System.out.println ("Sorry, that book does not exist in the library.");
      return;
    } else if (! b.get_reader().equals ("in library")) {
      System.out.println ("Sorry, that book is not available currently.");
      return;
    }

    System.out.print ("What is your name? ");
    String name = input.nextLine();
    b.set_reader (name);
  }

  public static void sign_in () {
    input.nextLine();
    System.out.print ("\nWhat is the title of the book you would like to sign in? ");
    String title = input.nextLine ();
    System.out.print ("Who is the author of the book you would like to sign in? ");
    String author = input.nextLine ();

    Book b = find_book (title, author);
    if (b == null) {
      System.out.println ("Sorry, that book does not exist in the library.");
      return;
    } else if (b.get_reader().equals("in library")) {
      System.out.println ("Sorry, that book has already been returned.");
      return;
    }

    System.out.print ("What is your name? ");
    String name = input.nextLine ();
    
    if (! b.get_reader().equals("with " + name)) {
      System.out.println ("Sorry, that book is not signed out by that user.");
      return;
    }

    b.set_reader ("in library");
  }
  
}
