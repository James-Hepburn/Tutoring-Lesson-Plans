import java.util.Scanner;

class Main {
  
  public static void main(String[] args) {

    Scanner input = new Scanner (System.in);

    Continent asia = new Continent("Asia", 44580000, 49);
    Continent africa = new Continent("Africa", 30370000, 54);
    Continent northAmerica = new Continent("North America", 24709000, 23);
    Continent southAmerica = new Continent("South America", 17840000, 12);
    Continent europe = new Continent("Europe", 10180000, 44);
    Continent australia = new Continent("Australia", 8600000, 14);
    Continent antarctica = new Continent("Antarctica", 14000000, 0);

    Country china = new Country("China", 9596961, "Asia");
    Country egypt = new Country("Egypt", 1001450, "Africa");
    Country canada = new Country("Canada", 9984670, "North America");
    Country argentina = new Country("Argentina", 2780400, "South America");
    Country germany = new Country("Germany", 357022, "Europe");
    Country newZealand = new Country("New Zealand", 268680, "Australia");

    City beijing = new City("Beijing", 16411, 21707000);
    City cairo = new City("Cairo", 606, 20000000);
    City toronto = new City("Toronto", 630.2, 2731571);
    City buenosAires = new City("Buenos Aires", 203, 2891082);
    City berlin = new City("Berlin", 891.8, 3769495);
    City auckland = new City("Auckland", 133, 1554300);

    System.out.println ("\nGeographical Information! \n");
    System.out.println ("1) View Continent Information");
    System.out.println ("2) View Country Information");
    System.out.println ("3) View City Information");
    System.out.print ("\nYour selection: ");
    int selection = input.nextInt();

    if (selection == 1) {
      System.out.println ("\nContinent Information: \n");
      System.out.println ("1) Asia");
      System.out.println ("2) Africa");
      System.out.println ("3) North America");
      System.out.println ("4) South America");
      System.out.println ("5) Europe");
      System.out.println ("6) Australia");
      System.out.println ("7) Antarctica");
      System.out.print ("\nYour selection: ");
      int continent = input.nextInt();

      if (continent == 1) {
        asia.displayInfo ();
      } else if (continent == 2) {
        africa.displayInfo ();
      } else if (continent == 3) {
        northAmerica.displayInfo ();
      } else if (continent == 4) {
        southAmerica.displayInfo ();
      } else if (continent == 5) {
        europe.displayInfo ();
      } else if (continent == 6) {
        australia.displayInfo ();
      } else if (continent == 7) {
        antarctica.displayInfo ();
      } else {
        System.out.println ("\nInvalid selection.");
      }
    }
    
    else if (selection == 2) {
      System.out.println ("\nCountry Information: \n");
      System.out.println ("1) China");
      System.out.println ("2) Egypt");
      System.out.println ("3) Canada");
      System.out.println ("4) Argentina");
      System.out.println ("5) Germany");
      System.out.println ("6) New Zealand");
      System.out.print ("\nYour selection: ");
      int country = input.nextInt();

      if (country == 1) {
        china.displayInfo();
      } else if (country == 2) {
        egypt.displayInfo();
      } else if (country == 3) {
        canada.displayInfo();
      } else if (country == 4) {
        argentina.displayInfo();
      } else if (country == 5) {
        germany.displayInfo();
      } else if (country == 6) {
        newZealand.displayInfo();
      } else {
        System.out.println ("\nInvalid selection.");
      }
    }

    else if (selection == 3) {
      System.out.println ("\nCity Information: \n");
      System.out.println ("1) Beijing");
      System.out.println ("2) Cairo");
      System.out.println ("3) Toronto");
      System.out.println ("4) Buenos Aires");
      System.out.println ("5) Berlin");
      System.out.println ("6) Auckland");
      System.out.print ("\nYour selection: ");
      int city = input.nextInt();

      if (city == 1) {
        beijing.displayInfo();
      } else if (city == 2) {
        cairo.displayInfo();
      } else if (city == 3) {
        toronto.displayInfo();
      } else if (city == 4) {
        buenosAires.displayInfo();
      } else if (city == 5) {
        berlin.displayInfo();
      } else if (city == 6) {
        auckland.displayInfo();
      } else {
        System.out.println ("\nInvalid selection.");
      }
    }

    else {
      System.out.println ("\nInvalid selection.");
    }
    
  }
  
}
