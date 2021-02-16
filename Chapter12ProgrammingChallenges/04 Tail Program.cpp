#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	string filename;
	string content;
	fstream afile;
	char ch;

	long read_pos;
	long size_of_file;
	long last_pos = -1;
	long read_bytes = 0;
	int count;

	int counter = 0;
	cout << "Please enter a file name.\n";
	cout << "FILE NAME: ";
	// please enter myfile3.txt
	getline(cin, filename);
	afile.open(filename, ios::in);

	afile.seekg(-1L, ios::end); // take us the last character in the file. The stream is set to this position.
	size_of_file = afile.tellg(); //-1 because of the end of flag character.
	//cout << "SIZE OF FILE: " << size_of_file << endl;


	afile.get(ch);
	read_bytes++;
	//cout << ch << endl;

	while (counter < 10) {
		count = 0;
		while (ch != '\n') {
			afile.seekg(-2L, ios::cur);
			afile.get(ch);
			count++;
			//cout << ch << count << endl;
			read_bytes++;
			last_pos = afile.tellg();
			//cout << last_pos << endl;
			if (last_pos == 1) { //if the last position is found
				//cout << "Last Position Found.\n";
				break;
			}
		}
		read_pos = afile.tellg();
		//edit this to find the position to read from
		//cout << "\nREAD POSITION: " << read_pos << endl;
		afile.clear();
		if (last_pos == 1) {
			afile.seekg(0L, ios::beg);
		}
		else {
			afile.seekg(read_pos, ios::beg);
		}
		afile.get(ch);
		while (ch != '\n') {
			if (afile.eof())
			{
				//cout << "\nEND OF FILE.\n";
				break;
			}
			cout << ch;
			afile.get(ch);
		}
		cout << endl;
		//cout << "READ BYTES: " << read_bytes << endl;
		read_bytes += 2;

		afile.clear();
		afile.seekg(-read_bytes, ios::end);

		afile.get(ch);
		if (last_pos == 1) {
			break;
		}
		counter++;
	}

	if (counter < 10) {
		cout << endl;
		cout << "Entire File Displayed.\n";
	}
	return 0;
}
