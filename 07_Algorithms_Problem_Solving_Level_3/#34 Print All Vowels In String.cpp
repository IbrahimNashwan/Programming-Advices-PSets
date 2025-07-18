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
bool IsVowel(char c) {
	c = ((c >= 'A' && c <= 'Z') ? char(c + 32) : c);

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

void PrintAllVowels(string str) {

	cout << "\nVowels in string are :";
	for (int i = 0; i < str.length(); i++)
	{
		if (IsVowel(str[i])) {
			cout << str[i] << "   ";
		}
	}
	cout << endl;
}
//AbuHadhoud Solution

int main() {

	string str = ReadAlphabeticText("Please enter your string?");
	PrintAllVowels(str);




	//AbuHadhoud Solution

}