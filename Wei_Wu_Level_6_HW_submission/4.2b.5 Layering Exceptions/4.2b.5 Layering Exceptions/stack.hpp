#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
template<typename T>
class Stack
{
private:
	Array<T> cM_data;
	int m_current;
public:
	// Constructors
	Stack();
	Stack(const int& s);
	Stack(const Stack<T>& a);

	// Destructor
	~Stack() 
	{ 
		cout << "delete stack class\n";
	};

	// Modifiers
	void Push(const T& in);
	T Pop();


	Stack<T>& operator = (const Stack<T>& source); // Assignment operator.
//	bool operator == (const Stack<T>& a) const; // Equally compare operator.

};

class StackException
{
private:
public:
	StackException()
	{
		cout << "construct StackException " << endl;
	};
	virtual ~StackException()
	{
		cout << "destruct StackException " << endl;
	};
	//void GetMessage();
	virtual std::string GetMessage() const
	{
		//std::string sssss;
		//return sssss;
		return "Exception in Stack class.";
	}
	//virtual void get()=0;


};

class StackFullException: public StackException
{
private:
	int m_index;
public:
	StackFullException()
	{
//		cout << "construct StackFullException " << endl;
	};
	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
//	StackFullException(int i): m_index(i)		
//	{
//		cout << "erroneous array index is " << i << endl;
////		m_index = i;
//	}
	~StackFullException()
	{
//		cout << "destruct StackFullException " << endl;
	};
	std::string GetMessage() const
	{
		std::stringstream ss;
		ss << "stack full." ;
		std::string s = ss.str();
		return s;			//return the given index is out of bounds.
	}

};

class StackEmptyException: public StackException
{
private:
	int m_index;
public:
	StackEmptyException()
	{
//		cout << "construct StackEmptyException " << endl;
	};
	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
//	ArraySizeException(int i): m_index(i)		
//	{
//		cout << "erroneous array index is " << i << endl;
////		m_index = i;
//	}
	~StackEmptyException()
	{
//		cout << "destruct StackEmptyException " << endl;
	};
	std::string GetMessage() const
	{
		std::stringstream ss;
		ss << "stack empty." ;
		std::string s = ss.str();
		return s;			//return the given index is out of bounds.
	}

};


#ifndef Stack_cpp
#include "Stack.cpp"
#endif
#endif


