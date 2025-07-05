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

vector <string> ReplaceWordsInVector(vector <string>& vWords, string Replace, string ReplaceTo) {

	string Delim = " ";
	cout << "please enter number (1-2)?" << endl;
	cout << "1)Repalce with match case" << endl;
	cout << "2)Repalce with don\'t match case" << endl;
	int number; 
	cin >> number;
	if (number == 1){
	
		for (string& Word : vWords) {

			if (Word == Replace)
			{
				Word = ReplaceTo;
			}
		}
	}
	else {
		string str1 = "";
		for (int i = 0; i < Replace.length(); i++) {

			str1 = str1 + char(tolower(Replace[i]));
		}

		for (string& Word : vWords) {
			string str2 = "";
			for (int i = 0; i < Word.length(); i++) {

				str2 = str2 + char(tolower(Word[i]));
			}
			if (str1 == str2) {
				Word = ReplaceTo;
			}
			
		}
	}
	
	return vWords;
}

string ReplaceWordsInString(string S1, string Replace, string ReplaceTo) {

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
string JoinString(vector<string> vString, string Delim) {

	string S1 = "";


	for (string& word : vString) {

		S1 = S1 + word + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
string LowerAllString(string str) {

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);

	}
	return str;
}

string ReplaceWordsInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo,bool MatchCase = true) {

	vector <string> vWords;
	string S2 = "";
	vWords = SplitWords(S1, " ");

	for (string& Word : vWords) {

		if (MatchCase) {

			if (Word == StringToReplace)
			{
				Word = ReplaceTo;
			}
		}
		else {
			if (LowerAllString(Word) == LowerAllString(StringToReplace)) {
				Word = ReplaceTo;

			}
		}
		
	}
	return JoinString(vWords, " ");
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
	cout << "\nRepalce with match case" << endl;
	cout << ReplaceWordsInStringUsingSplit(S1, Replace, ReplaceTo) << endl;

	cout << "\nRepalce with don\'t match case" << endl;	
	cout << ReplaceWordsInStringUsingSplit(S1, Replace, ReplaceTo,false) << endl;

	system("pause>0");


}