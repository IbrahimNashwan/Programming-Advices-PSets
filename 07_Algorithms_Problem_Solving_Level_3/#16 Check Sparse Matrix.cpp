#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%d   ", arr[i][j]);


		}
		cout << endl;
	}
	cout << endl;
}
//MySolution

bool IsSparseMatrices(int Matrix1[3][3], short Rows, short Cols) {

	int ZerosCount = 0;
	int NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == 0) {
				ZerosCount++;
			}
			else {
				NumberCount++;
			
			}

		}
	}
	return ZerosCount > NumberCount;
}


//AbuHadhoud Solution
int CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols) {

	int NumberCount = 0;


	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number) {
				NumberCount++;
			}

		}
	}
	return NumberCount;
}

bool IsSparseMatrices2(int Matrix1[3][3], short Rows, short Cols) {

	int SizeMatrix = Rows * Cols;
	return CountNumberInMatrix(Matrix1,0, 3, 3) > (SizeMatrix / 2);
}

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3] = { {7,0,0},{0,0,0},{6,6,7} };


	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);
	if (IsSparseMatrices2(Matrix1, 3, 3))
		cout << "Yes: It is Sparse." << endl;
	else
		cout << "No: It's NOT Sparse." << endl;

}