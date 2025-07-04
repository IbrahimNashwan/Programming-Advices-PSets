#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems37_Course5_CopyArrayUsinhAddArrayElement

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    arrLength = ReadPosativeNumber("Please enter Number Of Elements ?");
    for (int i = 0; i < arrLength; i++) {

        arr[i] = RandomNumber(1, 100);

    }
    cout << endl;
}

void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int SourseLength, int& LengthDestination) {

    for (int i = 0; i < SourseLength; i++) {

        AddArrayElement(arrSource[i], arrDestination, LengthDestination);
    }

}

int main() {
    srand((unsigned)time(NULL));

    int arrSource[100], arrDestination[100], SourseLength = 0, LengthDestination = 0;
    FillArrayWithRandomNumbers(arrSource, SourseLength);


    cout << "\nArray 1 elements : ";
    PrintArray(arrSource, SourseLength);

    CopyArrayUsingAddArrayElement(arrSource, arrDestination, SourseLength, LengthDestination);

    cout << "\nArray 1 elements after copy: ";
    PrintArray(arrSource, LengthDestination);

}
