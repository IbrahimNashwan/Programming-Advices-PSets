#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems34_Course5_Return_Number_index_In_Array'';

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


char GetRandomCharacter(enCharType CharType) {

    switch (CharType) {

    case enCharType::SmallLetter:
        return (char)RandomNumber(97, 122);
        break;


    case enCharType::CapitalLetter:
        return (char)RandomNumber(65, 90);
        break;


    case enCharType::Special_C:
        return (char)RandomNumber(33, 47);
        break;

    case enCharType::AndDigit_inOrder:
        return (char)RandomNumber(48, 57);
        break;

    }
}



string GenerateWord(enCharType CharType, short Length) {

    string word = "";

    for (int i = 1; i <= Length; i++)
    {
        word += GetRandomCharacter(enCharType::CapitalLetter);
    }

    return word;
}

string GenerateKey() {

    string word = "";

    word = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4);


    return word;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength) {

    //arrLength = ReadPosativeNumber("Please enter Number of elements ?");

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

bool CheckForMatch(int NumberSearchFor, int Number) {

    return NumberSearchFor == Number;
}

int SearchForNumber(int arr[100], int arrLength, int SearchNumber) {

    for (int i = 0; i < arrLength; i++) {
        if (CheckForMatch(SearchNumber, arr[i])) {

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


int FindNumberPositionInArray(int arr[100], int arrLength, int SearchNumber) {

    for (int i = 0; i < arrLength; i++) {

        if (SearchNumber == arr[i]) {
            return i;//this will break the function and return the index 
        }
    }
    // if you reached here ,this means the number is not found
    return -1;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength, SearchNumber;

    arrLength = ReadPosativeNumber("Please enter the number of elements ?");

    FillArrayWithRandomNumber(arr, arrLength);
    PrintArray(arr, arrLength);

    cout << endl;
    SearchNumber = ReadPosativeNumber("Please enter a number to search for?");

    //SearchForNumber(arr,arrLength,SearchNumber);


    //abuHadhoud solution Function 
    short NumberPosition = FindNumberPositionInArray(arr, arrLength, SearchNumber);
    if (NumberPosition == -1) {
        cout << "Number you are looking for is  : " << SearchNumber << endl;
        cout << "The number is not found. " << endl;
    }
    else
    {
        cout << "Number you are looking for is  : " << SearchNumber << endl;
        cout << "The number found at position : " << NumberPosition << endl;
        cout << "The number found its order : " << NumberPosition + 1 << endl;
    }
}
