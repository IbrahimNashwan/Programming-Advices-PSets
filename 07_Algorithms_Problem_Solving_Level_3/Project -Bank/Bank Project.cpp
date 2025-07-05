#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;
enum enMainMenueOptions { eListCliets = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, TransactionOption = 6, eExit = 7 };
enum enClientData { ePinCode = 1, eName = 2, ePhone = 3, eAcountBalance = 4 };
enum enTransactionMainMenueOptions { eDeposit = 1, eWithdraw = 2, TotalBalance = 3, MainMenue = 4 };

// This structure holds the data of a single client in the bank system.
struct stClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkClientToDelete = false;
};

const string ClientsFile = "ClientsFile.txt";

void ShowMainMenueScreen();
void ShowTransactionMainMenueScreen();

// Checks if a string contains only letters, numbers, and spaces.
bool isAlphaAndNumber(const string& Text) {
	for (char c : Text) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || (c >= '0' && c <= '9')))
			return false;
	}
	return true;
}

// Prompts the user for a string containing both letters and numbers.
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

// Reads an integer within a given range from the user.
int ReadNumberFromTo(int From, int To) {
	int number = 0;
	cout << "Choose What Do you want to do?  [" << From << " to " << To << "]?";
	cin >> number;


	while (number < From || number >To || cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Input ,Please enter number between (" << From << "-" << To << ") only !!!" << endl;
		cin >> number;
	}
	cin.ignore();
	return number;
}

// Reads an integer from the user with validation.
int ReadInteger(string Message) {
	int number = 0;
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

// Reads a float from the user with validation.
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

// Reads a single character from the user.
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

// ============================
// File Handling Functions
// ============================
// Converts a client record to a line suitable for saving to file.
string ConvertRecordToLine(stClients Client, string Seperator = "#//#") {
	string sClientLine = "";

	sClientLine += Client.AccountNumber + Seperator;
	sClientLine += Client.PinCode + Seperator;
	sClientLine += Client.Name + Seperator;
	sClientLine += Client.Phone + Seperator;
	sClientLine += to_string(Client.AccountBalance);

	return sClientLine;
}

// Splits a string line into words using a separator.
vector<string> SplitWords(string Line, string Seperator = "#//#") {

	vector <string> vWords;
	string Word;
	int pos = 0;

	while ((pos = Line.find(Seperator)) != std::string::npos) {

		Word = Line.substr(0, pos);

		if (Word != "") {
			vWords.push_back(Word);
		}
		Line.erase(0, pos + Seperator.length());
	}

	if (Line != "") {
		vWords.push_back(Line);
	}

	return vWords;
}

// Converts a line from file to a client record.
stClients ConvertLineToRecord(string Line) {

	vector <string> vWords = SplitWords(Line);
	stClients Client;

	Client.AccountNumber = vWords.at(0);
	Client.PinCode = vWords.at(1);
	Client.Name = vWords.at(2);
	Client.Phone = vWords.at(3);
	Client.AccountBalance = stod(vWords.at(4));

	return Client;
}

// Loads all client records from the file.
vector <stClients> LoadAllClientsDataFromFile(string ClientsFile) {

	vector <stClients> Clients;

	fstream MyFile;
	MyFile.open(ClientsFile, ios::in);

	if (MyFile.is_open()) {
		string Line;
		stClients Client;

		while ((getline(MyFile, Line)))
		{
			Client = ConvertLineToRecord(Line);
			Clients.push_back(Client);
		}
	}
	MyFile.close();
	return Clients;
}

bool ExistClientInFile(string AccountNumber) {
	vector <stClients>Clients = LoadAllClientsDataFromFile(ClientsFile);
	for (stClients& C : Clients) {

		if (C.AccountNumber == AccountNumber) {
			return true;
		}
	}
	return false;
}

stClients ReadNewClient() {
	stClients Client;

	cout << "Enter AccountNumber ? ";
	getline(cin >> ws, Client.AccountNumber);
	while (ExistClientInFile(Client.AccountNumber)) {

		cout << "Client with [" << Client.AccountNumber << "] Already exists ,Enter another account number ? ";
		getline(cin >> ws, Client.AccountNumber);
	}
	cout << "Enter PinCode ? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin >> ws, Client.Name);

	cout << "Enter Phone ?";
	getline(cin >> ws, Client.Phone);

	cout << "Enter AccountBalance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

// Adds client data to the file.
void AddClientDataToFile(stClients Client) {


	fstream MyFile;
	MyFile.open(ClientsFile, ios::out | ios::app);
	string line;
	if (MyFile.is_open()) {
		line = ConvertRecordToLine(Client);
		MyFile << line << endl;


	}
	MyFile.close();
}

// Adds a new client after checking account number doesn't already exist.
void AddNewClients() {

	char AddMore = 'Y';
	stClients Client;

	cout << "\nAdding New Client:\n\n";

	while (toupper(AddMore) == 'Y')
	{
		Client = ReadNewClient();
		AddClientDataToFile(Client);
		cout << "Client Added Successfully ,Do you want to Add more clients ?";
		cin >> AddMore;
	}

}

void ShowAddClientsScreen() {
	cout << "--------------------------------------------" << endl;
	cout << "\t    Add New Client Screen " << endl;
	cout << "--------------------------------------------" << endl;
	AddNewClients();
}

void PrintClientData(stClients Client) {

	cout << setw(10) << "" << "| " << left << setw(16) << Client.AccountNumber
		<< " | " << left << setw(12) << Client.PinCode
		<< "| " << left << setw(40) << Client.Name
		<< "| " << left << setw(13) << Client.Phone
		<< "| " << left << setw(13) << Client.AccountBalance << "|" << endl;
}

// Prints all client records in a formatted table.
void PrintAllClientData() {

	system("cls");
	vector <stClients> Clients = LoadAllClientsDataFromFile(ClientsFile);

	if (Clients.size() == 0) {
		cout << setw(49) << "" << "There is no Client(s) to display." << endl;
		return;
	}
	else {

	}
	cout << setw(49) << "" << "Clients List (" << Clients.size() << ") Client(s)." << endl;
	cout << setw(10) << "" << "----------------------------------------------------------------------------------------------------------" << endl;;
	cout << setw(10) << "" << "| " << " Account Number  | PinCode     | Client Name                             | Phone        | Balance      |" << endl;
	cout << setw(10) << "" << "----------------------------------------------------------------------------------------------------------" << endl;;

	for (stClients& C : Clients) {
		PrintClientData(C);
	}
	cout << setw(10) << "" << "-----------------------------------------------------------------------------------------------------------" << endl;;

}

// Print client's total balance line for report
void PrintClientsTotalBalance(stClients Client) {

	cout << setw(10) << "" << "| " << left << setw(16) << Client.AccountNumber
		<< "| " << left << setw(35) << Client.Name
		<< "| " << left << setw(20) << Client.AccountBalance << setw(15) << "" << "|"
		<< endl;

}

// Calculate total balance of all clients
int CalulateTotalBalance(vector<stClients> vClients) {
	int TotalBalance = 0;

	for (stClients& Client : vClients)
	{
		TotalBalance += Client.AccountBalance;
	}
	return TotalBalance;
}

// Calculates and prints total balance of all clients.
void PrintTotalBalance() {

	system("cls");
	vector<stClients> vClients = LoadAllClientsDataFromFile(ClientsFile);
	if (vClients.size() == 0) {
		cout << "\n" << setw(48) << "" << "There is no Client(s)." << endl << endl;
		return;
	}
	else
	{
		cout << "\n" << setw(48) << "" << "Client List (" << vClients.size() << ") Client(s)." << endl << endl;
		cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";
		cout << setw(10) << "" << "| Account Number  |  Client Name  " << setw(19) << "" << "  | Account Balance  " << setw(18) << "" << "|" << endl;;
		cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";

		for (stClients& Client : vClients)
		{
			PrintClientsTotalBalance(Client);
		}

		cout << setw(10) << "" << "---------------------------------------------------------------------------------------------\n";
		cout << setw(66) << "" << " Total Balance = " << CalulateTotalBalance(vClients) << "\n";
	}
}

// Pause and return to main menu
void GoBackToMainMenue() {

	cout << "\n\nPress any key to go back to Main Menue ." << endl;
	system("pause>0");
	ShowMainMenueScreen();
}

// Pause and return to transaction main menu
void GoBackToTransactionMainMenu() {

	cout << "Press any key to go back to Main Menue..." << endl;
	system("pause>0");
	ShowTransactionMainMenueScreen();
}

// Display detailed client information card
void PrintClientCard(stClients Client) {
	cout << "\nThe following are the client details :" << endl;
	cout << "_______________________________________" << endl;
	cout << "Account Number  :" << Client.AccountNumber << endl;
	cout << "PinCode         :" << Client.PinCode << endl;
	cout << "Name            :" << Client.Name << endl;
	cout << "Phpne           :" << Client.Phone << endl;
	cout << "Account Balance :" << Client.AccountBalance << endl;
	cout << "_______________________________________" << endl;

}

// Find client by account number and return client info
bool FindClientByAccountNumber(vector<stClients> Clients, string AccountNumber, stClients& Client) {

	for (stClients C : Clients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}

// Check if client exists by account number (overload)
bool FindClientByAccountNumber(vector<stClients>& vClients, string AccountNumber) {

	for (stClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber) {
			return true;
		}
	}
	return false;
}

// Mark client for deletion in the list
bool MarkClientToDelete(vector<stClients>& Clients, string AccountNumber) {

	for (stClients& C : Clients) {

		if (C.AccountNumber == AccountNumber) {
			C.MarkClientToDelete = true;
			return true;
		}
	}
	return false;
}

// Save clients to file excluding marked for deletion
void SaveClientsDataToFile(vector<stClients>& Clients, string ClientsFile) {


	fstream MyFile;
	MyFile.open(ClientsFile, ios::out);
	string line;
	if (MyFile.is_open()) {

		for (stClients& C : Clients)
		{
			if (C.MarkClientToDelete == false)
			{
				line = ConvertRecordToLine(C);
				MyFile << line << endl;
			}
		}


	}
	MyFile.close();
}

// Deletes a client after confirmation and rewrites the file.
bool DeleteClientByAccountNumber(vector<stClients>& Clients, string AccountNumber) {

	stClients Client;

	if (FindClientByAccountNumber(Clients, AccountNumber, Client)) {
		PrintClientCard(Client);

		char c = ReadCharacter("Are you sure you want delete this client ? y/n ?");

		if (toupper(c) == 'Y') {
			MarkClientToDelete(Clients, AccountNumber);
			SaveClientsDataToFile(Clients, ClientsFile);
		}
		cout << "Client Delete Sussessfully." << endl;
		Clients = LoadAllClientsDataFromFile(ClientsFile);
	}
	else {
		cout << "\nCLient with Account Number (" << AccountNumber << ") is Not Found\n";
		return false;
	}

}

// Show delete client screen and start delete process
void ShowDeleteClientsScreen() {
	cout << "--------------------------------------------" << endl;
	cout << "\t    Delete Client Screen " << endl;
	cout << "--------------------------------------------" << endl;
	vector <stClients> Clients = LoadAllClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadTextAndNumber("Please enter account Number? ");

	DeleteClientByAccountNumber(Clients, AccountNumber);
}

// Update specific client data option
void UpdateSpecificDataOfClient(stClients& Client) {
	system("cls");
	cout << "--------------------------------------------------" << endl;;
	cout << "\t\tUpdate Client Screen\n";
	cout << "--------------------------------------------------" << endl;;


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
		getline(cin >> ws, Client.Name);
		break;

	case ePhone:
		cout << "Enter Phone?";
		getline(cin >> ws, Client.Name);
		break;

	case eAcountBalance:
		Client.AccountBalance = ReadFloat("Enter Acount Balance :");
		break;

	}
}

// Update all client data option
void UpdateClientAllData(stClients& Client) {

	system("cls");
	cout << "--------------------------------------------------" << endl;;
	cout << "\t\tUpdate Client Screen\n";
	cout << "--------------------------------------------------" << endl;;

	Client.AccountNumber = Client.AccountNumber;

	cout << "\n\nEnter PinCode?";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name?";
	getline(cin, Client.Name);

	cout << "Enter Phone?";
	getline(cin, Client.Phone);

	Client.AccountBalance = ReadFloat("Enter Acount Balance :");
}

// Choose update method (all data or specific data)
void UpdateClient(stClients& Client) {
	system("cls");
	cout << "--------------------------------------------------" << endl;;
	cout << "\t\tUpdate Client Screen\n";
	cout << "--------------------------------------------------" << endl;;

	cout << "\nChoose update method :\n";
	cout << "1)Update All Data." << endl;
	cout << "2)Update Specific Data." << endl;
	int Chose = ReadNumberFromTo(1, 2);

	if (Chose == 1) {
		UpdateClientAllData(Client);
	}
	if (Chose == 2) {
		UpdateSpecificDataOfClient(Client);
	}
}

// Updates specific or all data of a client by account number.
bool UpdateClientByAccountNumber(vector<stClients>& vClients, string AccountNumber) {

	stClients Client;
	if (FindClientByAccountNumber(vClients, AccountNumber, Client)) {

		PrintClientCard(Client);
		char c = ReadCharacter("Are you sure you want to Update this client ? Y/N ?");
		if (toupper(c) == 'Y')
		{
			for (stClients& C : vClients) {

				if (C.AccountNumber == AccountNumber) {
					UpdateClient(C);
					break;
				}

			}
			cout << "\nClient Updated Successfully." << endl;
			SaveClientsDataToFile(vClients, ClientsFile);
			return true;
		}
	}
	else {
		cout << "\nClient with account number " << AccountNumber << " NOT found.  \n\n";
		return false;
	}
}

// Show update client screen and start update process
void ShowUpdateClientScreen() {


	system("cls");
	cout << "--------------------------------------------------" << endl;;
	cout << "\t\tUpdate Client Screen\n";
	cout << "--------------------------------------------------" << endl;;

	vector<stClients> vClients = LoadAllClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadTextAndNumber("Please enter account number to search :");
	UpdateClientByAccountNumber(vClients, AccountNumber);

}

// Finds a client by account number and prints their card.
void ShowFindClientScreen() {


	cout << "--------------------------------------------------" << endl;
	cout << "\t\Find Client Screen\n";
	cout << "--------------------------------------------------" << endl;
	vector<stClients> vClients = LoadAllClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");
	stClients Client;
	while (!FindClientByAccountNumber(vClients, AccountNumber, Client))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n" << endl;
		AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");

	}
	PrintClientCard(Client);

	GoBackToMainMenue();

}

// Adds the deposit amount to the client balance.
int DepositClient(stClients& Client, int CountNumber) {

	return Client.AccountBalance + CountNumber;
}

// Handles deposit transaction for a client.
bool DepositClients(vector<stClients>& vClients, string AccountNumber) {

	stClients Client;

	for (stClients& C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			PrintClientCard(C);

			int numberDeposit = ReadInteger("Please enter deposit amount ?");
			char c = ReadCharacter("Are you sure you want to perform this trancation ? Y/N ?");
			if (toupper(c) == 'Y')
			{
				C.AccountBalance = DepositClient(C, numberDeposit);
				cout << "Done Successfully new Balance is " << C.AccountBalance << endl;;
				break;
			}
			else {
				return false;
			}
		}

	}
	SaveClientsDataToFile(vClients, ClientsFile);
	return true;
}

// Show deposit screen and process deposit transaction
void ShowDepositScreen() {


	cout << "--------------------------------------------------" << endl;;
	cout << "\t\Deposit Screen\n";
	cout << "--------------------------------------------------" << endl;;
	vector<stClients> vClients = LoadAllClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");
	while (!ExistClientInFile(AccountNumber))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n" << endl;
		AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");

	}

	DepositClients(vClients, AccountNumber);
	GoBackToTransactionMainMenu();

}

// Ensure withdrawal amount does not exceed client balance
int CheckAmount(stClients Client, int Amount) {
	while (Amount > Client.AccountBalance) {
		cout << "Amount exceeds the balance,you can withdraw up to : " << Client.AccountBalance << endl;
		Amount = ReadInteger("Please enter another amount ?");

	}
	return Amount;
}

// Handles withdrawal transaction for a client with balance checking.
bool WithdrawClients(vector<stClients>& vClients, string AccountNumber) {

	stClients Client;

	for (stClients& C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			PrintClientCard(C);

			int Amount = ReadInteger("Please enter amount ?");
			while (Amount > C.AccountBalance)
			{
				cout << "Amount exceeds the balance,you can withdraw up to : " << Client.AccountBalance << endl;
				Amount = ReadInteger("Please enter another amount ?");
			}
			char c = ReadCharacter("Are you sure you want to perform this trancation ? Y/N ?");

			if (toupper(c) == 'Y')
			{
				C.AccountBalance = DepositClient(C, Amount * -1);
				cout << "Done Successfully new Balance is " << C.AccountBalance << endl;;
				break;
			}
			else {
				return false;
			}
		}

	}
	SaveClientsDataToFile(vClients, ClientsFile);
	return true;
}

// Show withdraw screen and handle withdraw transaction
void ShowWithdrawScreen() {


	cout << "--------------------------------------------------" << endl;;
	cout << "\t\Withdraw Screen\n";
	cout << "--------------------------------------------------" << endl;;
	vector<stClients> vClients = LoadAllClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");
	while (!FindClientByAccountNumber(vClients, AccountNumber))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n" << endl;
		AccountNumber = ReadTextAndNumber("Please enter accountNumber ?");

	}

	WithdrawClients(vClients, AccountNumber);
	GoBackToTransactionMainMenu();

}

// Perform action based on transaction menu choice
void PerFormtTransactionMainMenueOptions(enTransactionMainMenueOptions TransactionMainMenue) {

	switch (TransactionMainMenue)
	{
	case enTransactionMainMenueOptions::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionMainMenu();
		break;

	case enTransactionMainMenueOptions::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionMainMenu();
		break;

	case enTransactionMainMenueOptions::TotalBalance:
		system("cls");
		PrintTotalBalance();
		GoBackToTransactionMainMenu();

		break;
	case enTransactionMainMenueOptions::MainMenue:
		ShowMainMenueScreen();

		break;

	}
}

// Display transaction main menu options
void ShowTransactionMainMenueScreen() {

	system("cls");
	cout << "===================================================\n";
	cout << "\t\tTransaction Main Menue Screen\n";
	cout << "===================================================\n";

	cout << setw(10) << "" << "[1] Deposit.\n";
	cout << setw(10) << "" << "[2] Withdraw.\n";
	cout << setw(10) << "" << "[3] Total Balance.\n";
	cout << setw(10) << "" << "[4] Main Menue.\n";
	cout << "===================================================\n";
	PerFormtTransactionMainMenueOptions((enTransactionMainMenueOptions)ReadNumberFromTo(1, 4));
}

// Show program end message and wait for key press
void ShowEndScreen() {


	cout << "\n--------------------------------------------------" << endl;;
	cout << "\t\tPrograms Ends";
	cout << "\n--------------------------------------------------" << endl;;
	system("Pause>0");

}

// Perform action based on main menu choice
void PerFormMainMenueOPtions(enMainMenueOptions MainMenueOptions) {

	switch (MainMenueOptions)
	{
	case eListCliets:
		system("cls");
		PrintAllClientData();
		GoBackToMainMenue();
		break;

	case eAddClient:
		system("cls");
		ShowAddClientsScreen();
		GoBackToMainMenue();
		break;

	case eDeleteClient:
		system("cls");
		ShowDeleteClientsScreen();
		GoBackToMainMenue();
		break;

	case eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;

	case eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();

		break;
	case TransactionOption:
		system("cls");
		ShowTransactionMainMenueScreen();
		GoBackToTransactionMainMenu();
		break;
	case eExit:
		system("cls");
		ShowEndScreen();
		return;

	}
}

// Displays and handles the Main Menu logic.
void ShowMainMenueScreen() {
	system("cls");
	cout << "==================================================" << endl;
	cout << "\t\tMain Menue Screen " << endl;
	cout << "==================================================" << endl;
	cout << "\t[1] Show Client List." << endl;
	cout << "\t[2] Add New Clients." << endl;
	cout << "\t[3] Delete Client." << endl;
	cout << "\t[4] Update Client Info." << endl;
	cout << "\t[5] Find Client." << endl;
	cout << "\t[6] Trancactions." << endl;
	cout << "\t[7] Exit." << endl;
	cout << "==================================================" << endl;

	int Choose = ReadNumberFromTo(1, 7);
	PerFormMainMenueOPtions((enMainMenueOptions)Choose);

}

int main() {
	ShowMainMenueScreen();
}