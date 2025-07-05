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
	bool MarkForDelete = false;
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

float ReadFloat(string Message) {
	float number = 0;
	cout << Message;
	cin >> number;


	while (cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Input ,Please enter number only !" << endl;
		cin >> number;
	}
	cin.ignore();
	return number;
}

stClient ReadNewClient() {

	stClient Client;

	cout << "Enter Acount Number?";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode?";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name?";
	getline(cin >> ws, Client.FullName);

	cout << "Enter Phone?";
	getline(cin >> ws, Client.PhoneNumber);

	Client.AcountBalance = ReadFloat("Enter Acount Balance :");

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

	for (stClient Client : vClient)
	{
		PrintClientData(Client);
	}

	cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";


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

bool FindClientByAccountNumber(vector<stClient> vClients,string AccountNumber) {

	for (stClient Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber) {
			PrintClientCard(Client);
			return true;
		}
	}
	cout << "\nClients with account number " << AccountNumber << " NOT found.  \n\n";
	return false;
}

void LoadAllClientsAfterDelete(string FileName, vector<string> sLineClients) {

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (string ClientLine : sLineClients)
		{
			MyFile << ClientLine << endl;
		}
		MyFile.close();
	}
}

vector<string> DeleteClientByAccountNumber(vector<stClient>& vClients, string AccountNumber) {

	vector<string> sLineClients;
	for (stClient Client : vClients)
	{
		if (Client.AccountNumber!= AccountNumber) {
			string Line = "";
			Line = ConvertRecordToLine(Client);
			sLineClients.push_back(Line);
		}
	}
	return sLineClients;
}

void DeleteClient() {

	vector<string> sLineClients;
	vector<stClient> vClients = LoadAllClientsFromFile(FileName);

	string AccountNumber = ReadTextAndNumber("Please enter account number to search :");

	if (FindClientByAccountNumber(vClients, AccountNumber)) {

	char c = ReadCharacter("Are you sure you want delete this client ? Y/N ?");
	if(toupper(c) == 'Y')
	{
		sLineClients = DeleteClientByAccountNumber(vClients, AccountNumber);
		LoadAllClientsAfterDelete(FileName, sLineClients);
		cout << "\nClient Deleted Successfully." << endl;
		}
	}
}



void AddDataLineToFile(string FileName, string stDataLine) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

//AbuHadhoud Solution47

void AddNewClient() {
	stClient Client;

	Client = ReadNewClient();
	AddDataLineToFile(FileName, ConvertRecordToLine(Client));
}

void AddClients() {

	char AddMore = 'Y';


	do {
		system("cls");
		cout << "Add New Client :\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully,do you want to add more clients?" << endl;

		AddMore = ReadCharacter("Pleasse enter (Y-y) to continue ?");

	} while (toupper(AddMore) == 'Y');
}

//AbuHadhoud Solution50
bool FindClientByAccountNumber(vector<stClient>& vClients, string AccountNumber, stClient& Client) {

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string FileName,vector<stClient>& vClients) {

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	
	if (MyFile.is_open()) {
		string ClientLine;
		
		for (stClient& C : vClients) {
			
			if (C.MarkForDelete == false) {
				ClientLine = ConvertRecordToLine(C);
				MyFile << ClientLine << endl;
			}
		}

		MyFile.close();
	}
}

void MarkClientByAccountNumber(vector<stClient>& vClients, string AccountNumber) {
	
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber) {
			C.MarkForDelete = true;
			return;
		}
	}
}

bool DeleteClientByAccountNumber2(vector<stClient>& vClients, string AccountNumber) {

	stClient Client;

	if (FindClientByAccountNumber(vClients, AccountNumber, Client)) {

		PrintClientCard(Client);

		char c = ReadCharacter("Are you sure you want delete this client ? Y/N ?");
		if (toupper(c) == 'Y')
		{
			MarkClientByAccountNumber(vClients, AccountNumber);
			SaveClientsDataToFile(FileName, vClients);

			vClients = LoadAllClientsFromFile(FileName);
			cout << "\nClient Deleted Successfully." << endl;
			return true;
		}
	}
	else {
		cout << "\nClients with account number " << AccountNumber << " NOT found.  \n\n";
		return false;
	}
	
	return false ;
}

int main() {
	vector<stClient> vClients = LoadAllClientsFromFile(FileName);

	/*PrintAllClientsData(vClients);
	DeleteClient();
	vClients = LoadAllClientsFromFile(FileName);
	PrintAllClientsData(vClients);*/

	//AbuHadhoud Solution
	//AddClients();
	string AccountNumber = ReadTextAndNumber("Please enter account number to search :");

	DeleteClientByAccountNumber2(vClients, AccountNumber);

	system("pause>0");
	return 0;

}