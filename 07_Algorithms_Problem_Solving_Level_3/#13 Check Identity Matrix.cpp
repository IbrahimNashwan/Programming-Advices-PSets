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
bool IsIdentityMatrices(int arrOne[3][3]) {

	
			if ((arrOne[0][0] == 1 && arrOne[0][1] == 0 && arrOne[0][2] == 0) &&
				(arrOne[1][0] == 0 && arrOne[1][1] == 1 && arrOne[1][2] == 0) &&
				(arrOne[2][0] == 0 && arrOne[2][1] == 0 && arrOne[2][2] == 1))
			{
				return true;
			}
	return false;
}

//AbuHadhoud Solution
bool IsIdentityMatrices(int arr[3][3],short Rows ,short Cols) {

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1) {
				return false;
			}
			else if (i != j && arr[i][j] != 0) {
				return false;
			}

		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	//int Matrix1[3][3] =  {{1,2,3},{4,5,6},{7,8,9}};
	int Matrix1[3][3] = {{1,0,0},{0,1,0},{0,0,1}};


	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrices(Matrix1,3,3))
		cout << "Yes: matrix is identity." << endl;
	else
		cout << "No: matrirx is Not identity." << endl;


}