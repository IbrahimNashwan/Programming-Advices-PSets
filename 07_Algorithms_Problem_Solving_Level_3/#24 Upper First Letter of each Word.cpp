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

void PrintUpperFirstLetterOfEachWord(string S1) {
	bool FristLetter = true;
	cout << "\nString after conversion:" << endl;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && FristLetter) {
			if (S1[i] >= 'a' && S1[i] <= 'z')
				cout << char(S1[i] - 32);
			else
				cout << S1[i];
		}
		else {
			if (S1[i] >= 'a' && S1[i] <= 'z' || S1[i] == ' ')
				cout << S1[i];
			else
				cout << char(S1[i] + 32);


		}
			FristLetter = (S1[i] == ' ' ? true : false);

	}
}
// Capitalize the first letter of each word and lowercase the rest
string CapitalizeFirstLetterOfEachWord(string str) {
	bool FristLetter = true;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && FristLetter) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = char(str[i] + 32);
		}
		FristLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}
//AbuHadhoud Solution
string UpperFirstLetterOfEachWord(string S1) {

	bool FristLetter = true;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && FristLetter) {
			S1[i] = toupper(S1[i]);
		}
		FristLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

int main() {

	

	//MySolution
	string S1 = ReadText("Please enter your string ?");
	//PrintUpperFirstLetterOfEachWord(S1);
	S1 = CapitalizeFirstLetterOfEachWord(S1);
	//PrintUpperFirstLetterOfEachWord(ReadText("Please enter your string ?"));

	//AbuHadhoud Solution
	cout << "\nString after conversion:" << endl;
	//S1 = UpperFirstLetterOfEachWord(S1);
	cout << S1 << endl;
}