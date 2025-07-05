#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//Proplem 6 3x3 Ordered Matrix
int RandomNumber(int From, int To) {
    int Number = rand() % (To - From + 1) + From;
    return Number;
}

//MySolution
int ColSum(int arr[3][3], int ColNumber, int Rows)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumMatrixColinArray(int arr[3][3],int arrCol[3], int Rows, int Cols) {


    for (int i = 0; i < Rows; i++)
    {
        arrCol[i] = ColSum(arr, i, Rows);

    }

}

void PrintColSumArray(int arr[100], int size) {
    cout << "The following are the sum of each Col in the matrix in Array:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;

    }
}

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3], arrSum[3];
    int arrCol[3];
    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "The following is a 3x3 Orderd matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    SumMatrixColinArray(arr, arrSum, 3, 3);
    PrintColSumArray(arrSum,3);
}