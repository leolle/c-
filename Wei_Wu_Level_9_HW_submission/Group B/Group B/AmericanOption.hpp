// EuropeanOption.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only.
//
// (C) Datasim Component Technology BV 2003-2011
//

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include "EuropeanOption.hpp"
#include <string>
using namespace std;

class AmericanOption: public EuropeanOption
{
private:		

	void init();	// Initialise all default values
	void copy(const AmericanOption& o2);

	// 'Kernel' functions for option calculations
	double CallPrice(double U) const;
	double PutPrice(double U) const;
	

	// Gaussian functions
	//double n(double x) const;
	//double N(double x) const;


public:

	// Member data public for convenience; anyway, the format will 
	// not change for a plain option.

	//struct OptionData option_argu;


public:	// Public functions
	AmericanOption();							// Default call option
	AmericanOption(const AmericanOption& option2);	// Copy constructor
	AmericanOption(const string& optionType);	// Create option type
	virtual ~AmericanOption();	

	AmericanOption& operator = (const AmericanOption& option2);

	// Functions that calculate option price and sensitivities
	double APrice(double U) const;

	// Modifier functions

};

#endif