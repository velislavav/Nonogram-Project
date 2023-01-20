/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Velislava Veneva
* @idnumber 5MI0600243 
* @compiler VC
*
* <main file>
*
*/

#include <iostream>
#include <fstream>
using namespace std;
const int MAX_MISTAKES = 3;
const int MAX_LEVELS = 5;


//print the task like a matrix from file
void printTask(string inputFile) {
	ifstream taskFile(inputFile, ios::in);
	char task[1024];

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

//check if the input from the player is the same as the one in the solution
void checkSolution(string solutionFile, bool &levelIsFinished, bool &lostGame) {
	ifstream solFile(solutionFile, ios::in);
	char solution[1024];
	char temp[1024];
	int mistakes = 0;
	int leftMistakes = MAX_MISTAKES;

	if (!solFile)
	{
		cout << "Error! Failed to check the answer\n";
	}
	else
	{
		//the player enters for every empty box 'full' or 'empty'
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


//choosing the file with the correct solution for the chosen level and version
void mySolution(int level, int version, bool &levelIsFinished, bool &lostGame) {
	string solutionFile = "solutions/solx.x.txt";
	solutionFile[13] = level + '0';
	solutionFile[15] = version + '0';
	checkSolution(solutionFile, levelIsFinished, lostGame);

	
}

//choosing the file with the task for the chosen level and version
void chooseLevel(int level, int version, bool &levelIsFinished, bool &lostGame) {
	string inputFile = "levelsTasks/Lx_Vx.txt";
	inputFile[13] = level + '0';
	inputFile[16] = version + '0';
	printTask(inputFile);
	mySolution(level, version, levelIsFinished, lostGame);

}

//the game step by step
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
	bool gameOver = false;
	playTheGame(gameOver);

	if (gameOver == true)
	{
		gameOver = false;
		playTheGame(gameOver);
	}
}