
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//Proplem 7 Transposed Matrix
int RandomNumber(int From, int To) {
    int Number = rand() % (To - From + 1) + From;
    return Number;
}



void FillMatrixWithOrderdNumber(int arr[3][3], int Rows, int Cols) {

    int counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            counter++;
            arr[i][j] = counter;
        }
    }
}


void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], int Rows, int Cols)
{
    cout << "The following is a Transpose matrix:" << endl;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
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
    int arr[3][3], arrTransposed[3][3];

    FillMatrixWithOrderdNumber(arr, 3, 3);
    cout << "The following is a 3x3 Orderd matrix:" << endl;
    PrintMatrix(arr, 3, 3);
    TransposeMatrix(arr, arrTransposed, 3, 3);

    PrintMatrix(arrTransposed, 3, 3);
}
