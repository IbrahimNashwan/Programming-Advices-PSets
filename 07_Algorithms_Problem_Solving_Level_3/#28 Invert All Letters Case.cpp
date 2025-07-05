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
string InvertAllLettersCaseMuFunction(string str) {

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
	}

	return str;
}

//AbuHadhoud Solution
char InvertCharcterCase(char c) {

	return (isupper(c) ? tolower(c) : toupper(c));
}

string InvertAllLettersCase(string str) {

	for (int i = 0; i < str.length(); i++)
	{
		 str[i] = InvertCharcterCase(str[i]);
	}

	return str;
}

int main() {




	string S1 = ReadAlphabeticText("Please Enter your string?");

	//MySolution
	/*cout << "\nCharcter after inverting case:" << endl;
	S1 = InvertAllLettersCaseMuFunction(S1);
	cout << S1 << endl;*/



	//AbuHadhoud Solution
	cout << "\String after Inverting  All Letters Case:" << endl;
	S1 = InvertAllLettersCase(S1);
	cout << S1 << endl;



}