public class Book {

  private String title;
  private String author;
  private String reader;

  public Book (String title, String author) {
    this.title = title;
    this.author = author;
    reader = "in library";
  }

  public void print_information () {
    System.out.print ("\n" + title + " written by " + author);
    System.out.print (" - [" + reader + "]");
  }

  public void set_reader (String name) {
    reader = "with " + name;
  }

  public String get_title () {
    return title;
  }

  public String get_author () {
    return author;
  }

  public String get_reader () {
    return reader;
  }
  
}
