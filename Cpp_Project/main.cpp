#include "Bank_System.h"
#include <iostream>

using namespace std;

int main() {
    Account accounts[MAX_ACCOUNTS];  // Array to hold account details
    int accountCounter = 100;       // Initial account number
    int accountCount = 0;            // Number of accounts created
    int choice;

    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Delete Account" << endl;  // New option for deleting an account
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount >= MAX_ACCOUNTS) {
                cout << "Maximum account limit reached!" << endl;
                continue;
            }

            // Call createAccount function with correct arguments
            createAccount(accounts, accountCount, accountCounter);

        } else if (choice == 2) {
            // Display all accounts
            cout << "\nAll Created Accounts:" << endl;
            for (int i = 0; i < accountCount; ++i) {
                cout << "Account Holder: " << accounts[i].name << endl;
                cout << "Account Number: " << accounts[i].accountNumber << endl;
                cout << "Balance: $" << accounts[i].balance << endl;
                cout << "--------------------------" << endl;
            }

            if (accountCount == 0) {
                cout << "No accounts available." << endl;
            }

        } else if (choice == 3) {
            // Call the depositMoney function to deposit money into an account
            depositMoney(accounts, accountCount);

        } else if (choice == 4) {
            // Call the withdrawMoney function to withdraw money from an account
            withdrawMoney(accounts, accountCount);

        } else if (choice == 5) {
            // Call the deleteAccount function to delete an account
            deleteAccount(accounts, accountCount);

        } else if (choice == 6) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

