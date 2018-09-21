#ifndef Array_HPP
#define Array_HPP

#include "point.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
namespace WEIWU
{
	namespace CONTAINER
	{
		using namespace CAD;
		class Array
		{
		private:
			Point* m_data;
			int m_size;
		public:
			// Constructors
			Array();
			Array(const int& s);
			Array(const Array& a);

			// Destructor
			~Array()
			{
				cout << "delete array class\n";
				delete[] m_data;
			};

			// Modifiers
			int Size() const;
			void SetElement(const int& index, const Point& p);
			Point GetElement(const int& index);

			Array& operator = (const Array& source); // Assignment operator.
			Point& operator [] (int index); // Assignment operator.
			const Point& operator [] (int index) const; // Assignment operator.
			bool operator == (const Array& a) const; // Equally compare operator.

		};
	}
}
#endif


