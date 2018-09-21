// TestEuropeanOption.cpp
//
// program for the exact solutions of European options. 
//
#pragma warning(disable: 4996)
#include "EuropeanOption.hpp"
#include <iostream>
#include <vector>
#include "boost/multi_array.hpp"
#include <cassert>

using namespace std;

// !! The variable b is cost of carry (b = r -q for a dividend-paying stock)

double PerpetualCall (double K, double S, double sig, double r, double b)
{ // Dividend q = r - b

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double PerpetualPut (double K, double S, double sig, double r, double b)
{

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
}

typedef boost::multi_array<double, 2> array_type;
typedef array_type::index index;

array_type MeshArray(double start, double end, double h)
{
    array_type mesh(boost::extents[100][3]);
	index i=0;
    for (double n = start; n <= end; n += h)
	{
        mesh[i][0] = n;
		i++;
	}
    return mesh;
}

#define H 0.5		// used for mesh array
#define START 90
#define END 115

int main()
{ 
	//Exercise B
	EuropeanOption stock1;
	//stock1.b = 0.02;
	//stock1.r = 0.1;
	//stock1.K = 100;
	//stock1.sig = 0.1;
	stock1.b = 0.02;
	stock1.r = 0.02;
	stock1.K = 45;
	stock1.sig = 0.25;
	stock1.optType = "AC";	// AC = american call

	cout << "Call option on stock 1: " << stock1.Price(45)<< endl;

	stock1.optType = "AP";	// AP = american put
	cout << "Put option on stock 1: "  << stock1.Price(45)<< endl;



	//Exercise B c
	std::vector<double> stock_vect, stock_call, stock_put;
	array_type marry(boost::extents[100][3]);
	marry = MeshArray(START, END, H);	//create stock mesh array

	//cout << "***"<< endl;
	//cout << "Stock \t \t Call \t \t Put"<< endl;

	//for (index i = 0; i < (END-START)/H+1; i++)
	//{
	//	stock1.optType = "AC";
	//	cout <<fixed << marry[i][0] << '\t' << stock1.Price(marry[i][0]) << '\t';
	//	marry[i][1] = stock1.Price(marry[i][0]);
	//	stock1.optType = "AP";
	//	cout << fixed << stock1.Price(marry[i][0]) << endl;
	//	marry[i][2] = stock1.Price(marry[i][0]);
	//}

	//cout << "***"<< endl;
	//cout << "Expiry time \t Call \t \t Put"<< endl;
	//for (int i = 0; i < expiry_time.size(); i++)
	//{
	//	stock1.optType = "C";
	//	stock1.T = expiry_time[i];
	//	cout << fixed << expiry_time[i] << '\t' << stock1.Price(60) << '\t';
	//	stock1.toggle();
	//	cout << fixed << stock1.Price(60) << endl;
	//}

	//cout << "***"<< endl;
	//stock1.T = 0.25;
	//cout << "Volatility \t Call \t \t Put"<< endl;
	//for (int i = 0; i < volatility.size(); i++)
	//{
	//	stock1.optType = "C";
	//	stock1.sig = volatility[i];
	//	cout << fixed << volatility[i] << '\t' << stock1.Price(60) << '\t';
	//	stock1.toggle();
	//	cout << fixed << stock1.Price(60) << endl;
	//}

	//// A1 a: greeks
	//stock1.K = 100;
	//stock1.T = 0.5;
	//stock1.r = 0.1;
	//stock1.b = 0;
	//stock1.sig = 0.36;
	//stock1.optType = "C";
	//cout << "Delta on a call: " << stock1.Delta(105) << endl;
	//stock1.toggle();
	//cout << "Delta on a put: " << stock1.Delta(105) << endl;

	//// A1 b: greeks
	//std::vector<double> call_delta;
	////stock_vect = MeshArray(50.0, 106.0, h);	//create stock mesh array
	//stock1.optType = "C";
	//cout << "***"<< endl;
	//cout << "Stock \t \tCall Delta"<< endl;
	//// to calculate delta by formula
	//for (int i = 0; i < stock_vect.size(); i++)
	//{
	//	cout << fixed << stock_vect[i] << '\t' << stock1.Delta(stock_vect[i]) << endl;
	//	call_delta.push_back(stock1.Delta(stock_vect[i]));
	//}

	//// A1 c: greeks
	//// use devided difference to approximate option sensitivities
	//cout << "***"<< endl;
	//cout << "Stock \t \tCall Delta"<< endl;
	//int vec_size = stock_vect.size();
	//double delta, gamma;
	//stock1.optType = "C";
	//stock_call.clear();

	//// to approximate delta
	//for (int i = 0; i < vec_size; i++)
	//{
	//	stock_call.push_back(stock1.Price(stock_vect[i]));
	//}
	//for (int i = 1; i < vec_size - 1; i++)
	//{
	//	//delta = (stock_call[i+1]*(stock_vect[i+1]+1)-stock_call[i+1]*(stock_vect[i+1]-1))/2;
	//	delta = (stock_call[i+1]-stock_call[i-1])/2/h;	//h=0.5
	//	cout << fixed << stock_vect[i] << '\t' << delta << endl;
	//}

	//std::vector<double> call_gamma;
	////stock_vect = MeshArray(50.0, 106.0, h);	//create stock mesh array
	//cout << "***"<< endl;
	//cout << "Stock \t \tCall Gamma"<< endl;
	//// to calculate gamma by formula
	//for (int i = 0; i < stock_vect.size(); i++)
	//{
	//	cout << fixed << stock_vect[i] << '\t' << stock1.Gamma(stock_vect[i]) << endl;
	//	call_gamma.push_back(stock1.Gamma(stock_vect[i]));
	//}
	//cout << "Stock \t \tCall Gamma"<< endl;
	//// to approximate gamma
	//for (int i = 1; i < vec_size - 1; i++)
	//{
	//	gamma = (stock_call[i+1]+stock_call[i-1]-2*stock_call[i])/pow(h,2);	//h=0.5
	//	cout << fixed << stock_vect[i] << '\t' << gamma << endl;
	//}
	
	
	return 0;
}
