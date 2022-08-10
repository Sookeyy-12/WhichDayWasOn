#include <stdio.h>

int leap; //GLOBALLY DECLARING leap VARIABLE

// FUNCTION TO CHECK IF THE GIVEN YEAR IS LEAP OR NOT
int leapOrNot(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0 && year % 400 == 0) {
      leap = 1;
    } else if (year % 100 == 0 && year % 400 != 0) {
      leap = 0;
    } else if (year % 100 != 0) {
      leap = 1;
    };
  } else if (year % 4 != 0) {
    leap = 0;
  };
  return leap; // 0 MEANS NO AND 1 MEANS YES
};

// CALCULATE ODD DAYS IN DAY (DD)
int oddDD(int day) {
  int oddDay;
  oddDay = day % 7;
  return oddDay;
};

// FUNCTION TO CALCULATE ODD DAYS IN MONTH
int oddMM(int month) {
  int oddMonths = 0;
  if (leap == 0){
    int months[12] = {3,0,3,2,3,2,3,3,2,3,2,3};
    for (int i = 0; i < month; i++) {
      oddMonths = oddMonths + months[i];
    };
  } else if (leap == 1) {
    int months[12] = {3,1,3,2,3,2,3,3,2,3,2,3};
    for (int i = 0; i < month; i++) {
      oddMonths = oddMonths + months[i];
    };
  };
  return oddMonths;
};

//  FUNCTION TO CALCULATE ODD DAYS IN YEARS
int oddYYYY(int year) {
  int remainingYears, centuries, leapYears, normalYears;
  remainingYears = year % 400;
  centuries = remainingYears/100;
  leapYears = remainingYears/4 - centuries;
  normalYears = remainingYears - leapYears;
  int oddYears;
  oddYears = (leapYears * 2) + (normalYears);
  return oddYears;
};

// FUNCTION TO TELL WHICH DAY IT IS
char* whatDay(int tod) {
  char* days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  return days[tod];
};

int main() {
  int date, month, year;
  printf("Enter Date (DD): ");
  scanf("%i", &date);  // inputs date
  printf("Enter Month (MM): ");
  scanf("%i", &month);  // inputs month 
  printf("Enter Year (YYYY): ");
  scanf("%i", &year);  // inputs year

  leapOrNot(year);
  int totalOddDays;
  char* actualDay;
  totalOddDays = (oddDD(date) + oddMM(month-1) + oddYYYY(year-1)) % 7;
  actualDay = whatDay(totalOddDays);
  printf("%s", actualDay);
}
