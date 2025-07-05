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
int CountWordsInstring(string S1) {
	string delim = " ";

	int pos = 0;
	string word;
	int counter = 0;

	while ((pos = S1.find(delim)) != std::string::npos) {

		word = S1.substr(0, pos);

		if (word != "") {
			counter++;

		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "") {
		counter++;
	}
	return counter;
}
int main() {

	string str = ReadAlphabeticText("Please enter your string?");




	cout << "\nThe number of words in your string :" << CountWordsInstring(str) << endl;;
}