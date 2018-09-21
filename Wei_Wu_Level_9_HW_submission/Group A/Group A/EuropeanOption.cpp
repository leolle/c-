// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003-2011
//


#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>

//////////// Gaussian functions /////////////////////////////////

// In general, we would use similar functions in Boost::Math Toolkit

//double EuropeanOption::n(double x) const
//{ 
//
//	double A = 1.0/sqrt(2.0 * 3.1415);
//	return A * exp(-x*x*0.5);
//
//}
//
//double EuropeanOption::N(double x) const
//{ // The approximation to the cumulative normal distribution
//
//
//	double a1 = 0.4361836;
//	double a2 = -0.1201676;
//	double a3 = 0.9372980;
//
//	double k = 1.0/(1.0 + (0.33267 * x));
//	
//	if (x >= 0.0)
//	{
//		return 1.0 - n(x)* (a1*k + (a2*k*k) + (a3*k*k*k));
//	}
//	else
//	{
//		return 1.0 - N(-x);
//	}
//
//}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + ( r - q + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;


	return (U * exp((b-q)*T) * cdf(myNormal,d1)) - (K * exp(-r * T)* cdf(myNormal, d2));
	//return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));

}

double EuropeanOption::PutPrice(double U) const
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 

	double tmp = sig * sqrt(T);
	double d1 = ( log(U/K) + (b -r + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* cdf(myNormal, -d2)) - (U * exp((b-q)*T) * cdf(myNormal, -d1));

}

double EuropeanOption::CallDelta(double U) const
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;


	return exp((b-r)*T) * cdf(myNormal,d1);
}

double EuropeanOption::PutDelta(double U) const
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (cdf(myNormal, d1) - 1.0);
}



/////////////////////////////////////////////////////////////////////////////////////

void EuropeanOption::init()
{	// Initialise all default values

	// Default values
	r = 0.08;
	sig= 0.3;

	K = 65.0;
	T = 0.25;

	b = r;			// Black and Scholes stock option model (1973)
	
	optType = "C";		// European Call Option (this is the default type)
}

void EuropeanOption::copy( const EuropeanOption& o2)
{

	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	
	optType = o2.optType;
	
}

EuropeanOption::EuropeanOption() 
{ // Default call option

	init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor

	copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

}



EuropeanOption::~EuropeanOption()
{

}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price(double U) const
{


	if (optType == "C")
	{	
		//cout << "calling call\n";
		return CallPrice(U);
	}
	else
	{
		//cout << "calling put\n";
		return PutPrice(U);
	}
}	

double EuropeanOption::Delta(double U) const 
{
	if (optType == "C")
		return CallDelta(U);
	else
		return PutDelta(U);

}

double EuropeanOption::Gamma(double U) const 
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * pdf(myNormal,d1) / U / tmp;

}

double EuropeanOption::Vega(double U) const 
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * pdf(myNormal,d1) * U * sqrt(T);

}

double EuropeanOption::Theta(double U) const 
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return -U*sig*exp((b-r)*T)*pdf(myNormal,d1)/2/sqrt(T)-(b-r)*U*exp((b-r)*T)*cdf(myNormal,d1)-r*K*exp(-r*T)*cdf(myNormal,d2);

}

double EuropeanOption::ImpliedVolatility(double U)  
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double x0 = 0.25;
	double x_new = x0;
	double x_old = x0 - 1;
	double tol = 1.0e-6;
	while(abs(x_new - x_old) > tol)
	{
		x_old = x_new;
		sig = x_new;
		x_new = x_new - (CallPrice(U) - call_price) / Vega(U);
	}
	return x_new;

}


// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}

// calculate call/put price using parity
double EuropeanOption::Prity(double stockPrice)
{
	if (optType == "C")
		return stockPrice + put_price - K*exp(-r*T);	//return call option price
	else if (optType == "P")
		return K*exp(-r*T) + call_price - stockPrice;	//return put option price
}
