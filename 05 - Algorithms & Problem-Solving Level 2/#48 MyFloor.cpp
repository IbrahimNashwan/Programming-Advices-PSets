#include <iostream>
#include <cmath>
using namespace std;
//Problems48_Course5_MyFloor

float ReadNumber()
{
    float Number;

    cout << "Enter Number ?" << endl;
    cin >> Number;

    return Number;
}

float GetFraction(float Number) {
    return Number - int(Number);
}
//my solution 


float MyFloor(float Number) {
    int IntPart = int(Number);
    float FractionsPart = GetFraction(Number);

    if (Number > 0)
        return IntPart;
    else
        return --IntPart;
}
// solution abo hadhood 
float MyFloor1(float Number) {

    if (Number > 0)
        return int(Number);
    else
        return int(Number) - 1;
}
int main() {

    float Number = ReadNumber();
    cout << "\nMy floor result : ";
    cout << MyFloor1(Number) << endl;

    cout << "C++ floor result : ";
    cout << floor(Number) << endl;
}

