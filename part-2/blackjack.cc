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

bool IsAce(const std::string& card_name) { return (card_name == "A"); }

bool IsFaceCard(const std::string& card_name) {
  return (card_name == "J") || (card_name == "Q") || (card_name == "K");
}

bool IsNumberCard(const std::string& card_name) {
  int card_value{0};
  bool is_number_card{true};
  try {
    card_value = stoi(card_name);
    if ((card_value < 2) || (card_value > 10)) {
      is_number_card = false;
    }
  } catch (std::exception const& e) {
    is_number_card = false;
  }
  return is_number_card;
}

bool IsCardName(const std::string& str) {
  return (IsAce(str)) || (IsFaceCard(str)) || (IsNumberCard(str));
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
  int return_card_value{0};
  if (IsAce(card_name)) {
    return_card_value = 1;
  } else if (IsFaceCard(card_name)) {
    return_card_value = 10;
  } else if (IsNumberCard(card_name)) {
    return_card_value = std::stoi(card_name);
  }
  return return_card_value;
}
bool HandContainsAce(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); ++i) {
    if (IsAce(arguments.at(i))) {
      return true;
    }
  }
  return false;
}

bool IsBust(int score) { return score > 21; }

int HandScore(const std::vector<std::string>& arguments) {
  int sum{0};
  for (int i = 1; i < arguments.size(); ++i) {
    sum += CardPoints((arguments.at(i)));
  }
  if (!(IsBust(sum + 10)) && (HandContainsAce(arguments))) {
    sum += 10;
  }
  return sum;
}

void PrintScore(int score) {
  if (score < 22) {
    std::cout << "Score is " << score << "\n";
  } else {
    std::cout << "Score is " << score << ", BUST\n";
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
