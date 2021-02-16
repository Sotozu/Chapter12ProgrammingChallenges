#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

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
	afile.open(filename, ios::in | ios::out | ios::binary);

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

			if (user_choice_menu2 == 1) {

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
			cout << "Customer Name:  " << info->name << endl;
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
	return sizeof(Customer) * (record_choice - 1);
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

void DeleteRecord(Customer* info, fstream& afile, string filename) {
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
	afile.seekg(RecordPosition(rec_num_del + 1), ios::beg);

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
