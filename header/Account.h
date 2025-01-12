#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string firstName;
    string lastName;
    string phoneNumber;
    double balance;

public:
    Account();
    Account(const string& accNum, const string& fName, const string& lName, const string& phone, double bal);

    string getAccountNumber() const;
    void setPhoneNumber(const string& phone);
    void setBalance(double bal);

    void setFirstName(const string &firstName);

    void setLastName(const string &lastName);

    void display() const;
    string toString() const;

    static Account fromString(const string& line);
};

#endif // ACCOUNT_H
