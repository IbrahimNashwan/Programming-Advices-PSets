#include <iostream>
using namespace std;
//My_SolutionProblems40_Course5_CopyDistinctNumbersToNewArray


int ReadPosativeNumber(string massage)
{
    int Number;

    do
    {
        cout << massage << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}


void CopyDistinctNumbersToNewArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrLengthDestination, int& CpoyNumber)
{
    for (int i = 0; i < arrLength; i++) {
        if (arrSource[i] != CpoyNumber)
        {
            AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);
        }
        CpoyNumber = arrSource[i];
    }

}

int main() {

    int arr[100], arr2[100];
    int arrLength = 10, arr2Length = 0;

        
    arr[0] = 10, arr[1] = 10,
        arr[2] = 10, arr[3] = 50,
        arr[4] = 50, arr[5] = 70,
        arr[6] = 70, arr[7] = 70,
        arr[8] = 70, arr[9] = 90;


    cout << "\nArray Length : " << arrLength;
    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);

    int CpoyNumber = 0;
    CopyDistinctNumbersToNewArray(arr, arr2, arrLength, arr2Length, CpoyNumber);
    cout << "\nArray 2 Prime number elements : ";
    PrintArray(arr2, arr2Length);

}
