import java.util.Random;
import java.util.Stack;

public class Customer {

  private int id;
  private Random r = new Random ();
  private Stack <Item> items = new Stack <>();

  public Customer () {
    id = 1 + r.nextInt (100);
  }

  public void add_item (Item i) {
    items.push (i);
  }

  public void purchase_items () {
    System.out.println ("\nHere is your receipt: \n");
    double total = 0;
    while (items.size() != 0) {
      Item i = items.peek();
      items.pop();
      i.display();
      total += i.get_price ();
    }
    total = Math.round (total * 100.0) / 100.0;
    System.out.println ("\nTotal: $" + total);
  }

  public Item generate_item () {
    int item = 1 + r.nextInt (10);
    if (item == 1) {
      return new Item ("Milk", 2.99);
    } else if (item == 2) {
      return new Item ("Bread", 1.99);
    } else if (item == 3) {
      return new Item ("Eggs", 2.49);
    } else if (item == 4) {
      return new Item ("Apples", 1.29);
    } else if (item == 5) {
      return new Item ("Chicken", 5.99);
    } else if (item == 6) {
      return new Item ("Rice", 3.49);
    } else if (item == 7) {
      return new Item ("Pasta", 1.79);
    } else if (item == 8) {
      return new Item ("Tomatoes", 0.99);
    } else if (item == 9) {
      return new Item ("Cereal", 3.99);
    } else {
      return new Item ("Cheese", 4.29);
    }
  }

  public void generate_cart () {
    int cart = 1 + r.nextInt (5);
    for (int i = 0; i < cart; i++) {
      Item it = generate_item ();
      add_item (it);
    }
  }

  public int get_id () {
    return id;
  }
  
}
