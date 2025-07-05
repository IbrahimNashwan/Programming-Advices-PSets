#include <iostream>
#include <string>
#include <vector>

using namespace std;
//MySolution

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);


	return Text;

}
void PrintVector(vector <string> Word) {

	for (string& W : Word) {

		cout << W << endl;
	}
}
void PrintFirstLetterOfWord(vector <string> Word) {
	cout << "\nFrist letter of this string :" << endl;
	for (string& W : Word) {
		//cout << W << endl;
		cout << char(W.at(0)) << endl;

	}
}
void ReadWordToVector(string Text) {
	
	vector <string> Word;
	string Temp;
	int j = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (char(Text[i]) == ' ') {
			Word.push_back(Temp);
			Temp = "";
			continue;
		}
		else {
			Temp += char(Text[i]);
		}
	}
	Word.push_back(Temp);
	PrintFirstLetterOfWord(Word);
 }

//AbuHadhoud Solution
void PrintFirstLetterOfEachWord(string S1) {
	bool FristLetter = true;
	cout << "\nFrist letter of this string :" << endl;
	for (int i = 0; i < S1.length();i++) {
		if (S1[i] != ' ' && FristLetter) {
			cout << S1[i] << endl;
		}
		FristLetter = (S1[i] == ' ' ? true : false);
	}
}

int main() {

	/*cout << "Fibonacci Series:" << endl;
	cout << "1   ";
	FibonacciSeries(10);
	*/


	//ReadWordToVector(ReadText("Please enter your string ?"));
	PrintFirstLetterOfEachWord(ReadText("Please enter your string ?"));
}