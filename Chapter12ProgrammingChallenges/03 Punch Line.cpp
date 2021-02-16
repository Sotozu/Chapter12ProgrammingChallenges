#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getjoke(fstream&);
void getpunchline(fstream&);

int main() {

	fstream jokefile, punchline;

	jokefile.open("joke.txt", ios::in);
	if (!jokefile) {
		cout << "ERROR OPENING JOKE FILE.\n";
		cout << "ENDING PROGRAM.\n";
		return 0;
	}

	punchline.open("punchline.txt", ios::in);
	if (!punchline) {
		cout << "ERROR OPENING PUNCHLINE FILE.\n";
		cout << "ENDING PROGRAM.\n";
		return 0;
	}

	getjoke(jokefile);
	getpunchline(punchline);



	return 0;
}

void getjoke(fstream& jokefile) {

	string content;
	getline(jokefile, content);
	cout << content << endl;

}

void getpunchline(fstream& punchline) {
	char ch;

	punchline.seekg(0L, ios::end);

	punchline.seekg(-1L, ios::cur);

	punchline.get(ch);

	while (ch != '\n') {
		punchline.seekg(-2L, ios::cur);
		punchline.get(ch);
	}

	while (punchline.get(ch)) {
		cout << ch;
	}
}