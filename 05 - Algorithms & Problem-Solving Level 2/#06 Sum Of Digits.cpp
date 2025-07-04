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


int SumOfDigit(int Number) {
    int Remainder = 0;
    int Sum = 0;
    while (Number > 0) {

        Remainder = Number % 10;
        Number = Number / 10;

        Sum += Remainder;
    }
    return Sum ;

}

int main() {
   
         //Solution Abu Hadhuod
    cout << "The Sum Of Digits " << SumOfDigit(ReadPosativeNumber("Please Enter Posative Number ?")) << endl;


}