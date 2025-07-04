
#include <iostream>
#include <cstdlib>
#include <cmath>

//Problems32_Course5_CopyArrayInReverseOrdered
using namespace std;


int ReadPosativeNumber(string Message) {

    int Number;
    do {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
int RandomNumber(int From, int To) {

    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}



void FillArrayWithRandomNumber(int arr[100], int& arrLength) {

    //arrLength = ReadPosativeNumber("Please enter Number of elements ?");

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, arrLength);
    }
    cout << endl;
}



void PrintArray(int arr[100], int arrLength) {
    int counter = 0;
    for (int i = 0; i < arrLength; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}



void CopyArrayInReverseOrdered(int arrSource[100], int arrDestination[100], int arrLength) 
{
    for (int i = 0; i < arrLength; i++) 
    {
        arrDestination[i] = arrSource[arrLength - 1 - i];

    }
    cout << endl;
}
//abuHadhoud solution 

int main() {
    int arr[100], arr2[100];
    int arrLength = ReadPosativeNumber("Please enter the number of elements ?");
    srand((unsigned)time(NULL));

    FillArrayWithRandomNumber(arr, arrLength);
    CopyArrayInReverseOrdered(arr, arr2, arrLength);

    cout << "\nArray 1 elements : " << endl;
    PrintArray(arr, arrLength);

    cout << "\nArray 1 elements after Reserve  : " << endl;
    PrintArray(arr2, arrLength);

}
