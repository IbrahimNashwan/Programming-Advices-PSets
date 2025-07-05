#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//MySolution

void FibonacciSeries(int n) {
	if (n < 2) {
		return;
	}
	else {
		static int Perv1 = 1, Perv2 = 0;
		int FebNumber = 0;
		FebNumber = Perv1 + Perv2;
		cout << FebNumber << "   ";
		Perv2 = Perv1;
		Perv1 = FebNumber; 
		FibonacciSeries(n - 1);
	}
 }
//AbuHadhoud Solution
void PrintFibonacciSeriesUsingRecursion(int Number, int Perv1,int Perv2) {

	
	int FebNumber = 0;
	if (Number > 0)
	{
		FebNumber = Perv2 + Perv1;
		Perv2 = Perv1;
		Perv1 = FebNumber;
		cout << FebNumber << "   ";
		PrintFibonacciSeriesUsingRecursion(Number - 1, Perv1, Perv2);
	}

}

void PrintFibonacciSeries2(int length) {


	int Perv2 = 0, Perv1 = 1;
	int FebNumber = 0;
	cout << "1   ";

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

	/*cout << "Fibonacci Series:" << endl;
	cout << "1   ";
	FibonacciSeries(10);
	*/


	PrintFibonacciSeriesUsingRecursion(10, 0, 1);

}