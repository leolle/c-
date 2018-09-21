#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <deque>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <functional>

template<class ContainerType>
double Sum(const ContainerType Container)
{
	using namespace std;
	ContainerType::const_iterator it;
	double sum=0;
    it = Container.begin(); // assign it to the start of the list

	while (it != Container.end()) // while it hasn't reach the end
    {
    //    cout << *it << " "; // print the value of the element it points to
		sum  += *it;
        ++it; // and iterate to the next element
    }
	return sum;
}


//sum function for container map because map element can't be access from iterator it directly.
double Sum(const std::map<double, double> &Container)
{
	using namespace std;
	map<double, double>::const_iterator it;
	double sum=0;
    it = Container.begin(); // assign it to the start of the list

	while (it != Container.end()) // while it hasn't reach the end
    {
    //    cout << *it << " "; // print the value of the element it points to
		sum  += it->second;
        ++it; // and iterate to the next element
    }
	return sum;
}

//sum function with iterators as parameter for container list and vector
template<class InputIt>
double Sum(InputIt first, InputIt last)
{
	double init = 0;
    for (; first != last; ++first) {
        init = init + *first;
    }
    return init;
}
//sum function with iterators as parameter for container map because map element can't be access from iterator it directly.
//template<typename InputIt = std::map<double, double>::const_iterator>
////template<typename Iterator, typename Comp = std::map<typename std::iterator_traits<Iterator>::value_type> >
//double Sum(InputIt first, InputIt last)
//{
//	double init = 0;
//    for (; first != last; ++first) {
//        init = init + first->second;
//    }
//    return init;
//}
template<>
double Sum(std::map<double,double>::const_iterator first, std::map<double,double>::const_iterator last)
{
	double init = 0;
    for (; first != last; ++first) {
        init = init + first->second;
    }
    return init;
}
 
//template<typename It, typename Container>
//double Sum1(It begin, It end) 
//{
//	using namespace std;
//	Container::const_iterator it=begin;
//	double sum=0;
//
//	while (it != end) // while it hasn't reach the end
//    {
//    //    cout << *it << " "; // print the value of the element it points to
//		sum  += *it;
//        ++it; // and iterate to the next element
//    }
//	return sum;
//}

//template<class ContainerType>
//double Sum(const ContainerType Container)
//{
//	using namespace std;
//	ContainerType::const_iterator it;
//	double sum=0;
//    it = Container.begin(); // assign it to the start of the list
//    while (it != Container.end()) // while it hasn't reach the end
//    {
//        cout << *it << " "; // print the value of the element it points to
//		sum += *it;
//        ++it; // and iterate to the next element
//    }
//	return sum;
//}

//template<class ContainerType>
//double Sum1( ContainerType::const_iterator first,  ContainerType::const_iterator last)
//{
//	using namespace std;
//	ContainerType::const_iterator  i;
//	double sum=0;
//	for (i = first; i != last; ++i)
//	{
//			cout << *i << ",";
//			sum += *i;
//	}
//
//	//it = Container.begin(); // assign it to the start of the list
// //   while (it != Container.end()) // while it hasn't reach the end
// //   {
// //       cout << *it << " "; // print the value of the element it points to
//	//	sum += *it;
// //       ++it; // and iterate to the next element
// //   }
//	return sum;
//}
//template<template<typename T> class ContainerType>
//class MyClass
//{
//ContainerType<int> intContainer;
//ContainerType<std::string> stringContainer;
//// rest of class
//};
int main()
{
    using namespace std;

	//Create a list of doubles and add some data. Use the front() and back() functions to
	//access the first and last element
	list<double> li;
    for (int nCount=0; nCount < 6; nCount++)
    	li.push_back(nCount+0.5);
		
    cout << "front: " << li.front() << endl; // print the value of the element it points to
    cout << "back: " << li.back() << endl; // print the value of the element it points to

	//use sum function to get the sum of all values in the container
	cout << "sum of list = " << Sum(li) << endl; 
	cout << "sum of list = " << Sum(li.begin(),li.end()) << endl; 

	//Create a vector of doubles and add some data. Then use the index operator to access
	//some elements.
	vector<double> vect;
	vect.reserve(100);
	for (int n_count=0; n_count < 6; n_count++)
	{
        vect.push_back(n_count+0.9);
	}

	for (int i = 0; i < 6; i++)
	{
		cout<< vect[i] << " ";
	}
	cout << endl;

	//use sum function to get the sum of all values in the container
	cout << "sum of vector = " << Sum(vect) << endl; 
	cout << "sum of vector = " << Sum(vect.begin(),vect.end()) << endl; 
	//Create a map that maps strings to doubles. Fill the map and access elements using the
	//square bracket operator
	map<double, string> my_map;
    my_map.insert(make_pair(4.6, "apple"));
    my_map.insert(make_pair(2.2, "orange"));
    my_map.insert(make_pair(1.1, "banana"));
    my_map.insert(make_pair(3.5, "grapes"));
    my_map.insert(make_pair(6.4, "mango"));
    my_map.insert(make_pair(5.8, "peach"));

	cout << my_map[1.1] << " "<< my_map[2.2] << " "<< my_map[3.5] << " "<< my_map[6.4] << endl;
 
	
	//Create a map that maps numerical numbers to doubles. 
	map<double, double> my_map1;
    my_map1.insert(make_pair(4, 1.5));
    my_map1.insert(make_pair(2.2, 2.5));
    my_map1.insert(make_pair(1, 3.5));
    my_map1.insert(make_pair(3, 4.5));
    my_map1.insert(make_pair(6, 5.5));
    my_map1.insert(make_pair(5, 6.5));

	//use sum function to get the sum of all values in the container
	cout << "sum of map = " << Sum(my_map1) << endl; 
//	cout << "sum of map = " << Sum<double, double>(my_map1.begin(), my_map1.end()) << endl; 

double x=5/2;
printf("%.1f\n", x);return 0;
}