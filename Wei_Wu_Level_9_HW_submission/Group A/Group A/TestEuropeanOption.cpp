// TestEuropeanOption.cpp
//
// program for the exact solutions of European options. 
// *should make option arguments private

#include "EuropeanOption.hpp"
#include <iostream>
#include <vector>
//Exercise A1 a

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

#define h 0.5		// used for mesh array
#define START 90
#define END 105

int main()
{ 

	//Exercise A1 a
	//cout << "Call option on stock 1: " << CallOption(0.08, 0.3, 65, 0.25, 0.08, 60) << endl;
	//cout << "Put option on stock 1: " << PutOption(0.08, 0.3, 65, 0.25, 0.08, 60) << endl;

	//cout << "Call option on stock 2: " << CallOption(0.0, 0.2, 100, 1.0, 0.0, 100) << endl;
	//cout << "Put option on stock 2: " << PutOption(0.0, 0.2, 100, 1.0, 0.0, 100) << endl;

	//cout << "Call option on stock 3: " << CallOption(0.12, 0.5, 10, 1.0, 0.12, 5) << endl;
	//cout << "Put option on stock 3: " << PutOption(0.12, 0.5, 10, 1.0, 0.12, 5) << endl;

	//cout << "Call option on stock 4: " << CallOption(0.08, 0.3, 100.0, 30.0, 0.08, 100) << endl;
	//cout << "Put option on stock 4: " << PutOption(0.08, 0.3, 100.0, 30.0, 0.08, 100) << endl;

	//cout << "Call option on stock 1: " << CallPutParity(0.08, 65, 0.25, 60, 5.84584, "P") << endl;
	//cout << "Put option on stock 1: " << CallPutParity(0.08, 65, 0.25, 60, 2.13293, "C") << endl;
	
	////Exercise A1 b&c
	////using call put parity to get call option price
	EuropeanOption stock1;
	stock1.b = 0;
	stock1.q = 0.01;
	stock1.r = 0.03;
	stock1.T = 0.5;
	stock1.K = 30;
	stock1.sig = 0.5;
	stock1.call_price = 2.5;
	stock1.put_price = 5.84628;
	stock1.optType = "C";

	//cout << "Call option on stock 1: " << stock1.Price(25)<< endl;
	//cout << "Call option on stock 1: " << stock1.Prity(100)<< endl;
	//stock1.toggle();
	//cout << "Put option on stock 1: "  << stock1.Prity(60)<< endl;
	//cout << "Put option on stock 1: "  << stock1.Price(25)<< endl;
	cout.precision(12);
	cout << "Vol on stock 1: "  << stock1.ImpliedVolatility(30)<< endl;

	EuropeanOption stock2;
	stock2.b = 0.0;
	stock2.r = 0.01;
	stock2.T = 0.75;
	stock2.K = 50;
	stock2.q = 0.02;
	stock2.sig = 0.2;
	//stock2.call_price = 7.96557;
	//stock2.put_price = 7.96557;
	stock2.optType = "C";
	cout.precision(11);
	cout << "Call option on stock 2: " << stock2.Price(60)<< endl;
	//cout << "Put option on stock 2: " << stock2.Prity(60)<< endl;
	stock2.toggle();
	cout << "Put option on stock 2: "  << stock2.Price(60)<< endl;
	//cout << "Put option on stock 2: "  << stock2.Prity(100)<< endl;

	EuropeanOption stock3;
	stock3.b = 0.0;
	stock3.r = 0.02;
	stock3.T = 0.25;
	stock3.K = 40;
	stock3.q = 0.03;
	stock3.sig = 0.3;
	//stock3.call_price = 0.204058;
	//stock3.put_price = 4.07326;
	stock3.optType = "P";
	cout << "Call option on stock 3: " << stock3.Price(20)<< endl;
	//cout << "Put option on stock 3: " << stock3.Prity(20)<< endl;
	stock3.toggle();
	cout << "Put option on stock 3: "  << stock3.Price(20)<< endl;
	//cout << "Put option on stock 3: "  << stock3.Prity(5)<< endl;

	//EuropeanOption stock4;
	//stock4.b = 0.08;
	//stock4.r = 0.08;
	//stock4.T = 30;
	//stock4.K = 100;
	//stock4.sig = 0.3;
	//stock4.call_price = 92.17570 ;
	//stock4.put_price = 1.24750;
	//stock4.optType = "C";

	//cout << "Call option on stock 4: " << stock4.Price(100)<< endl;
	//cout << "Call option on stock 4: " << stock4.Prity(100)<< endl;
	//stock4.toggle();
	//cout << "Put option on stock 4: "  << stock4.Price(100)<< endl;
	//cout << "Put option on stock 4: "  << stock4.Prity(100)<< endl;


	////Exercise A1 c
	//struct OptionData batch1 = {0.25, 65, 0.30, 0.08, 0.08, "P", 2.13293, 5.84584};
	//struct OptionData* optPointer;
	//optPointer = &batch1;
	//cout << "Call option on stock 1: " << CallOption(optPointer, 60) << endl;
	//cout << "Put option on stock 1: " << PutOption(optPointer, 60) << endl;
	//cout << "Call option on stock 1: " << CallPutParity(optPointer, 60) << endl;
	//batch1.opt_type = "C";
	//cout << "Put option on stock 1: " << CallPutParity(optPointer, 60) << endl;

	//Exercise A1 d&e
	std::vector<double> stock_vect, expiry_time, volatility, stock_call, stock_put;

	stock_vect = MeshArray(START, END, h);	//create stock mesh array
	expiry_time = MeshArray(0.25, 10.0, 0.25);	//create expiry time mesh array
	volatility = MeshArray(0.1 , 0.5, 0.02);	//create volatility mesh array

	cout << "***"<< endl;
	cout << "Stock \t \t Call \t \t Put"<< endl;
	for (int i = 0; i < stock_vect.size(); i++)
	{
		stock1.optType = "C";
		cout << fixed << stock_vect[i] << '\t' << stock1.Price(stock_vect[i]) << '\t';
		stock_call.push_back(stock1.Price(stock_vect[i]));
		stock1.toggle();
		cout << fixed << stock1.Price(stock_vect[i]) << endl;
		stock_put.push_back(stock1.Price(stock_vect[i]));
	}

	cout << "***"<< endl;
	cout << "Expiry time \t Call \t \t Put"<< endl;
	for (int i = 0; i < expiry_time.size(); i++)
	{
		stock1.optType = "C";
		stock1.T = expiry_time[i];
		cout << fixed << expiry_time[i] << '\t' << stock1.Price(60) << '\t';
		stock1.toggle();
		cout << fixed << stock1.Price(60) << endl;
	}

	cout << "***"<< endl;
	stock1.T = 0.25;
	cout << "Volatility \t Call \t \t Put"<< endl;
	for (int i = 0; i < volatility.size(); i++)
	{
		stock1.optType = "C";
		stock1.sig = volatility[i];
		//cout << fixed << volatility[i] << '\t' << stock1.Price(60) << '\t';
		stock1.toggle();
		//cout << fixed << stock1.Price(60) << endl;
	}

	// A1 a: greeks
	stock1.K = 120;
	stock1.T = 1.5;
	stock1.r = 0.04;
	stock1.b = 0;
	stock1.sig = 0.4;
	stock1.optType = "C";
	cout << "Delta on a call11111111111: " << stock1.Delta(100) << endl;
	cout << "G on a call11111111111: " << stock1.Gamma(100) << endl;
	stock1.toggle();
	cout << "Delta on a put11111111: " << stock1.Delta(100) << endl;
	cout << "G on a put11111111: " << stock1.Gamma(100) << endl;

	// A1 b: greeks
	std::vector<double> call_delta;
	//stock_vect = MeshArray(50.0, 106.0, h);	//create stock mesh array
	stock1.optType = "C";
	cout << "***"<< endl;
	cout << "Stock \t \tCall Delta"<< endl;
	// to calculate delta by formula
	for (int i = 0; i < stock_vect.size(); i++)
	{
		//cout << fixed << stock_vect[i] << '\t' << stock1.Delta(stock_vect[i]) << endl;
		call_delta.push_back(stock1.Delta(stock_vect[i]));
	}

	// A1 c: greeks
	// use devided difference to approximate option sensitivities
	cout << "***"<< endl;
	cout << "Stock \t \tCall Delta"<< endl;
	int vec_size = stock_vect.size();
	double delta, gamma;
	stock1.optType = "C";
	stock_call.clear();

	// to approximate delta
	for (int i = 0; i < vec_size; i++)
	{
		stock_call.push_back(stock1.Price(stock_vect[i]));
	}
	for (int i = 1; i < vec_size - 1; i++)
	{
		//delta = (stock_call[i+1]*(stock_vect[i+1]+1)-stock_call[i+1]*(stock_vect[i+1]-1))/2;
		delta = (stock_call[i+1]-stock_call[i-1])/2/h;	//h=0.5
		//cout << fixed << stock_vect[i] << '\t' << delta << endl;
	}

	std::vector<double> call_gamma;
	//stock_vect = MeshArray(50.0, 106.0, h);	//create stock mesh array
	cout << "***"<< endl;
	cout << "Stock \t \tCall Gamma"<< endl;
	// to calculate gamma by formula
	for (int i = 0; i < stock_vect.size(); i++)
	{
		//cout << fixed << stock_vect[i] << '\t' << stock1.Gamma(stock_vect[i]) << endl;
		call_gamma.push_back(stock1.Gamma(stock_vect[i]));
	}
	cout << "Stock \t \tCall Gamma"<< endl;
	// to approximate gamma
	for (int i = 1; i < vec_size - 1; i++)
	{
		gamma = (stock_call[i+1]+stock_call[i-1]-2*stock_call[i])/pow(h,2);	//h=0.5
		//cout << fixed << stock_vect[i] << '\t' << gamma << endl;
	}
	
	
	//double S[40];
	//for (int i = 0; i < 40; i++)
	//{
	//	S[i] = i + 30;
	//}
	//for (int j = 0; j < 40; j++)
	//{
	//	stock_call.push_back(CallOption(optPointer, S[j]));
	//	stock_put.push_back(PutOption(optPointer, S[j]));
	//}
	//PrintOption(stock_call, stock_put, S);
	return 0;
}
