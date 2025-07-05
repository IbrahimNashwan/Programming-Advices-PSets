#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

//MySolution

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

int SumMatrix(int arr[3][3], short Rows, short Cols) {

	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}
	}
	cout << endl;
	return Sum;
}
void CheckEqual(int arrOne[3][3],int arrTwo[3][3], short Rows, short Cols) {

	bool check = false;
	string Text = "";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arrOne[i][j] != arrTwo[i][j])
			{
				cout << "No: matrices are Not equal." << endl;
				return;
			}
			

		}
	}
	cout << endl;
			cout << "Yes: matrices are equal." << endl;
			
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
}

//AbuHadhoud Solution
bool AreEqualMatrices(int Matrices1[3][3], int Matrices2[3][3], short Rows, short Cols) {
	
	return SumMatrix(Matrices1, Rows, Cols) == SumMatrix(Matrices2, Rows, Cols);
}

int main() {
	srand( (unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);
	cout << "Sum of Matrix1 is:" << SumMatrix(Matrix1, 3, 3) << endl << endl;;

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);
	cout << "Sum of Matrix2 is:" << SumMatrix(Matrix2, 3, 3) << endl << endl;;

	/*if (SumMatrix(Matrix1, 3, 3) != SumMatrix(Matrix2, 3, 3))
		cout << "No: matrices are Not equal." << endl;
	else
		cout << "Yes: matrices are equal." << endl;*/

	if (!AreEqualMatrices(Matrix1, Matrix2,3,3))
		cout << "No: matrices are Not equal." << endl;
	else
		cout << "Yes: matrices are equal." << endl; 


}