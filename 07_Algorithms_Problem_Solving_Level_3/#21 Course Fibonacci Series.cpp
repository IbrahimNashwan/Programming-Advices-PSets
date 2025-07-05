#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//MySolution
void PrintFibonacciSeries(int length) {

	int Perv1 = 1;
	int Perv2 = 1;
	int Result = 0;
	cout << Perv1 << "   " << Perv2;

	for (short i = 0; i < length - 2; i++)
	{
		Result = Perv1 + Perv2;
		cout << "  " << Result;

		Perv2 = Perv1;
		Perv1 = Result;
	}

}

//AbuHadhoud Solution
void PrintFibonacciSeries2(int length) {

	
	int Perv2 = 0, Perv1 = 1;
	int FebNumber = 0;
	cout <<"1   ";

	for (short i = 2; i <= length; i++)
	{
		FebNumber = Perv1 + Perv2;
		cout << FebNumber << "  ";
		
		Perv2 = Perv1;
		Perv1 = FebNumber;
	}
	cout << endl;
}

int main() {

	cout << "Fibonacci Series:" << endl;
	PrintFibonacciSeries2(10);

	

}