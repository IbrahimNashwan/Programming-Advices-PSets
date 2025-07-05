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

//MySolution
string JoinStringMySolution(vector<string> vString,string Delim) {

	vector<string> ::iterator iter;
	string sWords;
	for (iter = vString.begin(); iter != vString.end(); iter++) {
		
		if (iter != vString.end()) {
			sWords.append(*iter);
			sWords.append(Delim);
		}
		else {
			sWords.append(*iter);
			return sWords;
		}
	}
	return sWords;
}

string JoinString(vector<string> vString, string Delim) {

	string S1 = "";
	
	
	for (string& word : vString) {

		S1 = S1 + word + Delim;
	}
	return S1.substr(0,S1.length() - Delim.length());
}
int main() {

	vector<string> vString = {"ibrahim","Mohammed","Kalid","Ismail"};
	//MySolution
	/*cout << JoinStringMySolution(vString," ") << endl;*/


	//AbuHadhoud Solution
	cout << JoinString(vString, ",") << endl;


}