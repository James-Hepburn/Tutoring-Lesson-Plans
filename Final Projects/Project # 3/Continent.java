public class Continent extends Location {
  private int countriesCount;

  public Continent(String name, double area, int countriesCount) {
    super(name, area);
    this.countriesCount = countriesCount;
  }

  public int getCountriesCount() {
    return countriesCount;
  }

  public void displayInfo() {
    super.displayInfo();
    System.out.println("Number of Countries: " + countriesCount);
  }
}
