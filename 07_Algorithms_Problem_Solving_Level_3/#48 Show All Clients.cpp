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

string ConvertRecordToLine(stClient CilentAcounts, string Seperator = "#//#") {
	string sClientRecord = "";

	sClientRecord += CilentAcounts.AccountNumber + Seperator;
	sClientRecord += CilentAcounts.PinCode + Seperator;
	sClientRecord += CilentAcounts.FullName + Seperator;
	sClientRecord += CilentAcounts.PhoneNumber + Seperator;
	sClientRecord += to_string(CilentAcounts.AcountBalance);;

	return sClientRecord;
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

void PrintClientData(stClient Client) {

	cout << setw(10) << "" << "| " << left << setw(16) << Client.AccountNumber
		<< "| " << left << setw(10) << Client.PinCode
		<< "| " << left << setw(25) << Client.FullName
		<< "| " << left << setw(16) << Client.PhoneNumber
		<< "| " << left << setw(15) << Client.AcountBalance
		<< "| " << endl;

}

void PrintAllClientsData(vector<stClient> vClient) {

	cout << "\n" << setw(48) << "" << "Client List (" << vClient.size() << ") Client(s)." << endl << endl;
	cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";
	cout << setw(10) << "" << "| Account Number  | Pin Code  |  Client Name  " << setw(10) << "" << " | Phone           | Account Balance|" << endl;;
	cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";

	for(stClient Client: vClient)
	{
		PrintClientData(Client);
	}

	cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";


}

vector<stClient> LoadAllClientsFromFile(string FileName) {

	vector<stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;
		stClient TempClient;

		while (getline(MyFile,Line)) {
			TempClient = ConvertLineToRecord(Line);
			vClients.push_back(TempClient);
		}
		MyFile.close();
	}
	return vClients;
}

void AddDataLineToFile2(string FileName, string Line) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << Line << endl;


		MyFile.close();
	}
}

void AddNewClient() {
	char AddMore = 'y';
	string sLineClient;
	stClient AddClint;

	do {
		AddClint = ReadNewClient();
		sLineClient = ConvertRecordToLine(AddClint);
		AddDataLineToFile2(FileName, sLineClient);
		cout << "\nClient Added Successfully,do you want to add more clients?" << endl;
		AddMore = ReadCharacter("Pleasse enter (Y-y) to continue ?");


	} while (AddMore == 'Y' || AddMore == 'y');
}
int main() {

	vector<stClient> vClients = LoadAllClientsFromFile(FileName);
	PrintAllClientsData(vClients);
	AddNewClient();

	system("pause>0");

}