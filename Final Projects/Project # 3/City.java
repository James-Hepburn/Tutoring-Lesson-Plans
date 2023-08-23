public class City extends Location {
  private int population;

  public City(String name, double area, int population) {
    super(name, area);
    this.population = population;
  }

  public int getPopulation() {
    return population;
  }

  public void displayInfo() {
    super.displayInfo();
    System.out.println("Population: " + population);
  }
}
