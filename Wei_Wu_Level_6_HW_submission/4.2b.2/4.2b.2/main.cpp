#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "NumericArray.hpp"

using namespace std;

int main()
{
	NumericArray<int> cNum1, cNum2;
	for (int i = 0; i < 10; i++)
	{
		cNum1.SetElement(i, i);		//cNum1[]={0,1,2,3,4,5,6,7,8,9}
		cNum2.SetElement(i, i+1);	//cNum2[]={1,2,3,4,5,6,7,8,9,10}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << cNum1[i] << " " << cNum2[i] << endl;
	}
	cNum1 = cNum1 * 2;				//cNum1[]={0,2,4,6,8,10,12,14,16,18}
	cNum2 = cNum2 + cNum1;			//cNum2[]={1,4,7,10,13,16,19,22,25,28}
	for (int i = 0; i < 10; i++)	
	{
		cout << cNum1[i] << " " << cNum2[i] << endl;
	}
	cout << cNum1.DotProduct(cNum2) << endl;	//dot product = 1800
	//It's assume that the template argument can be any types, 
	//but the production of two points are not defined, 
	//so we can't use numberic array dot function with Point objects.
	return 0;
}