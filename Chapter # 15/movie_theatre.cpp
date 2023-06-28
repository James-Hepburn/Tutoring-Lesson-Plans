#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>

class movie {

  private:

    std::string name;
    int minutes;
    int age_rating;
    std::string time_playing;

  public:

    movie (std::string n, int m, int ar, std::string tp) {
      name = n;
      minutes = m;
      age_rating = ar;
      time_playing = tp;
    }

    std::string get_name () {
      return name;
    }

    int get_minutes () {
      return minutes;
    }

    int get_age_rating () {
      return age_rating;
    }

    std::string get_time_playing () {
      return time_playing;
    }

    void get_description () {
      std::cout << "- " << name << ": \n";
      std::cout << "  - age rating: " << age_rating << "\n";
      std::cout << "  - run time (minutes): " << minutes << "\n";
      std::cout << "  - time playing: " << time_playing << "\n\n";
    }

};

class patron {

  private:

    std::string film;

  public:

    patron (std::string f) {
      film = f;
    }

    std::string get_film () {
      return film;
    }

    void greet () {
      std::cout << "Hello! \n\n";
      std::cout << "I just have a few questions about the movie '" << film << "'. \n\n";
    }

    void ask_time_playing () {
      std::cout << "What time is the movie playing? \n\n";
    }

    void ask_age_rating () {
      std::cout << "What is the age rating of this movie? \n\n";
    }

    void ask_running_time () {
      std::cout << "What is the runtime of this movie? \n\n";
    }

    void finish () {
      std::cout << "Great! I will take " << rand() % 5 << " tickets please. \n\n";
    }

};

void erase (int microseconds) {
  usleep(microseconds); 
  std::cout << "\033[2J\033[1;1H";
}

patron generate_patron () {
  std::vector <std::string> movies = {"Shrek", "American Psycho", "Inception"};
  std::string movie = movies [rand() % 3];
  return patron (movie);
}

std::vector <int> generate_questions () {
  std::vector <int> questions;
  int number = 1 + rand() % 3;
  for (int i = 0; i < number; i++) {
    questions.push_back(i);
  }
  return questions;
}

void ask_question (patron p, int question) {
  if (question == 1) {
    p.ask_time_playing();
  } else if (question == 2) {
    p.ask_age_rating();
  } else {
    p.ask_running_time();
  }
}

bool question1 (movie m) {
  std::cout << "1) 3 pm \n";
  std::cout << "2) 9 pm \n";
  std::cout << "3) 5 pm \n";
  int answer;
  std::cout << "What time is " << m.get_name() << " playing? ";
  std::cin >> answer;
  if (answer == 1 && m.get_name() == "Shrek") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 2 && m.get_name() == "American Psycho") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 3 && m.get_name() == "Inception") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else {
    std::cout << "\nIncorrect! You did not answer the customer's question efficiently! \n";
    return false;
  }
}

bool question2 (movie m) {
  std::cout << "1) 6 and up \n";
  std::cout << "2) 18 and up \n";
  std::cout << "3) 13 and up \n";
  int answer;
  std::cout << "What is the age rating of " << m.get_name() << "? ";
  std::cin >> answer;
  if (answer == 1 && m.get_name() == "Shrek") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 2 && m.get_name() == "American Psycho") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 3 && m.get_name() == "Inception") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else {
    std::cout << "\nIncorrect! You did not answer the customer's question efficiently! \n";
    return false;
  }
}

bool question3 (movie m) {
  std::cout << "1) 90 minutes \n";
  std::cout << "2) 102 minutes \n";
  std::cout << "3) 148 minutes \n";
  int answer;
  std::cout << "What is the runtime of " << m.get_name() << "? ";
  std::cin >> answer;
  if (answer == 1 && m.get_name() == "Shrek") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 2 && m.get_name() == "American Psycho") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else if (answer == 3 && m.get_name() == "Inception") {
    std::cout << "\nCorrect! You answered the customer's question efficiently! \n";
    return true;
  } else {
    std::cout << "\nIncorrect! You did not answer the customer's question efficiently! \n";
    return false;
  }
}

int main() {

  srand (time (0));

  movie shrek = movie ("Shrek", 90, 6, "3 pm");
  movie american_psycho = movie ("American Psycho", 102, 18, "9 pm");
  movie inception = movie ("Inception", 148, 13, "5 pm");

  std::queue <patron> patrons;
  for (int i = 0; i < 1 + rand() % 10; i++) {
    patrons.push(generate_patron());
  }

  std::queue <patron> p = patrons;

  std::vector <movie> movies;
  for (int i = 0; i < patrons.size(); i++) {
    if (p.front().get_film() == "Shrek") {
      movies.push_back(shrek);
    } else if (p.front().get_film() == "American Psycho") {
      movies.push_back(american_psycho);
    } else {
      movies.push_back(inception);
    }
    p.pop();
  }

  erase (0);
  std::cout << "You are a concession worker at a movie theatre. \n";
  std::cout << "You must serve all customers in a timely manner. \n";
  std::cout << "Press 'enter' to start: ";
  std::cin.ignore();

  erase (3000000);
  std::cout << "Here is the information for the movies that are playing today: \n\n";
  shrek.get_description();
  american_psycho.get_description();
  inception.get_description();
  std::cout << "When you have memorized these movies, press 'enter' to continue: ";
  std::cin.ignore();

  int score = 0;
  int amount = 0;
  int count = 1;

  while (patrons.size() != 0) {
    erase (3000000);
    std::cout << "Customer # " << count << ": \n\n";
    patrons.front().greet();
    std::vector <int> questions = generate_questions();
    for (int j = 0; j < questions.size(); j++) {
      amount += 1;
      ask_question(patrons.front(), questions[j]);
      if (questions[j] == 1) {
        if (question1(movies[count-1])) {
          score += 1;
        } 
      } else if (questions[j] == 2) {
        if (question2(movies[count-1])) {
          score += 1;
        } 
      } else {
        if (question3(movies[count-1])) {
          score += 1;
        } 
      }
      std::cout << "\n";
    }
    std::cout << "You have served this customer!\n";
    patrons.pop();
    count += 1;
  }

  erase (3000000);
  std::cout << "All the customers have been served! \n";
  std::cout << "\nYou answered " << score << " out of " << amount << " questions correctly! \n";
  
}
