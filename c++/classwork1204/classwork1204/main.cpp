#include <iostream>

using namespace std;

class Foo
{
private:
	int i;
public:
	void SetI(int newI)
	{
		i = newI;
		//cout << this <<"\n\n";
	}
	int GetI()
	{
		return i;
	}
};




int (Foo::*pg)();

int main()
{
	Foo f1;
	//cout << (&f1) << "\n\n";

	Foo f2;
	//cout << (&f2) << "\n\n";


	pg = &Foo::GetI;

	f1.SetI(99);
	f2.SetI(88);

	int i = (f1.*pg)();
	cout << i <<"\n\n";
	i = (f2.*pg)();
	cout << i <<"\n\n";

	int j = 1000;
	int k = ~j + 1;
	cout << "j = " << j << "\n\n" << "k = " << k << "\n\n";



	return 0;
}