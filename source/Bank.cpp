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
    int isAsk=1;
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


    void saveRecords()  {
        ofstream outFile(filename);
        for (const auto& record : records) {
            outFile << record.toString() << "\n";
        }
        outFile.close();
    }

    void deleteRecords() {
        ofstream outFile(filename, ios::trunc);
        outFile << "";
        outFile.close();
    }

    bool isValidAccountNumber(const string& accountNumber) {
        for (const auto& record : records) {
            if (accountNumber == record.getAccountNumber()) {
                cout << "Number account " << record.getAccountNumber() << " already exist" << endl;
                return false;
            }
        }
        return regex_match(accountNumber, regex("^\\d{6,10}$")); // 6-10 chiffres
    }

    static bool isValidName(const string& name) {
        return !name.empty() && regex_match(name, regex("^[A-Za-z\\s'-]+$"));
    }

    static bool isValidPhoneNumber(const string& phoneNumber) {
        return regex_match(phoneNumber, regex("^\\+?\\d{9,15}$")); // Format international
    }

    static bool isValidBalance(double balance) {
        return balance >= 0.0; // Le solde ne peut pas être négatif
    }

public:
    Bank() { loadRecords(); }

    ~Bank() { saveRecords(); }

    void addRecord() {
        string accountNumber, firstName, lastName, phoneNumber;
        double balance;

        bool validAccountNumber;
        do {
            cout << "Enter Account Number (6-10 digits): ";
            getline(cin, accountNumber);
            validAccountNumber = isValidAccountNumber(accountNumber);
            if (!validAccountNumber) {
                cout << "Invalid Account Number. Please enter 6-10 digits." << endl;
            }
        } while (!validAccountNumber);

        do {
            cout << "Enter First Name: ";
            getline(cin, firstName);
            if (!isValidName(firstName)) {
                cout << "Invalid First Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
            }
        } while (!isValidName(firstName));

        do {
            cout << "Enter Last Name: ";
            getline(cin, lastName);
            if (!isValidName(lastName)) {
                cout << "Invalid Last Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
            }
        } while (!isValidName(lastName));

        do {
            cout << "Enter Phone Number (10-15 digits, optional + at the start): ";
            getline(cin, phoneNumber);
            if (!isValidPhoneNumber(phoneNumber)) {
                cout << "Invalid Phone Number. Please enter 10-15 digits, optionally starting with a +." << endl;
            }
        } while (!isValidPhoneNumber(phoneNumber));

        while (true) {
            cout << "Enter Balance: ";
            cin >> balance;

            if (cin.fail()) {
                cout << "Invalid Balance. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (!isValidBalance(balance)) {
                cout << "Invalid Balance. The balance cannot be negative." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        records.emplace_back(accountNumber, firstName, lastName, phoneNumber, balance);
        cout << "Record added successfully!" << endl;
        saveRecords();
    }

    void displayRecords() {
        cout << "\n*** Records information ***" << endl;
        for (const auto& record : records) {
            record.display();
        }
    }

    void modifyRecord() {
        string accountNumber;
        displayRecords();
        cout << "\n*** Modify a record ***" << endl;
        cout << "Enter Account Number: "; getline(cin, accountNumber);

        for (auto& record : records) {
            if (record.getAccountNumber() == accountNumber) {
                string firstName, lastName, phoneNumber;
                double balance;
                do {
                    cout << "Enter First Name: ";
                    getline(cin, firstName);
                    if (!isValidName(firstName)) {
                        cout << "Invalid First Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
                    }
                } while (!isValidName(firstName));

                do {
                    cout << "Enter Last Name: ";
                    getline(cin, lastName);
                    if (!isValidName(lastName)) {
                        cout << "Invalid Last Name. Please use only letters, spaces, hyphens, or apostrophes." << endl;
                    }
                } while (!isValidName(lastName));

                do {
                    cout << "Enter Phone Number (10-15 digits, optional + at the start): ";
                    getline(cin, phoneNumber);
                    if (!isValidPhoneNumber(phoneNumber)) {
                        cout << "Invalid Phone Number. Please enter 10-15 digits, optionally starting with a +." << endl;
                    }
                } while (!isValidPhoneNumber(phoneNumber));

                while (true) {
                    cout << "Enter Balance: ";
                    cin >> balance;

                    if (cin.fail()) {
                        cout << "Invalid Balance. Please enter a valid number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (!isValidBalance(balance)) {
                        cout << "Invalid Balance. The balance cannot be negative." << endl;
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                record.setFirstName(firstName);
                record.setLastName(lastName);
                record.setPhoneNumber(phoneNumber);
                record.setBalance(balance);
                deleteRecords();
                saveRecords();
                cout << "Record modified successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void deleteRecord() {
        string accountNumber;
        displayRecords();
        cout << "\n*** Delete a record ***" << endl;
        cout << "Enter Account Number: "; getline(cin, accountNumber);

        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getAccountNumber() == accountNumber) {
                records.erase(it);
                cout << "Record deleted successfully!" << endl;
                deleteRecords();
                saveRecords();
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void searchRecord() const {
        int saveNumber;
        cout << "\n*** Search for a record ***" << endl;

        cout << "Number of records found: " << records.size() << endl;
        cout << "Enter Account Number: ";
        cin >> saveNumber;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number : Enter a valid save number: ";
            cin >> saveNumber;
        }

        if(saveNumber > records.size() || saveNumber < 1) {
            cout << "Record not found!" << endl;
            return;
        }
        cout << "\nRecord number " << saveNumber << endl;
        records.at(saveNumber-1).display();
    }


    void searchRecordBONUS()  {
        int saveNumber;
        cout << "\n*** Recherche d'un enregistrement ***" << endl;
        if (isAsk==1){
            cout << "Nombre total d'enregistrements disponibles : " << records.size() << endl;
            isAsk=0;
        }

        if (records.empty()) {
            cout << "Erreur d'ouverture ! Fichier introuvable!!" << endl;
            return;
        }

        cout << "Entrez le numéro d'enregistrement : ";
        cin >> saveNumber;

        while (cin.fail()) {
            cin.clear();
            cout << "Numéro invalide : Entrez un numéro valide : ";
            cin >> saveNumber;
        }

        if (saveNumber > records.size() || saveNumber < 1) {
            cout << "Erreur d'ouverture ! Fichier introuvable!!" << endl;
            return;
        }

        cout << "\nEnregistrement numéro " << saveNumber << ":" << endl;
        records.at(saveNumber - 1).display();
    }
};