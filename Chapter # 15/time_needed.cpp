#include <iostream>
#include <queue>

int answer (std::queue <int> tickets, int k) {
  int time = 0;
  int pos = 1;
  
  while (tickets.size() != 0) {
    
    int f = tickets.front();
    tickets.pop();

    if (f > 0) {
      time += 1;
    } 

    if (pos == k && f - 1 == 0) {
      break;
    }

    tickets.push(f-1);
    pos += 1;

    if (pos == tickets.size() + 1) {
      pos = 1;
    }

  }

  return time;
}

int main() {

  std::cout << "\nProgram Description: \n\n";
  std::cout << "There are people in a line queuing to buy tickets. Each person takes exactly 1 minute to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line in order to buy more tickets. For the sake of this program, if the person does not have anymore tickets to buy, they will still enter the line but will not purchase anymore tickets.\n";

  std::cout << "\nExamples:\n\n";
  std::cout << "tickets = [2,3,2], pos = 3 -> answer = 6\n";
  std::cout << "tickets = [5,1,1,1], pos = 1 -> answer = 8\n\n";

  std::queue <int> tickets;
  int counter = 1;

  while (true) {
    int number;
    std::cout << "Enter how many tickets person " << counter << " is buying or enter '-1' to quit: ";
    std::cin >> number;
    if (number == -1) {
      break;
    } 
    tickets.push(number);
    counter += 1;
  }

  int k;
  std::cout << "\nWhich person would you like to calculate the time for? ";
  std::cin >> k;

  std::cout << "\nIt would take person-" << k << " " << answer(tickets, k) << " minutes.\n";
  
}
