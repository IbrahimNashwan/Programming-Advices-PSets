#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

//MySolution

void SumRowMatrix(int arr[3][3], int Rows, int Cols,int arrSum[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(j == 0)
				arrSum[i] = arr[i][j];
	
			else
				arrSum[i] += arr[i][j];

		}
		cout << endl;
	}
}

void SumColMatrix(int arr[3][3], int Rows, int Cols, int arrSum[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				arrSum[i] = arr[j][i];

			else
				arrSum[i] += arr[j][i];

		}
		cout << endl;
	}
}

void PrintArray(int arr[100], int arrLenght) {

	for (int i = 0; i < arrLenght; i++)
	{
		printf("Row %d Sum = %d\n", i + 1, arr[i]);

	}
}

//Solution AbuHadhoud
int RowSum(int arr[3][3], int RowNumber, int Cols) 
{
	int Sum = 0;
	for (int i = 0; i < Cols; i++)
	{
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], int Rows, int Cols) {

	cout << "The following are the sum of each raw in the matrix:" << endl;

	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;

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
	int arr[3][3],arrSum[3];

	FillMatrixWithRandomNumber(arr, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrix(arr, 3, 3);
	PrintEachRowSum(arr, 3, 3);

	//SumRowMatrix(arr, 3, 3, arrSum);
	//SumColMatrix(arr, 3, 3, arrSum);
	//cout << "The following are the sum of each raw in the matrix:" << endl;
	//PrintArray(arrSum, 3);


}