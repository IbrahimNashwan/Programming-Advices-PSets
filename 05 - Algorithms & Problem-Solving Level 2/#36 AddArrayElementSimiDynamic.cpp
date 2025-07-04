
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems36_Course5_AddArrayElementSimiDynamic 

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void FillArrayWithNumber(int arr[100], int& arrLength, int Number) {

    arr[arrLength] = Number;
    arrLength++;
}

int ReadNumber()
{
    int Number;

    do
    {
        cout << "Please enter a number ? " << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void EnterUserNumberInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more numbers ? [0]:No,[1]:yes?";
        cin >> AddMore;
    } while (AddMore != 0);

}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;
    EnterUserNumberInArray(arr, arrLength);

    cout << "\nArray Length : " << arrLength;
    cout << "\nArray  elements : ";
    PrintArray(arr, arrLength);

}