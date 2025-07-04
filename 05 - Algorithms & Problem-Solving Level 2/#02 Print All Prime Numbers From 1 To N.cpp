#include <iostream>
#include <cmath>
using namespace std;
//38-4
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPosativeNumber(string message) {
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

enPrimeNotPrime CheckPrime(int Number) {
    int M;
    M = round(Number / 2);
    for (int counter = 2; counter <= M; counter++) {
        if (Number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void PrintNumberType(int Number)     {
    cout << "\n";
    cout << "Prime Numbers From " << 1 << " To " << Number ;
    cout << " are :" << endl;
    for (int i = 1; i <= Number; i++) {
        if (CheckPrime(i) == enPrimeNotPrime::Prime) {

            cout << i << endl;
        }
    }
}
int main() {


    PrintNumberType(ReadPosativeNumber("please enter positive number ?"));

}