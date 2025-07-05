#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

enum enClientData { ePinCode = 1, eName = 2, ePhone = 3, eAcountBalance = 4 };

struct stClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string PhoneNumber;
	double AcountBalance;
	bool MarkForDelete = false;

};
const string ClientsFileName = "ClientsFile.txt";


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

int ReadNumberFromTo(int From, int To) {
	int number = 0;
	cout << "Please enter number between (" << From << "-" << To << ") !?";
	cin >> number;


	while (number < From || number >To || cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Input ,Please enter number between (" << From << "-" << To << ") only " << endl;
		cin >> number;
	}
	cin.ignore();
	return number;
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

string ConvertRecordToLine(stClient CilentAcounts, string Seperator = "#//#") {
	string sClientRecord = "";

	sClientRecord += CilentAcounts.AccountNumber + Seperator;
	sClientRecord += CilentAcounts.PinCode + Seperator;
	sClientRecord += CilentAcounts.FullName + Seperator;
	sClientRecord += CilentAcounts.PhoneNumber + Seperator;
	sClientRecord += to_string(CilentAcounts.AcountBalance);;

	return sClientRecord;
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

void PrintClientCard(stClient& Client) {
	cout << "\nThe following are the client details: \n\n";
	cout << "Account Number :" << Client.AccountNumber << endl;;
	cout << "Pin Code       :" << Client.PinCode << endl;
	cout << "Name           :" << Client.FullName << endl;
	cout << "Phone          :" << Client.PhoneNumber << endl;
	cout << "Account Balance:" << Client.AcountBalance << endl;
}

void AddDataLineToFile(string ClientsFileName, string stDataLine) {

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

//AbuHadhoud Solution47

void AddNewClient() {
	stClient Client;

	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
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



void SaveClientsDataToFile(vector<stClient>& vClients, string AccountNumber, stClient Client) {

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::out);


	if (MyFile.is_open()) {
		string ClientLine;

		for (stClient& C : vClients) {

			if (C.AccountNumber == AccountNumber) {
				C = Client;
				ClientLine = ConvertRecordToLine(C);
				MyFile << ClientLine << endl;
			}
			else{
				ClientLine = ConvertRecordToLine(C);
				MyFile << ClientLine << endl;
			}
		}

		MyFile.close();
	}
}

void EditSpecificDataOfClient(stClient& Client) {


	cout << ")Choose one  to update specific data :\n\n";
	cout << "1) PinCode" << endl;
	cout << "2) Name" << endl;
	cout << "3) Phone" << endl;
	cout << "4) AcountBalance" << endl;
	Client.AccountNumber = Client.AccountNumber;
	int Chose = ReadNumberFromTo(1, 4);

	enClientData ClientData = (enClientData)Chose;
	switch (ClientData)
	{
	case ePinCode:
		cout << "Enter PinCode?";
		getline(cin >> ws, Client.PinCode);
		break;

	case eName:
		cout << "Enter Name?";
		getline(cin >> ws, Client.FullName);
		break;

	case ePhone:
		cout << "Enter Phone?";
		getline(cin >> ws, Client.PhoneNumber);
		break;

	case eAcountBalance:
		Client.AcountBalance = ReadFloat("Enter Acount Balance :");
		break;

	}
}

void EditClientAllData(stClient& Client) {

	Client.AccountNumber = Client.AccountNumber;

	cout << "\n\nEnter PinCode?";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name?";
	getline(cin, Client.FullName);

	cout << "Enter Phone?";
	getline(cin , Client.PhoneNumber);

	Client.AcountBalance = ReadFloat("Enter Acount Balance :");
}

void EditClient(stClient& Client) {

	cout << "\n\nChoose update method :\n\n";
	cout << "1)Update All Data." << endl;
	cout << "2)Update Specific Data." << endl;
	int Chose = ReadNumberFromTo(1, 2);

	if (Chose == 1) {
		EditClientAllData(Client);
	}
	if (Chose == 2) {
		EditSpecificDataOfClient(Client);
	}
}



bool UpdateClientByAccountNumber(vector<stClient>& vClients, string AccountNumber) {

	stClient Client;
	for (stClient& C : vClients)
	{
		if (FindClientByAccountNumber(vClients, AccountNumber, Client)) {

			PrintClientCard(Client);

			char c = ReadCharacter("Are you sure you want to Update this client ? Y/N ?");
			if (toupper(c) == 'Y')
			{
				EditClient(Client);
				SaveClientsDataToFile(vClients, AccountNumber, Client);

				vClients = LoadAllClientsFromFile(ClientsFileName);
				cout << "\nClient Updated Successfully." << endl;
				return true;
			}
			else {
				break;
			}
		}
		else {
			cout << "\nClient with account number " << AccountNumber << " NOT found.  \n\n";
			return false;
		}
	}
	return false;
}




//AbuHadhoud Solution51
bool FindClientByAccountNumber2(vector<stClient>& vClients, string AccountNumber,stClient& Client) {

	for (stClient& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}
void SaveClientsDataToFile2(string ClientsFileName, vector<stClient>& vClients, bool MarkForDelete = false) {

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::out);

	if (MyFile.is_open()) {
		string sClientDataLine;

		for (stClient& C : vClients) {

			if (C.MarkForDelete == false) {
				sClientDataLine = ConvertRecordToLine(C);
				MyFile << sClientDataLine << endl;
			}
		}
		MyFile.close();
	}
}


bool UpdateClientByAccountNumber2(vector<stClient>& vClients, string AccountNumber) {

	stClient Client;
	if (FindClientByAccountNumber2(vClients, AccountNumber, Client)) {

		PrintClientCard(Client);
		char c = ReadCharacter("Are you sure you want to Update this client ? Y/N ?");
		if (toupper(c) == 'Y')
		{
			for (stClient& C : vClients) {

				if (C.AccountNumber == AccountNumber) {
					EditClient(C);
					break;
				}

			}
			cout << "\nClient Updated Successfully." << endl;
			SaveClientsDataToFile2(ClientsFileName, vClients);
			return true;
		}
	}
	else {
		cout << "\nClient with account number " << AccountNumber << " NOT found.  \n\n";
		return false;
	}

}
int main() {
	//AddClients();
	vector<stClient> vClients = LoadAllClientsFromFile(ClientsFileName);
	string AccountNumber = ReadTextAndNumber("Please enter account number to search :");

	UpdateClientByAccountNumber(vClients, AccountNumber);
	system("pause>0");

}