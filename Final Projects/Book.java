public class Book {

  private String title;
  private String author;
  private User reader;

  public Book (String title, String author) {
    this.title = title;
    this.author = author;
    reader = null;
  }

  public void print_information () {
    System.out.print ("\n" + title + " written by " + author);
    if (reader == null) {
      System.out.print (" - [in library] ");
    } else {
      System.out.print (" - [with " + reader.get_name () + "] ");
    }
  }

  public void set_reader (User u) {
    reader = u;
  }

  public String get_title () {
    return title;
  }

  public String get_author () {
    return author;
  }

  public User get_reader () {
    return reader;
  }
  
}
