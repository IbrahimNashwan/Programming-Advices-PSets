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

//MySolution1
vector<string> SplitWords1(string S1) {
	string delim = " ";
	int pos = 0;
	string sWord;
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

string JoinReversedVector(vector<string> vString, string Delim = " ") {

	string S1 = "";

	vector<string> ::iterator iter;
	for (iter = vString.end(); iter >= vString.begin();iter--) {

		if (iter == vString.begin()) {
			S1 = S1 + *(iter) + Delim;
			return S1.substr(0, S1.length() - Delim.length());
		}
		S1 = S1 + *(iter) + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

string ReverseString(string S1) {

	vector<string> vString;
	vString = SplitWords1(S1);
	S1 = JoinReversedVector(vString);

	return S1;
}

//MySolution2 after saw Abo-Hadhoud
vector<string> SplitWords2(string S1, string delim = " ") {
	
	int pos = 0;
	string sWord;
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



string ReverseStringSolution2(string S1) {

	vector<string> vString;
	vString = SplitWords2(S1," ");
	string S2 = "";
	string Delim = " ";
	vector<string> ::iterator iter;
	for (iter = vString.end()-1; iter >= vString.begin(); iter--) {

		if (iter == vString.begin()) {
			S2 = S2 + *(iter) + Delim;
			return S2.substr(0, S2.length() - Delim.length());
		}
		S2 = S2 + *(iter) + Delim;
	}
	return S2.substr(0, S2.length() - Delim.length());
}



//AbuHadhoud Solution
vector <string> SplitWords(string S1, string Delim) {

	vector <string> vWords;
	string sWords;
	int pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos) {

		sWords = S1.substr(0, pos);

		if (sWords != "") {
			vWords.push_back(sWords);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {
		vWords.push_back(S1);
	}

	return vWords;
}

string ReplaceWords(string S1) {

	vector <string> vWords;
	string S2 = "";

	vWords = SplitWords(S1, " ");
	vector <string> ::iterator iter = vWords.end();
	while (iter != vWords.begin()) {

		--iter;
		S2 = S2 + (*iter) + " ";
	}
	return S2.substr(0, S2.length() - 1);
}
int main() {

	string S1 = ReadAlphabeticText("Please enter a string");
	cout << ReverseStringSolution2(S1) << endl;;
	/*cout << "\nString before Reverse:" << endl;
	cout << S1 << endl;

	cout << "\nString after Reverse:" << endl;
	cout << ReverseString(S1) << endl;*/

	system("pause>0");


}