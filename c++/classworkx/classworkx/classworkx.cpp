/*
  *----------------------------------------------*
  |  _____ _     _ ______   _____  _____  _   _  |
  |    |   |     | |______    |      |   | \  |  |
  |  __|   |_____| ______|    |    __|__ |  \_|  |
  |                                              |
  |  _______               _______ __   _        |
  |  |_____| |      |      |______ | \  |        |
  |  |     | |_____ |_____ |______ |  \_|        |
  |                                              |
  |                                              |
  |                 6-6-2009                     |     
  *----------------------------------------------*
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "employee.h" // use this header
using namespace Employees; // and this namespace
#define NUMEMPLOYEES 10

Employee employees[NUMEMPLOYEES];
 
//prototypes
void Inputemployees();
void Outputemployees();
float getInputFloat();
char* getInputString();
char _Input[40];

int main()
{
	Inputemployees();
	Outputemployees();
	return 0;
}

float getInputFloat()
{
	cin.sync();
	float Input = 0.0f;
	cin >> Input;
	cin.clear();
	return Input;
}

char* getInputString()
{
	
	cin.sync();
	cin.getline(_Input, 1000);
	cin.clear();
	return _Input;
}

void Inputemployees()
{
	
	for (int i = 0; i < NUMEMPLOYEES; i++)
	{
		cout << "employee #" << (i + 1) << endl;
		cout << "Enter Name	: " ;
		employees[i].setName( getInputString());
		cout << "Enter title	: " ;
		employees[i].setJobTitle( getInputString());
		cout << "Enter Wage	: " ;
		employees[i].setWage( getInputFloat());
		cout << "Enter Hours	: " ;
		employees[i].setHoursWorked( getInputFloat());

	}
}



void Outputemployees()
{	
	cout << endl << endl << endl;
	for (int i = 0; i < NUMEMPLOYEES; i++)
	{
		float wage = employees[i].getWage();
		float pay = employees[i].getPay();

		cout << "[employee #" << (i + 1) << "]" << endl;
		cout << "Name	: " << employees[i].getName();
		if((wage >= 20) || (pay >= 800))
		{
			cout <<"*";
		}
		cout << endl;
		cout << "title	: " << employees[i].getJobTitle() << endl;
		cout << "Wage	: " << employees[i].getWage() << endl;	
		cout << "Hours	: " << employees[i].getHoursWorked() << endl;
		cout << "Pay	: $" << employees[i].getPay() << endl << endl;

	}
}