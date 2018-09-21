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
	for (int i = 0; i < 19; i++)
	{
		try
		{
		cStack.Push(i);	//push 0-9 to stack
//		cout << i << endl;
	
		}
		catch(ArrayException &cException)	//catching the ArrayException base class.
		{
			cout << "In catch handler." << endl;
			cout << "Caught cArray exception type: ";
			cout << cException.GetMessage() << endl; //to display an error message.
		}
	}
	for (int i = 0; i < 12; i++)
	{
		int j;
		try
		{
			j = cStack.Pop();	//pop 9-0
			cout << j << endl;
		}
		catch(ArrayException &cException)	//catching the ArrayException base class.
		{
			cout << "In catch handler." << endl;
			cout << "Caught cArray exception type: ";
			cout << cException.GetMessage() << endl; //to display an error message.
		}
	}  
	return 0;
}