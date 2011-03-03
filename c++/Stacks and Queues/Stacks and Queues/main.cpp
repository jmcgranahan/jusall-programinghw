//main.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "node.h"
#include "stack.h"
#include "queue.h"


using namespace std;
void breakLine()
{
	cout << "===============================================" << endl;
}

/******** Function: operatorPriority
Inputs: char operator
Output: int
Description: returns the priority of the operator
********/
int operatorPriority(char input)
{
	if ( input == '+' || input == '-')
		return 1;
	else if ( input == '*' || input == '/' || input == '%')
		return 2;
	return 0;
}

/******** Function: infixToPostfix
Inputs: char[]
Output: string
Description: translates a infix line into a postfix line
********/
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
			_queue.append(' '); // space's out the digits
			if (_stack.getLength() == 0)
				_stack.push(currentchar);

			else
			{
				while ( operatorPriority(currentchar) <= operatorPriority(_stack.peak()) )  // while top of stack has higher or equal priority, pop top to queue
				{
					_queue.append(_stack.pop());
					_queue.append(' ');
				}
				_stack.push(currentchar);
			}
		}

		else if ( currentchar == '(')
			_stack.push(currentchar);

		else if ( currentchar == ')')
		{
			_queue.append(' ');
			char poped = _stack.pop();
			while( poped && poped != '(' ) // checks until bracket
			{
				_queue.append(poped);
				_queue.append(' ');
				poped = _stack.pop();
			}
		}
	}
	
	while( _stack.getLength() ) // removes anything fom the stacj
	{
		_queue.append(' ');
		_queue.append(_stack.pop());
	}
	
	string sOutput;
	
	while(_queue.getLength())
		sOutput += _queue.remove();

	return sOutput;
} 

/******** Function: postfixEval
Inputs: string postfix
Output: float
Description: evaluates a postfix string 
********/
float postfixEval(string postfix)
{
	stack<double> floatStack;
	for(int i = 0; i < postfix.length(); i++)
	{
		if( isdigit(postfix[i]) )
		{
			int start = i;
			while(isdigit(postfix[i+1])) // gets multi-digit numbers
				i++;

			float sum = 0;
			for(int j = start; j <= i; j++)
				sum += (float)(postfix[j]-48)*(pow(10,(double)(i-j))); // multiplys the first digit by the appropriate power of 10
			floatStack.push(sum);
		}

		else if( postfix[i] == '+' )
			floatStack.push( floatStack.pop() + floatStack.pop() );
		else if( postfix[i] == '-' )
			floatStack.push( -floatStack.pop() - -floatStack.pop() ); //damn negitives
		else if( postfix[i] == '*' )
			floatStack.push( floatStack.pop() * floatStack.pop() );
		else if( postfix[i] == '/' )
		{										// has to be parsed in reverse order
			double bottom = floatStack.pop();
			double top = floatStack.pop();
			floatStack.push( top / bottom );
		} 
		else if( postfix[i] == '%' )
			floatStack.push( (int)floatStack.pop() % (int)floatStack.pop() );
	}
	if( floatStack.getLength() == 1)
		return floatStack.pop();
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
	char buffer[20];
	do {
	cout << "input infix equation" << endl;
	gets(input);
	breakLine();	
	for(int i = 0; i < 20; i++)
		buffer[i] = input[i];

	string postfix = infixToPostfix(buffer);
	

	cout << "postfix expreasion: " << postfix << endl;
	cout << "Evaluated: " << postfixEval(postfix) << endl;

	system("PAUSE");
	} while( input[0] != 'q');
}