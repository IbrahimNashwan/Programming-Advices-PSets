#include <iostream>
using namespace std;
//Problems12_Course5_InvertedNumberPattern

int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void InvertedNumberPattern(int Number) {

    for (int i = Number; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {

            cout << i;
        }
        cout << endl;
    }
}

int main() {



    //My Solution    
    InvertedNumberPattern(ReadPosativeNumber("please enter positive number ?"));

}