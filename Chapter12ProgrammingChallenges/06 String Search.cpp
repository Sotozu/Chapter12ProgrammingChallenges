#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string filename, user_input, file_content;
	fstream afile;
	vector<int> line_number;
	int line_num = 0;

	int counter = 0;
	cout << "Please enter a file name.\n";

	cout << "FILE NAME: ";
	//please enter myfile2.txt
	getline(cin, filename);

	cout << endl;
	cout << "Please enter a string (phrase or any text) to search for in the file.\n";
	cout << "STRING: ";
	getline(cin, user_input);

	afile.open(filename, ios::in);

	if (!afile) {
		cout << "ERROR OPENING FILE.\n";
		cout << "ENDING PROGRAM.\n";
		return 0;
	}

	while (getline(afile, file_content)) {
		line_num++;

		if (file_content.find(user_input, 0) != string::npos) { //why is this always returning true?
			counter++;
			line_number.push_back(line_num);
		}
	}

	cout << "The phrase was found " << counter << " time(s) in the file.\n";
	cout << "Found on line(s):\n";

	for (int i = 0; i < line_number.size(); i++) {
		cout << "line: " << line_number[i] << endl;
	}




	return 0;
}
