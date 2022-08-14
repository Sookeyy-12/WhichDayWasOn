// THIS PROGRAM CAN BE MUCH MORE REFINED AND POLISHED


#include <stdio.h>

int leap; //GLOBALLY DECLARING leap VARIABLE

// FUNCTION TO CHECK IF THE GIVEN YEAR IS LEAP OR NOT
int leapOrNot(int year) {
  if (year % 4 == 0) {                                  // if year is divisble by 4
    if (year % 100 == 0 && year % 400 == 0) {             // if year is divisible both 100 and 400 it is a leap year
      leap = 1;
    } else if (year % 100 == 0 && year % 400 != 0) {      // if year is divisible by 100 but not by 400 it is not a leap year
      leap = 0;
    } else if (year % 100 != 0) {                         // if year is not divisible by 100 is it a leap year
      leap = 1;
    };
  } else if (year % 4 != 0) {                           // if year is not divisible by 4 it is not a leap year
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
  if (leap == 0){                               //for a normal year
    int months[12] = {3,0,3,2,3,2,3,3,2,3,2,3}; //february has 0 odd days (since 28/7 gives remainder = 0
    for (int i = 0; i < month; i++) {
      oddMonths = oddMonths + months[i];  // sums up odd days till given month
    };
  } else if (leap == 1) {                        //for a leap year
    int months[12] = {3,1,3,2,3,2,3,3,2,3,2,3};  //february has 1 odd days (since 29/7 gives remainder = 1
    for (int i = 0; i < month; i++) {
      oddMonths = oddMonths + months[i];  // sums up odd days till given month
    };
  };
  return oddMonths;
};

//  FUNCTION TO CALCULATE ODD DAYS IN YEARS
int oddYYYY(int year) {
  int remainingYears, centuries, leapYears, normalYears;
  remainingYears = year % 400;                          //every 400 years, odd days reset, so this calculates the remaining years which have significance
  centuries = remainingYears/100;                       //centuries are not leap years unless they are divisible by 400
  leapYears = remainingYears/4 - centuries;             //calculates total leap years
  normalYears = remainingYears - leapYears;             //calculates total normal years
  int oddYears;
  oddYears = (leapYears * 2) + (normalYears);           // calculates the total odd days for years
  return oddYears;
};

// FUNCTION TO TELL WHICH DAY IT IS
char* whatDay(int tod) {
  char* days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; //list containing days with their corresponding numbers as indices
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

  leapOrNot(year);  // gets the value of leap variable
  int totalOddDays;
  char* actualDay;
  totalOddDays = (oddDD(date) + oddMM(month-1) + oddYYYY(year-1)) % 7;  // get total odd days ranging from 0-6
  actualDay = whatDay(totalOddDays);  // send the value of total odd days to get the 'day'
  printf("Day on %i-%i-%i = %s",date, month, year,  actualDay);
}
