#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileinput, fileoutput;
	string file_content;
	fstream ainputfile, aoutputfile;

	char ch;
	char upper_case;
	char lower_case;
	char period_check;

	long pos;
	bool upper_next = false;
	bool lower_next = false;

	cout << "Please enter the file for input.\n";
	cout << "FILE FOR INPUT: ";
	//fileinput7.txt
	getline(cin, fileinput);

	cout << "Please enter the file for output.\n";
	cout << "FILE FOR OUTPUT: ";
	//fileoutput7.txt
	getline(cin, fileoutput);

	ainputfile.open(fileinput, ios::in);

	aoutputfile.open(fileoutput, ios::out);

	pos = ainputfile.tellg();

	// Will have to upper case the first letter in the first sentence.
	ainputfile.get(ch);
	upper_case = toupper(ch);
	aoutputfile << upper_case;
	//

	while (ainputfile.get(ch)) {

		if (upper_next == true) {
			upper_case = toupper(ch);
			aoutputfile << upper_case;
			upper_next = false;

		}
		else if (ch == '\n') {
			upper_next = true;
			aoutputfile << ch;
		}
		else {
			lower_case = tolower(ch);
			aoutputfile << lower_case;
		}

	}

	return 0;
}