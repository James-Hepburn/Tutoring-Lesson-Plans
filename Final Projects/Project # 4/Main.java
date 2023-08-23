import java.util.Scanner;

class Main {
  
  public static void main(String[] args) {

    Scanner input = new Scanner (System.in);

    Cashier cashier = new Cashier ();

    System.out.println ("\nWelcome to the grocery store!\n");

    System.out.print ("How many customers will be served today? ");
    int customers = input.nextInt();

    for (int i = 0; i < customers; i++) {
      Customer c = new Customer ();
      c.generate_cart ();
      cashier.add_customer (c);
    }

    System.out.println ("\nGreat all of the customers are in line and will now be served!");

    for (int i = 0; i < customers; i++) {
      cashier.serve_customer ();
    }

    System.out.println ("\nAll customers have been served! Have a great day!");
    
  }
  
}
