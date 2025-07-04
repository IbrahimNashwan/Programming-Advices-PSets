#include <iostream>
#include <cstdlib>


//Problems31_Course5_ShuffleOrderedArray
using namespace std;


void PrintArray(int arr[100], int arrLength) {
    int counter = 0;
    for (int i = 0; i < arrLength; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int ReadPosativeNumber(string Message) {

    int Number;
    do {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

int RandomNumber(int From, int To) {

    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}

void Swap(int& A, int& B) {
    int Temp;

    Temp = A;
    A = B;
    B = Temp;

}

void FillArrayWith1toN(int arr[100], int& arrLength) {

    //arrLength = ReadPosativeNumber("Please enter Number of elements ?");

    for (int i = 0; i < arrLength; i++) {
        arr[i] = i + 1;
    }
    cout << endl;
}



void SuffleArray(int arr[100], int arrLength) {
    int counter = 0;
    for (int i = 0; i < arrLength; i++) {

        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
    cout << endl;
}




//chat says More reliable and trustworthy
void FisherYatesShuffle(int arr[100], int arrLength) {
    int counter = 0;

    for (int i = arrLength - 1; i > 0; i--) {

        int j = RandomNumber(0, i);

        if (j == i) {
            counter++;
        }

        Swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[100];
    int arrLength = ReadPosativeNumber("Please enter the number of elements ?");
    srand((unsigned)time(NULL));

    FillArrayWith1toN(arr, arrLength);

    cout << "\nArray 1 elements : " << endl;
    PrintArray(arr, arrLength);
    //abuHadhoud solution 
    SuffleArray(arr, arrLength);

    //chat 
    //FisherYatesShuffle(arr, arrLength);
    cout << "\nArray 1 elements after random : " << endl;
    PrintArray(arr, arrLength);



}
