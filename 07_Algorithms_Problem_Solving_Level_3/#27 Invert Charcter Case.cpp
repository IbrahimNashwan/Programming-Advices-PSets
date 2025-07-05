#include <iostream>
#include <string>
#include <cctype>


using namespace std;

// Reads a single alphabetic character from the user and validates the input.
char ReadCharacter(string Message) {
	string str;
	cout << Message << endl;
	getline(cin,str);

	while (str.length() != 1 || (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))) {
		cout << "Input error, please enter a single letter (a-z or A-Z)." << endl;
		getline(cin, str);
		
	}
	char c = str[0];
	return c;
}
//MySolution
char InvertCharcterCaseMuFunction(char c) {

		if ((c >= 'a' && c <= 'z')) 
			c = c - 32;
		else
			c = c + 32;

	
	return c;
}

//AbuHadhoud Solution
char InvertCharcterCase(char c) {

	return (isupper(c) ? tolower(c):toupper(c));
}

int main() {




	char S1 = ReadCharacter("Please enter a character?");

	//MySolution
	/*cout << "\nCharcter after inverting case:" << endl;
	S1 = InvertCharcterCaseMuFunction(S1);
	cout << S1 << endl;*/



	//AbuHadhoud Solution
	cout << "\nCharcter after inverting case:" << endl;
	S1 = InvertCharcterCase(S1);
	cout << S1 << endl;
	


}