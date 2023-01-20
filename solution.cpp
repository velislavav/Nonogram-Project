#include <iostream>
#include <fstream>
using namespace std;
const int MAX_MISTAKES = 3;
const int MAX_LEVELS = 5;

void printTask(string inputFile) {
	ifstream taskFile(inputFile, ios::in);
	char task[1024];
	//taskFile.open(inputFile);

	if (!taskFile)
	{
		cout << "Error! Failed to open task\n";
	}
	else
	{
		cout << "Your task is:\n";
		while (taskFile.getline(task, 1024, '\n'))
		{

			cout << task << endl;
			taskFile.get();
		}
		taskFile.close();
	}
}

void checkSolution(string solutionFile, bool &levelIsFinished, bool &lostGame) {
	ifstream solFile(solutionFile, ios::in);
	char solution[1024];
	//char trueAnswer[1024];
	char temp[1024];
	int mistakes = 0;
	int leftMistakes = MAX_MISTAKES;

	if (!solFile)
	{
		cout << "Error! Failed to check the answer\n";
	}
	else
	{
		cout << "For 'full' enter '#' and for empty enter '.' !\n";
		while (solFile.getline(solution, 1024, '\n') )
		{
			cin >> temp;
			if (strcmp(solution, temp) == 0)
			{
				if (!solFile.eof())
				{
					cout << "True answer, keep playing!\n";
				}
			}
			else
			{
				mistakes++;
				leftMistakes--;
				cout << "Wrong answer, you have " << leftMistakes<< " more chances.\nThe true answer is: " << solution << endl;
				if (leftMistakes == 0)
				{
					lostGame = true;
					mistakes = 0;
					solFile.close();
					break;
				}
			}

			if (solFile.eof())
			{
				levelIsFinished = true;
				cout << "You finished this level.\n\n";

			}
			else
			{
				cout << "Enter next one.\n";
			}
			solFile.get();
		}
		solFile.close();
	}
}

void mySolution(int level, int version, bool &levelIsFinished, bool &lostGame) {
	string solutionFile = "";

	switch (level) {
	case 1:
		switch (version) {
		case 1:
			solutionFile = "solutions/sol1.1.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		case 2:
			solutionFile = "solutions/sol1.2.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		}
		break;
	case 2:
		switch (version) {
		case 1:
			solutionFile = "solutions/sol2.1.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		case 2:
			solutionFile = "solutions/sol2.2.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		}
		break;
	case 3:
		switch (version) {
		case 1:
			solutionFile = "solutions/sol3.1.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		case 2:
			solutionFile = "solutions/sol3.2.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		}
		break;
	case 4:
		switch (version) {
		case 1:
			solutionFile = "solutions/sol4.1.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		case 2:
			solutionFile = "solutions/sol4.2.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		}
		break;
	case 5:
		switch (version) {
		case 1:
			solutionFile = "solutions/sol5.1.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		case 2:
			solutionFile = "solutions/sol5.2.txt";
			checkSolution(solutionFile, levelIsFinished, lostGame);
			break;
		}
		break;
	}
}


void chooseLevel(int level, int version, bool &levelIsFinished, bool &lostGame) {
	string inputFile = "";


	switch (level) {
	case 1:
		switch (version) {
		case 1:
			inputFile = "levelsTasks/L1_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		case 2:
			inputFile = "levelsTasks/L1_V2.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		}
		break;
	case 2:
		switch (version) {
		case 1:
			inputFile = "levelsTasks/L2_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		case 2:
			inputFile = "levelsTasks/L2_V2.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		}
		break;
	case 3:
		switch (version) {
		case 1:
			inputFile = "levelsTasks/L3_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		case 2:
			inputFile = "levelsTasks/L3_V2.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		}
		break;
	case 4:
		switch (version) {
		case 1:
			inputFile = "levelsTasks/L4_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		case 2:
			inputFile = "levelsTasks/L4_V2.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		}
		break;
	case 5:
		switch (version) {
		case 1:
			inputFile = "levelsTasks/L5_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		case 2:
			inputFile = "levelsTasks/L5_V2.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished, lostGame);
			break;
		}
		break;
	}
}

void playTheGame(bool &gameOver) {
	cout << "Do you want to start a new game?" << endl << "For yes, enter 1, else enter 0!" << endl;
	int yesOrNo = 0;
	cin >> yesOrNo;

	int level = 0;
	int version = 0;

	if (yesOrNo == 1)
	{
		bool levelIsChosen = false;
		bool versionIsChosen = false;

		if (levelIsChosen == false)
		{
			cout << "Chose a level from 1 to 5!" << endl;
			cin >> level;
			levelIsChosen = true;
		}

		if (versionIsChosen == false)
		{
			cout << "Version 1 or 2?" << endl;
			cin >> version;
			versionIsChosen = true;
		}

		if (levelIsChosen && versionIsChosen)
		{
			bool levelIsFinished = false;
			bool lostGame = false;
			chooseLevel(level, version, levelIsFinished, lostGame);

			if (levelIsFinished == true)
			{
				if (level < MAX_LEVELS)
				{
					level++;
					cout << "Next level is: " << level << ". If you want to continue enter 1, else enter 0.\n";
					versionIsChosen = false;
					levelIsFinished = false;
					cin >> yesOrNo;
					if (yesOrNo == 1) {
						gameOver = true;
					}
				}
				else {
					cout << "No more levels.\nGame finished!\n";
					gameOver = true;
				}

			}
			 if (lostGame == true)
			{
				cout << "Do you want to try again?\nIf yes enter 1, else enter 0.\n";
				versionIsChosen = false;
				levelIsChosen = true;
				cin >> yesOrNo;
				
			}
		}

	}
	else
	{
		gameOver = true;
	}
}


int main() {
	//char username[1024];
	//char reachedLevel[1024];

	bool gameOver = false;
	

	playTheGame(gameOver);

	if (gameOver == true)
	{
		gameOver = false;
		playTheGame(gameOver);
	}
}