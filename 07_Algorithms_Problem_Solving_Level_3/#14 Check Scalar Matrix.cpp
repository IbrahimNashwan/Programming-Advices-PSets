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
bool CheckScalar(int arr[3][3],int Row,int Col, int IndexNumber) {
	if (IndexNumber == 2) {
		return false;
	}
	else {
		return arr[Row][Col] != arr[Row + 1][Col + 1];
	}
}

bool IsScalarMatrices(int arr[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && CheckScalar(arr,i,j,j)) {
				return false;
			}
			else if (i != j && arr[i][j] != 0) {
				return false;
			}

		}
	}
	return true;
}

//AbuHadhoud Solution
bool IsScalarMatrices2(int Matrix1[3][3], short Rows, short Cols) {

	int FristDiagElement = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix1[i][j] != FristDiagElement) {
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0) {
				return false;
			}

		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	//int Matrix1[3][3] =  {{1,2,3},{4,5,6},{7,8,9}};
	int Matrix1[3][3] = { {7,0,0},{0,7,0},{0,0,7} };


	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrices2(Matrix1, 3, 3))
		cout << "Yes: matrix is scalar." << endl;
	else
		cout << "No: matrirx is Not scalar." << endl;


}