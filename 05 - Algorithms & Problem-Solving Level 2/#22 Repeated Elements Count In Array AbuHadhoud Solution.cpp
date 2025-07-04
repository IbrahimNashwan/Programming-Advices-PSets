#include <iostream>
#include <cstdlib>
using namespace std;
//Problems22_Course5_RepeatedElementsCountInArray_Abu-HadhoudSolution;

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

void FillArrayWithUser(int arr[100], int& arrLength) {

    cout << "Please enter Number Of Elements ?" << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++) {
        cout << "Element [" << i << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int ElementsCountInArray(int arr[100], int arrLength ,int Number) {
    int counter = 0;

    for (int i = 0; i < arrLength; i++) 
    {
        if (arr[i] == Number) {
            counter++;
        }
   
    }
    return counter;

}

//solution abu hadhuod
int TimesRepeated(int arr[100], int arrLength, int NumberOfCheck) {
    int counter = 0;

    for (int i = 1; i <= arrLength; i++) {

        if (arr[i] == NumberOfCheck) {
            counter++;
        }

    }
    return counter;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithUser(arr, arrLength);
    cout << endl;

    short DigitToCheck = ReadPosativeNumber("Please enter Number to Check ?");
    cout << " Array Elements : ";
    PrintArray(arr, arrLength);

    int counter = 0;
    counter = ElementsCountInArray(arr, arrLength, DigitToCheck);

    cout << DigitToCheck << " is repeted " << counter << " time(s)";


}
