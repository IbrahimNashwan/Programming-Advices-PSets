#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems39_Course5_CopyPrimeNumbersToNewArray

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number) {
    int M;
    M = round(Number / 2);

    for (int counter = 2; counter <= M; counter++) {

        if (Number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void CopyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arrLengthDestination)
{

    for (int i = 0; i < arrLength; i++) {

        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime) {
            AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);

        }
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

    CopyPrimeNumber(arr, arr2, arrLength, arr2Length);
    cout << "\nArray 2 Prime number elements : ";
    PrintArray(arr2, arr2Length);

}