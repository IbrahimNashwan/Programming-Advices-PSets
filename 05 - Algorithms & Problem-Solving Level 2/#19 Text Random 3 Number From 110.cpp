
#include <iostream>
#include <cstdlib>
using namespace std;
//Problems19_Course5__Text_Random3NumberFrom1_10;

int RendomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}


int main() {
    srand((unsigned)time(NULL));
    //my solution 


    cout << RendomNumber(200, 300) << endl;
    cout << RendomNumber(200, 300) << endl;
    cout << RendomNumber(200, 300) << endl;
    cout << rand() << endl;



}