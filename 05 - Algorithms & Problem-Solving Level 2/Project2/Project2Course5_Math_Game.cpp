#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Enum for question difficulty levels
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3,Mix = 4};

// Enum for operation types
enum enOperationType { Add = 1,Sub = 2, Mul = 3,Div = 4,Mix2 = 5 };

// Structure to store math question components
struct stMathComponents {
	int NumberOne = 0 ;
	int NumberTwo = 0;
	char OT;
	enOperationType OType ;
};

// Structure to store full math game information
struct stMathInfo {

	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;

};

// Reads a single character from user input
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

// Asks the user for how many questions to answer (1–100)
int ReadHowManyQuestions()
{
	short HowManyQuestions;
	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> HowManyQuestions;

	} while (HowManyQuestions < 1 || HowManyQuestions > 100);

	return HowManyQuestions;
}

// Reads the desired question level from user
enQuestionLevel ReadQuestionLevel() {
	short Choice = 1;

	do {
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix  ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 4);

	return (enQuestionLevel)Choice;
}

// Reads the desired operation type from user
enOperationType ReadOperationType() {
	short Choice = 1;

	do {
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix  ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 5);

	return (enOperationType)Choice;
}

// Returns a random number between From and To (inclusive)
int RandomNumber(int From, int To) {
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

// Generates numbers randomly based on mixed difficulty
stMathComponents MixQuestions(stMathComponents& MathInsredients) {

	

	enQuestionLevel Number =(enQuestionLevel) RandomNumber(1, 3);

	switch (Number) 
	{
	case enQuestionLevel::Easy:
		MathInsredients.NumberOne = RandomNumber(1, 10);
		MathInsredients.NumberTwo = RandomNumber(1, 10);
		return MathInsredients;
		break;

	case enQuestionLevel::Med:
		MathInsredients.NumberOne = RandomNumber(1, 50);
		MathInsredients.NumberTwo = RandomNumber(1, 50);
		return MathInsredients;
		break;

	case enQuestionLevel::Hard:
		MathInsredients.NumberOne = RandomNumber(1, 100);
		MathInsredients.NumberTwo = RandomNumber(1, 100);
		return MathInsredients;
		break;

	default:
		MathInsredients.NumberOne = RandomNumber(1, 10);
		MathInsredients.NumberTwo = RandomNumber(1, 10);
		return MathInsredients;
		break;
	}

}

// Generates numbers based on selected difficulty
stMathComponents DefineQuestionLevel(enQuestionLevel QuestionLevel,stMathComponents& MathInsredients)
{
	
	

		switch (QuestionLevel)
		{
		case Easy:
			MathInsredients.NumberOne = RandomNumber(1, 10);
			MathInsredients.NumberTwo = RandomNumber(1, 10);
			return MathInsredients;
		case Med:
			MathInsredients.NumberOne = RandomNumber(1, 50);
			MathInsredients.NumberTwo = RandomNumber(1, 50);
			return MathInsredients;

		
		case Hard:
			MathInsredients.NumberOne = RandomNumber(1, 100);
			MathInsredients.NumberTwo = RandomNumber(1, 100); 
			return MathInsredients;


		default:
			return MixQuestions(MathInsredients);
		}
	
		return MathInsredients;

}

// Selects a random operation type
stMathComponents MixOperationType(stMathComponents &MathInsredients) {

	

	enOperationType OT = (enOperationType)RandomNumber(1, 4);

	switch (OT)
	{
	case Add:
		MathInsredients.OT = '+';
		return MathInsredients;
		break;
	case Sub:
		MathInsredients.OT = '-';
		return MathInsredients;
		break;

	case Mul:
		MathInsredients.OT = '*';
		return MathInsredients;
		break;

	case Div:
		MathInsredients.OT = '/';
		return MathInsredients;
		break;

	}
	return MathInsredients;
}

// Sets operation symbol based on selected operation type
stMathComponents DefineOperationType(enOperationType OperationType,stMathComponents MathInsredients)
{

	
	switch (OperationType)
	{
	case enOperationType::Add:
		MathInsredients.OT = '+';
		return MathInsredients;
		

	case enOperationType::Sub:
		MathInsredients.OT = '-';
		return MathInsredients;


	case enOperationType::Mul:
		MathInsredients.OT = '*';
		return MathInsredients;
	

	case enOperationType::Div:
		MathInsredients.OT = '/';
		return MathInsredients;

	default:
		return MixOperationType(MathInsredients);
	}

}

// Calculates the result of the operation
int GetResults(int NumberOne, int NumberTwo, char OT) {

	switch (OT)
	{
	case '+' :
		return NumberOne + NumberTwo;

	case '-':
		return NumberOne - NumberTwo;

	case '*':
		return NumberOne * NumberTwo;

	case '/':
		if (NumberOne < NumberTwo)
			return 0;
		else
			return NumberOne / NumberTwo;
		
	}
	return 0;
}

// Asks the user to solve the question and checks correctness
bool QuestionsResult(stMathComponents MathInsredients)
{
	int Results = 0;
	cout << "\n"<< MathInsredients.NumberOne << endl;
	cout << MathInsredients.NumberTwo << " " << MathInsredients.OT << endl;
	cout << "--------------" << endl;
	cin >> Results;
	
	if (Results == GetResults(MathInsredients.NumberOne, MathInsredients.NumberTwo, MathInsredients.OT)) {
		cout << "Right Answers :-) ." << endl << endl << endl;
		system("color 2F");
		return true;
	}
	else
	{
		cout << "Wrong Answers :-( ." <<endl;
		cout << "The Right Answers is: " << GetResults(MathInsredients.NumberOne, MathInsredients.NumberTwo, MathInsredients.OT) << endl << endl << endl;
		system("color 4F");
			return false;
	}
	return 0;
	//SetWinnerScreenColor(RoundInfo.Winner);
}

// Displays if the player passed or failed
void PrintPassOrFial(short NumberOfRightAnswers,short NumberOfWrongAnswers) {

		cout << "\n-------------------------------------\n";
	if(NumberOfRightAnswers > NumberOfWrongAnswers)
	{
		cout << "Final Results is Pass";
		system("color 2F");
	}
	else
	{
		cout << "Final Results is Fial";
		system("color 4F");
		cout << "\a";
		cout << "\n-------------------------------------\n";
	}
}

// Main game logic – runs the question loop
stMathInfo PlayGameMath(short HowManyQuestions)
{
	stMathInfo MathInfo;
	stMathComponents MathInsredients;

	MathInfo.NumberOfQuestions = HowManyQuestions;
	MathInfo.QuestionLevel = ReadQuestionLevel();
	MathInfo.OperationType = ReadOperationType();

	for (short QustionNumber = 1; QustionNumber <= HowManyQuestions; QustionNumber++)
	{
		cout << "Qustion  [" << QustionNumber <<"/" << HowManyQuestions << "] : " << endl;
		MathInsredients = DefineQuestionLevel(MathInfo.QuestionLevel,MathInsredients);
		MathInsredients = DefineOperationType(MathInfo.OperationType, MathInsredients);
		

		if (QuestionsResult(MathInsredients))
			MathInfo.NumberOfRightAnswers++;
		else
			MathInfo.NumberOfWrongAnswers++;
	}

	PrintPassOrFial(MathInfo.NumberOfRightAnswers, MathInfo.NumberOfWrongAnswers);
	return MathInfo;
}

// Converts operation enum to string
string ChoiceOpType(enOperationType ChoiceOpType)

{
	string arrChoiceOptype[5] = { "Add","Sub","Mul","Div" ,"Mix" };

	return arrChoiceOptype[ChoiceOpType - 1];
}

// Converts level enum to string
string ChoiceLevel(enQuestionLevel ChoiceLevel)

{
	string arrChoiceLevel[4] = { "Easy","Med","Hard","Mix"};

	return arrChoiceLevel[ChoiceLevel - 1];
}

// Displays final game results
void PrintFinalResultsMath(stMathInfo MathInfo) {

	cout << "\nNumber of Qustions   : " << MathInfo.NumberOfQuestions << endl;
	cout << "Qustions Level         : " << ChoiceLevel(MathInfo.QuestionLevel) << endl;
	cout << "OpType                 : " << ChoiceOpType(MathInfo.OperationType) << endl;
	cout << "Number of Right Answers: " << MathInfo.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << MathInfo.NumberOfWrongAnswers << endl;
	cout << "\n-------------------------------------\n";

}

// Prints the game title
void NameOfGame() {
	system("cls");
	system("color 0F");

	cout << "==========================" << endl;
	cout << "       Math Game\n";
	cout << "==========================\n" << endl;

}

// Starts the game and allows replay
void StartPlayWithMath() 
{
	char PlayAgain = 'Y';

	do {
		NameOfGame();
		stMathInfo MathInfo = PlayGameMath(ReadHowManyQuestions());
		PrintFinalResultsMath(MathInfo);
		
		cout << "Do you want yo play again ?  Y/N";
		PlayAgain = ReadCharacter("Do you want yo play again ?  Y/N");
	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}
                                                                                                   
// Main function – program entry point
int main() {
	srand((unsigned)time(NULL));// Seed for random numbers

	StartPlayWithMath();// Launch the game
}
