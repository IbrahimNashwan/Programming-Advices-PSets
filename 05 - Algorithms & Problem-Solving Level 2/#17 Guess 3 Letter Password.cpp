#include <iostream>
#include <string>
using namespace std;
//Problems17_Course5_Guessa_3_letter_Password 

//my solution 
bool isValdateCapitalLetters(const string& name) {
    for (char c : name) {
        if (!((c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }

    return true;
}

string ReadCapitalLetters(string message) {
    string word = "";

    do {
        cout << message << endl;
        cin >> word;
    } while (!(isValdateCapitalLetters(word)));

    return word;
}

bool CheckPassword(string Password, string Word) {

    return Word == Password;
}

void GuessaThreeLetterPassword(string Password) {
    string word = "";
    int count = 0;

    for (int i = 65; i <= 90; i++) {

        for (int j = 65; j <= 90; j++) {

            for (int k = 65; k <= 90; k++) {

                count++;

                cout << char(i) << char(j) << char(k) << endl;

                cout << "Trial [" << count << "] : " << word << endl;

                if (CheckPassword(Password, word))
                {
                    cout << "Password is " << Password << endl;
                    cout << "Found after " << count << " Trial(s)" << endl;

                    return;
                }


                word = "";

            }

        }

    }
}

//solution abu hadhuod
void GuessaThreeLetterPassword1(string Password) {
    string word = "";
    int count = 0;
    for (int i = 65; i <= 90; i++) {

        for (int j = 65; j <= 90; j++) {

            for (int k = 65; k <= 90; k++) {

                count++;

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << "Trial [" << count << "] : " << word << endl;

                if (word == Password)
                {
                    cout << "Password is " << Password << endl;
                    cout << "Found after " << count << " Trial(s)" << endl;
                    return;
                }


                word = "";

            }

        }

    }
}

int main() {

    //my solution 
    GuessaThreeLetterPassword1(ReadCapitalLetters("Please Enter 3 capital letters ?"));


}

