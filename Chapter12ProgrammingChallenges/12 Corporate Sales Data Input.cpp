#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

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

		cout << division[i].division_name << " Division" << endl;
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
		cout << "Quarter " << lowest_q_num[i] << ": $" << lowest_quarter[i] << endl;
	}
	cout << "----------------------------" << endl;
	cout << "HIGHEST QUARTERs: " << endl;
	for (int i = 0; i < highest_quarter.size(); i++) {
		cout << highest_quarter_name[i] << " Division" << endl;
		cout << "Quarter " << highest_q_num[i] << ": $" << highest_quarter[i] << endl;
	}
	return 0;
}
