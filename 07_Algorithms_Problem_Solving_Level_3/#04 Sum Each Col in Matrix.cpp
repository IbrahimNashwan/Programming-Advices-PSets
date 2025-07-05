#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

//MySolution
int ColSum(int arr[3][3], int ColNumber, int Rows)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

void PrintEachColSum(int arr[3][3], int Rows, int Cols) {

	cout << "The following are the sum of each Col in the matrix:" << endl;

	for (int i = 0; i < Rows; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << ColSum(arr, i, Rows) << endl;

	}

}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3], arrSum[3];

	FillMatrixWithRandomNumber(arr, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrix(arr, 3, 3);

	PrintEachColSum(arr, 3, 3);


}