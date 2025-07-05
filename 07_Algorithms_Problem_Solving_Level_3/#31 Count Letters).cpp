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

char ReadCharacter(string Message) {
	string str;
	cout << Message << endl;
	getline(cin, str);

	while (str.length() != 1 || (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))) {
		cout << "Input error, please enter a single letter (a-z or A-Z)." << endl;
		getline(cin, str);

	}
	char c = str[0];
	return c;
}


//MySolution

int CountCharExact(string str, char ch) {

	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch) {
			Counter++;
		}
	}
	return Counter;
}
int CountCharIgnoreCase(string str, char ch) {

	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch) {
			Counter++;
		}
		else if (str[i] == char(ch - 32)) {
			Counter++;
		}
		else if (str[i] == char(ch + 32)) {
			Counter++;
		}
	}
	return Counter;
}


//AbuHadhoud Solution
int CountLetters(string str, char letter,bool MatchCase = true) {

	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (MatchCase) {
			if(str[i] == letter)
			{
				Counter++;
			}
		}
		else {
			if (tolower(str[i]) == tolower(letter)) {
				Counter++;
			}
		}
	}
	return Counter;
}

char InvertCharcterCase(char c) {

	return (isupper(c) ? tolower(c) : toupper(c));
}
int main() {


	cout << " ";


	string str = ReadAlphabeticText("Please enter your string?");
	char ch = ReadCharacter("Please enter a letter or digit to search for in the text:");
	
	//cout << "Letter \'" << ch << "\' Count = " << CountCharExact(str, ch) << endl;

	//cout << "Letter '" << ch << "' Or '" <<  (isupper(ch) ? char(ch + 32) : char(ch - 32)) << "'  Count = " << CountCharIgnoreCase(str, ch) << endl;





	//AbuHadhoud Solution
	cout << "Letter \'" << ch << "\' Count = " << CountLetters(str, ch) << endl;

	cout << "Letter '" << ch << "' Or '" << InvertCharcterCase(ch) << "'  Count = " << CountLetters(str, ch,false) << endl;


}