#include <iostream>
using namespace std;
//Problems46_Course5_MyABS

float ReadNumber()
{
    float Number;

    cout << "Enter Number ?" << endl;
    cin >> Number;

    return Number;
}

float MyABS(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

int main() {

    float Number = ReadNumber();
    cout << "\nMy abs result : ";
    cout << MyABS(Number) << endl;

    cout << "C++ abs result : ";
    cout << abs(Number) << endl;

}