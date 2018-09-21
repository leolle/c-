#ifndef _SCL_SECURE_NO_WARNINGS
# define _SCL_SECURE_NO_WARNINGS
#endif
 
#ifndef _CRT_SECURE_NO_WARNINGS
# define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <map>
#include <boost/limits.hpp>
#include <math.h>

using namespace std;

int main()
{

	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> uni(1,6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome
	
	// C. Choose the desired accuracy
	cout << "How many trials? "; 
	long N; 
	cin >> N;
	for (long n = 1; n <= N; ++n)
	{
		outcome = uni(myRng);
		//cout << outcome << endl;
		switch (outcome)
		{
		case 1:
			{
				statistics[1]++;
				break;
			}
		case 2:
			{
				statistics[2]++;
				break;
			}
		case 3:
			{
				statistics[3]++;
				break;
			}
		case 4:
			{
				statistics[4]++;
				break;
			}
		case 5:
			{
				statistics[5]++;
				break;
			}
		case 6:
			{
				statistics[6]++;
				//statistics[0]++;
				break;
			}
		default:
			break;
		}
	}
	for (int i = 1; i < 7; i++)
	{
		cout << "Trial " << i << " has " << (float)statistics[i]/N*100 << '%' << " outcomes." << endl;
	}
		//cout << "Trial " << (float)statistics[0] << endl;

	return 0;

}