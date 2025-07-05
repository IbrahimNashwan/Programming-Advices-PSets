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
			printf("%0*d   ",2, arr[i][j]);


		}
		cout << endl;
	}
	cout << endl;
}
//MySolution
bool IsExistsInMatrices(int Matrix1[3][3],int Number, short Rows, short Cols) {

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

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	int Number;
	cout << "Please Enter the number to look for in matrix? ";
	cin >> Number;

	if (IsExistsInMatrices(Matrix1, Number, 3, 3))
		cout << "\nYes: It is there." << endl;
	else
		cout << "\nNo: It's NOT there." << endl;

}