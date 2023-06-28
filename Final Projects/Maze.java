import java.util.Scanner;

class Maze {

  public static Scanner input = new Scanner (System.in);

  public static char [][] maze = {{'S', '#', '#', '#', '#'}, {'.', '.', '.', '.', '#'}, {'#', '#', '#', '.', '#'}, {'#', '.', '.', '.', '.'}, {'#', '#', '#', '#', 'E'}};

  public static int row = 0;
  public static int column = 0;
  
  public static void main(String[] args) {

    while (maze[row][column] != 'E') {
      clear ();
      print_maze ();
      move ();
    }

    clear ();
    print_maze ();
    System.out.println ("\nYou win! ");
    
  }

  public static void clear () {
    try {
      Thread.sleep(1500);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.print("\033[H\033[2J");
    System.out.flush();
  }

  public static void print_maze () {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (i == row && j == column) {
          System.out.print ("\033[1;31m" + maze[i][j] + "\033[0m ");
        } else {
          System.out.print (maze[i][j] + " ");
        }
      }
      System.out.println ();
    }
  }

  public static void move () {
    System.out.print ("\nWhich direction? (U, D, L, R) ");
    char direction = input.nextLine().charAt(0);

    if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R') {
      System.out.println ("Error: Invalid direction. ");
      return;
    }

    int temp_row = row;
    int temp_column = column;

    if (direction == 'U') {
      temp_row -= 1;
    } else if (direction == 'D') {
      temp_row += 1;
    } else if (direction == 'R') {
      temp_column += 1;
    } else if (direction == 'L') {
      temp_column -= 1;
    }

    if (temp_row < 0 || temp_row > 4 || temp_column < 0 || temp_column > 4) {
      System.out.println ("Error: Out of bounds. ");
      return;
    } else if (maze[temp_row][temp_column] == '#') {
      System.out.println ("Error: Hit a wall. ");
      return;
    }

    row = temp_row;
    column = temp_column;
  }
  
}
