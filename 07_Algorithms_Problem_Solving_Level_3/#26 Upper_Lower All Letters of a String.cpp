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
string UpperAllStringMyFunction(string str) {

	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 'a' && str[i] <= 'z')) {
			str[i] = str[i] - 32;
		}
	}
	return str;
}

string LowerAllStringMyFunction(string str) {

	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z')) {
			str[i] = str[i] + 32;
		}
	}
	return str;
}

//AbuHadhoud Solution
string UpperAllString(string str) {

	bool FristLetter = true;
	for (int i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
	}
	return str;
}

string LowerAllString(string str) {

	for (int i = 0; i < str.length(); i++)
	{			str[i] = tolower(str[i]);
		
	}
	return str;
}

int main() {




	string S1 = ReadAlphabeticText("Please enter your string ?");

	//MySolution
	cout << "\nString after Upper:" << endl;
	S1 = UpperAllStringMyFunction(S1);
	cout << S1 << endl;

	cout << "\nString after Lower:" << endl;
	S1 = LowerAllStringMyFunction(S1);
	cout << S1 << endl;

	//AbuHadhoud Solution
	/*cout << "\nString after Upper:" << endl;
	S1 = UpperAllString(S1);
	cout << S1 << endl;

	cout << "\nString after Lower:" << endl;
	S1 = LowerAllString(S1);
	cout << S1 << endl; */

	
}