
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems35_Course5_CheckNumberInArray;

enum enCharType { SmallLetter, CapitalLetter, Special_C, AndDigit_inOrder };

void PrintArray(int arr[100], int arrLength) {

    cout << "\nArray 1 elements : " << endl;
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

void FillArrayWithRandomNumber(int arr[100], int& arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
    cout << endl;
}

int ReadPosativeNumber(string Message) {

    int Number;
    do {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

bool IsFoundInArray(int NumberSearchFor, int Number) {

    return NumberSearchFor == Number;
}

//my solution function 
int SearchForNumber(int arr[100], int arrLength, int SearchNumber) {

    for (int i = 0; i < arrLength; i++) {
        if (IsFoundInArray(SearchNumber, arr[i])) {

            cout << "Number you are looking for is  : " << SearchNumber << endl;
            cout << "The number found at position : " << i << endl;
            cout << "The number found its order : " << i + 1 << endl;
            return 0;
        }
    }
    cout << "Number you are looking for is  : " << SearchNumber << endl;
    cout << "The number is not found. " << endl;
    return 0;
}

//abo hadhood solution 
int FindNumberPositionInArray(int arr[100], int arrLength, int SearchNumber) {

    for (int i = 0; i < arrLength; i++) {

        if (SearchNumber == arr[i]) {
            return i;//this will break the function and return the index 
        }
    }
    // if you reached here ,this means the number is not found
    return -1;
}

bool IsNumberInArray(int arr[100], int arrLength, int SearchNumber) {

    return FindNumberPositionInArray(arr, arrLength, SearchNumber) != -1;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength, SearchNumber;
    arrLength = ReadPosativeNumber("Please enter the number of elements ?");

    FillArrayWithRandomNumber(arr, arrLength);
    PrintArray(arr, arrLength);

    cout << endl;
    SearchNumber = ReadPosativeNumber("Please enter a number to search for?");


    //abuHadhoud solution Function 
    if (!IsNumberInArray(arr, arrLength, SearchNumber)) {
        cout << "Number you are looking for is  : " << SearchNumber << endl;
        cout << "No,The number is not found :-( " << endl;
    }
    else
    {
        cout << "Number you are looking for is  : " << SearchNumber << endl;
        cout << "Yes,The number is found :-) " << endl;

    }
}
