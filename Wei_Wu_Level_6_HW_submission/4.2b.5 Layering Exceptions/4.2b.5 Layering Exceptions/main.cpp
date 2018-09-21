#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"

using namespace std;

int main()
{
	Stack<int> cStack(10);

	for (int i = 0; i < 5; i++)
	{
		try
		{
			cStack.Push(i);	//push 0-9 to stack
//		cout << i << endl;
		}
		catch(StackException &cException)
		{
			cout << "StackFullException " << endl;
			cout << cException.GetMessage() << endl; //to display an error message.
		}
	} 
	Stack<int> cStack1=cStack;
	for (int i = 0; i < 5; i++)
	{
		try
		{
			int j;
			j = cStack1.Pop();	//pop 9-0
			cout << j << endl;
		}
		catch(StackException &cException)
		{			
			cout << "StackFullException " << endl;
			cout << cException.GetMessage() << endl; //to display an error message.
		}
	}
	return 0;
}