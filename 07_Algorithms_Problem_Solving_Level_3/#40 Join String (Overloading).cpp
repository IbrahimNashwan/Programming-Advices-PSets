#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

bool isAlphaOnly(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '-'))
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



string JoinString(vector<string> vString, string Delim) {

	string S1 = "";


	for (string& word : vString) {

		S1 = S1 + word + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
string JoinString(string arrString[],int length, string Delim) {

	string S1 = "";

	for (int i = 0; i < length; i++) {

		S1 = S1 + arrString[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
int main() {

	vector<string> vString = { "ibrahim","Mohammed","Kalid","Ismail" };
	string  arrString[] = {"ibrahim","Mohammed","Kalid","Ismail"};


	cout << "\nVector after join:" << endl;
	cout << JoinString(vString, ",") << endl;

	cout << "\nArray after join:" << endl;
	cout << JoinString(arrString,4, ",") << endl;

	system("pause>0");


}