#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

bool isAlphaOnly(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '  ||ispunct(c)))
			return false;
	}
	return true;
}
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
string RemovePunctuation(string S1) {

	string S2 = "";
	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i])) {
			S2 = S2 + S1[i];
		}
	}
	return S2;
}
int main() {
	string S1 = ReadAlphabeticText("Please enter a string");

	cout << "\nString after remove puncuation:" << endl;
	cout << RemovePunctuation(S1) << endl;
	system("pause>0");


}