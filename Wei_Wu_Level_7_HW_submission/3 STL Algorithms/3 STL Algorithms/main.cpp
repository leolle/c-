#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <deque>
#include <string>
#include <set>
#include <algorithm>

template<class ContainerType>
double Sum(ContainerType Container)
{
	using namespace std;
	ContainerType::const_iterator it;
	double sum=0;
    it = Container.begin(); // assign it to the start of the list
    while (it != Container.end()) // while it hasn't reach the end
    {
        cout << *it << " "; // print the value of the element it points to
		sum += *it;
        ++it; // and iterate to the next element
    }
	return sum;
}
//template<template<typename T> class ContainerType>
//class MyClass
//{
//ContainerType<int> intContainer;
//ContainerType<std::string> stringContainer;
//// rest of class
//};
#define VALUE 5

bool Smaller (const double i) { return (i < VALUE); }	//global function to compare a value

template<int val>
bool Smaller(double i)
{
	return (i<val);
}
//check for should not be a ¡®literal¡¯ value, but taken from a data member that was set in the constructor of the function object.
class Compare
{
private:
	double m_data;
public:
	Compare(){};
	Compare(double j);
	~Compare();

	bool operator()(const double &a) const
	{
		return a < m_data;
	}
};

Compare::Compare(double j):m_data(j)
{
}

Compare::~Compare()
{
}

int main()
{
    using namespace std;

	//Create a list of doubles and add some data. Use the front() and back() functions to
	//access the first and last element
	list<double> li;
    for (int nCount=0; nCount < 6; nCount++)
        li.push_back(nCount+0.5);	//li = {0.5, 1.5 ,2.5 ,3.5 ,4.5 ,5.5 }
	//double x =5;
    cout << "front: " << li.front() << endl; // print the value of the element it points to
    cout << "back: " << li.back() << endl; // print the value of the element it points to
	cout << "the number of elements smaller than 5 = " << count_if(li.begin(), li.end(), Smaller) << endl; 
	cout << "the number of elements smaller than 5 = " << count_if(li.begin(), li.end(), Smaller<5>) << endl; 
	cout << "the number of elements smaller than 5 = " << count_if(li.begin(), li.end(), Compare(5)) << endl; 

	//Create a vector of doubles and add some data. Then use the index operator to access
	//some elements.
	vector<double> vect;
	vect.reserve(100);
	for (int n_count=0; n_count < 6; n_count++)
	{
        vect.push_back(n_count+1.5);	//vect = {1.5 ,2.5 ,3.5 ,4.5 ,5.5, 6.5 }
		//cout << "capacity: " << (int) vect.capacity() << '\n';
	}
	//cout << "size: " << (int) vect.size() << '\n';
	//cout << "max_size: " << (int) vect.max_size() << '\n';

	for (int i = 0; i < 6; i++)
	{
		cout<< vect[i] << " ";
	}
	cout << endl;

	cout << "the number of elements smaller than 5 = " << count_if(vect.begin(), vect.end(), Smaller) << endl; 
	cout << "the number of elements smaller than 5 = " << count_if(vect.begin(), vect.end(), Smaller<5>) << endl; 
	cout << "the number of elements smaller than 5 = " << count_if(vect.begin(), vect.end(), Compare(5)) << endl; 

    //list<double>::const_iterator it; // declare an iterator
    //it = li.begin(); // assign it to the start of the list
    //while (it != li.end()) // while it hasn't reach the end
    //{
    //    cout << *it << " "; // print the value of the element it points to
    //    ++it; // and iterate to the next element
    //}
    //map<int, string> mymap;
    //mymap.insert(make_pair(4, "apple"));
    //mymap.insert(make_pair(2, "orange"));
    //mymap.insert(make_pair(1, "banana"));
    //mymap.insert(make_pair(3, "grapes"));
    //mymap.insert(make_pair(6, "mango"));
    //mymap.insert(make_pair(5, "peach"));
 
    //map<int, string>::const_iterator it; // declare an iterator
    //it = mymap.begin(); // assign it to the start of the vector
    //while (it != mymap.end()) // while it hasn't reach the end
    //{
    //    cout << it->first << "=" << it->second << " "; // print the value of the element it points to
    //    ++it; // and iterate to the next element
    //}
 
    //cout << endl;
 
    //set<int> myset;
    //myset.insert(7);
    //myset.insert(2);
    //myset.insert(-6);
    //myset.insert(8);
    //myset.insert(1);
    //myset.insert(-4);
 
    //set<int>::const_iterator it; // declare an iterator
    //it = myset.end(); // assign it to the start of the set
    ////while (it != myset.end()) // while it hasn't reach the end
    ////{
    //    cout << *it << " "; // print the value of the element it points to
    ////    ++it; // and iterate to the next element
    ////}
 
    //cout << endl;
	return 0;
}