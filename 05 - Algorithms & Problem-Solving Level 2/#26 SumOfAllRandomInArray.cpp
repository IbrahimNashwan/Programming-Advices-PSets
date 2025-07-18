#include <iostream>
#include <cstdlib>
using namespace std;
//Problems26_Course5_SumOfAllRandomInArray
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

    cout << "Please enter Number Of Elements ?" << endl;
    cin >> arrLength;

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

int SumArray(int arr[100], int arrLength) {

    int Sum = 0;

    for (int i = 0; i < arrLength; i++) {

        Sum += arr[i];
    }

    return Sum;
}


int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;


    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    cout << "\n\Sum Of All Random Number : " << SumArray(arr, arrLength) << endl;

}
