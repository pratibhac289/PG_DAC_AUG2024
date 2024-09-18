#include "Bank_System.h"
#include <iostream>

using namespace std;

// Function to withdraw money from an account
void withdrawMoney(Account accounts[], int accountCount) {
    if (accountCount == 0) {
        cout << "No accounts available to withdraw money." << endl;
        return;
    }

    int accountNumber;
    double withdrawAmount;
    bool accountFound = false;

    cout << "Enter the account number to withdraw money: ";
    cin >> accountNumber;

    // Search for the account
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account found. Current balance: $" << accounts[i].balance << endl;
            cout << "Enter the amount to withdraw: ";
            cin >> withdrawAmount;

            if (withdrawAmount > 0 && withdrawAmount <= accounts[i].balance) {
                accounts[i].balance -= withdrawAmount;
                cout << "Withdrawal successful! New balance: $" << accounts[i].balance << endl;
            } else if (withdrawAmount > accounts[i].balance) {
                cout << "Insufficient balance!" << endl;
            } else {
                cout << "Invalid withdrawal amount!" << endl;
            }

            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cout << "Account number not found!" << endl;
    }
}

