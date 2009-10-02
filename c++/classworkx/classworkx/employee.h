namespace Employees //new namespace
{

	int string_length(char* str)
	{
		int i = 0;
		while (i < 9999)
		{
			if(str[i] == '\0') return i;
			++i;
		}
		return -1;
	}

	class Employee // new class
	{
	private://private sections
		char* name;
		char* jobTitle;
		float wage;
		float hoursWorked;

	public: //public sections and prototypes
		void setName(char* name);
		const char* getName(); 

		void setJobTitle(char* jobTitle);
		const char* getJobTitle();

		void setWage(float wage);
		float getWage();

		void setHoursWorked(float hoursWorked);
		float getHoursWorked();

		float getPay();


		//constructors and deconstructors
		Employee();
		Employee(char* name, char* jobTitle, float wage, float hoursWorked);
		~Employee();
	};

	// initialization of prototypes
	void Employee::setName(char* name)
	{
		delete [] this->name; //delete current name
		int size = string_length(name); // get length of new name
		this->name = new char [size +1]; // set length + 1
		for (int i = 0; i <= size; i++)
		{
			this->name [i] = name[i]; //copy selected char
		}
	}

	const char* Employee::getName()
	{
		return name;
	}

	void Employee::setJobTitle(char* jobTitle)
	{
		delete [] this->jobTitle;
		int size = string_length(jobTitle);
		this->jobTitle = new char [size +1];
		for (int i = 0; i <= size; i++)
		{
			this->jobTitle [i] = jobTitle[i];
		}
	}

	const char* Employee::getJobTitle()
	{
		return jobTitle;
	}

	void Employee::setWage(float wage)
	{
		this->wage = wage;
	}

	float Employee::getWage()
	{
		return wage;
	}

	void Employee::setHoursWorked(float hoursWorked)
	{
		this->hoursWorked = hoursWorked;
	}

	float Employee::getHoursWorked()
	{
		return hoursWorked;
	}

	float Employee::getPay()
	{
		return wage * hoursWorked;
	}

	Employee::Employee() //init employee
	{
		name = new char [1];
		jobTitle = new char [1];
		wage = 0.0f;
		hoursWorked = 0.0f;
	}

	Employee::Employee(char* name, char* jobTitle, float wage, float hoursWorked)
	{
		this->name = new char [1];
		setName(name);

		this->jobTitle = new char [1];
		setJobTitle(jobTitle);

		this->wage = 0.0f;
		setWage(wage);

		this->hoursWorked = 0.0f;
		setHoursWorked(hoursWorked);
	}

	Employee::~Employee()
	{
		delete [] name;
		delete [] jobTitle;
	}
}