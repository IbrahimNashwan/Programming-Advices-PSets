#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct stClient{
	string AccountNumber;
	string PinCode;
	string FullName;
	string PhoneNumber;
	double AcountBalance;
};

bool isAlphaOnly(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || ispunct(c)))
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
stClient ReadNewClient() {

	stClient Client;
	cout << "Please Enter Client Data :\n\n";

	cout << "Enter Acount Number?";
	getline(cin, Client.AccountNumber);

	cout << "Enter PinCode?";
	getline(cin, Client.PinCode);

	cout << "Enter Name?";
	getline(cin, Client.FullName);

	cout << "Enter Phone?";
	getline(cin, Client.PhoneNumber);

	cout << "Enter Acount Balance:";
	cin >> Client.AcountBalance;

	return Client;
}
string ConvertRecordToLine(stClient CilentAcounts, string Seperator = "#//#") {
	string sClientRecord = "";

	sClientRecord += CilentAcounts.AccountNumber + Seperator;
	sClientRecord += CilentAcounts.PinCode + Seperator;
	sClientRecord += CilentAcounts.FullName + Seperator;
	sClientRecord += CilentAcounts.PhoneNumber + Seperator;
	sClientRecord += to_string(CilentAcounts.AcountBalance);;

	return sClientRecord;
}
int main() {

	stClient Client = ReadNewClient();

	cout << "\nClient Record for Saving is :" << endl;
	cout << ConvertRecordToLine(Client, "#//#") << endl;
	system("pause>0");

}