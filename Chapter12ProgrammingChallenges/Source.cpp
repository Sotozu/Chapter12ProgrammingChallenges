#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <iomanip>

using namespace std;

/*
// 1. File Head Program
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
*/

// 2. File Display Program
/*
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
*/

/*
// 3. Punchline

void getjoke(fstream &);
void getpunchline(fstream &);

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
*/
/*
// 4. Tail Program

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

	while (counter < 10){
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
*/

/*
// 5. Line Numbers

int main() {
	string filename;
	fstream afile;
	string content;
	int counter = 0;
	int num = 1;

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
		cout << num << ": ";
		cout << content << endl;
		num++;
	}
	afile.close();

	return 0;
}
*/

/*
// 6. String Search

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
*/
/*
// 7. Sentence Filter

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
	getline(cin, fileinput);

	cout << "Please enter the file for output.\n";
	cout << "FILE FOR OUTPUT: ";
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
*/

/*
// 8. Array/File Function

void arrayToFile(string, int*, int);
void fileToArray(string, int*, int);
int main() {
	const int SIZE = 10;
	string filename;
	int my_array[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int array_copy[SIZE];

	int* intP1 = my_array;
	int* intP2 = array_copy;

	fstream afile;

	cout << "Please enter the name of the file to open.\n";
	cout << "FILE NAME: ";
	//please enter outfil8.txt;
	getline(cin, filename);

	//afile.open(filename, ios::out | ios::binary);
	//afile.write(reinterpret_cast<char*>(my_array), sizeof(my_array));
	arrayToFile(filename, intP1, sizeof(my_array));
	fileToArray(filename, intP2, sizeof(array_copy));

	for (int i = 0; i < SIZE; i++) {
		cout << array_copy[i] << endl;
	}
	return 0;
}
void arrayToFile(string filename, int* my_array, int size) {

	fstream binfile;

	binfile.open(filename, ios::out | ios::binary);
	for (int i = 0; i < size; i++)
	{
		binfile.write(reinterpret_cast<char*>(my_array), size);
	}
	binfile.close();

}

void fileToArray(string filename, int* array_copy, int size) {
	
	fstream binfile;

	binfile.open(filename, ios::in | ios::binary);

	for (int i = 0; i < size; i++) {
		binfile.read(reinterpret_cast<char*>(array_copy), size);
	}
	binfile.close();
}
*/

/*
// 9. File Encryption Filter

void makeSecretVersion(fstream&, fstream&, int);
void decryptSecret(fstream&, fstream&, int);

int main() {

	fstream afile, codedfile, decryption;
	int encryption_key = 7;

	afile.open("secretmessage.txt", ios::in);
	codedfile.open("encryptionfile.txt", ios::out);

	makeSecretVersion(afile, codedfile, encryption_key);

	codedfile.close();
	afile.close();

	cout << "Press 'enter' to Decrypt.\n";
	cin.get();

	codedfile.open("encryptionfile.txt", ios::in);
	decryption.open("decryption.txt", ios::out);
	decryptSecret(codedfile, decryption, encryption_key);




	



	return 0;
}

void makeSecretVersion(fstream& afile, fstream& codedfile, int encryption_key) {
	char ch;
	char new_ch;
	int char_change;
	int value_char;
	while (afile.get(ch)) {
		value_char = static_cast<int>(ch);
		new_ch = static_cast<char>(value_char + encryption_key);
		codedfile << new_ch;
	}
	
}

void decryptSecret(fstream& codedfile, fstream& decryption, int encryption_key) {
	char ch;
	char decoded_ch;
	int char_change;
	int value_char;
	while (codedfile.get(ch)) {

		value_char = static_cast<int>(ch);
		decoded_ch = static_cast<char>(value_char - encryption_key);

		decryption << decoded_ch;
	}

}
*/

// 10. File Decryption Filter
/*
void makeSecretVersion(fstream&, fstream&, int);
void decryptSecret(fstream&, fstream&, int);

int main() {

	fstream afile, codedfile, decryption;
	int encryption_key = 7;

	afile.open("secretmessage.txt", ios::in);
	codedfile.open("encryptionfile.txt", ios::out);

	makeSecretVersion(afile, codedfile, encryption_key);

	codedfile.close();
	afile.close();

	cout << "Press 'enter' to Decrypt.\n";
	cin.get();

	codedfile.open("encryptionfile.txt", ios::in);
	decryption.open("decryption.txt", ios::out);
	decryptSecret(codedfile, decryption, encryption_key);








	return 0;
}

void makeSecretVersion(fstream& afile, fstream& codedfile, int encryption_key) {
	char ch;
	char new_ch;
	int char_change;
	int value_char;
	while (afile.get(ch)) {
		value_char = static_cast<int>(ch);
		new_ch = static_cast<char>(value_char + encryption_key);
		codedfile << new_ch;
	}

}

void decryptSecret(fstream& codedfile, fstream& decryption, int encryption_key) {
	char ch;
	char decoded_ch;
	int char_change;
	int value_char;
	while (codedfile.get(ch)) {

		value_char = static_cast<int>(ch);
		decoded_ch = static_cast<char>(value_char - encryption_key);

		decryption << decoded_ch;
	}

}
*/

/*
// 11. Corporate Sales Data Output

const int NAME_LENGTH = 25;
const int DIVISIONS = 4;
const int QUARTERS = 4;


struct Company {
	char division_name[NAME_LENGTH];
	int quarter[QUARTERS];
	double q_sales[QUARTERS];

};

int main() {

	Company division[DIVISIONS]{
		{"East", {1,2,3,4}}, {"West", {1,2,3,4}}, {"North", {1,2,3,4}}, {"South", {1,2,3,4}}
	};

	Company division_data_copy[DIVISIONS];

	fstream afile;
	for (int i = 0; i < DIVISIONS; i++) {
		cout << "DIVISION NAME " << i + 1 << ": ";
		cout << division[i].division_name << endl;
		
		cout << "Please Enter Quarterly Sales.\n";
		for (int j = 0; j < QUARTERS; j++) {
			do {
				cout << "Quarter " << division[i].quarter[j] << ": $";
				cin >> division[i].q_sales[j];
				if (division[i].q_sales[j] < 0) {
					cout << "ERROR: Please enter a positive value.\n";
				}
			} while (division[i].q_sales[j] < 0);
		}
		cout << endl;
	}

	afile.open("record.txt", ios::out | ios::binary);

	for (int i = 0; i < DIVISIONS; i++) {
		afile.write(reinterpret_cast<char*>(division), sizeof(division));
	}

	afile.close();

	afile.open("record.txt", ios::in | ios::binary);
	
	for (int i = 0; i < DIVISIONS; i++) {
		afile.read(reinterpret_cast<char*>(division_data_copy), sizeof(division_data_copy));
	}
	cout << "********************************" << endl;
	cout << "COPIED DATA TO NEW STRUCT" << endl;
	cout << "********************************" << endl;

	for (int i = 0; i < DIVISIONS; i++) {

		cout << "DIVISION NAME " << i + 1 << ": ";
		cout << division[i].division_name << endl;

		cout << "Quarterly Sales.\n";
		for (int j = 0; j < QUARTERS; j++) {
			cout << "Quarter " << division[i].quarter[j] << ": $" << division[i].q_sales[j] << endl;
		}
		cout << endl;

	}

	return 0;
}
*/
/*
// 12. Corporate Data Sales Input

const int NAME_LENGTH = 25;
const int DIVISIONS = 4;
const int QUARTERS = 4;


struct Company {
	char division_name[NAME_LENGTH];
	int quarter[QUARTERS];
	double q_sales[QUARTERS];

};

int main() {

	Company division[DIVISIONS]{
		{"East", {1,2,3,4}}, {"West", {1,2,3,4}}, {"North", {1,2,3,4}}, {"South", {1,2,3,4}}
	};

	Company division_data_copy[DIVISIONS];

	double total_division_sales[DIVISIONS] = { 0,0,0,0 };
	double quarterly_totals[QUARTERS] = { 0,0,0,0 };
	double total_sales = 0;
	double average_quarterly[QUARTERS];

	string lown, highn;
	vector<string> lowest_quarter_name, highest_quarter_name;
	vector<double> lowest_quarter, highest_quarter;
	vector <int> lowest_q_num, highest_q_num;

	fstream afile;
	for (int i = 0; i < DIVISIONS; i++) {
		cout << "DIVISION NAME " << i + 1 << ": ";
		cout << division[i].division_name << endl;

		cout << "Please Enter Quarterly Sales.\n";
		for (int j = 0; j < QUARTERS; j++) {
			do {
				cout << "Quarter " << division[i].quarter[j] << ": $";
				cin >> division[i].q_sales[j];
				if (division[i].q_sales[j] < 0) {
					cout << "ERROR: Please enter a positive value.\n";
				}
			} while (division[i].q_sales[j] < 0);
		}
		cout << endl;
	}

	afile.open("record.txt", ios::out | ios::binary);

	for (int i = 0; i < DIVISIONS; i++) {
		afile.write(reinterpret_cast<char*>(division), sizeof(division));
	}

	afile.close();

	afile.open("record.txt", ios::in | ios::binary);

	for (int i = 0; i < DIVISIONS; i++) {
		afile.read(reinterpret_cast<char*>(division_data_copy), sizeof(division_data_copy));
	}


	//calculations
	for (int i = 0; i < DIVISIONS; i++) {
		for (int j = 0; j < QUARTERS; j++) {
			quarterly_totals[i] += division[j].q_sales[i];
			total_division_sales[i] += division[i].q_sales[j];
			total_sales += quarterly_totals[i];
		}
		average_quarterly[i] = quarterly_totals[i] / QUARTERS;
	}

	//find lowest and highest quarters

	lowest_quarter.push_back(division[0].q_sales[0]);
	highest_quarter.push_back(division[0].q_sales[0]);
	//
	lown = "East";
	highn = "East";

	lowest_quarter_name.push_back(lown);
	highest_quarter_name.push_back(highn);
	//
	highest_q_num.push_back(1);
	lowest_q_num.push_back(1);



	for (int i = 0; i < DIVISIONS; i++) {
		for (int j = 0; j < QUARTERS; j++) {

			if (lowest_quarter[0] > division[i].q_sales[j]) {
				lowest_quarter.clear();
				lowest_quarter.push_back(division[i].q_sales[j]);

				lowest_quarter_name.clear();
				if (i == 0) {
					lown = "East";
				}
				else if (i == 1) {
					lown = "West";
				}
				else if (i == 2) {
					lown = "North";
				}
				else {
					lown = "South";
				}
				lowest_quarter_name.push_back(lown);

				lowest_q_num.clear();
				lowest_q_num.push_back(j + 1);
			}
			else if (lowest_quarter[0] == division[i].q_sales[j]) {
				lowest_quarter.push_back(division[i].q_sales[j]);

				if (i == 0) {
					lown = "East";
				}
				else if (i == 1) {
					lown = "West";
				}
				else if (i == 2) {
					lown = "North";
				}
				else {
					lown = "South";
				}
				lowest_quarter_name.push_back(lown);

				lowest_q_num.push_back(j + 1);

			}

			if (highest_quarter[0] < division[i].q_sales[j]) {
				highest_quarter.clear();
				highest_quarter.push_back(division[i].q_sales[j]);

				highest_quarter_name.clear();
				if (i == 0) {
					highn = "East";
				}
				else if (i == 1) {
					highn = "West";
				}
				else if (i == 2) {
					highn = "North";
				}
				else {
					highn = "South";
				}
				highest_quarter_name.push_back(highn);

				highest_q_num.clear();
				highest_q_num.push_back(j + 1);
			}
			else if (highest_quarter[0] == division[i].q_sales[j]) {

				highest_quarter.push_back(division[i].q_sales[j]);

				if (i == 0) {
					highn = "East";
				}
				else if (i == 1) {
					highn = "West";
				}
				else if (i == 2) {
					highn = "North";
				}
				else {
					highn = "South";
				}
				highest_quarter_name.push_back(highn);

				highest_q_num.push_back(j + 1);

			}

		}
	}

	cout << "********************************" << endl;
	cout << "DIVISION TOTALS" << endl;
	cout << "********************************" << endl;

	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < DIVISIONS; i++) {

		cout << division[i].division_name << " Division" <<endl;
		cout << "Yearly Sales: $" << total_division_sales[i];
		cout << endl << endl;
	}
	cout << endl;

	cout << "********************************" << endl;
	cout << "COMPANY QUARTERLY TOTALS" << endl;
	cout << "********************************" << endl;
	for (int i = 0; i < DIVISIONS; i++) {
		for (int j = 0; j < QUARTERS; j++) {
			quarterly_totals[i] += division[j].q_sales[i];
		}
		cout << "QUARTER " << i + 1 << ": $" << quarterly_totals[i] << endl;
	}
	cout << endl;

	cout << "********************************" << endl;
	cout << "DIVISION QUARTERLY AVERAGES" << endl;
	cout << "********************************" << endl;
	for (int i = 0; i < DIVISIONS; i++) {
		cout << division[i].division_name << " Division\n";
		cout << "Quarterly Average: $" << average_quarterly[i] << endl;
		cout << endl;
	}
	
	cout << "********************************" << endl;
	cout << "HIGHEST & LOWEST QUARTERLY SALES" << endl;
	cout << "********************************" << endl;
	cout << endl;
	cout << "LOWEST QUARTERS:" << endl;
	for (int i = 0; i < lowest_quarter.size(); i++) {
		cout << lowest_quarter_name[i] << " Division" << endl;
		cout << "Quarter " << lowest_q_num[i] <<": $" << lowest_quarter[i] << endl;
	}
	cout << "----------------------------" << endl;
	cout << "HIGHEST QUARTERs: " << endl;
	for (int i = 0; i < highest_quarter.size(); i++) {
		cout << highest_quarter_name[i] << " Division" << endl;
		cout << "Quarter " << highest_q_num[i] << ": $" << highest_quarter[i] << endl;
	}
	return 0;
}
*/

/*
// 13. Inventory Program

const int DESCRIPTION_LENGTH = 30;
enum Menu{ADD_RECORD = 1, DISPLAY_A_RECORD, CHANGE_A_RECORD, EXIT};
struct Material {
	char description[DESCRIPTION_LENGTH];
	int quantity_on_hand;
	double whole_sale_cost;
	double retail_cost;
	char date_added[DESCRIPTION_LENGTH];
};

void AddRecord(Material*);
void DisplayRecord(Material*);
void DisplayMenu();
long ByteNum(int);
int main() {

	Material item;
	Material* mptr = &item;
	string filename = "file13.txt";
	fstream afile;
	afile.open(filename, ios::in | ios::out | ios::binary);

	int user_option, rec_num, total_rec = 0;


	if (!afile) {
		cout << "ERROR OPENING FILE" << endl;
		return 0;
	}

	do {

		DisplayMenu();

		cout << "Please enter an option: ";
		cin >> user_option;
		cin.ignore();
		switch (user_option) {
			case 1:
				cout << endl;
				AddRecord(mptr); // Will write data to the struct
				afile.write(reinterpret_cast<char*>(&item), sizeof(item)); //places data in struct to the binary file
				total_rec++;
				cout << endl;
				break;
			case 2:
				if (total_rec < 1) {
					cout << "No records available.\n";
					break;
				}
				else {
					cout << "-----------------" << endl;
					cout << "TOTAL RECORDS: " << total_rec << endl;
					cout << "-----------------" << endl;
					do {
						cout << "Which record would you like to view?" << endl;
						cout << "Record Number: ";
						cin >> rec_num;
						if (rec_num < 1 || rec_num > total_rec) {
							cout << "ERROR: Please enter a valid record.\n";
						}

					} while (rec_num < 1 || rec_num > total_rec);
					afile.seekg(ByteNum(rec_num), ios::beg); //moves the reades up (x)records from the beginning of the file.

					afile.read(reinterpret_cast<char*>(&item), sizeof(item)); //reads data from read postions of size 'item' to location 'item'
																			  // in memory.
					cout << endl;
					DisplayRecord(mptr); //displays he contents in the 'item' struct. Should now hold content read from the binary file
					cout << endl;
				}
				
				break;
			case 3:
				cout << "-----------------" << endl;
				cout << "TOTAL RECORDS: " << total_rec << endl;
				cout << "-----------------" << endl;
				do {
					cout << "Which record would you like to change?" << endl;
					cout << "Record Number: ";
					cin >> rec_num;
					if (rec_num < 1 || rec_num > total_rec) {
						cout << "ERROR: Please enter a valid record.\n";
					}
				} while (rec_num < 1 || rec_num > total_rec);
				cout << endl;
				cout << "Enter Data To Replace Record." << endl;
				cin.ignore();
				AddRecord(mptr); // Will write data to the struct

				afile.seekg(ByteNum(rec_num), ios::beg); //moves the reades up (x)records from the beginning of the file.
				afile.write(reinterpret_cast<char*>(&item), sizeof(item));

				cout << endl;
				cout << "RECORD REPLACED" << endl;
				cout << endl;
				break;
			case 4:
				break;
			default:
				cout << "ERROR" << endl;

		}

		

	} while (user_option != 4);
		
	cout << "Good Bye!" << endl;

	return 0;
}


void AddRecord(Material* item){

	cout << "Description: ";
	cin.getline(item->description, DESCRIPTION_LENGTH);
	cout << "Quantity: ";
	cin >> item->quantity_on_hand;
	cout << "Wholesale Price: ";
	cin >> item->whole_sale_cost;
	cout << "Retail Price: ";
	cin >> item->retail_cost;
	cout << "Date Added (xx/xx/xxxx): ";
	cin.ignore();
	cin.getline(item->date_added, DESCRIPTION_LENGTH);
}

void DisplayRecord(Material *item) {
	cout << "Description: " << item->description << endl;
	cout << "Quantity: " << item->quantity_on_hand << endl;
	cout << "Wholesale Price: " << item->whole_sale_cost << endl;
	cout << "Retail Price: " << item->retail_cost << endl;
	cout << "Date Added (xx/xx/xxxx): " << item->date_added << endl;
}

void DisplayMenu() {
	cout << "********" << endl;
	cout << "  MENU  " << endl;
	cout << "********" << endl;
	cout << "1. Add New Records To The File" << endl;
	cout << "2. Display A Record In The File" << endl;
	cout << "3. Change A Record In The File" << endl;
	cout << "4. Exit" << endl;
}

long ByteNum(int rec_num) {
	return sizeof(Material) * (rec_num - 1);
}
*/

// 14. Inventory Screen Report
/*
const int DESCRIPTION_LENGTH = 30;
enum Menu { ADD_RECORD = 1, DISPLAY_A_RECORD, CHANGE_A_RECORD, EXIT };
struct Material {
	char description[DESCRIPTION_LENGTH];
	int quantity_on_hand;
	double whole_sale_cost;
	double retail_cost;
	char date_added[DESCRIPTION_LENGTH];
};

void AddRecord(Material*);
void DisplayRecord(Material*);
void DisplayMenu();
long ByteNum(int);
int main() {

	Material item;
	Material* mptr = &item;
	string filename = "file13.txt";
	fstream afile;
	afile.open(filename, ios::in | ios::out | ios::binary);

	int user_option, rec_num, total_rec = 0;
	int total_items = 0;
	double t_w_v = 0, t_r_v = 0;


	if (!afile) {
		cout << "ERROR OPENING FILE" << endl;
		return 0;
	}

	do {

		DisplayMenu();
		cout << endl;
		do {
			cout << "Please enter an option: ";
			cin >> user_option;
			if (user_option < 1 || user_option > 5) {
				cout << "ERROR: Please enter a valid option.\n";
			}
		} while (user_option < 1 || user_option > 5);

		cin.ignore();

		switch (user_option) 
		{
			case 1:
				cout << endl;
				AddRecord(mptr); // Will write data to the struct
				afile.write(reinterpret_cast<char*>(&item), sizeof(item)); //places data in struct to the binary file
				total_rec++;
				cout << endl;
				break;
			case 2:

				if (total_rec < 1) {
					cout << "No records available.\n";
					break;
				}
				else {
					cout << endl;
					cout << "-----------------" << endl;
					cout << "TOTAL RECORDS: " << total_rec << endl;
					cout << "-----------------" << endl;
					do {
						cout << "Which record would you like to view?" << endl;
						cout << "Record Number: ";
						cin >> rec_num;
						if (rec_num < 1 || rec_num > total_rec) {
							cout << "ERROR: Please enter a valid record.\n";
						}

					} while (rec_num < 1 || rec_num > total_rec);
					afile.seekg(ByteNum(rec_num), ios::beg); //moves the reades up (x)records from the beginning of the file.

					afile.read(reinterpret_cast<char*>(&item), sizeof(item)); //reads data from read postions of size 'item' to location 'item'
																			  // in memory.
					cout << endl;
					DisplayRecord(mptr); //displays he contents in the 'item' struct. Should now hold content read from the binary file
					cout << endl;
				}
				break;
			case 3:
				cout << endl;
				cout << "-----------------" << endl;
				cout << "TOTAL RECORDS: " << total_rec << endl;
				cout << "-----------------" << endl;
				do {
					cout << "Which record would you like to change?" << endl;
					cout << "Record Number: ";
					cin >> rec_num;
					if (rec_num < 1 || rec_num > total_rec) {
						cout << "ERROR: Please enter a valid record.\n";
					}
				} while (rec_num < 1 || rec_num > total_rec);
				cout << endl;
				cout << "Enter Data To Replace Record." << endl;
				cin.ignore();
				AddRecord(mptr); // Will write data to the struct

				afile.seekg(ByteNum(rec_num), ios::beg); //moves the reades up (x)records from the beginning of the file.
				afile.write(reinterpret_cast<char*>(&item), sizeof(item));

				cout << endl;
				cout << "RECORD REPLACED" << endl;
				cout << endl;
				break;
			case 4:
				cout << endl;
				cout << "-----------------" << endl;
				cout << "     REPORT      " << endl;
				cout << "-----------------" << endl;
				afile.seekg(0L, ios::beg);
				afile.read(reinterpret_cast<char*>(&item), sizeof(item));
				while (!afile.eof()){
					
					t_w_v += item.whole_sale_cost * item.quantity_on_hand;
					t_r_v += item.retail_cost * item.quantity_on_hand;
					total_items += item.quantity_on_hand;
					afile.read(reinterpret_cast<char*>(&item), sizeof(item));
				}
				cout << setprecision(2) << fixed << showpoint;
				cout << "TOTAL WHOLE SALE VALUE: $" << t_w_v << endl;
				cout << "TOTAL RETAIL VALUE: $" << t_r_v << endl;
				cout << "TOTAL ITEMS IN INVENTORY: " << total_items << endl;
				break;
			case 5:
				cout << "Good Bye!" << endl;
				break;
			default:
				break;
		}




	} while (user_option != 5);

	return 0;
}

void AddRecord(Material* item) {
	cout << "-----------------" << endl;
	cout << "ADD RECORD" << endl;
	cout << "-----------------" << endl;
	cout << "Description: ";
	cin.getline(item->description, DESCRIPTION_LENGTH);
	cout << "Quantity: ";
	cin >> item->quantity_on_hand;
	cout << "Wholesale Price: $";
	cin >> item->whole_sale_cost;
	cout << "Retail Price: $";
	cin >> item->retail_cost;
	cout << "Date Added (xx/xx/xxxx): ";
	cin.ignore();
	cin.getline(item->date_added, DESCRIPTION_LENGTH);
}

void DisplayRecord(Material* item) {
	cout << "Description: " << item->description << endl;
	cout << "Quantity: " << item->quantity_on_hand << endl;
	cout << "Wholesale Price: " << item->whole_sale_cost << endl;
	cout << "Retail Price: " << item->retail_cost << endl;
	cout << "Date Added (xx/xx/xxxx): " << item->date_added << endl;
}

void DisplayMenu() {
	cout << "********" << endl;
	cout << "  MENU  " << endl;
	cout << "********" << endl;
	cout << "1. Add New Records To The File" << endl;
	cout << "2. Display A Record In The File" << endl;
	cout << "3. Change A Record In The File" << endl;
	cout << "4. Generate Report" << endl;
	cout << "5. Exit" << endl;
}

long ByteNum(int rec_num) {
	return sizeof(Material) * (rec_num - 1);
}
*/

// 15. Average Number of Words
/*
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
		else if (ch == '\n'){
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
*/
// GROUP PROJECT (SOLO)

// 16. Customer Accounts

const int N_SIZE = 25;
const int ADD_SIZE = 35;
const int C_SIZE = 25;
const int S_SIZE = 25;
const int L_PAY_SIZE = 25;
const int TEL_SIZE = 25;

struct Customer {
	char name[N_SIZE];
	char address[ADD_SIZE];
	char city[C_SIZE];
	char state[S_SIZE];
	int zip;
	char telephone[TEL_SIZE];
	double account_balance;
	char last_payment[L_PAY_SIZE];
};

int DisplayMenu1();
int DisplayMenu2();
void DisplayAllRecords(Customer*, fstream&);
void SearchName(Customer*, fstream&);
void EnterRecord(Customer*, fstream&);
long RecordPosition(int);
void SearchRecord(Customer*, fstream&);
void ChangeRecord(Customer*, fstream&);
void DeleteRecord(Customer*, fstream&, string);
int main() {
	int user_choice_menu, user_choice_menu2;

	Customer info;
	Customer* cptr = &info;

	fstream afile;
	string filename = "file16.txt";
	afile.open(filename, ios:: in | ios::out | ios::binary);

	afile.seekg(0L, ios::end);

	afile.seekg(0L, ios::beg); // read position is set to the beginning of the file

	if (!afile) {
		cout << "ERROR OPENING FILE.\n";
		return 0;
	}

	do {
		user_choice_menu = DisplayMenu1();

		switch (user_choice_menu) {
		case 1:
			EnterRecord(cptr, afile);
			break;
		case 2:
			afile.seekg(0L, ios::end);

			user_choice_menu2 = DisplayMenu2();

			if (user_choice_menu2 == 1){

				SearchName(cptr, afile);

			}
			else if (user_choice_menu2 == 2) {

				SearchRecord(cptr, afile);

			}
			break;
		case 3:
			DeleteRecord(cptr, afile, filename);
			afile.open(filename, ios::in | ios::out | ios::binary);
			break;
		case 4:
			ChangeRecord(cptr, afile);
			break;
		case 5:
			DisplayAllRecords(cptr, afile);
			break;
		case 6:
			cout << "GOOD BYE!" << endl;
			break;
		default:
			cout << "ERROR" << endl;
		}

	} while (user_choice_menu != 6);


	return 0;

}

int DisplayMenu1() {

	int user_choice_menu;

	cout << "-----------------------" << endl;
	cout << "         Menu          " << endl;
	cout << "-----------------------" << endl;
	cout << "1. Enter a New Record" << endl;
	cout << "2. Display a Customers Records " << endl;
	cout << "3. Delete a Customers Records" << endl;
	cout << "4. Change a Customers Records " << endl;
	cout << "5. Display All Records" << endl;
	cout << "6. Exit" << endl;

	do {
		cout << "ENTER MENU OPTION: ";
		cin >> user_choice_menu;
		if (user_choice_menu < 1 || user_choice_menu > 6) {
			cout << "ERROR: Please enter a valid menu option.\n";
		}
	} while (user_choice_menu < 1 || user_choice_menu > 6);

	return user_choice_menu;
}

void EnterRecord(Customer* info, fstream& afile) {
	cin.ignore();
	cout << "-----------------------" << endl;
	cout << "     Enter Record      " << endl;
	cout << "-----------------------" << endl;
	cout << "Name: ";
	cin.getline(info->name, N_SIZE);
	cout << "Address: ";
	cin.getline(info->address, ADD_SIZE);
	cout << "City: ";
	cin.getline(info->city, C_SIZE);
	cout << "State: ";
	cin.getline(info->state, S_SIZE);
	cout << "Zip Code: ";
	cin >> info->zip;
	cin.ignore();
	cout << "Phone Number [(xxx) xxx-xxxx]: ";
	cin.getline(info->telephone, TEL_SIZE);
	cout << "Account Balance: $";
	cin >> info->account_balance;
	cin.ignore();
	cout << "Last Payment Date (xx/xx/xxxx): ";
	cin.getline(info->last_payment, L_PAY_SIZE);
	afile.seekp(0L, ios::end);
	afile.write(reinterpret_cast<char*>(info), sizeof(*info));
	cout << "-------------------------------------" << endl;
	cout << "     Record  Entered Succesfully     " << endl;
	cout << "-------------------------------------" << endl;

}
 int DisplayMenu2() {
	int user_choice_menu2;
	cout << "-------------------------------------" << endl;
	cout << "        Search Criteria Menu         " << endl;
	cout << "-------------------------------------" << endl;
	cout << "1. Name" << endl;
	cout << "2. Record Number" << endl;


	do {
		cout << "Enter Choice: ";
		cin >> user_choice_menu2;
		if (user_choice_menu2 < 1 || user_choice_menu2 > 2) {
			cout << "ERROR: Please enter a valid menu option.\n";
		}
	} while (user_choice_menu2 < 1 || user_choice_menu2 > 2);

	return  user_choice_menu2;
}
 void SearchName(Customer* info, fstream& afile) {
	
	 cout << "---------------------" << endl;
	 cout << "     SEARCH NAME     " << endl;
	 cout << "---------------------" << endl;

	 string hold_info_name;
	 string search_name;
	 int record_num = 1;
	 int record_choice;
	 vector<int> record_found;
	 bool match_found = false;
	 cout << "Please enter a name (or partial name) to begin the search.\n";
	 cout << "NAME: ";
	 cin.ignore();
	 getline(cin, search_name);
	 afile.clear();
	 afile.seekg(0L, ios::end);
	 afile.seekg(0L, ios::beg);
	 cout << "------------------------" << endl;
	 cout << "     SEARCH RESULTS     " << endl;
	 cout << "------------------------" << endl;

	 while (afile.read(reinterpret_cast<char*>(info), sizeof(*info))) {
		 hold_info_name = info->name;

		 if (hold_info_name.find(search_name) != string::npos) { //if it finds a match
			 cout << "RECORD: " << record_num << endl;
			 cout << "Customer Name:  "<< info->name << endl;
			 cout << endl;
			 match_found = true;

		 }
		 record_num++;
	 }
	 afile.clear(); //!!!!clears the error flag!!! **SOLVED THE ISSUE WITH THE FILE SIZE RETURNING -1****

	 // we are at the end of the file in the read mode.

	 if (match_found == false) {
		 cout << "NO MATCH FOUND.\n";
	 }
	 else {
		 cout << "Which Record Would You Like To View?" << endl;
		 cout << "RECORD NUMBER: ";
		 cin >> record_choice;

		 afile.seekg(0L, ios::beg); // read position is set to the beginning of the file
		 afile.seekg(RecordPosition(record_choice), ios::beg);
		 afile.read(reinterpret_cast<char*>(info), sizeof(*info));
		 cout << endl;

		 cout << fixed << showpoint << setprecision(2);
		 cout << "Name: " << info->name << endl;
		 cout << "Address: " << info->address << endl;
		 cout << "City: " << info->city << endl;
		 cout << "State: " << info->state << endl;
		 cout << "Zip Code: " << info->zip << endl;
		 cout << "Phone Number: " << info->telephone << endl;
		 cout << "Account Balance: $" << info->account_balance << endl;
		 cout << "Last Payment Date: " << info->last_payment << endl;
	 }
	 
 }

 long RecordPosition(int record_choice) {
	 return sizeof(Customer) * (record_choice-1);
 }

 void SearchRecord(Customer* info, fstream& afile) {
	 afile.seekg(0L, ios::beg);
	 int num_of_records = 0;
	 string names;
	 vector<string> list_names;
	 int user_rec_choice;
	 afile.clear();
	 afile.seekg(0L, ios::beg);
	 while (afile.read(reinterpret_cast<char*>(info), sizeof(*info))) {
		 num_of_records++;
		 names = info->name;
		 list_names.push_back(names);
	 }

	 afile.clear(); //clear eof() flag
	 cout << "------------------------" << endl;
	 cout << "     SEARCH RECORDS     " << endl;
	 cout << "------------------------" << endl;

	 cout << "NUMBER OF RECORDS: " << num_of_records << endl;
	 for (int i = 0; i < list_names.size(); i++) {
		 cout << "Record " << i + 1 << ": " << list_names[i] << endl;
	 }
	 cout << endl;
	 do {
		 cout << "Choose a record to view: ";
		 cin >> user_rec_choice;
		 if (user_rec_choice < 1 || user_rec_choice > num_of_records) {
			 cout << "ERROR: Please enter a valid record number.\n";
		 }
	 } while (user_rec_choice < 1 || user_rec_choice > num_of_records);
	
	 afile.seekg(RecordPosition(user_rec_choice), ios::beg);
	 afile.read(reinterpret_cast<char*>(info), sizeof(*info));

	 cout << fixed << showpoint << setprecision(2) << endl;
	 cout << "Name: " << info->name << endl;
	 cout << "Address: " << info->address << endl;
	 cout << "City: " << info->city << endl;
	 cout << "State: " << info->state << endl;
	 cout << "Zip Code: " << info->zip << endl;
	 cout << "Phone Number: " << info->telephone << endl;
	 cout << "Account Balance: $" << info->account_balance << endl;
	 cout << "Last Payment Date: " << info->last_payment << endl;

 }
 void ChangeRecord(Customer* info, fstream& afile) {
	 int user_rec_number;
	 cout << "----------------------" << endl;
	 cout << "     CHANGE RECORD    " << endl;
	 cout << "----------------------" << endl;

	 cout << "Which Record Do You Wish To Change?" << endl;
	 cout << "RECORD NUMBER: ";
	 cin >> user_rec_number;

	 cout << "Enter New Data" << endl;
	 cin.ignore();
	 cout << "Name: ";
	 cin.getline(info->name, N_SIZE);
	 cout << "Address: ";
	 cin.getline(info->address, ADD_SIZE);
	 cout << "City: ";
	 cin.getline(info->city, C_SIZE);
	 cout << "State: ";
	 cin.getline(info->state, S_SIZE);
	 cout << "Zip Code: ";
	 cin >> info->zip;
	 cin.ignore();
	 cout << "Phone Number [(xxx) xxx-xxxx]: ";
	 cin.getline(info->telephone, TEL_SIZE);
	 cout << "Account Balance: $";
	 cin >> info->account_balance;
	 cin.ignore();
	 cout << "Last Payment Date (xx/xx/xxxx): ";
	 cin.getline(info->last_payment, L_PAY_SIZE);
	 afile.seekp(RecordPosition(user_rec_number), ios::beg);
	 afile.write(reinterpret_cast<char*>(info), sizeof(*info));

	 cout << "RECORD REPLACED" << endl;
 }

 void DeleteRecord(Customer* info, fstream& afile, string filename ) {
	 fstream tempfile;
	 string temp_name = "tempfile16.txt";
	 int rec_num_del;

	 long pos_skip;

	 tempfile.open(temp_name, ios::out | ios::binary);
	 if (!tempfile) {
		 cout << "ERROR OPENING TEMP FILE.\n";
	 }
	 cout << "----------------------" << endl;
	 cout << "     DELETE RECORD    " << endl;
	 cout << "----------------------" << endl;

	 cout << "Which Record Would You Like To Delete?" << endl;
	 cout << "DELETE RECORD: ";
	 cin >> rec_num_del;
	 afile.clear();
	 afile.seekg(RecordPosition(rec_num_del+1), ios::beg);

	 pos_skip = afile.tellg(); //beginning position of record to be skipped
	 cout << "SKIP POS: " << pos_skip << endl;
	 afile.seekg(0L, ios::beg); //resets read position to the beginning of the file
	 
	 
	 while (afile.read(reinterpret_cast<char*>(info), sizeof(*info))) {
		 cout << endl;
		 cout << "SKIP POS: " << pos_skip << endl;
		 cout << "CURRENT POS: " << afile.tellg() << endl;
		 if (pos_skip == afile.tellg()) {
			 //afile.seekg(sizeof(Customer), ios::cur); // move it up one record. Skipping 

			 cout << "***SKIPED****" << endl;
		 }
		 else {
			 
			 tempfile.write(reinterpret_cast<char*>(info), sizeof(*info));

		 }
	 }
	 afile.clear();
	 afile.close();
	 afile.open(filename, ios::out | ios::binary);

	 tempfile.close();
	 tempfile.open(temp_name, ios::in | ios::binary);
	 tempfile.seekg(0L, ios::beg);

	 while (tempfile.read(reinterpret_cast<char*>(info), sizeof(*info))) {
		
		 afile.write(reinterpret_cast<char*>(info), sizeof(*info));
	 }
	 tempfile.clear();
	 tempfile.close();
	 afile.close();
 }

 void DisplayAllRecords(Customer* info, fstream& afile) {
	 cout << "---------------------" << endl;
	 cout << "     ALL RECORDS     " << endl;
	 cout << "---------------------" << endl;

	 int counter = 1;
	 afile.clear();
	 afile.seekg(0L, ios::beg);
	 
	 while (afile.read(reinterpret_cast<char*>(info), sizeof(*info))) {
		 cout << fixed << showpoint << setprecision(2) << endl;
		 cout << "RECORD: " << counter << endl;
		 cout << "Name: " << info->name << endl;
		 cout << "Address: " << info->address << endl;
		 cout << "City: " << info->city << endl;
		 cout << "State: " << info->state << endl;
		 cout << "Zip Code: " << info->zip << endl;
		 cout << "Phone Number: " << info->telephone << endl;
		 cout << "Account Balance: $" << info->account_balance << endl;
		 cout << "Last Payment Date: " << info->last_payment << endl;
		 cout << endl;
		 counter++;
	 }
 }
