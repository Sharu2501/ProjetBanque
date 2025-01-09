#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <string>

class Bank {
private:
    std::vector<Account> records;
    const std::string filename = "bank_records.txt";

    void loadRecords();

    void saveRecords() const;

public:

Bank();

    ~Bank();

    void addRecord();

    void displayRecords() const;

    void modifyRecord();

    void deleteRecord();

    void searchRecord() const;
};

#endif // BANK_H
