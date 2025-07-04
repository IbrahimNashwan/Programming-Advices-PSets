#include <iostream>
#include <cmath>
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

bool IsPrefetNumber(int Number) {
    int Sum = 0;
    for (int i = 1; i < Number; i++) {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintPerfectNumberFrom1ToN(int Number) {
    for (int i = 1; i <= Number; i++) {
        if (IsPrefetNumber(i))
            cout << i << " is Perfect" << endl;
    }
}

int main() {


    PrintPerfectNumberFrom1ToN(ReadPosativeNumber("Please Enter Posative Number ?"));
}