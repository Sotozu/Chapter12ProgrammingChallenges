#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream afile;
	string filename = "file15.txt";
	afile.open(filename, ios::in);
	char ch;
	int num_words = 0;
	int num_sentence = 0;

	if (!afile) {
		cout << "ERROR OPENING FILE.\n";
		return 0;
	}
	while (!afile.eof()) {
		afile.get(ch);
		if (ch == ' ') {
			num_words++;
		}
		else if (ch == '\n') {
			num_words++;
			num_sentence++;
		}
	}
	num_words += 1;
	num_sentence += 1;
	cout << "Number of words: " << num_words << endl;
	cout << "Number of sentences: " << num_sentence << endl;

	cout << "Average number of words per sentence: " << num_words / num_sentence;



	return 0;
}
