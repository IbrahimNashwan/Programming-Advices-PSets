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

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3] = { {7,0,7},{0,7,0},{0,0,7} };


	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);
	int Number;
	cout << "Enter the number to count in Matrix ?";
	cin >> Number;

	cout << "Number "<< Number << " count in matrix is " << CountNumberInMatrix(Matrix1,Number,3,3);

}