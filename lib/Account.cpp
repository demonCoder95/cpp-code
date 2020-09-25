// Interface implementation of the Account class
#include <iostream>
#include "Account.h"
using namespace std;

// class constructor
Account::Account(int initialBalance){
    if (initialBalance <= 0){
        balance = 0;
        cerr << "Invalid intial balance. Setting to 0." << endl;
    }else {
        balance = initialBalance;
    }
}

// function to credit the current balance
void Account::credit(int creditAmount){
    if (creditAmount <= 0){
        cerr << "Invalid credit amount, balance unchanged." << endl;
    }else{
        balance += creditAmount;
    }
}

// function to debit the current balance
void Account::debit(int debitAmount){
    if (debitAmount > balance){
        cerr << "Debit amount exceeded the account balance." << endl;
    }else {
        balance -= debitAmount;
    }
}

// function to get the current balance
int Account::getBalance(){
    return balance;
}