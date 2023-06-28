#include <iostream>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <string>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

// event class

class event {

  private:

    int day, month, year, hour, minute;
    std::string noon, description;

  public:

    event (int d, int m, int y, int h, int min, std::string n, std::string des) {
      day = d;
      month = m;
      year = y;
      hour = h;
      minute = min;
      noon = n;
      description = des;
    }

    int get_day () {
      return day;
    }

    int get_month () {
      return month;
    }

    int get_year () {
      return year;
    }

    int get_hour () {
      return hour;
    }

    int get_minute () {
      return minute;
    }

    std::string get_noon () {
      return noon;
    }

    void print_event () {
      std::cout << "EVENT = " << description << "\n";
      std::cout << "  - DATE = " << year << " / " << month << " / " << day << "\n";
      std::cout << "  - TIME = " << hour << " : " << minute << " " << noon << "\n\n";
    }
  
};

// global variables

std::vector <event> events;
int option, day, month, year, hour, minute;
std::string noon, description;

// exception methods

void valid_option () {
  std::cout << "\nWhich option would you like to select? ";
  std::cin >> option;

  if (option > 3 || option < 1) {
    throw std::runtime_error ("Invalid option.");
  } 

  else if (option == 1 && events.size() == 0) {
    throw std::runtime_error ("No events are scheduled.");
  }
}

void valid_date () {
  std::cout << "\nWhat day is the event? ";
  std::cin >> day;
  if (day > 31 || day < 1) {
    throw std::runtime_error ("Invalid date.");
  }
  
  std::cout << "What month is the event? ";
  std::cin >> month;
  if (month > 12 || month < 1) {
    throw std::runtime_error ("Invalid date.");
  }
  
  std::cout << "What year is the event? ";
  std::cin >> year;
  if (year < 2023) {
    throw std::runtime_error ("Invalid date.");
  }
  
  std::cout << "What hour is the event? ";
  std::cin >> hour;
  if (hour > 12 || hour < 1) {
    throw std::runtime_error ("Invalid time.");
  }
  
  std::cout << "What minute is the event? ";
  std::cin >> minute;
  if (minute > 59 || minute < 0) {
    throw std::runtime_error ("Invalid time.");
  }
  
  std::cout << "AM or PM? ";
  std::cin >> noon;
  if (noon != "AM" && noon != "PM") {
    throw std::runtime_error ("Invalid time.");
  }

  // std::cout << "What is the event? ";
  // std::getline (std::cin, description);

  for (int i = 0; i < events.size(); i++) {
    event e = events[i];
    if (e.get_day() == day && e.get_month() == month && e.get_year() == year && e.get_hour() == hour && e.get_minute() == minute && e.get_noon() == noon) {
    throw std::runtime_error ("Conflicting date.");
    }
  }
}

int main() {

  erase (0);

  while (true) {
  
    std::cout << "Welcome to the Event Scheduler! \n\n";
    std::cout << "1) View all events \n";
    std::cout << "2) Add an event \n";
    std::cout << "3) Exit \n";
  
    try {
      valid_option();

      if (option == 1) {
        for (int i = 0; i < events.size(); i++) {
          events[i].print_event();
        }
      }

      else if (option == 2) {
        try {
          valid_date();
          
          event e = event (day, month, year, hour, minute, noon, description);
          events.push_back (e);
        }

        catch (const std::runtime_error& e) {
          std::cout << "\nError: " << e.what() << "\n";
        }
      }

      else if (option == 3) {
        std::cout << "\nGoodbye. \n";
        break;
      }
    }

    catch (const std::runtime_error& e) {
      std::cout << "\nError: " << e.what() << "\n";
    }

    erase (5000000);

  }
  
}
