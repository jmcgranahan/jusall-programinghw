// MyDate.cpp

#include <iostream>
#include "MyDate.h"
#include <ctime>
#include <cstring>
using namespace std;

//Custom
int MyDate::monthToDay(int month, int year)
{
	int tempDays = 0;
	/*fml*/
	bool isLeap = (year%4 == 0)&& ((year%100 != 0) || (year%400 == 0));
	if(month == 1) tempDays += 0;
	
	else if(month == 2) tempDays += 31;
	else if(month == 3) tempDays += (59 + (isLeap *1));
	else if(month == 4) tempDays += (90 + (isLeap *1));
	else if(month == 5) tempDays += (120 + (isLeap *1));
	else if(month == 6) tempDays += (151 + (isLeap *1));
	else if(month == 7) tempDays += (181 + (isLeap *1));
	else if(month == 8) tempDays += (212 + (isLeap *1));
	else if(month == 9) tempDays += (243 + (isLeap *1));
	else if(month == 10) tempDays += (273 + (isLeap *1));
	else if(month == 11) tempDays += (304 + (isLeap *1));
	else if(month == 12) tempDays += (334 + (isLeap *1));
	return tempDays;
}

int MyDate::yearToDay(int year)
{
	int tempDays = 0;
	bool isLeap = this->IsLeapYear();
	while (year > 1) {
		
		if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0)))
		{
			tempDays += 366;
		}
		else
		{
			tempDays += 365;
		}
		year--;
	}
	if(isLeap) tempDays--;
	return tempDays;
}
 
      // CONSTRUCTORS
MyDate::MyDate()
{
	_days = 0;
}
MyDate::MyDate(int day, int month, int year)
{
	int tempDays = 0;

	if(month == 2 && (day > ( 28 + (IsLeapYear(year) * 1))))
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		day = 28 + (IsLeapYear(year) * 1);
	}
	else if( (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		day = 31;
	}
	else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		day = 30;
	}
	if( day < 1) {
		cout << "day too low, using first of month"<<endl;
		day = 1;
	}
 
	tempDays += (year-1) * 365 + ( ((int) ((year-1) / 4)) - ((int) ((year-1) / 100)) + ((int) ((year-1) / 400)));
	tempDays += monthToDay(month, year);
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
 
bool MyDate::IsLeapYear(MyDate & aMyDate)
{
	int year = aMyDate.GetYear();
	if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))) return true;
	else return false;
}

bool MyDate::IsLeapYear(int year)
{
	if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))) return true;
	else return false;
}

bool MyDate::IsLeapYear()
{
	int year = this->GetYear();
	if((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))) return true;
	else return false;
}
 
      
int MyDate::GetDay()
{
	int tempDays = _days;
	int year = this->GetYear();
	int month = this->GetMonth();
	tempDays -= yearToDay(year);
	tempDays -= monthToDay(month,year);
	return tempDays;

}


void MyDate::SetDay(int newDay)
{
	int day = this->GetDay();
	int newMonth = this->GetMonth();
	int newYear = this->GetYear();
	int tempDays = _days;
	tempDays -= day;
	if(newMonth == 2 && (newDay > ( 28 + (IsLeapYear(newYear) * 1))))
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 28 + (IsLeapYear(newYear) * 1);
	}
	else if( (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) && newDay > 31)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 31;
	}
	else if((newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) && newDay > 30)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 30;
	}
	if( newDay < 1) {
		cout << "day too low, using first of month"<<endl;
		newDay = 1;
	}
	
	tempDays += newDay;
	_days = tempDays;

}

     
      
int MyDate::GetMonth()/*I lost the game*/
{
	int tempDays = _days;
	int year = this->GetYear();
	int month = 0;
	bool isLeap = this->IsLeapYear();
	tempDays -= yearToDay(year);

	//cout << tempDays <<endl;
	if(tempDays <= 31) month = 1;
	else if (tempDays <= (59 + ( 1 * isLeap))) month = 2;
	else if (tempDays <= (243 + ( 1 * isLeap))) {
		tempDays -= (59 + ( 1 * isLeap));
		month = 3;
		int extraDay = 1;
		while(tempDays > (30 + extraDay))
		{
			tempDays -= (30 + extraDay);
			month++;
			extraDay = !extraDay;
		}
	}
	else {
		tempDays -= (243 + ( 1 * isLeap));
		month = 9;
		int extraDay = 1;
		while(tempDays > (30 + extraDay))
		{
			tempDays -= (30 + extraDay); 
			month++;
			extraDay = !extraDay;
		}
	}
	return month;
}

void MyDate::SetMonth(int newMonth)
{
	int newDay = this->GetDay();
	int Month = this->GetMonth();
	int newYear = this->GetYear();
	int tempDays = _days;
	tempDays -= newDay;
	tempDays -= monthToDay(Month, newYear);

	if(newMonth == 2 && (newDay > ( 28 + (IsLeapYear(newYear) * 1))))
	{
		//cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 28 + (IsLeapYear(newYear) * 1);
	}
	else if( (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) && newDay > 31)
	{
		//cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 31;
	}
	else if((newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) && newDay > 30)
	{
		//cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 30;
	}
	 
	tempDays += monthToDay(newMonth,newYear);
	tempDays += newDay;
	_days = tempDays;

}
 
int MyDate::GetYear()
{
	int tempDays = _days;
	int year = 1;
	while(tempDays >= 365){
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
void MyDate::SetYear(int newYear)
{
	int tempDays = _days;
	int year = this->GetYear();
	tempDays -= yearToDay(year);
	tempDays += yearToDay(newYear);
	_days = tempDays;

}
 
//void GetDayName(char * dayBuffer);
void MyDate::GetMonthName(char * monthBuffer)
{
	int month = this->GetMonth();
	char * monthStr = new char[10];
	if(month == 1) strcpy(monthStr, "January");
	else if(month == 2) strcpy(monthStr, "Febuary");
	else if(month == 3) strcpy(monthStr, "March");
	else if(month == 4) strcpy(monthStr, "April");
	else if(month == 5) strcpy(monthStr, "May");
	else if(month == 6) strcpy(monthStr, "June");
	else if(month == 7) strcpy(monthStr, "July");
	else if(month == 8) strcpy(monthStr, "August");
	else if(month == 9) strcpy(monthStr, "September");
	else if(month == 10) strcpy(monthStr, "October");
	else if(month == 11) strcpy(monthStr, "November");
	else if(month == 12) strcpy(monthStr, "December");
	strcpy(monthBuffer, monthStr);
	delete [] monthStr;

}

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
	if(newMonth == 2 && (newDay > ( 28 + (IsLeapYear(newYear) * 1))))
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 28 + (IsLeapYear(newYear) * 1);
	}
	else if( (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) && newDay > 31)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 31;
	}
	else if((newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) && newDay > 30)
	{
		cout << "day too large for month, changing to last day of month" <<endl;
		newDay = 30;
	}
	if( newDay < 1) {
		cout << "day too low, using first of month"<<endl;
		newDay = 1;
	}

	tempDays += (newYear-1) * 365 + ( ((int) ((newYear-1) / 4)) - ((int) ((newYear-1) / 100)) + ((int) ((newYear-1) / 400)));
	tempDays += monthToDay(newMonth,newYear);
	tempDays += newDay;
	_days = tempDays;
	return;
}

void MyDate::SetDate(const MyDate & aMyDate)
{
	_days = aMyDate.GetDateSerial();
	return;
}
 
MyDate MyDate::Now()
{
	time_t seconds;
	seconds = time (NULL);
	MyDate tempMyDate(1,1,1970);
	tempMyDate.AddDays(seconds/86400);
	return tempMyDate;
}
 
void MyDate::AddYears(int moreYears)
{
	int year = this->GetYear();
	int tempDays = _days;
	tempDays -= yearToDay(year);
	year += moreYears;
	tempDays += yearToDay(year);
	_days = tempDays;

}

void MyDate::AddMonths(int moreMonths)
{
	int year = this->GetYear();
	int month = this->GetMonth();
	int tempDays = _days;
	tempDays -= monthToDay(month,year);
	month += moreMonths;
	tempDays += monthToDay(month,year);
	_days = tempDays;

}

void MyDate::AddDays(long moreDays)
{
	this->_days += moreDays;
}

void MyDate::AddDate(const MyDate & aMyDate)
{
	_days += aMyDate.GetDateSerial();
}
 

int MyDate::Compare(const MyDate & aMyDate) const
{
	return aMyDate.GetDateSerial() - _days;
}


bool MyDate::Equals(const MyDate & aMyDate) const
{
	if (aMyDate.GetDateSerial() - _days == 0) return true;
	else return false;
}

void MyDate::SubtractYears(int lessYears)
{
	int tempDays = _days;
	int year = this->GetYear();
	tempDays -= yearToDay(year);
	year -= lessYears;
	tempDays += yearToDay(year);
	_days= tempDays;
}
    
void MyDate::SubtractMonths(int lessMonths)
{
	int year = this->GetYear();
	int month = this->GetMonth();
	int tempDays = _days;
	tempDays -= monthToDay(month,year);
	month -= lessMonths;
	tempDays += monthToDay(month,year);
	_days = tempDays;

}

void MyDate::SubtractDays(long lessDays)
{
	this->_days -= lessDays;
}

void MyDate::SubtractDate(const MyDate & aMyDate)
{
	_days -= aMyDate.GetDateSerial();
}


MyDate MyDate::operator= (const MyDate & aMyDate)
{
	this->_days = aMyDate.GetDateSerial();
	return 0;
}

MyDate MyDate::operator+ (const MyDate & aMyDate) const
{
	MyDate temp;
	temp.SetDate(*this);
	temp.AddDate(aMyDate);
	return temp;
}

MyDate MyDate::operator+= (const MyDate & aMyDate)
{
	this->AddDate(aMyDate);
	return 0;
}


// >, <, >=, <=, ==, != (boolean relational test operators)
bool MyDate::operator> (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() > aMyDate.GetDateSerial()) return true;
	else return false;
}
bool MyDate::operator< (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() < aMyDate.GetDateSerial()) return true;
	else return false;
}
bool MyDate::operator>= (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() >= aMyDate.GetDateSerial()) return true;
	else return false;
}
bool MyDate::operator<= (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() <= aMyDate.GetDateSerial()) return true;
	else return false;
}
bool MyDate::operator== (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() == aMyDate.GetDateSerial()) return true;
	else return false;
}
bool MyDate::operator!= (const MyDate & aMyDate)  const
{
	if( this->GetDateSerial() != aMyDate.GetDateSerial()) return true;
	else return false;
}

// <<, >> stream insertion and extraction
ostream & operator<< (ostream & os, MyDate & aMyDate)
{
	os << "total days:" << aMyDate.GetDateSerial() <<endl<< aMyDate.GetDay() << "/"<<  aMyDate.GetMonth() <<"/" <<aMyDate.GetYear() <<endl<<endl;

	return os;

}
 
      // date must be one of these formats
      //    ???
istream & operator>> (istream & is, MyDate & aMyDate)
{
	int day;
	int month;
	int year;
	cout << "year: ";
	cin >> year;
	cout << endl << "month: ";
	cin >> month;
	cout << endl << "day: ";
	cin >> day;
	aMyDate.SetDate(day,month,year);
	return is;
}

