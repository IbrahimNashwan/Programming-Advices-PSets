#include <iostream>
#include <cstdlib>
using namespace std;

//Problems29_Course5_PrintOnlyPrimeNumber

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

int RandomNumber(int From, int To) {

    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    arrLength = ReadPosativeNumber("Please enter Number Of Elements ?");


    for (int i = 0; i < arrLength; i++) {

        arr[i] = RandomNumber(1, 100);
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
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

void PrintOnlyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {
    int counter = 0;

    for (int i = 0; i < arrLength; i++) {

        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime) {
            arrDestination[counter] = arrSource[i];
            counter++;
        }

    }
    arr2Length = --counter;
}
int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100], arr2Length;
    PrintOnlyPrimeNumber(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Elements : " << endl;
    PrintArray(arr, arrLength);

    cout << "\nPrime Number in Array2 : " << endl;
    PrintArray(arr2, arr2Length);
}

