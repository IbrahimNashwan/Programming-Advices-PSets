#include <iostream>
#include <string>
#include <cctype>


using namespace std;

bool isAlphaOnly(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '-'))
			return false;
	}
	return true;
}
// Prompts the user with the given message and reads a line containing alphabetic characters only.
string ReadAlphabeticText(string prompt) {
	string NumToStr;
	string text;

	do {
		cout << prompt << endl;
		getline(cin, text);

		if (!isAlphaOnly(text)) {
			cout << "Invalid input! Please enter Text only." << endl;
		}

	} while (!isAlphaOnly(text));

	return text;
}

//MySolution
void PrintEachWord(string str) {

	cout << "\nyour string words are:" << endl;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ') {
			cout << str[i];
		}
		if (str[i] == ' ') {
			cout << endl;
		}
	}
	cout << endl;
}
//AbuHadhoud Solution
void PrintWordsLineByLine(string S1) {
	string delim = " ";
	cout << "\nyour string words are:" << endl;

	int pos = 0;
	string word;

	while ((pos = S1.find(delim)) != std::string::npos) {

		word = S1.substr(0, pos);

		if (word != "") {
			cout << word << endl;
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != ""){
		cout << S1 << endl;
	}
}

int main() {

	string str = ReadAlphabeticText("Please enter your string?");
	//PrintEachWord(str);




	//AbuHadhoud Solution
	PrintWordsLineByLine(str);
}