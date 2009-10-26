#include <iostream>
#include <ctime>
#include "MyTime.h"
using namespace std;

int main()
{
	MyTime t1(12,0,0,0);
	MyTime t2(12,0,0,0);
	cout << t1 << t2;
	//cout << "total ticks:" << t1.GetTicks() <<endl;
	//cout << "hours	   :" << t1.GetHours() <<endl;
	//cout << "minutes    :" << t1.GetMinutes() <<endl;
	//cout << "seconds    :" <<t1.GetSeconds() <<endl<<endl;
	//cout << "total ticks:" << t2.GetTicks() <<endl;
	//cout << "hours	   :" << t2.GetHours() <<endl;
	//cout << "minutes    :" << t2.GetMinutes() <<endl;
	//cout << "seconds    :" <<t2.GetSeconds() <<endl<<endl;
}