// TestEuropeanOption.cpp
//
// program for the exact solutions of European options. 
// *should make option arguments private

#include "EuropeanOption.hpp"
#include <iostream>
#include <vector>
//Exercise A1 a
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <algorithm>
#include <cmath>
#include <list>
#include <string>

//Implement the BS formulae for call and put option pricing
double CallOption(double r, double sig, double K, double T, double b, double S)
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);
	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (S * exp((b-r)*T) * cdf(myNormal,d1)) - (K * exp(-r * T)* cdf(myNormal,d2));

}

double PutOption(double r, double sig, double K, double T, double b, double S)
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = sig * sqrt(T);
	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* cdf(myNormal,-d2)) - (S * exp((b-r)*T) * cdf(myNormal,-d1));

}

//Exercise A1 b
//Apply the put-call parity relationship to compute call and put option prices
//double CallPutParity(double r, double K, double T, double S, double optionPrice, string optType)
//{
//	if (optType == "P")		//known option type
//	{
//		return S + optionPrice - K*exp(-r*T);	//return call option price
//	}
//	else if (optType == "C")
//	{
//		return K*exp(-r*T) + optionPrice - S;	//return put option price
//	}
//}

//Exercise A1 c
// Encapsulate all data in one place
struct OptionData
{ // Option data + behaviour (all public!)
	double T;
	double K;
	double sig;
	double r;
	double b;
	string opt_type;	// Option name (C,P)
	double c;	//known call price
	double p;	//known put price

};

//Implement the BS formulae for call and put option pricing
double CallOption(struct OptionData* option, double S)
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = option->sig * sqrt(option->T);
	double d1 = ( log(S/option->K) + (option->b+ (option->sig*option->sig)*0.5 ) * option->T )/ tmp;
	double d2 = d1 - tmp;

	return (S * exp((option->b-option->r)*option->T) * cdf(myNormal, d1)) - (option->K * exp(-option->r * option->T)* cdf(myNormal, d2));

}

double PutOption(struct OptionData* option, double S)
{
	using namespace boost::math;
	normal_distribution<double> myNormal; 
	double tmp = option->sig * sqrt(option->T);
	double d1 = ( log(S/option->K) + (option->b+ (option->sig*option->sig)*0.5 ) * option->T )/ tmp;
	double d2 = d1 - tmp;

	return (option->K * exp(-option->r * option->T)* cdf(myNormal,-d2)) - (S * exp((option->b-option->r)*option->T) * cdf(myNormal,-d1));

}

//Apply the put-call parity relationship to compute call and put option prices
//double CallPutParity(struct OptionData* option, double S)
//{
//	if (option->opt_type == "P")		//known option type
//	{
//		return S + option->p - option->K*exp(-option->r*option->T);	//return call option price
//	}
//	else if (option->opt_type == "C")
//	{
//		return option->K*exp(-option->r*option->T) + option->c - S;	//return put option price
//	}
//}

//Exercise A1 d
/*template<class ContainerType>
void PrintOption(const ContainerType call, const ContainerType put, *//*template<class ContainerType>*/
//void PrintOption(const std::vector<double> call, const std::vector<double> put, double Stock[40])
//{
//	using namespace std;
//	std::vector<double>::const_iterator it_call, it_put;
//    it_call = call.begin(); // assign it to the start of the list
//	it_put = put.begin();
//	int i = 0;
//	cout << "S \t Call \t\t Put" << endl; 
//	while (it_call != call.end()) // while it hasn't reach the end
//    {
//		//cout << 
//		cout << Stock[i] << '\t' << *it_call << '\t' << '\t' << *it_put << endl;
//        ++it_call; // and iterate to the next element
//        ++it_put; // and iterate to the next element
//		i++;
//    }
//}
vector<double> MeshArray(double start, double end, double h)
{
    vector<double> mesh;
    mesh.reserve(100);
    for (double i = start; i <= end; i += h)
        mesh.push_back(i);
    return mesh;
}

#define h 1		// used for mesh array
#define START 0
#define END 325

int main()
{ 


	//cout << "Call option on stock 1: " << CallPutParity(0.08, 65, 0.25, 60, 5.84584, "P") << endl;
	//cout << "Put option on stock 1: " << CallPutParity(0.08, 65, 0.25, 60, 2.13293, "C") << endl;
	
	////Exercise A1 b&c
	////using call put parity to get call option price
	EuropeanOption stock1;
	stock1.b = 0.02;
	stock1.r = 0.02;
	stock1.T = 0.75;
	stock1.K = 50;
	stock1.K = 50;
	stock1.sig = 0.3;
	//stock1.call_price = 2.13337;
	//stock1.put_price = 5.84628;
	stock1.optType = "C";

	long N = END - START + 1;

	// Create abscissa x array
	Vector<double, long> x(N,0.0);
	double T = 10.0;
	double mesh_h = 1;
	//double mesh_h = T/double(N);
	x[x.MinIndex()] = START;
	x[x.MaxIndex()] = END;
	for (long j = x.MinIndex()+1; j <= x.MaxIndex()-1; ++j)
	{
		x[j] = x[j-1] + mesh_h;
	}


	//Exercise A1 d&e
	std::vector<double> stock_vect, expiry_time, volatility;
	Vector<double, long> stock_call(N,0.0),stock_put(N,0.0);
	stock_vect = MeshArray(START, END, h);	//create stock mesh array
	expiry_time = MeshArray(0.25, 10.0, 0.25);	//create expiry time mesh array
	volatility = MeshArray(0.1 , 0.5, 0.02);	//create volatility mesh array

	cout << "***"<< endl;
	cout << "Stock \t \t Call \t \t Put"<< endl;
	for (int i = 0; i < stock_vect.size(); i++)
	{
		stock1.optType = "C";
		cout << fixed << stock_vect[i] << '\t' << stock1.Price(stock_vect[i]) << '\t';
		stock_call[i] = stock1.Price(stock_vect[i]);
		stock1.toggle();
		cout << fixed << stock1.Price(stock_vect[i]) << endl;
		stock_put[i] = stock1.Price(stock_vect[i]);
		//stock_put[i] = (stock_vect[i]-stock1.K)>0?(stock_vect[i]):0;
		//stock_put[i] = stock1.Price(stock_vect[i]) -((stock1.K-stock_vect[i])>0?(stock1.K-stock_vect[i]):0);
		//stock_put[i] = stock1.Price(stock_vect[i]) - std::max((stock1.K-stock_vect[i]),0);
	}
	std::cout << "Data has been created\n";

	try 
	{
		printPairExcel(x,stock_call, stock_put, 
						string("Option price"), string("Stock Price"), string("Value"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	return 0;
}
