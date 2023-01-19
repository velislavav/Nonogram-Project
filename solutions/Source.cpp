#include <iostream>
#include <fstream>

using namespace std;

int main() {
	const char fileName[] = "Text1.txt";
	ifstream inputFile(fileName);
	if (!inputFile)
	{
		cout << "Error! Failed to open file\n";
		return -1;
	}

	int  matrix[13][13];
	//double grades[128];
	int i = 0;
	int j = 0;
	int counter = 0;
	while (inputFile >> matrix[i][j])
	{
		for (i = 0; i < 13; ++i) {
			for (j = 0; j < 13; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		
		//cout << 
		//cout << names[counter] << ' ' << grades[counter] << endl;
		//cout << matrix[counter][counter] << endl;
		inputFile.get();
		++counter;
	}

	inputFile.close();
}