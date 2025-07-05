
#include <iostream>
#include <iomanip>
#include <cstdlib>

//Problem 9 my Solution 
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
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void FillMiddileRawFromMatrix(int arr[3][3], int arrRow[3], int Rows, int Cols) {


    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == 1) {
                arrRow[j] = arr[i][j];
            }

        }
    }
}

void FillMiddileColFromMatrix(int arr[3][3], int arrCol[3], int Rows, int Cols) {


    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == 1) {
                arrCol[j] = arr[j][i];
            }

        }
    }
}

void PrintMiddleMatrix(int arr[3], int Length) {

    for (int j = 0; j < Length; j++)
    {
        printf("%02d   ", arr[j]);
    }
    cout << endl;
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
    int arr[3][3], arrRow[3], arrCol[3];

    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "Matrix1:" << endl;
    PrintMatrix(arr, 3, 3);

    FillMiddileRawFromMatrix(arr, arrRow, 3, 3);
    FillMiddileColFromMatrix(arr, arrCol, 3, 3);
    cout << "Middle Row of Matrix1 is:" << endl;
    PrintMiddleMatrix(arrRow, 3);


    cout << "Middle col of Matrix1 is:" << endl;
    PrintMiddleMatrix(arrCol, 3);
}