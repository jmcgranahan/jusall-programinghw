#include <iostream>

using namespace std;

#include <vector>

int main()
{

	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	for ( int i = 0; i < v1.size(); i++)
		cout << v1[i] << ", ";

	cout << endl;


	vector<int>::iterator iter;
	for (iter = v1.begin(); iter != v1.end(); iter++)
		cout << *iter << ", ";
	cout << endl;
	return 0;
}