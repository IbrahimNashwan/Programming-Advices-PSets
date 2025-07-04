
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//Problems47_Course5_MyRound

float ReadNumber()
{
    float Number;

    cout << "Enter Number ?" << endl;
    cin >> Number;

    return Number;
}

int ConvertFromAsciToInt(char A) {
    int N = char(A) - 48;
    return N;
}
//my solution 
float MyRound(float& Number)
{
    string NumberToText;
    int Temp;
    NumberToText = to_string(Number);
    for (int i = 0; i < NumberToText.length(); i++)
    {
        if (Number > 0) {

            if (NumberToText[i] == '.') {
                Temp = ConvertFromAsciToInt(NumberToText[i + 1]);

                if (Temp >= 5) {
                    return (int)Number + 1;
                }
                else {
                    return (int)Number;
                }
            }
        }
        else
        {
            if (NumberToText[i] == '.') {
                Temp = ConvertFromAsciToInt(NumberToText[i + 1]);

                if (Temp >= 5)
                    return (int)Number - 1;
                else
                    return (int)Number;
            }

        }
    }
}

//my solution after watched abu hadhood and i set the function 
float MyRound1(float Number)
{
    string NumberToText;
    int Temp;
    NumberToText = to_string(Number);
    for (int i = 0; i < NumberToText.length(); i++)
    {
        if (NumberToText[i] == '.') {
            Temp = ConvertFromAsciToInt(NumberToText[i + 1]);

            if (Temp >= 5) {

                if (Number > 0)
                    return (int) ++Number;
                else
                    return (int) --Number;

            }

            return Number;
        }
    }

}


int main() {

    float Number = ReadNumber();
    cout << "\nMy Round result : ";
    cout << MyRound1(Number) << endl;

    cout << "C++ Round result : ";
    cout << round(Number) << endl;
    
}

