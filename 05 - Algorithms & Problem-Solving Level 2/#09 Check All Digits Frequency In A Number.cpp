#include <iostream>
using namespace std;
//Problems9_Course5_DigitFrequency
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

    int Remainder = 0, Number2 = 0;

    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
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

void PrintAllDigitFrequency(int Number) 
{   
    Number = ReverseNumber(Number);
    int DigitCounter = 0;

    
    for (int i = 0; i < 10; i++) {

        DigitCounter = CountDigitFrequency(i, Number);
 
        if(DigitCounter > 0)
        {
            cout << " Digit " << i << "Frequency is " << DigitCounter << " Time(s)." << endl;
            
        }
    }
}

int main() {

    //Solution Abu Hadhuod
   // int Number = ReadPosativeNumber("Please enter the main number ?");
    short DigitToCheck = 0;


    PrintAllDigitFrequency(ReadPosativeNumber("Please Enter Posative Number ?"));

    //My Solution    
    //PrintReverseNumber2(ReadPosativeNumber("please enter positive number ?"));

}

