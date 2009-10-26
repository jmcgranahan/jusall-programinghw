// MyDate.cpp
#include <iostream>
#include "MyDate.h"
using namespace std;
 
      // CONSTRUCTORS
MyDate::MyDate()
{
	_days = 0;
}
//MyDate(int day, int month, int year);
//MyDate(int days); 
//MyDate(MyDate & aMyDate); 
 
// METHODS
 
//static bool IsLeapYear(MyDate & aMyDate);
//static bool IsLeapYear(int year);
//bool IsLeapYear();
 
      
//int GetDay();
//void SetDay(int newDay);
     
      
//int GetMonth()
//void SetMonth(int newMonth);
 
//int MyDate::GetYear()
//void SetYear(int newYear);
 
//void GetDayName(char * dayBuffer);
//void GetMonthName(char * monthBuffer);

//int GetDateSerial() const;
 
//void SetDate(int Days);
//void SetDate(int newDay, int newMonth, int newYear);
//void SetDate(const MyDate & aMyDate);
 
//static MyDate Now();
 
//void AddYears(int moreYears);
//void AddMonths(int moreMonths);
//void AddDays(long moreDays);
//void AddDate(const MyDate & aMyDate);
 
      // Compare
      // Takes a MyDate argument
      // Returns (zero) if the argument has the same time as this MyDate
      // Returns (a positive int)  if the argument is before this MyDate
      // Returns (a negative int)  if the argument is after this MyDate
      //int Compare(const MyDate & aMyDate) const;
 
      // Equals
      // Takes a MyDate argument
      // Returns (true) if the argument has the same time
//   as this MyDate, otherwise it returns (false).
      //bool Equals(const MyDate & aMyDate) const;
 
      // Subtract (various useful functions)
            // Years
      //void SubtractYears(int lessYears);
            // Months
      //void SubtractMonths(int lessMonths);
            // Days
      //void SubtractDays(long lessDays);
            // MyDate
      //void SubtractDate(const MyDate & aMyDate);
 
// OVERLOADED OPERATORS
 
      // = (assignment - takes a MyDate)
      //MyDate operator= (const MyDate & aMyDate);
 
      // +, += (Addition - takes a MyDate)
      //MyDate operator+ (const MyDate & aMyDate) const;
      //MyDate operator+= (const MyDate & aMyDate);
 
      // >, <, >=, <=, ==, != (boolean relational test operators)
      //bool operator> (const MyDate & aMyDate)  const;
      //bool operator< (const MyDate & aMyDate)  const;
      //bool operator>= (const MyDate & aMyDate)  const;
      //bool operator<= (const MyDate & aMyDate)  const;
      //bool operator== (const MyDate & aMyDate)  const;
      //bool operator!= (const MyDate & aMyDate)  const;
 
      // <<, >> stream insertion and extraction
      //friend ostream & operator<< (ostream & os, MyDate & aMyDate);
 
      // date must be one of these formats
      //    ???
      //friend istream & operator>> (istream & is, MyDate & aMyDate);
