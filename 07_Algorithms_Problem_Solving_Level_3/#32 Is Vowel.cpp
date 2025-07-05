#include <iostream>
#include <string>
#include <cctype>


using namespace std;
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
bool IsVowel(char c) {
	c = ((c >= 'A' && c <= 'Z') ? char(c + 32) : c );
	
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}


//AbuHadhoud Solution
bool IsVowelAbuHadhoud(char Ch1) {
	Ch1 = tolower(Ch1);

	return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

int main() {


	cout << " ";


	char ch = ReadCharacter("Please enter a character?");

	/*f (IsVowel(ch))
		cout << "Yes: letter \'" << ch << "\' is vowel." << endl;
	else
		cout << "No: letter \'" << ch << "\' is not vowel." << endl;*/



	//AbuHadhoud Solution
	if (IsVowelAbuHadhoud(ch))
		cout << "Yes: letter \'" << ch << "\' is vowel." << endl;
	else
		cout << "No: letter \'" << ch << "\' is not vowel." << endl;

}