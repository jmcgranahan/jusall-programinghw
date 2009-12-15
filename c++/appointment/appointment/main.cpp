#include <iostream>
#include "MyString.h"
#include "MyDate.h"
#include "MyTime.h"
#include "MyArray.h"
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using std::ofstream;

using namespace std;

class MyApp
{
private:
	MyString Description;
	MyDate Date;
	MyTime Time;
public:
	MyApp(){
		Description = "Empty appointment";
		Date = Date.Now();
		Time = Time.Now();
	};
	MyApp(const MyApp & aMyApp){
		Description = aMyApp.Description;
		Date = aMyApp.Date;
		Time = aMyApp.Time;
	};
	MyApp(MyDate & aMyDate){
		Description = "Empty appointment";
		Date.SetDate(aMyDate);
		Time = Time.Now();
	};
	MyApp(int day, int month, int year){
		Description = "Empty appointment";
		Date.SetYear(year);
		Date.SetMonth(month);
		Date.SetDay(day);
		Time = Time.Now();
	};
	MyApp(int day, int month, int year, int hour, int minute){
		Description = "Empty appointment";
		Date.SetYear(year);
		Date.SetMonth(month);
		Date.SetDay(day);
		Time.SetHours(hour);
		Time.SetMinutes(minute);
	};



	void SetDate(int year, int month, int day)
	{
		Date.SetYear(year);
		Date.SetMonth(month);
		Date.SetDay(day);
	}
	void SetDate(int month, int day)
	{
		Date.Now();
		Date.SetMonth(month);
		Date.SetDay(day);
	}
	void SetDate(int day)
	{
		Date.Now();
		Date.SetDay(day);
	}
	void SetDate(MyDate aMyDate)
	{
		Date = aMyDate;
	}
	void SetDate( MyApp aMyApp)
	{
		Date = aMyApp.GetDate();
	}



	void SetTime(int hour, int minute, int seconds)
	{
		Time.SetHours(hour);
		Time.SetMinutes(minute);
		Time.SetSeconds(seconds);
	}
	void SetTime(int hour, int minute)
	{
		Time.SetHours(hour);
		Time.SetMinutes(minute);
	}
	void SetTime(int minute)
	{
		Time.SetMinutes(minute);
	}
	void SetTime(MyTime aMyTime)
	{
		Time = aMyTime;
	}
	void SetTime( MyApp aMyApp)
	{
		Time = aMyApp.GetTime();
	}


	void SetDescription( MyApp aMyApp)
	{
		Description = aMyApp.GetDesc();
	}
	void SetDescription(const MyString & aMyString)
	{
		Description = aMyString;
	}
	void SetDescription(const char *  const aCString)
	{
		Description = aCString;
	}


	bool IsInDateRage(MyDate startDate, MyDate endDate)
	{
		if(Date >= startDate && Date <= endDate)
			return true;
		else
			return false;

	}
	MyDate GetDate() {
		MyDate temp;
		temp.SetDate(this->Date);
		return temp; 
	}
	MyTime GetTime() {
		MyTime temp;
		temp.SetTime(this->Time);
		return temp; 
	}
	MyString GetDesc() {
		MyString temp;
		temp = Description;
		return temp; 
	}

	MyApp operator= (MyApp aMyApp)
	{
		this->SetDescription(aMyApp);
		this->SetDate(aMyApp);
		this->SetTime(aMyApp);
		return aMyApp;
	}
	friend ostream & operator<< (ostream & os, MyApp & aMyApp)
	{
		os << aMyApp.GetDesc() << " " << aMyApp.GetTime() << " " << aMyApp.GetDate();
		return os;
	}
	friend istream & operator>> ( istream & is, MyApp & aMyApp)
	{
		char desc[512];
		int hour;
		char colens[5];
		int min;
		int sec;
		int year;
		int month;
		int day;
		is >> desc >> hour >> colens[0] >> min >> colens[0] >> sec >> day >> colens[0] >> month >> colens[0]>> year;
		aMyApp.SetDescription(desc);
		aMyApp.SetDate(year,month,day);
		aMyApp.SetTime(hour,min,sec);
		return is;
	}
};


int main()
{
	MyArray<MyApp> appointments(10);
	MyApp app1;
	MyDate startDate(1,1,1);
	MyDate endDate(4,1,1);
	ifstream myifile;


	for(int i = 0; i < 15; i++)
	{
		MyDate tempDate(i+1);
		app1.SetDate(tempDate);
		MyString String("test");
		String.Append(i);
		app1.SetDescription(String);
		appointments.Add(app1);
	}


	appointments.Display();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";

	appointments.WriteOut("data.txt");
	appointments.Display();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";

	appointments.WriteIn("data.txt");
	appointments.Display();


	for (int i = 0; i < appointments.Size(); i++)
	{
		if(appointments.At(i).IsInDateRage(startDate,endDate))
			cout << "appointment " << i << " is within the dates" << "\n" ;
		else
			cout << "appointment " << i << " is not within the dates" << "\n";
	}
	


	

	return 0;
}

