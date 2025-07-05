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
vector<string> SplitWords(string S1, string delim) {
	
	int pos = 0;
	string sWord ;
	vector<string> vWord;

	while ((pos = S1.find(delim)) != std::string::npos) {

		sWord = S1.substr(0, pos);

		if (sWord != "") {
			vWord.push_back(sWord);

		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "") {
		vWord.push_back(S1);
	}
	return vWord;
}

void PrintVectorWords(vector<string>& vWord) {
	int Token = vWord.size();
	cout << "\nToken = " << Token << endl;;

	for (string& word : vWord) {
		cout << word << endl;
	}
}
int main() {

	vector<string> vString;
	//string S2 = "ibrahim faiz Ali Nashwan";
	string S2 = "ibrahim,faiz,Ali,Nashwan";
	vString = SplitWords(S2,",");
	//PrintVectorWords(vWord);

	cout << "Token = " << vString.size() << endl;;
	for (string& word : vString) {
		cout << word << endl;
	}

	system("pause>0");


}