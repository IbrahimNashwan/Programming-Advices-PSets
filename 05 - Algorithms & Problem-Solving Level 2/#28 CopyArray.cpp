
#include <iostream>
#include <cstdlib>
using namespace std;
//Problems28_Course5_CopyArray
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


void CopyArray(int arrSource[100], int arrDestination[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arrDestination[i] = arrSource[i];
    }
}
int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);




    int arr2[100];
    CopyArray(arr, arr2, arrLength);

    cout << "\nArray 1 Elements : " << endl;
    PrintArray(arr, arrLength);

    cout << "\nArray 1 Elements after copy : " << endl;
    PrintArray(arr2, arrLength);
}

