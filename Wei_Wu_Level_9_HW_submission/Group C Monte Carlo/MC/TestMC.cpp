// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//
#pragma warning(disable : 4996)
#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"
#include <cmath>
#include <iostream>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

// generic function to compute the standard deviation and standard error based on the formulae
template <class T> 
void PrintSdSe(const std::vector<T>& myList, double interestRate, double expiryTime)
{  // A generic print function for vectors
	double c_t_sum = 0;
	double c_t_square = 0;
	double c_t_square_sum = 0;
	double standard_deviation;
	double M = myList.size();
	double tmp;


	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		tmp = *i;
		c_t_sum += tmp;
		c_t_square = pow(tmp,2);
		c_t_square_sum += c_t_square;	
	}
	standard_deviation = sqrt(c_t_square_sum - pow(c_t_sum,2)/M)*exp(-2*interestRate * expiryTime)/(M-1);

	double standard_error = standard_deviation/sqrt(M);

	std::cout << "standard deviation: " << standard_deviation << std::endl;
	std::cout << "standard error: " << standard_error << std::endl;
}



namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = 100;
	myOption.T = 1.5;
	myOption.r = 0.04;
	myOption.sig = 0.4;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = 120;
	
	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	Vector<double, long> x = range.mesh(N);
	

	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);
	vector<double> option_price;

	// Normal random number
	double dW;
	double price = 0.0;	// Option price

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	data = &myOption;

	Vector<double> res;
	int coun = 0; // Number of times S hits origin


	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration
			
		if ((i/10000) * 10000 == i)
		{// Give status after each 1000th iteration

				std::cout << i << std::endl;
		}

		VOld = S_0;
		for (long index = x.MinIndex()+1; index <= x.MaxIndex(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
			
		double tmp = myOption.myPayOffFunction(VNew);
		//c_t_sum += tmp;
		//c_t_square = pow(tmp,2);
		//c_t_square_sum += c_t_square;
		option_price.push_back(tmp);
		price += (tmp)/double(NSim);
	}
	//double standard_deviation;
	//standard_deviation = sqrt(c_t_square_sum - pow(c_t_sum,2)/NSim)*exp(-2*myOption.r * myOption.T)/(NSim-1);
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);
	//double standard_error = standard_deviation/sqrt(NSim);
	// Cleanup; V2 use scoped pointer
	delete myNormal;
	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	//std::cout << "standard deviation: " << standard_deviation << ", " << std::endl;
	//std::cout << "standard error: " << standard_error << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;
	PrintSdSe(option_price, myOption.r, myOption.T);

	return 0;
}