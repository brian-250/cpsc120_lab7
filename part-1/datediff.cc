// Grey Espinoza
// CPSC 120-12
// 2022-10-20
// gray@csu.fullerton.edu
// @CSUFgrey
//
// Lab 07-01
// Partners: @brian-250
//
// Program to calculate Julian Day differences
//

#include <iostream>

// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.
int JulianDay(int month, int day, int year) {
  return (day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
          367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
          3 * ((year + 4900 + (month - 14) / 12) / 100) / 4);
}

// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  return (JulianDay(end_month, end_day, end_year) -
          JulianDay(start_month, start_day, start_year));
}

// Print the given date to standard output in the format MM/DD/YYYY
void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}

int main(int argc, char* argv[]) {
  int start_month{0};
  int start_day{0};
  int start_year{0};
  int end_month{0};
  int end_day{0};
  int end_year{0};

  std::cout << "Let's find the number of days between two dates...\n";

  std::cout << "Enter a start month: ";
  std::cin >> start_month;
  std::cout << "Enter a start day: ";
  std::cin >> start_day;
  std::cout << "Enter a start year: ";
  std::cin >> start_year;
  std::cout << "\n";
  std::cout << "Enter an end month: ";
  std::cin >> end_month;
  std::cout << "Enter an end day: ";
  std::cin >> end_day;
  std::cout << "Enter an end year: ";
  std::cin >> end_year;
  std::cout << "\n";

  int date_difference{0};
  date_difference = DateDifference(start_month, start_day, start_year,
                                   end_month, end_day, end_year);
  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << date_difference << " days\n";

  return 0;
}