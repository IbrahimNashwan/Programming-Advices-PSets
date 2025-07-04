#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}
//MySolution

void ReverseNumber(int Number) {
    string NumberToString = to_string(Number);
   int Size = NumberToString.length();
    for (int i = Size; i >=0 ; i--) {
            cout << NumberToString[i] << endl;
    }
}

void PrintDigit(int Number) {
    int Remainder = 0;
    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;

        cout << Remainder ;
    }
}
int main() {
    //MySolution
    //ReverseNumber(ReadPosativeNumber("Please Enter Posative Number ?"));

        // Solution Abu Hadhuod
        PrintDigit(ReadPosativeNumber("Please Enter Posative Number ?"));

}