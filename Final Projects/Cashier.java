import java.util.Queue;
import java.util.LinkedList;

public class Cashier {

  private Queue <Customer> customers = new LinkedList <>();

  public Cashier () {
    
  }

  public void add_customer (Customer c) {
    customers.add (c);
  }

  public void serve_customer () {
    Customer c = customers.peek();
    System.out.println ("\nNext customer (id # " + c.get_id () + ") is up!");
    customers.poll();
    c.purchase_items();
  }
  
}
