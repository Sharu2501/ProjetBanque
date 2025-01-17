#include <iostream>
#include "source/Bank.cpp"

using namespace std;

int main() {
    Bank bank;
    bool show = true;

    while (show) {
        cout << "\n*** Account Information System ***" << endl;
        cout << "Select one option below:" << endl;
        cout << "\t 1 --> Add record to file" << endl;
        cout << "\t 2 --> Show records from file" << endl;
        cout << "\t 3 --> Search record from file" << endl;
        cout << "\t 4 --> Update record" << endl;
        cout << "\t 5 --> Delete record" << endl;
        cout << "\t 6 --> Search record from file (BONUS)" << endl;
        cout << "\t 7 --> Quit" << endl;
        cout << "Enter your choice: ";

        char choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                bank.addRecord();
                break;
            case '2':
                bank.displayRecords();
                break;
            case '3':
                bank.searchRecord();
                break;
            case '4':
                bank.modifyRecord();
            break;
            case '5':
                bank.deleteRecord();
                break;
            case '6':
                bank.searchRecordBONUS();
                break;
            case '7':
                show = false;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    cout << "Have a good day!" << endl;
    return 0;
}
