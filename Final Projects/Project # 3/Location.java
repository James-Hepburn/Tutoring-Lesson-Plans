public class Location {
  private String name;
  private double area;

  public Location(String name, double area) {
    this.name = name;
    this.area = area;
  }

  public String getName() {
    return name;
  }

  public double getArea() {
    return area;
  }

  public void displayInfo() {
    System.out.println("\nLocation: " + name);
    System.out.println("Area: " + area + " square kilometers");
  }
}
