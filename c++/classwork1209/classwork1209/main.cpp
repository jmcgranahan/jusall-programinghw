#include <iostream>
using namespace std;

#include <fstream>
using std::ofstream;

class Person
{
public:
	int age;
	char name[16];
};

int main()
{
	/*int ia[5] = {1,2,3,4,5};
	Person p = {11,"A1"};
	
	cout << &(p.name) << " " << &(p.age) << "\n\n";
	cout << p.name << " " << p.age << "\n\n";
	
	Person people[5] =
	{{11,"Albino"},{22,"bobcat"},{33,"cat"},{44,"dog"},{55,"fish"}};

	ofstream myfile;
	myfile.open("data.txt", ios::out);

	if(myfile.is_open())
	{
		for (int i = 0; i < 5; i++)
			myfile << people[i].name << " " << people[i].age << "\n";

		myfile.close();
	}
	else
		cout << "Failed to open" << "\n";
		*/
	Person people[5];
	ifstream myfile;
	myfile.open("data.txt", ios::in);
	
	if(myfile.is_open())
	{
		for (int i = 0; i < 5; i++)
			myfile >> people[i].name >> people[i].age;

		myfile.close();
	}
	else
		cout << "Failed to open" << "\n";

	for (int i = 0; i < 5; i++)
			cout << people[i].name << " " << people[i].age << "\n";

	return 0;
}