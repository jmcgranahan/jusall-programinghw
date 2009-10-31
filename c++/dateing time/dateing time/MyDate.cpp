// MyDate.cpp
#include <iostream>
#include "MyDate.h"
using namespace std;
 
      // CONSTRUCTORS
MyDate::MyDate()
{
	_days = 0;
}
MyDate::MyDate(int day, int month, int year)
{
	int tempDays = 0;
	tempDays += (year-1) * 365 + ( ((int) ((year-1) / 4)) - ((int) ((year-1) / 100)) + ((int) ((year-1) / 400)));
	tempDays += ((month-1) * 30) + ((month-1) % 2);
	if(month > 2)
	{
		if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))) tempDays -= 1;
		else tempDays -= 2 ;
	}
	tempDays += day;
	_days = tempDays;
	
}

MyDate::MyDate(int days)
{
	_days = days;
	return;

}

MyDate::MyDate(MyDate & aMyDate)
{
	_days = aMyDate.GetDateSerial();
	return;

}
 
// METHODS
 
//static bool IsLeapYear(MyDate & aMyDate);
//static bool IsLeapYear(int year);
bool MyDate::IsLeapYear()
{
	int year = this->GetYear();
	if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))) return true;
	else return false;
}
 
      
//int MyDate::GetDay()

//void MyDate::SetDay(int newDay)

     
      
int MyDate::GetMonth()
{
	int tempDays = _days;
	int year = this->GetYear();
	int month = 0;
	bool isLeap = this->IsLeapYear();
	while (year > 1) {
		
		if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0)))
		{
			tempDays -= 366;
		}
		else
		{
			tempDays -= 365;
		}
		year--;
	}
	if(tempDays <= 31) month = 1;
	else if (tempDays <= (59 + ( 1 * isLeap))) month = 2;
	else if (tempDays <= (213 + ( 1 * isLeap))) {
		tempDays -= (59 + ( 1 * isLeap));
		month = 3;
		int extraDay = 1;
		while(tempDays >= (30 + extraDay))
		{
			tempDays -= (30 + extraDay);
			month++;
			extraDay = !extraDay;
		}
	}
	else {
		tempDays -= (212 + ( 1 * isLeap));
		month = 9;
		int extraDay = 1;
		while(tempDays >= (30 + extraDay))
		{
			tempDays -= (30 + extraDay);
			month++;
			extraDay = !extraDay;
		}
	}
	return month;
}
//void SetMonth(int newMonth);
 
int MyDate::GetYear()
{
	int tempDays = _days;
	int year = 1;
	while(tempDays > 365){
		if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0)))
		{
			tempDays -= 366;
		}
		else
		{
			tempDays -= 365;
		}
		year++;
	}
	return year;


}
//void SetYear(int newYear);
 
//void GetDayName(char * dayBuffer);
//void GetMonthName(char * monthBuffer);

int MyDate::GetDateSerial() const
{
	return _days;

}
 
void MyDate::SetDate(int Days)
{
	_days = Days;
	return;
}

void MyDate::SetDate(int newDay, int newMonth, int newYear)
{
	int tempDays = 0;
	tempDays += (newYear-1) * 365 + ( ((int) ((newYear-1) / 4)) - ((int) ((newYear-1) / 100)) + ((int) ((newYear-1) / 400)));
	tempDays += ((newMonth-1) * 30) + ((newMonth-1) % 2);
	if(newMonth > 2)
	{
		if((newYear%4 == 0)&& ((newYear%100 != 0) || (newYear%400 == 0))) tempDays -= 2;
		else tempDays -= 1 ;
	}
	tempDays += newDay;
	_days = tempDays;
	return;
}

void MyDate::SetDate(const MyDate & aMyDate)
{
	_days = aMyDate.GetDateSerial();
	return;
}
 
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
