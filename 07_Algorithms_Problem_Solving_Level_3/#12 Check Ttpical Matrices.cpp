#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	int counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			counter++;
			arr[i][j] = RandomNumber(1, 10);
			//arr[i][j] = counter;
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

bool AreTypicalMatrices(int arrOne[3][3], int arrTwo[3][3], short Rows, short Cols) {
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arrOne[i][j] != arrTwo[i][j])
			{
				return false;
			}


		}
	}
	return true;
}


int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);


	if (!AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "No: matrices are Not equal." << endl;
	else
		cout << "Yes: matrices are equal." << endl;


}