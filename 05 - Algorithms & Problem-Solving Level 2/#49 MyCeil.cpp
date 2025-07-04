#include <iostream>
#include <cmath>

using namespace std;
//Problems49_Course5_MyCeil

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
float MyCeil(float Number) {
    if (GetFraction(Number) != 0) {
        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
        return int(Number);
}
// solution abo hadhood 
int main() {

    float Number = ReadNumber();
    cout << "\nMyCeil result : ";
    cout << MyCeil(Number) << endl;

    cout << "C++ Ceil result : ";
    cout << ceil(Number) << endl;

}