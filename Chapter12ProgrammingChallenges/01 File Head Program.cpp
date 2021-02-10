#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {

	string myfile;
	string content;
	fstream afile;
	int count = 0;

	cout << "Please enter than name of a file.\n";
	//Please enter "myfile.txt"
	cout << "FILE NAME: ";
	cin >> myfile;

	afile.open(myfile, ios::in);
	cout << endl;
	if (!afile) {
		cout << "Failed to open file. File does not exist.\n";
		cout << "Exiting program.\n";
		return 0;
	}



	while (getline(afile, content) && count < 10) {
		count++;
		cout << content << endl;

	}
	if (count < 10) {
		cout << endl;
		cout << "The entire file has been displayed.\n";
	}


	return 0;
}