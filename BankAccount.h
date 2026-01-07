/*
 * BankAccount.h
 * Assignment 4 - Exception Handling and Object Lifecycle Management
 * Author: Muhammad Sarmad
 * Registration: L1F24BSAI0059
 * 
 * This header file declares the BankAccount class that demonstrates:
 * - Exception handling in constructors
 * - Exception handling in member functions
 * - Proper object lifecycle management
 * - Safe resource cleanup using destructors
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <stdexcept>

using namespace std;

// Custom exception class for invalid initial balance
class InvalidBalanceException : public runtime_error {
public:
    explicit InvalidBalanceException(const string& message) 
        : runtime_error(message) {}
};

// Custom exception class for insufficient funds
class InsufficientFundsException : public runtime_error {
public:
    explicit InsufficientFundsException(const string& message)
        : runtime_error(message) {}
};

// Custom exception class for invalid transaction amounts
class InvalidTransactionException : public runtime_error {
public:
    explicit InvalidTransactionException(const string& message)
        : runtime_error(message) {}
};

// BankAccount class demonstrating exception handling and object lifecycle
class BankAccount {
private:
    string accountHolderName;
    double balance;

public:
    // Constructor with validation - throws exception for negative balance
    BankAccount(const string& name, double initialBalance);
    
    // Destructor - ensures proper cleanup
    ~BankAccount();
    
    // Getter methods
    string getAccountHolderName() const;
    double getBalance() const;
    
    // Withdraw method - throws exception if insufficient funds
    void withdraw(double amount);
    
    // Deposit method
    void deposit(double amount);
    
    // Display account information
    void displayAccountInfo() const;
};

#endif // BANKACCOUNT_H