#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct stClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string PhoneNumber;
	double AcountBalance;
};

const string FileName = "MyFile.txt";

//MySolution

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

char ReadCharacter(string Message) {
	string str;
	cout << Message << endl;
	getline(cin >>ws, str);

	while (str.length() != 1 || (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))) {
		cout << "Input error, please enter a single letter (a-z or A-Z)." << endl;
		getline(cin, str);

	}
	char c = str[0];
	return c;
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
	vector<string> vClientRecord = SplitWords(CilentAcounts, Seperator);
	stClient Client;

	Client.AccountNumber = vClientRecord.at(0);
	Client.PinCode = vClientRecord.at(1);
	Client.FullName = vClientRecord.at(2);
	Client.PhoneNumber = vClientRecord.at(3);
	Client.AcountBalance = stod(vClientRecord.at(4));

	return Client;

}

void PrintClientData(stClient Client) {
	cout << "\nThe Following is the extracted client record :\n\n";

	cout << "Account Number :" << Client.AccountNumber << endl;;
	cout << "Pin Code       :" << Client.PinCode << endl;
	cout << "Name           :" << Client.FullName << endl;
	cout << "Phone          :" << Client.PhoneNumber << endl;
	cout << "Account Balance:" << Client.AcountBalance << endl;
}

void AddDataLineToFile2(string FileName ,string Line) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << Line << endl;


		MyFile.close();
	}
}

void AddNewClient1() {
	char AddMore = 'y';
	string sLineClient;
	stClient Client;

	do{
		Client = ReadNewClient();
		sLineClient = ConvertRecordToLine(Client);
		AddDataLineToFile2(FileName, sLineClient);
		AddMore = ReadCharacter("Pleasse enter (Y-y) to continue ?");


	}while (AddMore == 'Y' || AddMore == 'y');
}



void AddDataLineToFile(string FileName, string stDataLine) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}


//AbuHadhoud Solution
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
int main() {

	
	AddClients();
	system("pause>0");

}