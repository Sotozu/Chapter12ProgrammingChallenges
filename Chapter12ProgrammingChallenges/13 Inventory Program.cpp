#include <string>
#include <fstream>
#include <iostream>

using namespace std;

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


void AddRecord(Material* item) {

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
	cout << "4. Exit" << endl;
}

long ByteNum(int rec_num) {
	return sizeof(Material) * (rec_num - 1);
}
