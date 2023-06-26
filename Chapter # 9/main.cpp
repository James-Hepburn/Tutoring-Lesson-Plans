#include <iostream>

/*
Exercise:

Make a class for a book. The class must have the following:

1. Attributes for the title of the book and its author
2. Constructor
3. Getters for title and author
4. Setters for title and author
5. Method that prints out a description of the book

Once you have coded the class file, make an object of this class and use all of the methods that exist for this file.
*/

class person {

  private:

    int age;
    std::string name;

  public:

    person (int a, std::string n) {
      age = a;
      name = n;
    }
  
    int get_age () {
      return age;
    }
  
    std::string get_name () {
      return name;
    }
  
    void set_age (int a) {
      age = a;
    }

    void set_name (std::string n) {
      name = n;
    }

    void description () {
      std::cout << name << " is " << age << " years old.\n";
    }
    
};

class book {

  private:

    std::string title;
    std::string author;

  public:

    book (std::string t, std::string a) {
      title = t;
      author = a;
    }
  
    std::string get_title () {
      return title;
    }
  
    std::string get_author () {
      return author;
    }
  
    void set_title (std::string t) {
      title = t;
    }

    void set_author (std::string a) {
      author = a;
    }

    void description () {
      std::cout << title << " is a book written by " << author << ".\n";
    }
    
};

int main() {

  person p1 = person (25, "John");

  p1.set_name("Rick");
  std::string name = p1.get_name();
  std::cout << name << "\n";

  p1.set_age(26);
  int age = p1.get_age();
  std::cout << age << "\n";

  p1.description();

  // exercise

  book b1 = book ("Animal Farm", "George Orwell");

  b1.set_title("The Minister's Black Veil");
  std::string title = b1.get_title();
  std::cout << title << "\n";

  b1.set_author ("Nathaniel Hawthorne");
  std::string author = b1.get_author();
  std::cout << author << "\n";

  b1.description();

}
