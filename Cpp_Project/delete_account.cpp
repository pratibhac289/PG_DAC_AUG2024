#include "Bank_System.h"
#include <iostream>

using namespace std;

// Function to delete an account
void deleteAccount(Account accounts[], int &accountCount) {
    if (accountCount == 0) {
        cout << "No accounts available to delete." << endl;
        return;
    }

    int accountNumber;
    bool accountFound = false;

    cout << "Enter the account number to delete: ";
    cin >> accountNumber;

    // Search for the account
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account found. Deleting account of: " << accounts[i].name << endl;

            // Shift remaining accounts
            for (int j = i; j < accountCount - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }

            accountCount--;  // Decrease the account count
            cout << "Account deleted successfully!" << endl;
            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cout << "Account number not found!" << endl;
    }
}

