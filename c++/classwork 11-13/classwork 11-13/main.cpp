#include <iostream>
using namespace std;
#include <stdexcept>

template <class T>
class SimpleStack
{
public:
	SimpleStack(int size);
	~SimpleStack();

	void Push(T val);
	T Pop();
	T Peek();

	int Count();

private:
	T* bottomPtr;
	int top;
	const int MAX_SIZE;
};

template <class T>
SimpleStack<T>::SimpleStack(int size): MAX_SIZE(size)
{
	bottomPtr = new T[MAX_SIZE];
	top = 0;

}
template <class T>
SimpleStack<T>::~SimpleStack()
{
	delete [] bottomPtr;
}

template <class T>
void SimpleStack<T>::Push(T val)
{
	if (top == MAX_SIZE) 
		throw overflow_error("uh oh, too much rum");
	else
		bottomPtr[top++] = val;
}
template <class T>
T SimpleStack<T>::Pop()
{
	if (top == 0)
		throw underflow_error("WHYS THE RUM GONE!?");
	else
		return bottomPtr[--top];
}
template <class T>
T SimpleStack<T>::Peek()
{
	if (top == 0)
		throw underflow_error("WHYS THE RUM GONE!?");
	else
		return bottomPtr[top-1];
}

template <class T>
int SimpleStack<T>::Count()
{
	return top;
}

int main()
{
	SimpleStack<int> myStack(5);

	cout << "count = " << myStack.Count() << "\n";
	cout << "peek = " << myStack.Peek() << "\n";

	myStack.Push(100);
	myStack.Push(200);
	myStack.Push(300);
	myStack.Push(400);
	myStack.Push(500);
	myStack.Push(600);
	cout << "count = " << myStack.Count() << "\n";
	cout << "peek = " << myStack.Peek() << "\n";
	cout << "pop = " << myStack.Pop() << "\n";
	cout << "count = " << myStack.Count() << "\n";
	cout << "peek = " << myStack.Peek() << "\n";


	return 0;
}