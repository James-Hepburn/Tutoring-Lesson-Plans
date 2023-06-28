#include <iostream>

int main() {

  std::cout << "You wake up and walk outside. You see trees burning, people turned into zombies, and buildings destroyed. You don't know what to do. You see a group of survivors getting on a bus but as you are heading to them you remember your belongings.\n\n";
  
  std::string option;
  std::cout << "Do you get on the 'bus' or go 'back'? ";
  std::cin >> option;
  
  if (option == "bus") { 
    std::cout << "You get on the bus. You ask a man what is going on. He replies that the world is ending. You are shocked and take a seat to think about what he just said. The man starts the bus and goes about 20 feet when all of a sudden you see a pack of zombies blocking the bus' path. Everyone panics.\n\n";
    
    std::string choice;
    std::cout << "Do you 'stop' and board the bus up, or 'run' them over? ";
    std::cin >> choice;
    
    if (choice == "stop") {
      std::cout << "You and others on the bus start boarding it up. You wait only a minute before the zombies reach the bus. They manage to break through and eat all of your brains. The end.\n\n";
    } else if (choice == "run") {
      std::cout << "The bus moves at an incredible speed. The driver sees a garage up ahead. He opens the door and yells for everyone to jump out of the bus and try to secure themseleves in the garage.\n\n";

      std::string decision;
      std::cout << "Do you 'jump' or 'stay'? ";
      std::cin >> decision;

      if (decision == "jump") {
        std::cout << "You jump out of the bus, along with a few others. You all run to the garage and discover a bomb shelter. You head down to the bomb shelter and lock you and the other survivors inside. You are safe ... for now. The end.\n\n";
      } else if (decision == "stay") {
        std::cout << "You stay on the bus with a few others, as some begin to jump out. The driver moves forward towards the herd of zombies. Soon, the bus crashes into them and flips on its side. The zombies break in and eat all of your brains. The end.\n\n";
      }
    }
  } else if (option == "back") {
    std::cout << "You turn around to get some of your belongings. As you head towards your house, a zombie catches you and eats your brains. The end.\n\n";
  }

}
