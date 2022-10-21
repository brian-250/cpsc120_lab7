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

bool IsAce(const std::string& card_name) {
  if (card_name == "A") {
    return true;
  }
  return false;
}

bool IsFaceCard(const std::string& card_name) {
  if ((card_name == "J") || (card_name == "Q") || (card_name == "K")) {
    return true;
  }
  return false;
}

bool IsNumberCard(const std::string& card_name) {
  if ((std::stoi(card_name) < 11) && (std::stoi(card_name) > 1)) {
    return true;
  }
  return false;
}

bool IsCardName(const std::string& str) {
  if ((IsAce(str)) || (IsFaceCard(str)) || (IsNumberCard(str))) {
    return true;
  }
  return false;
}

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); ++i) {
    if (!IsCardName(arguments.at(i))) {
      std::cout << "error: unknown card '" << arguments.at(i) << "'\n";
      return false;
    }
  }
  return true;
}

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

bool HandContainsAce(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); ++i) {
    if (IsAce(arguments.at(i))) {
      return true;
    }
  }
  return false;
}

bool IsBust(int score) {
  if (score > 21) {
    return true;
  }
  return false;
}
 
int HandScore(const std::vector<std::string>& arguments) {
  int sum{0};
  for (int i = 1; i < arguments.size(); ++i) {
    sum += CardPoints((arguments.at(i)));
  }
  if (!(IsBust(sum+10)) && (HandContainsAce(arguments))) {
    sum += 10;
  }
  return sum;
}

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
    return -1;
  }
  PrintScore(HandScore(arguments));
  return 0;
}
