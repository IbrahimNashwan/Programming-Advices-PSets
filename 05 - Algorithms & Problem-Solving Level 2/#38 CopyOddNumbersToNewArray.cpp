
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems38_Course5_CopyOddNumbersToNewArray



int RandomNumber(int From, int To) {

    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}

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

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    arrLength = ReadPosativeNumber("Please enter Number Of Elements ?");
    for (int i = 0; i < arrLength; i++) {

        arr[i] = RandomNumber(1, 100);
    }
    cout << endl;
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


void CopyOddNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arrLengthDestination)
{
    for (int i = 0; i < arrLength; i++)
        if (arrSource[i] % 2 != 0)
        {
            AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);
        }

}
int main() {
    //Seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = 0, arr2Length = 0;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Length : " << arrLength;
    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);

    CopyOddNumber(arr, arr2, arrLength, arr2Length);
    cout << "\nArray 2 Odd number elements : ";
    PrintArray(arr2, arr2Length);

}