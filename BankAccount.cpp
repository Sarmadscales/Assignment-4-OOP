/*
 * BankAccount.cpp
 * Assignment 4 - Exception Handling and Object Lifecycle Management
 * Author: Muhammad Sarmad
 * Registration: L1F24BSAI0059
 * 
 * This implementation file contains the method definitions for BankAccount class.
 * It demonstrates proper exception handling, constructor validation, and
 * destructor cleanup with console messages showing execution order.
 */

#include "BankAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Constructor: Validates initial balance and creates account
 * Throws InvalidBalanceException if balance is negative
 * Displays console message showing constructor execution
 */
BankAccount::BankAccount(const string& name, double initialBalance) {
    cout << "\n[CONSTRUCTOR] Creating account for: " << name << endl;
    cout << "[CONSTRUCTOR] Validating initial balance..." << endl;
    
    // Validate initial balance - throw exception if negative
    if (initialBalance < 0) {
        cout << "[CONSTRUCTOR] ERROR: Negative balance detected!" << endl;
        cout << "[CONSTRUCTOR] Throwing InvalidBalanceException..." << endl;
        throw InvalidBalanceException("Invalid account creation: Initial balance cannot be negative!");
    }
    
    // If validation passes, initialize the account
    accountHolderName = name;
    balance = initialBalance;
    
    cout << "[CONSTRUCTOR] SUCCESS: Account created successfully!" << endl;
    cout << "[CONSTRUCTOR] Account Holder: " << accountHolderName << endl;
    cout << "[CONSTRUCTOR] Initial Balance: $" << fixed << setprecision(2) << balance << endl;
}

/**
 * Destructor: Ensures proper cleanup when object is destroyed
 * Displays console message showing destructor execution order
 */
BankAccount::~BankAccount() {
    cout << "\n[DESTRUCTOR] Destroying account for: " << accountHolderName << endl;
    cout << "[DESTRUCTOR] Final balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "[DESTRUCTOR] Performing cleanup operations..." << endl;
    cout << "[DESTRUCTOR] Account destroyed successfully!" << endl;
}

/**
 * Getter for account holder name
 */
string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

/**
 * Getter for current balance
 */
double BankAccount::getBalance() const {
    return balance;
}

/**
 * Withdraw method: Deducts amount from balance
 * Throws InvalidTransactionException if amount is negative or zero
 * Throws InsufficientFundsException if withdrawal amount exceeds balance
 */
void BankAccount::withdraw(double amount) {
    cout << "\n[WITHDRAW] Processing withdrawal of $" << fixed << setprecision(2) << amount << endl;
    cout << "[WITHDRAW] Current balance: $" << balance << endl;
    cout << "[WITHDRAW] Validating withdrawal amount..." << endl;

    // Validate withdrawal amount - must be positive
    if (amount <= 0) {
        cout << "[WITHDRAW] ERROR: Invalid withdrawal amount!" << endl;
        cout << "[WITHDRAW] Throwing InvalidTransactionException..." << endl;
        throw InvalidTransactionException("Withdrawal failed: Amount must be positive!");
    }

    // Check if sufficient funds are available
    cout << "[WITHDRAW] Checking available funds..." << endl;
    if (amount > balance) {
        cout << "[WITHDRAW] ERROR: Insufficient funds!" << endl;
        cout << "[WITHDRAW] Throwing InsufficientFundsException..." << endl;
        throw InsufficientFundsException("Withdrawal failed: Insufficient funds in account!");
    }

    // If validation passes and funds are sufficient, process withdrawal
    balance -= amount;
    cout << "[WITHDRAW] SUCCESS: Withdrawal completed!" << endl;
    cout << "[WITHDRAW] New balance: $" << fixed << setprecision(2) << balance << endl;
}

/**
 * Deposit method: Adds amount to balance
 * Throws InvalidTransactionException if amount is negative or zero
 */
void BankAccount::deposit(double amount) {
    cout << "\n[DEPOSIT] Processing deposit of $" << fixed << setprecision(2) << amount << endl;
    cout << "[DEPOSIT] Validating deposit amount..." << endl;

    // Validate deposit amount - must be positive
    if (amount <= 0) {
        cout << "[DEPOSIT] ERROR: Invalid deposit amount!" << endl;
        cout << "[DEPOSIT] Throwing InvalidTransactionException..." << endl;
        throw InvalidTransactionException("Deposit failed: Amount must be positive!");
    }

    // If validation passes, process deposit
    balance += amount;
    cout << "[DEPOSIT] SUCCESS: Deposit completed!" << endl;
    cout << "[DEPOSIT] New balance: $" << fixed << setprecision(2) << balance << endl;
}

/**
 * Display account information
 */
void BankAccount::displayAccountInfo() const {
    cout << "\n========================================" << endl;
    cout << "       ACCOUNT INFORMATION" << endl;
    cout << "========================================" << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "========================================" << endl;
}