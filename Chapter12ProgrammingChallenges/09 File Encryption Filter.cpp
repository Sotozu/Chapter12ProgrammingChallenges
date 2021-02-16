#include <iostream>
#include <fstream>

using namespace std;
void makeSecretVersion(fstream&, fstream&, int&);
void decryptSecret(fstream&, fstream&, int&);

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

void makeSecretVersion(fstream& afile, fstream& codedfile, int& encryption_key) {
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

void decryptSecret(fstream& codedfile, fstream& decryption, int& encryption_key) {
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