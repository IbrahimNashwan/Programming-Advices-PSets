#include <iostream>
#include <cstdlib>

using namespace std;
//Problems44_Course5_CountPositiveNumbersInArray



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

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    arrLength = ReadPosativeNumber("Please enter Number Of Elements ?");
    for (int i = 0; i < arrLength; i++) {

        arr[i] = RandomNumber(-100, 100);
    }
    cout << endl;
}

int PositiveCounNumbersInArray(int arr[100], int arrLength)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++) {

        if ((arr[i]) >= 0)
        {
            counter++;
        }
    }

    return counter;
}

int main() {
    //Seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 0;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);

    cout << "\Positive Numbers count is : ";
    cout << PositiveCounNumbersInArray(arr, arrLength) << endl;

}