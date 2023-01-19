#include <iostream>
#include <fstream>
using namespace std;
const int MAX_MISTAKES = 3;

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

void checkSolution(string solutionFile) {
	ifstream solFile(solutionFile, ios::in);
	char solution[1024];
	char trueAnswer[1024];
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
		while (solFile.getline(solution, 1024, '\n'))
		{
			cin >> temp;
			if (strcmp(solution, temp) == 0)
			{
				cout << "True answer, keep playing!\n";
			}
			else
			{
				mistakes++;
				cout << "Wrong answer, you have " << leftMistakes - mistakes << " more chances.\n The true answer is: " << solution << "\nEnter next one.\n";
			}
			solFile.get();
		}
		solFile.close();
	}
}

void mySolution(int level, int version) {
	string solutionFile = "";

	switch (level) {
	case 1:
		switch (version) {
		case 1:
			solutionFile = "sol1.1.txt";
			checkSolution(solutionFile);
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


void chooseLevel(int level, int version) {
	string inputFile = "";


	switch (level) {
	case 1:
		switch (version) {
		case 1:
			inputFile = "L1_V1.txt";
			printTask(inputFile);
			mySolution(level, version);
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


int main() {
	int level = 0;
	int version = 0;
	cout << "Chose a level from 1 to 5!" << endl;
	cin >> level;
	cout << "Version 1 or 2?" << endl;
	cin >> version;
	chooseLevel(level, version);
}