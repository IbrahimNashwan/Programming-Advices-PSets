
#include <iostream>
#include <string>
using namespace std;
//Problems18_Course5_Encryp/Decryp_Text

//my solution 
bool isValdateCapitalAndSmallLetters(const string& name) {
    for (char c : name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }

    return true;
}

string ReadText(string message) {
    string word = "";

    do {
        cout << message << endl;
        cin >> word;
    } while (!(isValdateCapitalAndSmallLetters(word)));

    return word;
}

string EncryptionText(string Text) {
    string NameWord = "";
    for (int i = 0; i < Text.length(); i++) {
        NameWord += char(Text[i] + 2);
    }
    cout << endl;

    return NameWord;
}

string DecryptionText(string Text) {
    string word = "";
    for (int i = 0; i < Text.length(); i++) {
        word += char(Text[i] - 2);
    }
    cout << endl;
    return word;
}


//solution abu hadhuod
string EncryptionText2(string Text, short EncryptionKey) {

    for (int i = 0; i < Text.length(); i++) {

        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    cout << endl;

    return Text;
}


string DecryptionText2(string Text, short EncryptionKey) {

    for (int i = 0; i < Text.length(); i++) {

        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    cout << endl;
    return Text;
}
int main() {

    //my solution 
    short EncryptionKey = 2;
    string Text = ReadText("Please Enter Your Name ?");
    string TextEncryption = EncryptionText(Text);
    string TextDecryption = DecryptionText(TextEncryption);

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << TextEncryption << endl;
    cout << "Text After Decryption : " << TextDecryption << endl;

    /*
   //AbuHadhuod
   const short EncryptionKey = 2 ;
    string Text = ReadText("Please Enter Your Name ?");
    string TextAfterEncryption = EncryptionText2(Text,EncryptionKey);
    string TextAfterDecryption = DecryptionText2(TextAfterEncryption,EncryptionKey);

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << TextAfterEncryption << endl;
    cout << "Text After Decryption : " << TextAfterDecryption << endl;
   */
}
