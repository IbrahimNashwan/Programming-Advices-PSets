#include <iostream>
#include <cstdlib>
using namespace std;

//Problems30_Course5_Sum2Array


int ReadPosativeNumber(string Message) {

    int Number;
    do {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

int ReadRandomNumber(int From, int To) {

    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arr[i] = ReadRandomNumber(1, 100);
    }
    cout << endl;
}


void PrintArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SumOf2Arrays(int arr[100], int arr2[100], int arrSum[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arrSum[i] = arr[i] + arr2[i];
    }

}

int main() {
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arrSum[100], arrLength;


    arrLength = ReadPosativeNumber("Please enter Number of elements ?");

    FillArrayWithRandomNumber(arr, arrLength);
    FillArrayWithRandomNumber(arr2, arrLength);

    SumOf2Arrays(arr, arr2, arrSum, arrLength);

    cout << "\nArray 1 elements : " << endl;
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements : " << endl;
    PrintArray(arr2, arrLength);

    cout << "\nSum of array1 and array2 elements : " << endl;
    PrintArray(arrSum, arrLength);

}

