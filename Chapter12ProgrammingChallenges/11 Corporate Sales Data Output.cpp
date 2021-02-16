#include <fstream>
#include <iostream>

using namespace std;

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