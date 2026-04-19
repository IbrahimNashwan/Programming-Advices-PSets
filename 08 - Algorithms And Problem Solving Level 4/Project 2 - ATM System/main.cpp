#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

sClient CurrentClient;

enum enATMMenueOptions { eQWithdraw = 1, eNWithdraw = 2, Deposite = 3, eCheckBalance = 4, Logout = 5 };

enum enManageUsersMenueOptions {
    eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
    eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
};

enum enMainMenueOptions {
    eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
    eManageUsers = 7, eExit = 8
};

enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};

const string ClientsFileName = "Clients.txt";

void ShowATMSystemMainMenue();
void Login();

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

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

void GoBackToATMMainMenue() {

    cout << "\n\nPress any key to go back to ATM System Main Menue...";
    system("pause>0");
    ShowATMSystemMainMenue();
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient>& vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient &C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";

}


bool DepositBalanceToClientByAccountNumber(string &AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                CurrentClient.AccountBalance = C.AccountBalance;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                

                return true;
            }

        }


        return false;
    }

}


void QuickWithdraw(double Amount) {

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    while (Amount > CurrentClient.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << CurrentClient.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount * -1, vClients);
    cout << "\n\nDone Successfully. New balance is: " << CurrentClient.AccountBalance;
}


void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";


    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    PrintClientCard(CurrentClient);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount, vClients);
    cout << "\n\nDone Successfully. New balance is: " << CurrentClient.AccountBalance;


}
void PerfromQuickWithdrawOption(short Choice )
{
    switch (Choice)
    {
    case 1:
        QuickWithdraw(20);
        break;
    
    case 2:
        
        QuickWithdraw(50);
        break;

    case 3:
        QuickWithdraw(100);
        break;

    case 4:
        QuickWithdraw(200);
        break;
    case 5:
        QuickWithdraw(400);
        break; 
    case 6:
        QuickWithdraw(600);
        break; 
    case 7:
        QuickWithdraw(800);
        break; 
    case 8:
        QuickWithdraw(1000);
        break;

    case 9:
        GoBackToATMMainMenue();
        //Login();
        break;
    }

}

void ShowQuickWithdraw() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit.\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
    int Choose = ReadNumberFromTo(1, 9);
    PerfromQuickWithdrawOption(Choose);
    

}

int ReadNormalWithdraw() {
    
    int Number;
    cout << "\nEnter an amount Muliple of 5's ?";
    cin >> Number;
   
    return Number;
}
void ShowNormalWithdraw() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\Normal Withdraw\n";
    cout << "===========================================\n";

    int Choose = 0;
    do {
        Choose = ReadNormalWithdraw();
    } while ((Choose % 5) != 0);

        QuickWithdraw(Choose);


}


void ShowCheckBalanceScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\t Check Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl << endl;;
    GoBackToATMMainMenue();

}

void PerfromATMMainMenueOption(enATMMenueOptions ATMMenueOptions)
{
    switch (ATMMenueOptions)
    {
    case enATMMenueOptions::eQWithdraw:
    {
        system("cls");
        ShowQuickWithdraw();
        GoBackToATMMainMenue();
        break;
    }
    case enATMMenueOptions::eNWithdraw:
        system("cls");
        ShowNormalWithdraw();
        GoBackToATMMainMenue();
        break;

    case enATMMenueOptions::Deposite:
        system("cls");
        ShowDepositScreen();
        GoBackToATMMainMenue();
        break;

    case enATMMenueOptions::eCheckBalance:
        ShowCheckBalanceScreen();       
        ShowATMSystemMainMenue();
        break;

    case enATMMenueOptions::Logout:
        system("cls");
        // ShowEndScreen();
        Login();

        break;
    }

}

void ShowATMSystemMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposite.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";

    int Choose = ReadNumberFromTo(1, 8);
    PerfromATMMainMenueOption((enATMMenueOptions)Choose);
}

bool  LoadClientInfo(string AccountNumber, string PinCode)
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);;
    if (FindClientByAccountNumber(AccountNumber, vClients, CurrentClient))
        return true;
    else
        return false;

}

void Login()
{
    bool LoginFaild = false;

    string AccountNumber, PinCode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter Password? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowATMSystemMainMenue();

}

int main() {
    Login();
}