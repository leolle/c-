#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <deque>
#include <string>
#include <set>

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

	//Create a vector of doubles and add some data. Then use the index operator to access
	//some elements.
	vector<double> vect;
	vect.reserve(100);
	for (int n_count=0; n_count < 50; n_count++)
	{
        vect.push_back(n_count+0.9);
		//cout << "capacity: " << (int) vect.capacity() << '\n';
		
	
	}
	//cout << "size: " << (int) vect.size() << '\n';
	//cout << "max_size: " << (int) vect.max_size() << '\n';

	for (int i = 0; i < 6; i++)
	{
		cout<< vect[i] << " ";
	}
	cout << endl;

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