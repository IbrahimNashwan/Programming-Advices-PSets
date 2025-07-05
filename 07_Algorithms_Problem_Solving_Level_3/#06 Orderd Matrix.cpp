
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//Proplem 6 3x3 Ordered Matrix
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

    FillMatrixWithOrderdNumber(arr, 3, 3);
    cout << "The following is a 3x3 Orderd matrix:" << endl;
    PrintMatrix(arr, 3, 3);
}
