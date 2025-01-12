#include "../header/Account.h"
#include <iostream>
#include <vector>

Account::Account() : balance(0.0) {}

Account::Account(const string& accNum, const string& fName, const string& lName, const string& phone, double bal)
    : accountNumber(accNum), firstName(fName), lastName(lName), phoneNumber(phone), balance(bal) {}

string Account::getAccountNumber() const { return accountNumber; }

void Account::setPhoneNumber(const string& phone) { phoneNumber = phone; }

void Account::setBalance(double bal) { balance = bal; }

void Account::setFirstName(const string& firstName) { this->firstName = firstName; }

void Account::setLastName(const string& lastName) { this->lastName = lastName; }

void Account::display() const {
    cout << "Account Number: " << accountNumber
         << "\nFirst Name: " << firstName
         << "\nLast Name: " << lastName
         << "\nPhone Number: " << phoneNumber
         << "\nBalance: " << balance << "\n" << endl;
}

string Account::toString() const {
    return accountNumber + "|" + firstName + "|" + lastName + "|" + phoneNumber + "|" + to_string(balance);
}

Account Account::fromString(const string& line) {
    size_t pos = 0;
    string token;
    vector<string> fields;
    string temp = line;

    while ((pos = temp.find('|')) != string::npos) {
        token = temp.substr(0, pos);
        fields.push_back(token);
        temp.erase(0, pos + 1);
    }
    fields.push_back(temp);

    return Account(fields[0], fields[1], fields[2], fields[3], stod(fields[4]));
}
