#include <iostream>
#include <unistd.h>

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

class bank_account {

  private:

    std::string account_holder;
    int pin;
    long account_number;
    int balance;

  public:

    bank_account (std::string a_h, int p, long a_n) {
      account_holder = a_h;
      pin = p;
      account_number = a_n;
      balance = 0;
    }

    std::string get_a_h () {
      return account_holder;
    }

    int get_pin () {
      return pin;
    }

    long get_a_n () {
      return account_number;
    }

    int get_balance () {
      return balance;
    }

    void deposit (int amount) {
      balance += amount;
    }

    void withdraw (int amount) {
      balance -= amount;
    }

};

int main() {
  
  std::cout << "\nWelcome to the Bank!\n";

  std::cout << "\nTo use this ATM, you must have a bank account. Please enter the information below to create an account.\n";

  std::string account_holder;
  std::cout << "\nAccount Holder: ";
  std::cin >> account_holder;

  std::string temp1;
  while (temp1.length() != 12) {
    std::cout << "Account Number: ";
    std::cin >> temp1;
  }
  long account_number = std::stol (temp1);

  std::string temp2;
  while (temp2.length() != 4) {
    std::cout << "PIN: ";
    std::cin >> temp2;
  }
  int pin = std::stoi (temp2);

  erase (3000000);
  bank_account account = bank_account (account_holder, pin, account_number);

  /*
  std::cout << "\nGreat! Now you must login!\n\n";

  long account_num;
  int PIN;

  while (PIN != account.get_pin() || account_num != account.get_a_n()) {
    std::cout << "Enter your account number: ";
    std::cin >> account_num;
  
    std::cout << "Enter your PIN: ";
    std::cin >> PIN;
  }
  */

  std::cout << "\nYou have successfully logged in!\n";

  int option;
  while (option != 4) {
     erase (3000000);
    std::cout << "\nWelcome " << account.get_a_h() << "!\n";
    std::cout << "\nWould you like to \n";
    std::cout << "1) View your balance\n";
    std::cout << "2) Deposit money\n";
    std::cout << "3) Withdraw money\n";
    std::cout << "4) Log out\n";
    std::cin >> option;

    if (option == 1) {
      std::cout << "\nBalance: $" << account.get_balance() << "\n";
    } else if (option == 2) {
      int amount;
      std::cout << "\nHow much money would you like to deposit? ";
      std::cin >> amount;
      account.deposit (amount);
    } else if (option == 3) {
      int amount;
      std::cout << "\n";
      while (true) {
        std::cout << "How much money would you like to withdraw? ";
        std::cin >> amount;
        if (amount <= account.get_balance()) {
          break;
        }
      }
      account.withdraw (amount);
    } else if (option == 4) {
      std::cout << "\nLogging out.\n";
    } else {
      std::cout << "\nInvalid input.\n";
    }
  }

}
