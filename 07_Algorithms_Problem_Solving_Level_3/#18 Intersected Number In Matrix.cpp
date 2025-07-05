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
bool IsExistsInMatrices(int Matrix1[3][3], int Number, short Rows, short Cols) {

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number) {
				return true;
			}

		}
	}
	return false;
}

int CountInterNumInMatrices(int Matrix1[3][3], int Matrix2[3][3],int arr[10],short Rows, short Cols) {

	int counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsExistsInMatrices(Matrix1, Matrix2[i][j], 3, 3)) {
				arr[counter] = Matrix2[i][j];
				counter++;
			}

		}
	}
	return counter;
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
	int Matrix1[3][3],Matrix2[3][3],arr[9];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);


	int length = CountInterNumInMatrices(Matrix1, Matrix2, arr, 3, 3);
	cout << "Intersected Number are :" << endl;
	PrintArray(arr, length);

}