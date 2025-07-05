
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//Proplem 8 Multiply two Matrix
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
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void MatrixResults(int arrOne[3][3], int arrTwo[3][3], int arrResults[3][3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrResults[i][j] = (arrOne[i][j] * arrTwo[i][j]);
        }
    }
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            printf("%02d   ", arr[i][j]);
            //cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int arrOne[3][3], arrTwo[3][3], arrResults[3][3];

    FillMatrixWithRandomNumber(arrOne, 3, 3);
    FillMatrixWithRandomNumber(arrTwo, 3, 3);

    cout << "Matrix1:" << endl;
    PrintMatrix(arrOne, 3, 3);

    cout << "Matrix2:" << endl;
    PrintMatrix(arrTwo, 3, 3);

    MatrixResults(arrOne, arrTwo, arrResults, 3, 3);
    cout << "Results:" << endl;
    PrintMatrix(arrResults, 3, 3);
}
