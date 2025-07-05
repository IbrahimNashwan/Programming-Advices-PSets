#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {
	int counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, arr[i][j]);


		}
		cout << endl;
	}
	cout << endl;
}

//MySolution
int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols) {

	int MinNumber = Matrix1[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] < MinNumber) {
				MinNumber = Matrix1[i][j];
			}

		}
	}
	return MinNumber;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols) {

	int MaxNumber = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] > MaxNumber) {
				MaxNumber = Matrix1[i][j];
			}

		}
	}
	return MaxNumber;
}

void PrintArray(int arr[100], int length) {

	for (int i = 0; i < length; i++)
	{
		printf("%0*d   ", 2, arr[i]);

	}
	cout << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3], arr[9];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);



	printf("Minimum Number is :%0*d\n\n", 2, MinNumberInMatrix(Matrix1, 3, 3));
	printf("Max Number is :%0*d\n", 2, MaxNumberInMatrix(Matrix1, 3, 3));


}