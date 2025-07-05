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
string TrimLeftMySolution(string S1) {

	string delim = " ";

	//while ((pos = S1.find(delim)) != std::string::npos)
	while(true) {

		if (S1[0] == ' ' && S1[1] == ' '){
			S1.erase(0,delim.length());

		}
		else if (S1[0] == ' ' && isalpha(S1[1])){
			S1.erase(0, delim.length());
			return S1;
		}
		else
		{
			return S1;
		}

	}
	return S1;
}

string TrimRightMySolution(string S1) {

	string delim = " ";
	while (true) {

		if (S1[S1.length()-1] == ' ' && S1[S1.length() - 2] == ' ') {
			S1.erase(S1.length() - 1, delim.length());

		}
		else if (S1[S1.length() - 1] == ' ' && isalpha(S1[S1.length() - 2])) {
			S1.erase(S1.length() - 1, delim.length());
			return S1;
		}
		else
		{
			return S1;
		}
	}
	return S1;
}

string TrimMySolution(string str) {

	str = TrimLeftMySolution(str);
	str = TrimRightMySolution(str);
	return str;
}
//AbuHadhoud Solution
string TrimLeft(string S1) {

	for (int i = 0; i < S1.length();i++) {

		if (S1[i] != ' ') {
			return S1.substr(i, S1.length() - i);
		}
	}
	return S1;
}

string TrimRight(string S1) {

	for (int i = S1.length() - 1; i >= 0; i--) {

		if (S1[i] != ' ') {
			return S1.substr(0, i + 1);
		}
	}
	return S1;
}

string Trim(string S1) {

	return TrimLeft(TrimLeft(S1));
}


int main() {

	string str = ReadAlphabeticText("Please enter your string?");
	//MySolution
	cout << "String    = " << str << endl;
	cout << "TrimLeft  = " << TrimLeftMySolution(str) << endl;
	cout << "TrimRight = " << TrimRightMySolution(str) << endl;
	cout << "Trim      = " << TrimMySolution(str) << endl;

	//AbuHadhoud Solution
	/*cout << "String    = " << str << endl;
	cout << "TrimLeft  = " << TrimLeft(str) << endl;
	cout << "TrimRight = " << TrimRight(str) << endl;
	cout << "Trim      = " << Trim(str) << endl;*/

	system("pause>0");


}