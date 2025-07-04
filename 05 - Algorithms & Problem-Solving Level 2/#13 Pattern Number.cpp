#include <iostream>
using namespace std;
//Problems13_Course5_PatternNumber

int ReadPositiveNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void PatternNumber(int Number) {

    for (int i = 1; i <= Number; i++) {
        for (int j = 1; j <= i; j++) {

            cout << i;
        }
        cout << endl;
    }
}


int main() {



    //My Solution    
    PatternNumber(ReadPositiveNumber("please enter positive number ?"));

}
