#include "../header/Account.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>
#include <limits>

class Account;
using namespace std;

class Bank {
private:
    vector<Account> records;
    const string filename = "bank_records.txt";

    void loadRecords() {
        ifstream inFile(filename);

        if (!inFile) {
            ofstream outFile(filename, ios::app);
            if (!outFile) {
                cout << "Error creating file!" << endl;
                return;
            }
            outFile.close();
            return;
        }

        string line;
        while (getline(inFile, line)) {
            records.push_back(Account::fromString(line));
        }
        inFile.close();
    }


    void saveRecords() const {
        ofstream outFile(filename);
        for (const auto& record : records) {
            outFile << record.toString() << "\n";
        }
        outFile.close();
    }

    bool isValidAccountNumber(const string& accountNumber) {
        return regex_match(accountNumber, regex("^\\d{6,10}$")); // 6-10 chiffres
    }

    bool isValidName(const string& name) {
        return !name.empty() && regex_match(name, regex("^[A-Za-z\\s'-]+$"));
    }

    bool isValidPhoneNumber(const string& phoneNumber) {
        return regex_match(phoneNumber, regex("^\\+?\\d{9,15}$")); // Format international
    }

    bool isValidBalance(double balance) {
        return balance >= 0.0; // Le solde ne peut pas être négatif
    }

public:
    Bank() { loadRecords(); }

    ~Bank() { saveRecords(); }

    void addRecord() {
        string accountNumber, firstName, lastName, phoneNumber;
        double balance;

        // Validation du numéro de compte
        do {
            cout << "Enter Account Number (6-10 digits): ";
            getline(cin, accountNumber);
            if (!isValidAccountNumber(accountNumber)) {
                cout << "Invalid Account Number. Please enter 6-10 digits." << endl;
            }
        } while (!isValidAccountNumber(accountNumber));

        // Validation du prénom
        do {
            cout << "Enter First Name: ";
            getline(cin, firstName);
            if (!isValidName(firstName)) {
                cout << "Invalid First Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
            }
        } while (!isValidName(firstName));

        // Validation du nom de famille
        do {
            cout << "Enter Last Name: ";
            getline(cin, lastName);
            if (!isValidName(lastName)) {
                cout << "Invalid Last Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
            }
        } while (!isValidName(lastName));

        // Validation du numéro de téléphone
        do {
            cout << "Enter Phone Number (10-15 digits, optional + at the start): ";
            getline(cin, phoneNumber);
            if (!isValidPhoneNumber(phoneNumber)) {
                cout << "Invalid Phone Number. Please enter 10-15 digits, optionally starting with a +." << endl;
            }
        } while (!isValidPhoneNumber(phoneNumber));

        // Validation du solde
        while (true) {
            cout << "Enter Balance: ";
            cin >> balance;

            if (cin.fail()) {
                cout << "Invalid Balance. Please enter a valid number." << endl;
                cin.clear(); // Efface l'état d'erreur du flux
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore l'entrée incorrecte
            } else if (!isValidBalance(balance)) {
                cout << "Invalid Balance. The balance cannot be negative." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore les caractères supplémentaires
                break;
            }
        }


        records.emplace_back(accountNumber, firstName, lastName, phoneNumber, balance);
        cout << "Record added successfully!" << endl;
    }

    void displayRecords() const {
        cout << "\n*** Records information ***" << endl;
        for (const auto& record : records) {
            record.display();
        }
    }

    void modifyRecord() {
        string accountNumber;
        cout << "\n*** Modify a record ***" << endl;
        cout << "Enter Account Number: "; getline(cin, accountNumber);

        for (auto& record : records) {
            if (record.getAccountNumber() == accountNumber) {
                string phoneNumber;
                double balance;

                cout << "Enter new phone number: "; getline(cin, phoneNumber);
                cout << "Enter new balance: "; cin >> balance; cin.ignore();

                record.setPhoneNumber(phoneNumber);
                record.setBalance(balance);
                cout << "Record modified successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void deleteRecord() {
        string accountNumber;
        cout << "\n*** Delete a record ***" << endl;
        cout << "Enter Account Number: "; getline(cin, accountNumber);

        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getAccountNumber() == accountNumber) {
                records.erase(it);
                cout << "Record deleted successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void searchRecord() const {
        string accountNumber;
        cout << "\n*** Search for a record ***" << endl;
        int cpt = 0;
        for (auto it = records.begin(); it != records.end(); ++it) {
            cpt = cpt+1;
        }
        cout << "Number of records found: " << cpt << endl;

        cout << "Enter Account Number: "; getline(cin, accountNumber);

        for (const auto& record : records) {
            if (record.getAccountNumber() == accountNumber) {
                record.display();
                return;
            }
        }
        cout << "Record not found!" << endl;
    }
};