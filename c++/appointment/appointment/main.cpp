#include <iostream>
#include "MyString.h"
#include "MyDate.h"
#include "MyTime.h"
#include "MyArray.h"
#include <fstream>
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
	MyArray<MyApp> appointments2(10);
	MyApp app1;
	ofstream myofile;
	ifstream myifile;
	for(int i = 0; i < 10; i++)
	{
		app1.SetDate(i+1,i+1,i+1);
		MyString String("test");
		String.Append(i);
		app1.SetDescription(String);
		appointments.Add(app1);
	}
	
	myofile.open("data.txt", ios::out);

	if(myofile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			myofile << appointments.At(i).GetDesc() << "  ";
			if(appointments.At(i).GetTime().GetTicks() > 0)
				myofile << appointments.At(i).GetTime() << "  ";
			myofile << appointments.At(i).GetDate() << "\n";

		}

		myofile.close();
	}
	else
		cout << "Failed to open" << "\n";

	myifile.open("data.txt", ios::in);

	if(myifile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			char desc[512];
			int hour;
			char colens[5];
			int min;
			int sec;
			int year;
			int month;
			int day;
			myifile >> desc >> hour >> colens[0] >> min >> colens[0] >> sec >> day >> colens[0] >> month >> colens[0]>> year;
			app1.SetDescription(desc);
			app1.SetDate(year,month,day);
			app1.SetTime(hour,min,sec);
			appointments2.Add(app1);
		}

		myifile.close();
	}
	else
		cout << "Failed to open" << "\n";

	for (int i = 0; i < 10; i++)
	{
		cout << appointments2.At(i).GetDesc() << "  ";
		if(appointments2.At(i).GetTime().GetTicks() > 0)
			cout << appointments2.At(i).GetTime() << "  ";
		cout << appointments2.At(i).GetDate() << "\n";
	}

	return 0;
}

