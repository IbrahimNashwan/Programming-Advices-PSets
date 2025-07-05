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
int CountLettersFunction(string str) {
	int SmallCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			SmallCount++;
		}
	}
	return SmallCount;
}

int CountCapitalLettersFunction(string str) {
	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			Counter++;
		}
	}
	return Counter;
}

//AbuHadhoud Solution
enum enWhatToCount { Capital = 0, Small = 1 ,All = 2 };

int CountLetters(string str, enWhatToCount WhatToCount = All) {

	int Counter = 0;

	if (WhatToCount == enWhatToCount::All) {
		return str.length();
	}
	
	for (int i = 0; i < str.length(); i++)
	{

		if (WhatToCount == enWhatToCount::Capital && isupper(str[i]))
		{
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::Small && islower(str[i]))
		{
			Counter++;
		}
		

	}
	return Counter;
}

int CountSmallLetters(string str) {
	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int CountCapitaletters(string str) {
	int Counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main() {




	string str = ReadAlphabeticText("Please Enter your string?");

	//MySolution
	/*cout << "\nString Length = " << str.length() << endl;
	cout << "Capital Letter Count = " << CountSmallLettersFunction(str) << endl;
	cout << "Small Letters Count = " << CountCapitalLettersFunction(str) << endl;*/




	//AbuHadhoud Solution
	cout << "\nMethod 1:" << endl;
	cout << "String Length = " << str.length() << endl;
	cout << "Capital Letter Count = " << CountCapitaletters(str) << endl;
	cout << "Small Letters Count = " << CountSmallLetters(str) << endl;

	cout << "\nMethod 2:" << endl;
	cout << "String Length = " << CountLetters(str) << endl;
	cout << "Capital Letter Count = " << CountLetters(str,enWhatToCount::Capital) << endl;
	cout << "Small Letters Count = " << CountLetters(str,enWhatToCount::Small) << endl;

}