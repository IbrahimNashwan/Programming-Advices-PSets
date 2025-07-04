
#include <iostream>
#include <cstdlib>
using namespace std;
//Problems21_Course5_GenerateKeys_Abu-HadhoudSolution;
enum enCharType { SmallLetter, CapitalLetter, Special_C, AndDigit_inOrder };

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


void GenerateKeys(int NumberOfKeys) {

    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}
int main() {
    srand((unsigned)time(NULL));



    GenerateKeys(ReadPosativeNumber("Please Enter how many keys to generator ?"));


}
