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

vector <string> ReplaceWordsInVector(vector <string>& vWords,string Replace, string ReplaceTo) {

	string Delim = " ";
	for (string& Word : vWords) {

		if (Word == Replace)
		{
			Word = ReplaceTo;
		}
	}
	return vWords;
}

string ReplaceWordsInString(string S1,string Replace , string ReplaceTo) {

	vector <string> vWords;
	string Delim = " ";
	string S2 = "";
	vWords = SplitWords(S1, " ");
	vWords = ReplaceWordsInVector(vWords, Replace, ReplaceTo);

	for (string& word : vWords) {

		S2 = S2 + word + Delim;
	}
	return S2.substr(0, S2.length() - 1);
}
//AbuHadhoud Solution

string ReplaceWordsInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo) {

	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos) {

		S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace);
	}
	
	return S1;
}

int main() {

	string S1 = ReadAlphabeticText("Please enter a string");
	string Replace = ReadAlphabeticText("Please enter word to reblace it ?");
	string ReplaceTo = ReadAlphabeticText("Please enter a new word to reblace it ?");
	//cout << ReplaceWordsInString(S1, Replace, ReplaceTo) << endl;

	/*cout << "\nString before Reblace:" << endl;
	cout << S1 << endl;

	cout << "\nString after Reblace:" << endl;
	cout << ReplaceWordsInString(S1,Replace, ReplaceTo) << endl;*/


	//AbuHadhoud Solution
	cout << "\nString before Reblace:" << endl;
	cout << S1 << endl;

	cout << "\nString after Reblace:" << endl;
	cout << ReplaceWordsInStringUsingBuiltInFunction(S1, Replace, ReplaceTo) << endl;

	system("pause>0");


}