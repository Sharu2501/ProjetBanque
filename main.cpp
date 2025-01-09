#include <iostream>
using namespace std;


void addRecord() {
}

void showRecords() {

}

void searchRecord() {

}

void updateRecord() {
    int accountNumber;
    cout << "Enter Account Number :" << endl;
    cin >> accountNumber;
}

void deleteRecord() {

}

int main()
{
    bool show = true;

    while (show) {
        cout << "\n***Account Information System***" << endl;
        cout << "Select one option below" << endl;
        cout << "\t 1 --> Add record to file" << endl;
        cout << "\t 2 --> Show record from file" << endl;
        cout << "\t 3 --> Search record from file" << endl;
        cout << "\t 4 --> Update record" << endl;
        cout << "\t 5 --> Delete record" << endl;
        cout << "\t 6 --> Quit" << endl;
        cout << "Enter your choice :" << endl;

        char choice;
        cin >> choice;

        switch (choice) {
            case '1': addRecord(); break;
            case '2': showRecords(); break;
            case '3': searchRecord(); break;
            case '4': updateRecord(); break;
            case '5': deleteRecord(); break;
            case '6': show = false; break;
            default: cout << "Invalid choice, please try again." << endl;
        }
    }

    cout << "Have a good day !" << endl;
    return 0;
}
