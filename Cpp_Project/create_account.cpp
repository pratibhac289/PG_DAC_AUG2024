#include "Bank_System.h"
#include <iostream>
#include <limits>  // Add this header for numeric_limits

using namespace std;

// Function to create a new account
void createAccount(Account accounts[], int &accountCount, int &accountCounter) {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Maximum account limit reached!" << endl;
        return;
    }

    // Clear the input buffer before using getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your name: ";
    getline(cin, accounts[accountCount].name);

    cout << "Enter initial deposit amount: ";
    cin >> accounts[accountCount].balance;

    accounts[accountCount].accountNumber = ++accountCounter;  // The incremented accountCounter provides a new unique number for each account.

    cout << "Account created successfully! Your account number is: " 
         << accounts[accountCount].accountNumber << endl;

    accountCount++;
}

