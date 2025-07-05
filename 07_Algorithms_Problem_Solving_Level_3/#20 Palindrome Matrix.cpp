#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
			//printf("%0*d   ", 2, arr[i][j]);


		}
		cout << endl;
	}
	cout << endl;
}

//MySolution
int ReverseNumber(int Number) {

	int Remainder = 0;
	int Number2 = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}

bool IsPalindrome(int Number) {
	return Number != ReverseNumber(Number);
}

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols) {

	int Remainder = 0;
	int Number2 = 0;
	for (short i = 0; i < Rows; i++)
	{
		Number2 = 0;
		for (short j = 0; j < Cols; j++)
		{
			Remainder = Matrix1[i][j];
			Number2 = Number2 * 10 + Remainder;
		}
		if (IsPalindrome(Number2)) {
			return false;
		}
		
	}
	return true;
}

//AbuHadhoud Solution
bool IsPalindromeMatrix2(int Matrix1[3][3], short Rows, short Cols) {

	
	for (short i = 0; i < Rows; i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int Matrix1[3][3] = {{1,2,1},{2,3,2},{5,7,5}};

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeMatrix2(Matrix1, 3, 3))
		cout << "Yes: Matrix is Palindrome." << endl;
	else
		cout << "No: Matrix is NOT Palindrome." << endl;


}