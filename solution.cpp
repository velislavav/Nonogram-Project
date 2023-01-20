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

			cout << task << '\n';
			taskFile.get();
		}
		taskFile.close();
	}
}

void checkSolution(string solutionFile, bool &levelIsFinished) {
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
				cout << "Wrong answer, you have " << leftMistakes - mistakes << " more chances.\nThe true answer is: " << solution << endl;
			}

			if (solFile.eof())
			{
				levelIsFinished = true;
				cout << "You finished this level.\nContinue with next one.\n";

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

void mySolution(int level, int version, bool &levelIsFinished) {
	string solutionFile = "";

	switch (level) {
	case 1:
		switch (version) {
		case 1:
			solutionFile = "sol1.1.txt";
			checkSolution(solutionFile, levelIsFinished);
			break;
		case 2:

			break;
		}
		break;
	case 2:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 3:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 4:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 5:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	}
}


void chooseLevel(int level, int version, bool &levelIsFinished) {
	string inputFile = "";


	switch (level) {
	case 1:
		switch (version) {
		case 1:
			inputFile = "L1_V1.txt";
			printTask(inputFile);
			mySolution(level, version, levelIsFinished);
			break;
		case 2:
			inputFile = "L1_V2.txt";
			printTask(inputFile);
			break;
		}
		break;
	case 2:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 3:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 4:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	case 5:
		switch (version) {
		case 1:
			break;
		case 2:
			break;
		}
		break;
	}
}

void playTheGame(bool &gameOver, bool &levelIsFinished) {
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
			
			chooseLevel(level, version, levelIsFinished);

			if (levelIsFinished == true)
			{
				if (level < MAX_LEVELS)
				{
					level++;
					cout << "Next level is: " << level << ". If you want to continue enter 1, else enter 0.\n";
					versionIsChosen = false;
					levelIsFinished = false;
					cin >> yesOrNo;
					if (yesOrNo == 0) {
						gameOver = true;
					}
				}
				else {
					cout << "No more levels.\nGame finished!\n";
					gameOver = true;
				}

			}
			/*
			else
			{
				cout << "Do you want to try again?\nIf yes enter 1, else enter 0.\n";
				cin >>
			}
			*/
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
	bool levelIsFinished = false;

	playTheGame(gameOver, levelIsFinished);

	if (gameOver == true)
	{
		gameOver = false;
		playTheGame(gameOver, levelIsFinished);
	}
}