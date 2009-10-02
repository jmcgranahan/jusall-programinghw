#include "Employee.h"
#include <cstring>
Employee::Employee()
	{
		name = new char[1];
		name[0] = '\0';

		jobTitle = new char[1];
		name[0] = '\0';

		wage = 0.0f;
		hoursWorked = 0.0f;
	}
	Employee(char* initName, char* initTitle, float initWage, float initHours)
	{
		name = new char[strlen(initName)+1];
		name[0] = '\0';

		jobTitle = new char[strlen(initTitle)+1];
		name[0] = '\0';

		wage = initWage;
		hoursWorked = initHours;

	}

	void Employee::SetName(const char* const newName);
	{
		if(name != newName)
		{
			delete [] name;
			name =  new char[strlen(newName)+1);
			strcpy(name,newName);
		}
	}

	void Employee::SetTitle(const char* const newTitle)
	{
		if(title != newTitle)
		{
			delete [] title;
			title =  new char[strlen(newTitle)+1);
			strcpy(title,newTitle);
		}
	}
	

	void Employee::SetWage(float const newWage)
	{
		if(newWage >= 0.0f && newWage <= 30f)
		{
			wage = newWage;
		}
		else
		{
				throw "FFFUUUUUUUU...."
		}
	}
	float Employee::GetWage() const
	{
		return wage;
	}

	void Employee::SetHours(float const newHours)
	{
		if(newHours > 0.0f)
		{
			hours = newHours;
		}
		else
		{
				throw "FFFUUUUUUUU...."
		}
		
	}
	float Employee::GetHours() const
	{
		return this->hoursWorked
	}

	float Employee::GetPay() const;


	Employee::~Employee()
	{
		delete [] name;
		delete [] jobTitle;

	}