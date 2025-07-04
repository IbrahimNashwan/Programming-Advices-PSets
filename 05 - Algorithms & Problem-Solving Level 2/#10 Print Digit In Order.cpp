#include <iostream>
using namespace std;
//Problems10_Course5_PrintDigitInOrder

int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void PrintNumber(int Number) {

    int Remainder = 0, Temp = 0, ReverNum = 0, counter = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;
        Temp = Temp * 10 + Remainder;
    }
    while (Temp > 0) {

        Remainder = Temp % 10;
        Temp = Temp / 10;
        cout << Remainder << endl;
    }
}

//Solution Abu Hadhuod
int ReverseNumber(int Number) {

    int Remainder = 0, Number2 = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}

void PrintDigits(int Number) {

    int Remainder = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
}

int main() {

    //Solution Abu Hadhuod
    PrintDigits(ReverseNumber(ReadPosativeNumber("please enter positive number ?")));

    //My Solution    
    //PrintNumber(ReadPosativeNumber("please enter positive number ?"));

}


