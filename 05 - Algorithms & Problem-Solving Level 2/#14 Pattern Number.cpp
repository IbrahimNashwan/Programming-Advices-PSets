
#include <iostream>
using namespace std;
//Problems14_Course5_PatternNumber
int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}
//Abu Hadhoud Solution 
void PrintInvertedLetterPattern(int Number) {


    for (int i = 65 + Number - 1; i >= 65; i--) {
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++) {

            cout << char(i);
        }
        cout << endl;
    }
}

//My Solution 
void PrintInvertedLetterPattern1(int Number) {
    int i = 64;

    for (i += Number; i >= 64; i--) {
        for (int j = 65; j <= i; j++) {

            cout << char(i);
        }
        cout << endl;
    }
}

int main() {

    //Abu Hadhoud Solution 
    PrintInvertedLetterPattern(ReadPosativeNumber("please enter positive number ?"));


    //My Solution    
    //PrintInvertedLetterPattern1(ReadPosativeNumber("please enter positive number ?"));

}
