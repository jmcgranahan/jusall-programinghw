#include <iostream>
#include <ctime>
#include "MyTime.h"
#include "MyDate.h"

using namespace std;

void outputTime( MyTime & t1, MyTime & t2)
{
	cout << "t1: " << t1 <<endl;
	cout << "t2: " << t2 <<endl;
	cout << "--------------------------------------" <<endl;
	t1.SetTicks(0);
	t2.SetTicks(0);
}

int main()
{
	MyTime t1;
	MyTime t2(1,2,3,4);
	outputTime(t1,t2);
	t1.AddHours(5);
	t2.AddMinutes(4);
	outputTime(t1,t2);
	t1.AddSeconds(5);
	t2.AddTicks(6);
	outputTime(t1,t2);
	t1.AddHours(5);
	t2.AddTime(t1);
	outputTime(t1,t2);
	t1 = MyTime::Now();
	t2= MyTime::Now();
	cout << t2.Compare(t1) <<endl;
	outputTime(t1,t2);



	




}