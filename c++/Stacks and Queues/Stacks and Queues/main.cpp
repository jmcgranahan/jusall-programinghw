//main.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "node.h"
#include "stack.h"
#include "queue.h"


using namespace std;
void breakLine()
{
	cout << "===============================================" << endl;
}

int operatorPriority(char input)
{
	if ( input == '+' || input == '-')
		return 1;
	else if ( input == '*' || input == '/' || input == '%')
		return 2;
	return 0;
}

string infixToPostfix(char infix[])
{
	stack<char> _stack;
	queue<char> _queue;

	for(int i = 0; infix[i];i++)
	{
		char currentchar = infix[i];
		if (isdigit(currentchar))
			_queue.append(currentchar);

		else if ( operatorPriority(currentchar) )
		{
			if (_stack.getLength() == 0)
				_stack.push(currentchar);

			else
			{
				while ( operatorPriority(currentchar) <= operatorPriority(_stack.peak()) )  // while top of stack has higher or equal priority, pop top to queue
					_queue.append(_stack.pop());
				_stack.push(currentchar);
			}
		}

		else if ( currentchar == '(')
			_stack.push(currentchar);

		else if ( currentchar == ')')
		{
			char poped = _stack.pop();
			while( poped && poped != '(' )
			{
				_queue.append(poped);
				poped = _stack.pop();
			}
		}
	}
	
	while( _stack.getLength() )
		_queue.append(_stack.pop());
	
	string sOutput;
	
	while(_queue.getLength())
		sOutput += _queue.remove();

	return sOutput
		;
} 

int postfixEval(string postfix)
{
	stack<int> intStack;
	for(int i = 0; i < postfix.length(); i++)
	{
		if( isdigit(postfix[i]) )
			intStack.push(postfix[i] - 48);
		else if( postfix[i] == '+' )
			intStack.push( intStack.pop() + intStack.pop() );
		else if( postfix[i] == '-' )
			intStack.push( -intStack.pop() - -intStack.pop() );
		else if( postfix[i] == '*' )
			intStack.push( intStack.pop() * intStack.pop() );
		else if( postfix[i] == '/' )
			intStack.push( intStack.pop() / intStack.pop() );
		else if( postfix[i] == '%' )
			intStack.push( intStack.pop() % intStack.pop() );
	}
	if( intStack.getLength() == 1)
		return intStack.pop();
	cout << "MISMATCHING OPERATOR TO OPERAND RATIO" << endl;
	return 0;
}

int main()
{
	stack<int> myStack;
	queue<int> myQueue;

	/*
	for(int i = 0; i < 10; i++)
	{
		cout << "adding " << i+1 << " to the stack" << endl;
		myStack.push(i+1);
	}

	breakLine();

	for(int i = 0; i < 10; i++ )
	{
		cout << "poping from list: " << myStack.pop() << endl;
	}

	breakLine();
	breakLine();

	for(int i = 0; i < 10; i++)
	{
		cout << "adding " << i+1 << " to the queue" << endl;
		myQueue.append(i+1);
	}

	breakLine();

	for(int i = 0; i < 10; i++ )
	{
		cout << "removing from queue: " << myQueue.remove() << endl;
	}
	breakLine();
	breakLine();
	*/

	char input[20];

	cout << "input infix equation" << endl;
	gets(input);
	breakLine();	
	
	string postfix = infixToPostfix(input);

	cout << "postfix expreasion: " << postfix << endl;
	cout << "Evaluated: " << postfixEval(postfix) << endl;

	system("PAUSE");
}