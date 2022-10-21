// Grey Espinoza
// CPSC 120-12
// 2022-10-20
// gray@csu.fullerton.edu
// @CSUFgrey
//
// Lab 07-02
// Partners: @brian-250
//
// Program to recreate Blackjack with functions
//

#include <iostream>
#include <string>
#include <vector>

// Return true if card_name is the name of the ace card ("A"); or
// false otherwise.
bool IsAce(const std::string& card_name) {
  if (card_name == "A") {
    return true;
  }
  return false;
}

// Return true if card_name is the name of the jack ("J"), queen ("Q"),
// or king ("K"); or false otherwise.
bool IsFaceCard(const std::string& card_name) {
  if ((card_name == "J") || (card_name == "Q") || (card_name == "K")) {
    return true;
  }
  return false;
}

// Return true if card_name is the name of a number card ("2" through "10");
// or false otherwise.
bool IsNumberCard(const std::string& card_name) {
  int number = std::stoi(card_name);
  if ((number < 11) && (number > 1)) {
    return true;
  }
  return false;
}

// Return true if card_name is any valid card name; or false otherwise.
bool IsCardName(const std::string& str) {
  if ((IsAce(str)) || (IsFaceCard(str)) || (IsNumberCard(str))) {
    return true;
  }
  return false;
}

// Return true if every argument (after the command name) is a valid card name;
// or false otherwise.
// The first element of arguments contains the command name, and is ignored by
// this function.
bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); ++i) {
    if (!IsCardName(arguments.at(i))) {
      return false;
    }
  }
  return true;
}

// Return the number of points that the given card is worth.
// A face card is worth 10 points.
// A number card is worth its number.
// This function ignores the ace bonus, so an ace is worth 1 point.
// This function may assume that card_name is a valid card name.
int CardPoints(const std::string& card_name) {
  if (IsAce(card_name)) {
    return 1;
  }
  else if (IsFaceCard(card_name)) {
    return 10;
  }
  else {
    return std::stoi(card_name);
  } 
}

// Return true if the arguments contain an ace.
// The first element of arguments contains the command name, and is ignored by
// this function. 
bool HandContainsAce(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); ++i) {
    if (!IsAce(arguments.at(i))) {
      return false;
    }
  }
  return true;
}

// Return true if score represents a bust; or false otherwise.
// A bust happens when score exceeds 21.
bool IsBust(int score) {
  if (score > 21) {
    return true;
  }
  return false;
}

// Return the total score of the cards named by the arguments.
// Each card contributes points as described for the CardPoints function above.
// In addition, if the hadn contains an ace, the ace counts for another 10
// points, unless that would cause a bust.
// The first element of arguments contains the command name, and is ignored by
// this function. 
int HandScore(const std::vector<std::string>& arguments) {
  int sum{0};
  for (int i = 1; i < arguments.size(); ++i) {
    sum += CardPoints((arguments.at(i)));
  }
  if (!IsBust(sum+10) && (HandContainsAce(arguments))) {
    sum += 10;
  }
  return sum;
}

// Print out a description of the score.
// If there is no bust (score is less than or equal to 21), print output
// "Score is *SCORE*"
// If there is a bust (score is greater than 21), print output
// "Score is *SCORE*, BUST"
void PrintScore(int score) {
  if (score < 22) {
  std::cout << "Score is " << score;
  } else {
    std::cout << "Score is " << score << ", BUST";
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  if (!AllArgumentsValid(arguments)) {
    std::cout << "error: invalid card";
    return -1;
  }

  PrintScore(HandScore(arguments));
  return 0;
}
