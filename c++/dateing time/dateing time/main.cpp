#include <iostream>
#include <ctime>
//#include "MyTime.h"
#include "MyDate.h"

using namespace std;

int main()
{
	int day = 1;
	int year = 3;

	MyDate d1(day,1,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,2,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,3,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,4,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,5,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,6,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,7,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,8,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,9,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,10,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,11,year);
	cout << d1.GetMonth() << endl;
	d1.SetDate(day,12,year);
	cout << d1.GetMonth() << endl;



}