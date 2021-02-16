#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string filename;
	fstream afile;
	string content;
	int counter = 0;

	cout << "Please enter the name of the file.\n";
	cout << "FILE NAME: ";
	//please enter "myfile2.txt"
	cin >> filename;
	afile.open(filename, ios::in);

	if (!afile) {
		cout << "ERROR OPENING FILE.\n";
		cout << "ENDING PROGRAM.\n";
		return 0;
	}
	cin.ignore();
	while (getline(afile, content)) {
		counter++;
		if (counter % 25 == 0) {
			cout << "PRESS 'ENTER' to continue.\n";
			cin.get();
			cout << endl;
		}
		cout << content << endl;

	}
	afile.close();

	return 0;
}
