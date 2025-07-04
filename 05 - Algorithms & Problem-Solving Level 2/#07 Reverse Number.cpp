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

int ReverseNumber(int Number) {

    int Remainder = 0,Number2 = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}

int main() {

        // Solution Abu Hadhuod
    cout << "Reverse is :\n"
         << ReverseNumber(ReadPosativeNumber("Please Enter Posative Number ?"))
         << "\n";

}