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

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
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


int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3], arrSum[3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "Sum of Matrix1 is:" << SumMatrix(Matrix1, 3, 3) << endl;;


	


}