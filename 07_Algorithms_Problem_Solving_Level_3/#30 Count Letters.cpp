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

char ReadCharacter(string Message) {
	string str;
	cout << Message << endl;
	getline(cin, str);

	while (str.length() != 1 || (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))) {
		cout << "Input error, please enter a single letter (a-z or A-Z)." << endl;
		getline(cin, str);

	}
	char c = str[0];
	return c;
}


//MySolution
// Counts how many times a specific character appears in a given string (case-sensitive).
int CountLettersFunction(string str,char ch) {
	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] == ch))
		{
			Counter++;
		}
	}
	return Counter;
}


//AbuHadhoud Solution

int main() {


	cout << " ";


	string str = ReadAlphabeticText("Please enter your string?");
	char ch = ReadCharacter("Please enter a letter or digit to search for in the text:");
	//MySolution
	cout << "\nLetter '" << ch <<"' Count = " << CountLettersFunction(str, ch) << endl;
	




	//AbuHadhoud Solution
	system("pause>0");

}