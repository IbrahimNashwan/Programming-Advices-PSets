#include <iostream>
#include <cmath>
using namespace std;
//Problems8_Course5
int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void PrintReverseNumber2(int Number) {

    int Remainder = 0;


    int number2;
    int counter = 0;
    cout << "Please enter digit number ?" << endl;
    cin >> number2;
    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;

        if (Remainder == number2) {
            counter++;
        }


    }
    cout << "Digit " << number2 << " frequency " << counter << " tim's " << endl;
}


//Solution Abu Hadhuod
int CountDigitFrequency(int DigitToCheck, int Number) {

    int FreqCounter = 0, Remainder = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;

        if (DigitToCheck == Remainder)
        {
            FreqCounter++;
        }

    }

    return FreqCounter;
}

int main() {

    //Solution Abu Hadhuod
    int Number = ReadPosativeNumber("Please enter the main number ?");
    short DigitToCheck = ReadPosativeNumber("Please enter digit to check ?");

    cout << endl << " Digit " << DigitToCheck << " Frequency is "
        << CountDigitFrequency(DigitToCheck, Number) << " Times \n";

    //My Solution    
    //PrintReverseNumber2(ReadPosativeNumber("please enter positive number ?"));

}

