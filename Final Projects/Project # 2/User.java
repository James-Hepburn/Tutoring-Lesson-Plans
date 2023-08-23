public class User {

  private String name;
  private Book book;

  public User (String name) {
    this.name = name;
    book = null;
  }

  public String get_name () {
    return name;
  }

  public void set_book (Book b) {
    book = b;
  }

  public Book get_book () {
    return book;
  }
  
}
