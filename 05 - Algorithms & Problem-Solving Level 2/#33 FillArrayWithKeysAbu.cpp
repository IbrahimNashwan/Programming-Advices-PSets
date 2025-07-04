#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems33_Course5_FillArrayWithKeys_Abu-HadhoudSolution;

enum enCharType { SmallLetter, CapitalLetter, Special_C, AndDigit_inOrder };

void PrintSringArray(string arr[100], int arrLength) {

    cout << "\nArray elements : " << endl;
    for (int i = 0; i < arrLength; i++)
    {
        cout << "array [" << i << "] : ";
        cout << arr[i] << " " << endl;
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

    word = GenerateWord(enCharType::CapitalLetter, 4)  + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    word += GenerateWord(enCharType::CapitalLetter, 4);


    return word;
}

void FillArrayWithKeys(string arr[100], int NumberOfKeys) {

    for (int i = 0; i < NumberOfKeys; i++)
    {
        //cout << "Key [" << i <<"] : ";
        //cout << GenerateKey() << endl;
        arr[i] = GenerateKey();
    }
}

int ReadPosativeNumber(string Message) {

    int Number;
    do {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
int main() {
    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = 0;

    arrLength = ReadPosativeNumber("Please enter the number of elements ?");

    FillArrayWithKeys(arr, arrLength);

    PrintSringArray(arr, arrLength);

}
