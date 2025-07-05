#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct stClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string PhoneNumber;
	double AcountBalance;
};


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

stClient ConvertLineToRecord(string CilentAcounts,string Seperator = "#//#") {
	vector<string> vClientRecord = SplitWords(CilentAcounts,Seperator);
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
int main() {

	string ClientLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#0775105358#//#5463.0000000";
	cout << "Line Record is :" << endl;
	cout << ClientLine << endl;

	stClient Client = ConvertLineToRecord(ClientLine);
	PrintClientData(Client);
	system("pause>0");

}