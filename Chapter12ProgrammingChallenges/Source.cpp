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