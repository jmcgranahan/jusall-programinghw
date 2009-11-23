#include <iostream>
#include "MyArray.h"
#include "MyArray.cpp"

using namespace std;
void breakLine()
{
	cout << "===============================================" << endl;
}
int main()
{
	MyArray<long> MyArray(10);
	cout << "capacity: " << MyArray.Capacity() << endl;
	cout << "size: " << MyArray.Size() << endl;
	breakLine();
	for(int i=0;i<16;i++)
		MyArray.Add(i);
	cout << "size: " << MyArray.Size() << endl;
	breakLine();
	for(int i=0;i<16;i++)
		cout << MyArray.At(i+1)<< endl;
	breakLine();
	MyArray.Add(66);
	cout << MyArray.At(17)<< endl;
	breakLine();
	cout << "capacity: " << MyArray.Capacity() << endl;
	cout << "size: " << MyArray.Size() << endl;
	cout << "find 66: " << MyArray.Find(66)<<endl;
	breakLine();
	cout << "insert 67  @ 4" <<endl;
	MyArray.Insert(67,4);
	for(int i=0;i<MyArray.Size();i++)
		cout << MyArray.At(i+1)<< endl;
	cout << "capacity: " << MyArray.Capacity() << endl;
	cout << "size: " << MyArray.Size() << endl;
	breakLine();
	MyArray.RemoveAt(4);
	cout << " remove 4:" << endl;
	for(int i=0;i<MyArray.Size();i++)
		cout << MyArray.At(i+1)<< endl;
	cout << "capacity: " << MyArray.Capacity() << endl;
	cout << "size: " << MyArray.Size() << endl;
	breakLine();
	MyArray.SetValue(16,17);
	cout << " set 17 to 16:" << endl;
	for(int i=0;i<MyArray.Size();i++)
		cout << MyArray.At(i+1)<< endl;
	cout << "capacity: " << MyArray.Capacity() << endl;
	cout << "size: " << MyArray.Size() << endl;
	breakLine();
	for(int i=0;i<MyArray.Size()+2;i++)
		cout << "MyArray["<<i<<"]: " << MyArray[i] << endl;


	return 0;

}
