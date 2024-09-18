#include "Bank_System.h"
#include <iostream>

using namespace std;

// Function to deposit money into an account
void depositMoney(Account accounts[], int accountCount) {
    if (accountCount == 0) {
        cout << "No accounts available to deposit money." << endl;
        return;
    }

    int accountNumber;
    double depositAmount;
    bool accountFound = false;

    cout << "Enter the account number to deposit money: ";
    cin >> accountNumber;

    // Search for the account
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account found. Current balance: $" << accounts[i].balance << endl;
            cout << "Enter the amount to deposit: ";
            cin >> depositAmount;

            if (depositAmount > 0) {
                accounts[i].balance += depositAmount;
                cout << "Deposit successful! New balance: $" << accounts[i].balance << endl;
            } else {
                cout << "Invalid deposit amount!" << endl;
            }

            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cout << "Account number not found!" << endl;
    }
}

