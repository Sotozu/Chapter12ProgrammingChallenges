#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void arrayToFile(fstream&, string&, int*, int);
void fileToArray(fstream&, string&, int*, int);
int main() {
	const int SIZE = 10;
	string filename;
	fstream binfile;
	int my_array[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int array_copy[SIZE];

	cout << "Please enter the name of the file to open.\n";
	cout << "FILE NAME: ";
	//please enter outfile8.txt;
	getline(cin, filename);

	arrayToFile(binfile, filename, my_array, sizeof(my_array));
	fileToArray(binfile, filename, array_copy, sizeof(array_copy));

	for (int i = 0; i < SIZE; i++) {
		cout << array_copy[i] << endl;
	}
	return 0;
}
void arrayToFile(fstream& file, string& filename, int* my_array, int size) {


	file.open(filename, ios::out | ios::binary);

	file.write(reinterpret_cast<char*>(my_array), size);
	
	file.close();

}

void fileToArray(fstream& file, string& filename, int* array_copy, int size) {

	file.open(filename, ios::in | ios::binary);

	file.read(reinterpret_cast<char*>(array_copy), size);
	
	file.close();
}