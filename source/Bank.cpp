#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

public:
    Bank() { loadRecords(); }

    ~Bank() { saveRecords(); }

    void addRecord() {
        string accountNumber, firstName, lastName, phoneNumber;
        double balance;

        cout << "\n*** Add a record ***" << endl;
        cout << "Enter Account Number: "; getline(cin, accountNumber);
        cout << "Enter First Name: "; getline(cin, firstName);
        cout << "Enter Last Name: "; getline(cin, lastName);
        cout << "Enter Phone Number: "; getline(cin, phoneNumber);
        cout << "Enter Balance: "; cin >> balance; cin.ignore();

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