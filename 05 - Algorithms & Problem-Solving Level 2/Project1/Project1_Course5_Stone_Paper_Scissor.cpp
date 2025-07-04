#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enGamePlay { Stone = 1, Papper = 2, Scissor = 3 };

struct stGamePlay {
    string Player1Choice, ComputerChoice, WinnerPlayer;
    int PlayerCounter = 0, ComputerCounter = 0 ,DrawTimes = 0;
}; 

// Reads a number from user within a specific range
int ReadNumberFromTo(int From, int To) {
    int number = 0;
    cout << "Choose between  [" << From << " - " << To << "]?";
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

// Reads a single alphabetic character from the user
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

// Generates a random number between From and To
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

// Displays final game results including winner and scores
void PrintFinnalInfoGAme(stGamePlay GamePlayers, int RoundsLength)
{
    cout << "\n\n\n\t\t\t\t----------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t+++ G a m e   O v e r +++" << endl;
    cout << "\t\t\t\t----------------------------------------------------------------" << endl;
    cout << "\t\t\t\t----------------------- [ Game Results ] -----------------------" << endl;

    cout << "\t\t\t\tGame Rounds         : " << RoundsLength << endl;
    cout << "\t\t\t\tPlayer1 won times   : " << GamePlayers.PlayerCounter << endl;
    cout << "\t\t\t\tComputer won times  : " << GamePlayers.ComputerCounter << endl;
    cout << "\t\t\t\tDraw times          : " << GamePlayers.DrawTimes << endl;
   
    if (GamePlayers.PlayerCounter > GamePlayers.ComputerCounter)
    {
        GamePlayers.WinnerPlayer = "User";
    }
    else if (GamePlayers.PlayerCounter < GamePlayers.ComputerCounter)
    {
        GamePlayers.WinnerPlayer = "Computer";
    }
    else {
        GamePlayers.WinnerPlayer = "No Winner";
    }
    cout << "\t\t\t\tFinal Winner        : " << GamePlayers.WinnerPlayer << endl;
    cout << "\t\t\t\t----------------------------------------------------------------\n\n" << endl;

}

// Displays result of a single round and updates scores
void PrintPlayRounds(stGamePlay& GamePlyers ,int Counter)
{           
    if (GamePlyers.WinnerPlayer == " User ")
    {
        system("color 2F");
    }
    else if (GamePlyers.WinnerPlayer == " Computer ") {
        system("color 4F");
        cout << "\a";
        
    }
    else {
        system("color 0F");
    }


    cout << "------------- Round [" << Counter << "] -------------" << endl;
    cout << "\nPlayer Choice   : " << GamePlyers.Player1Choice;
    cout << "\nComputer Choice : " << GamePlyers.ComputerChoice;
    cout << "\nRound Winner    : " << GamePlyers.WinnerPlayer << endl;
    cout << "\n-------------------------------------" << endl;

   
    if (GamePlyers.WinnerPlayer == " User ")
    {
        GamePlyers.PlayerCounter++;
    }
    else if (GamePlyers.WinnerPlayer == " Computer ")
    {
        GamePlyers.ComputerCounter++;
    }
    else
    {
        GamePlyers.DrawTimes++;

    }
     
}

// Determines the winner of a single round based on player choices
void CheckWinner(stGamePlay& WhoWinner, enGamePlay UserPlayer, enGamePlay ComputerPlayr)
{
    if (UserPlayer == enGamePlay::Papper && ComputerPlayr == enGamePlay::Stone)
    {
        WhoWinner.WinnerPlayer = " User ";
    }
    else if (UserPlayer == enGamePlay::Scissor && ComputerPlayr == enGamePlay::Papper)
    {
        WhoWinner.WinnerPlayer = " User ";
    }
    else if (UserPlayer == enGamePlay::Papper && ComputerPlayr == enGamePlay::Scissor)
    {
        WhoWinner.WinnerPlayer = " Computer ";
    }
    else if (UserPlayer == enGamePlay::Stone && ComputerPlayr == enGamePlay::Papper)
    {
        WhoWinner.WinnerPlayer = " Computer ";
    }
    else if (UserPlayer == enGamePlay::Stone && ComputerPlayr == enGamePlay::Scissor)
    {
        WhoWinner.WinnerPlayer = " User ";
    }
    else if (UserPlayer == enGamePlay::Scissor && ComputerPlayr == enGamePlay::Stone)
    {
        WhoWinner.WinnerPlayer = " Computer ";
    }
   
    else {
        WhoWinner.WinnerPlayer = " No Winner ";
    }

}

// Converts enum choices to string names and checks winner
void FillPlayers(stGamePlay& GamePlers,enGamePlay& UserPlayer, enGamePlay& ComputerPlayr) {
    
    if (UserPlayer == enGamePlay::Stone)
    {
        GamePlers.Player1Choice = "Stone";
    }
    else if (UserPlayer == enGamePlay::Papper) {
        GamePlers.Player1Choice = "Papper";
    }
    else if (UserPlayer == enGamePlay::Scissor) {
        GamePlers.Player1Choice = "Scissor";
    }

    if (ComputerPlayr == enGamePlay::Stone) {
        GamePlers.ComputerChoice = "Stone";

    }
    else if (ComputerPlayr == enGamePlay::Papper) {
        GamePlers.ComputerChoice = "Papper";

    }
    else if (ComputerPlayr == enGamePlay::Scissor) {
        GamePlers.ComputerChoice = "Scissor";

    }

    CheckWinner(GamePlers, UserPlayer, ComputerPlayr);
}

// Handles game rounds: reads input, plays round, and shows result
void ReadPlayRounds(stGamePlay& GamePlers,int& RoundsLength)
{
    int Player1Choice, ComputerChoice;
    for (int i = 0; i < RoundsLength; i++)
    {
        cout << "\nRound [" << i + 1 << "] begins: " << endl;
        cout << "\nYour Choice: [1]:Stone, [2]:Papper, [3]:Scissor ?" << endl;
        Player1Choice = ReadNumberFromTo(1,3);
       
        enGamePlay Gameplayer, GameComputer;
        Gameplayer = (enGamePlay)Player1Choice;

        ComputerChoice = RandomNumber(1, 3);
        GameComputer = (enGamePlay)ComputerChoice;
        FillPlayers(GamePlers, Gameplayer, GameComputer);

        PrintPlayRounds(GamePlers, i + 1);
    }

   

}

// Clears screen and prints game title
void NameOfGame() {
    system("cls");
    cout << "==========================" << endl;
    cout << "Rock Paper Sicissors Game\n";
    cout << "==========================\n" << endl;
}

// Main function to run the game loop
int main() {
    stGamePlay InfoGame;
    int RoundLength;
    char Letter;

    do
    {
        NameOfGame();
        cout << "How Many Rounds do you want to play ?"<< endl;;
        RoundLength = ReadNumberFromTo(1,10);
        ReadPlayRounds(InfoGame, RoundLength);
        PrintFinnalInfoGAme(InfoGame, RoundLength);

        Letter = ReadCharacter("Do you want yo play again ?  Y/N");

        // Reset counters for a new game
        InfoGame.PlayerCounter = 0 ;
        InfoGame.ComputerCounter = 0;
        InfoGame.DrawTimes = 0;
        system("color 0F");

    }while(Letter == 'Y'|| Letter == 'y');
    cout << "Press Any key to go out." << endl;
    system("pause>0");
   

    

}