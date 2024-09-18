#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

class Account {
public:
    string name;
    int accountNumber;
    double balance;
};

// Function declarations
void createAccount(Account accounts[], int &accountCount, int &accountCounter);
void depositMoney(Account accounts[], int accountCount);
void withdrawMoney(Account accounts[], int accountCount);
void deleteAccount(Account accounts[], int &accountCount);  // Declaration for the deleteAccount function

#endif

