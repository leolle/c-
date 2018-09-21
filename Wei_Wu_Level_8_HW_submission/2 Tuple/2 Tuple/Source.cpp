#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <string>
#include <iostream>
using namespace std;

typedef boost::tuple<string, int, double> Person;
void Print(const Person& per)
{
     string name = per.get<0>();
	 int age = per.get<1>();
     double length = per.get<2>();
     cout << name << ", " << age  << ", " << length << endl;
}
int main()
{
     // Using declaration, for readability purposes
     // Creating tuples
     //tuple<string, double> myTuple(string("Hello"), 3.1415);
     Person per[3];
	 
     per[0] = boost::make_tuple(string("Danny"), 10, 3234.5);
     per[1] = boost::make_tuple(string("Won"), 14, 3314.5);
     per[2] = boost::make_tuple(string("Jerry"), 12, 3244.5);

	 //print the info of each person
	 for (int i = 0; i < 3; i++)
	 {
		 Print(per[i]);
	 }

	 //modify the age of each person
	 for (int i = 0; i < 3; i++)
	 {
		 per[i].get<1>() = i+14;
	 }

	 //print the info of each person after modifying
	 cout << "print the info of each person after modifying" << endl;
	 for (int i = 0; i < 3; i++)
	 {
		 Print(per[i]);
	 }

     return 0;
}
