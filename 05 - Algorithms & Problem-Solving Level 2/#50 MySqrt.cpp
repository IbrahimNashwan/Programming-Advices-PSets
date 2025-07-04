#include <iostream>
#include <cmath>

using namespace std;
//Problems50_Course5_MySqrt

float ReadNumber()
{
    float Number;

    cout << "Enter Number ?" << endl;
    cin >> Number;

    return Number;
}
//my solution 
float MySqrt(float Number) {

    for (int i = 0; i < Number; i++)
    {
        if (i * i == Number) {
            return i;
        }
    }
}

// solution abo hadhood 
float MySqrt2(float Number) {

    return pow(Number, 0.5);
}

int main() {

    float Number = ReadNumber();
    cout << "\MySqrt2 result : ";
    cout << MySqrt2(Number) << endl;

    cout << "C++ Sqrt2 result : ";
    cout << sqrt(Number) << endl;

}