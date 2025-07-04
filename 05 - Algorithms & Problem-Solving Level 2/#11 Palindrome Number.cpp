#include <iostream>
#include <cmath>
using namespace std;
//Problems11_Course5_PalindromeNumber
int ReadPositiveNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}


int CheckReverse(int number) {

    int Remainder = 0;
    int Reverse = 0;

    while (number > 0) {
        Remainder = number % 10;
        number = number / 10;
        Reverse = Reverse * 10 + Remainder;
    }
    return Reverse;
}

bool IsPalindromeNumber(int Number) {
    return Number == CheckReverse(Number);
}



void PrintPalindromeNumber(int Number) {
    if (IsPalindromeNumber(Number))
        cout << Number << " Is Palindrome Number ." << endl;

    else
        cout << Number << " Is Not Palindrome Number ." << endl;
}
int main() {


    //PrintPalindromeNumber(ReadPosativeNumber("please enter positive number ?"));
     
    //Solution Abu Hadhuod
    if (IsPalindromeNumber(ReadPositiveNumber("please enter positive number ?")))
        cout << "\n Is Palindrome Number ." << endl;

    else
        cout << "\n Is Not Palindrome Number ." << endl;
}
