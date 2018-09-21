#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"

using namespace std;


int main()
{
	//Point* p_array[3];	//Arrays on the stack must have the size set at compile time
	Point* object_pointer;
	Point** p_array = new Point*[3];
	//Create for each element in the array a point on the heap 
	for (int i = 0; i < 3; i++)
	{
		object_pointer = new Point;
		object_pointer->SetX(2*i+2);
		object_pointer->SetY(3*i+3);
		p_array[i] = object_pointer;
	}

	//Iterate the array and print each point in the array
	for (int j = 0; j < 3; j++)
	{
		cout << p_array[j]->ToString() << endl;
	}

	//Iterate the array again and delete each point in the array
	for (int l = 0; l < 3; l++)
	{
		cout << p_array[l]->ToString() << endl;
		delete p_array[l];
		p_array[l] = NULL;
		//cout << "delete array element.\n";
	}

	//Delete the array itself
	delete[] p_array;
	cout << "delete array.\n";
	//system("pause");
	return 0;
} 