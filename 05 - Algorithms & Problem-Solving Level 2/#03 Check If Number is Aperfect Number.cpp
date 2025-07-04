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

void PrintResults(int Number) {
    if (IsPrefetNumber(Number))
        cout << Number << " is Perfect" << endl;
    else
        cout << Number << " is  Not Perfect" << endl;

}

int main() {


    PrintResults(ReadPosativeNumber("Please Enter Posative Number ?"));
}