#include <iostream>
#include <string>
#include <cctype>

using namespace std;
//MySolution

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);

	return Text;
}

//AbuHadhoud Solution

string LowerFirstLetterOfEachWord(string str) {

	bool FristLetter = true;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && FristLetter) {
			str[i] = tolower(str[i]);
		}
		FristLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

int main() {



	//MySolution
	//PrintUpperFirstLetterOfEachWord(ReadText("Please enter your string ?"));

	//AbuHadhoud Solution
	string S1 = ReadText("Please enter your string ?");
	cout << "\nString after conversion:" << endl;
	S1 = LowerFirstLetterOfEachWord(S1);
	cout << S1 << endl;
}