#include <iostream>
#include "MyString.h"
#include "MyDate.h"
#include "MyTime.h"
#include "MyArray.h"

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
		Date.Now();
		Time.Now();
	};
	MyApp(const MyApp & aMyApp){
		Description = aMyApp.Description;
		Date = aMyApp.Date;
		Time = aMyApp.Time;
	};
	MyApp(MyDate & aMyDate){
		Description = "Empty appointment";
		Date.SetDate(aMyDate);
		Time.Now();
	};
	MyApp(int day, int month, int year){
		Description = "Empty appointment";
		Date.SetYear(year);
		Date.SetMonth(month);
		Date.SetDay(day);
		Time.Now();
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
};

int main()
{
	MyArray<MyApp> appointments(10);
	MyApp app1(5,6,5);
	MyApp app2;
	app1.SetDescription("test");
	cout << app1.GetDesc() << "\n" << app1.GetDate() << "\n" << app1.GetTime() << "\n";
	appointments.Add(app1);
	app2 = appointments.At(1);
	cout << app2.GetDesc() << "\n" << app2.GetDate() << "\n" << app2.GetTime() << "\n";
	app2 = app1;
	cout << app2.GetDesc() << "\n" << app2.GetDate() << "\n" << app2.GetTime() << "\n";

	return 0;
}
