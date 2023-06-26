#include <iostream>

// protected means private but can be accessed from derived classes

class person {
  protected:
    std::string name;
    int age;
  public:
    void set_name (std::string n) {
      name = n;
    }
    void set_age (int a) {
      age = a;
    }
    void display () {
      std::cout << name << " is " << age << " years old.\n";
    }
};

class student : public person {
  protected:
    std::string course;
    std::string grade;
  public:
    void set_course (std::string c) {
      course = c;
    }
    void set_grade (std::string g) {
      grade = g;
    }
    void display () {
      std::cout << "Student " << name << " is " << age << " years old and has completed " << course << " with a grade of " << grade << ".\n";
    }
};

int main() {

  person p1;
  p1.set_name ("John");
  p1.set_age (20);
  p1.display ();

  student s1;
  s1.set_name ("Carl");
  s1.set_age (16);
  s1.set_course ("CS");
  s1.set_grade ("A");
  s1.display ();

  /*
  Exercise:

  Create a class for a vehicle. It will have attributes for the number of wheels and the number of doors. It will have a method that prints out its description.

  Create a class for a car. It will have attributes for the colour and the brand (Honda, Mercedes, etc.). It will have a method that prints out its descritpion.

  Create objects for each class. Use all of their methods.
  */
  
}
