
#include <iostream>
using namespace std;
//Problems15_Course5_LetterPattern
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
void LetterPattern(int Number) {


    for (int i = 65; i <= 65 + Number - 1; i++) {
        for (int j = 1; j <= i - 65 + 1; j++) {

            cout << char(i);
        }
        cout << endl;
    }
}

//My Solution 
void LetterPattern1(int Number) {


    for (int i = 65; i <= 65 + Number - 1; i++) {
        for (int j = 65; j <= i; j++) {

            cout << char(i);
        }
        cout << endl;
    }
}

int main() {

    //Abu Hadhoud Solution 
    LetterPattern(ReadPosativeNumber("please enter positive number ?"));


    //My Solution    
   // LetterPattern(ReadPosativeNumber("please enter positive number ?"));


}

