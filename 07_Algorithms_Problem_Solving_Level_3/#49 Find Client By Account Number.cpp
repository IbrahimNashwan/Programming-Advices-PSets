#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
struct stClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string PhoneNumber;
	double AcountBalance;
};
const string FileName = "MyFile.txt";


bool isAlphaAndNumber(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || (c >= '0' && c <= '9')))
			return false;
	}
	return true;
}



string ReadTextAndNumber(string prompt) {
	string NumToStr;
	string text;

	do {
		cout << prompt << endl;
		getline(cin, text);

		if (!isAlphaAndNumber(text)) {
			cout << "Invalid input! Please enter Text And Number only." << endl;
			getline(cin, text);

		}

	} while (!isAlphaAndNumber(text));

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

stClient ConvertLineToRecord(string CilentAcounts, string Seperator = "#//#") {
	vector <string> vClientRecord = SplitWords(CilentAcounts, Seperator);
	stClient Client;

	Client.AccountNumber = vClientRecord.at(0);
	Client.PinCode = vClientRecord.at(1);
	Client.FullName = vClientRecord.at(2);
	Client.PhoneNumber = vClientRecord.at(3);
	Client.AcountBalance = stod(vClientRecord.at(4));

	return Client;

}




vector<stClient> LoadAllClientsFromFile(string FileName) {

	vector<stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;
		stClient TempClient;

		while (getline(MyFile, Line)) {
			TempClient = ConvertLineToRecord(Line);
			vClients.push_back(TempClient);
		}
		MyFile.close();
	}
	return vClients;
}


void PrintClientCard(stClient Client) { 
	cout << "\nThe following are the client details: \n\n";
	cout << "Account Number :" << Client.AccountNumber << endl;;
	cout << "Pin Code       :" << Client.PinCode << endl;
	cout << "Name           :" << Client.FullName << endl;
	cout << "Phone          :" << Client.PhoneNumber << endl;
	cout << "Account Balance:" << Client.AcountBalance << endl;
}

void FindClientByAccountNumber(vector<stClient> vClients) {
	string AccountNumber = ReadTextAndNumber("Please enter account number to search :");

	for (stClient Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber) {
			PrintClientCard(Client);
			return;
		}
	}
	cout << "\nClients with account number " << AccountNumber <<" NOT found.  \n\n";


}
int main() {

	vector<stClient> vClients = LoadAllClientsFromFile(FileName);
	FindClientByAccountNumber(vClients);
	system("pause>0");
	
}