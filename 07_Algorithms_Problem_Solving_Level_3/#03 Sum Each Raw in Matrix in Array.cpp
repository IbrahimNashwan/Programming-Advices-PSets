#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

//MySolution
//Problem 3 Course7 Sum Each Raw in Matrix in Array
void PrintSumMatrixsArray(int arr[3], int Rows) {

	for (int i = 0; i < Rows; i++)
	{
		printf("Row %d Sum = %d\n", i + 1, arr[i]);

	}
}


int RowSum(int arr[3][3], int RowNumber, int Cols)
{
	int Sum = 0;
	for (int i = 0; i < Cols; i++)
	{
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void SumMatrixRowsInArray(int arr[3][3], int Rows, int Cols, int arrSum[3]) {

	for (int i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum(arr, i, Cols);
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

	SumMatrixRowsInArray(arr, 3, 3, arrSum);
	cout << "The following are the sum of each raw in the matrix:" << endl;
	PrintSumMatrixsArray(arrSum, 3);


}