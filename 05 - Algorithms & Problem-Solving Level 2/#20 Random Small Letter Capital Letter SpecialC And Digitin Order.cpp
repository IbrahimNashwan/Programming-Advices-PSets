#include <iostream>
#include <cstdlib>
using namespace std;
//Problems20_Course5_Random_SmallLetter,CapitalLetter,Special_C,AndDigit_inOrder;
enum enCharType { SmallLetter, CapitalLetter, Special_C, AndDigit_inOrder };

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


int main() {
    srand((unsigned)time(NULL));

    //my solution 

    cout << GetRandomCharacter(SmallLetter) << endl;
    cout << GetRandomCharacter(CapitalLetter) << endl;
    cout << GetRandomCharacter(Special_C) << endl;
    cout << GetRandomCharacter(AndDigit_inOrder) << endl;


}

