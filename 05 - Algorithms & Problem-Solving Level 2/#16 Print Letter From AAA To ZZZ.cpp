
#include <iostream>
#include <string>
using namespace std;
//Problems16_Course5_PrintLetterFromAAAToZZZ

void PrintLetterFromAAAToZZZ() {
    string word = "";

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                //solution abu hadhuod 
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << word << endl;
                word = "";
                //my solution 
               // cout << char(i) << char(j) << char(g) << endl;
            }

        }

    }
}


//my solution 
void PrintLetterFromAAAToZZZ1() {
    string word = "";

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {

                cout << char(i) << char(j) << char(k) << endl;
            }

        }

    }
}

int main() {


    PrintLetterFromAAAToZZZ();



}
