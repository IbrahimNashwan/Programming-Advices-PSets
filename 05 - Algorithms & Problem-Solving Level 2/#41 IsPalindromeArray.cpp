#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
//Problems41_Course5_IsPalindromeArray

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    arr[0] = 10,
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;

}

void PrintArray(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool IsPalindromeArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!(arr[i] == arr[arrLength - 1 - i]))
        {
            return false;
        }

    }
    return true;
}
//my solution 
void PrintPalindromeArray(int arrSource[100], int SourceLength)
{
    if (IsPalindromeArray(arrSource, SourceLength))
    {
        cout << "\nit is Palindrome Array";
    }
    else
    {
        cout << "\n Not Palindrome Array";
    }
}
int main() {
    //Seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = 0;
    FillArray(arr, arrLength);



    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);

       //PrintPalindromeArray(arr, arrLength);
    
      //abuHadhoud solution Function
    if(IsPalindromeArray(arr,arrLength) != false )
        {
            cout << "\nit is Palindrome Array" ;
        }else
        {
            cout << "\n Not a Palindrome Array" ;
        }
        

}


