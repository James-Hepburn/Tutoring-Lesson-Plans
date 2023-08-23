public class Country extends Location {
  private String continent;

  public Country(String name, double area, String continent) {
    super(name, area);
    this.continent = continent;
  }

  public String getContinent() {
    return continent;
  }

  public void displayInfo() {
    super.displayInfo();
    System.out.println("Continent: " + continent);
  }
}
