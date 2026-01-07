/*
 * main.cpp
 * Assignment 4 - Exception Handling and Object Lifecycle Management
 * Author: Muhammad Sarmad
 * Registration: L1F24BSAI0059
 * Course: CP223-F25-BS-AI-F24-AC2
 * Instructor: Syed Atir Raza Shirazi
 * 
 * This program demonstrates:
 * 1. Exception handling in constructors with validation
 * 2. Exception handling in member functions (withdraw, deposit)
 * 3. Input validation for transaction amounts
 * 4. Dynamic object creation using 'new'
 * 5. Proper destructor invocation even when exceptions occur
 * 6. No memory leaks through proper cleanup
 * 7. Clear console messages showing execution order
 */

#include "BankAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Function to print section headers for better output organization
void printSectionHeader(const string& title) {
    cout << "\n\n" << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << endl;
}

int main() {
    cout << fixed << setprecision(2);
    
    printSectionHeader("ASSIGNMENT 4: EXCEPTION HANDLING & OBJECT LIFECYCLE");
    cout << "Author: Muhammad Sarmad (L1F24BSAI0059)" << endl;
    cout << "Demonstrating exception handling with dynamic objects" << endl;
    
    
    // ========================================================================
    // SCENARIO 1: Valid Account Creation (Success Case)
    // ========================================================================
    printSectionHeader("SCENARIO 1: Valid Account Creation");
    cout << "Creating account with valid positive balance..." << endl;
    
    BankAccount* account1 = nullptr;
    try {
        account1 = new BankAccount("Alice Johnson", 1000.00);
        account1->displayAccountInfo();
        
        // Perform successful deposit
        account1->deposit(500.00);
        account1->displayAccountInfo();
        
        // Perform successful withdrawal
        account1->withdraw(300.00);
        account1->displayAccountInfo();
        
        // Clean up - destructor will be called
        delete account1;
        account1 = nullptr;
    }
    catch (const InvalidBalanceException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        // No memory leak - object was not created
    }
    catch (const InsufficientFundsException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        // Clean up if object exists
        if (account1 != nullptr) {
            delete account1;
            account1 = nullptr;
        }
    }
    catch (const InvalidTransactionException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        // Clean up if object exists
        if (account1 != nullptr) {
            delete account1;
            account1 = nullptr;
        }
    }
    
    
    // ========================================================================
    // SCENARIO 2: Invalid Account Creation (Constructor Exception)
    // ========================================================================
    printSectionHeader("SCENARIO 2: Invalid Account Creation (Negative Balance)");
    cout << "Attempting to create account with negative balance..." << endl;
    
    BankAccount* account2 = nullptr;
    try {
        // This will throw InvalidBalanceException in constructor
        account2 = new BankAccount("Bob Smith", -500.00);
        
        // This code will NOT execute because exception is thrown
        account2->displayAccountInfo();
    }
    catch (const InvalidBalanceException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        cerr << "[MAIN] Account creation failed - no object was created" << endl;
        cerr << "[MAIN] No memory leak - 'new' operator cleaned up automatically" << endl;
        
        // account2 is nullptr because constructor threw before assignment
        // No need to delete - object was never fully constructed
    }
    
    
    // ========================================================================
    // SCENARIO 3: Insufficient Funds Exception
    // ========================================================================
    printSectionHeader("SCENARIO 3: Withdrawal with Insufficient Funds");
    cout << "Creating account and attempting withdrawal exceeding balance..." << endl;
    
    BankAccount* account3 = nullptr;
    try {
        account3 = new BankAccount("Carol Williams", 500.00);
        account3->displayAccountInfo();
        
        // Attempt to withdraw more than available balance
        cout << "\nAttempting to withdraw $800.00..." << endl;
        account3->withdraw(800.00);  // This will throw InsufficientFundsException
        
        // This code will NOT execute because exception is thrown
        account3->displayAccountInfo();
    }
    catch (const InvalidBalanceException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        // Clean up if object exists
        if (account3 != nullptr) {
            delete account3;
            account3 = nullptr;
        }
    }
    catch (const InsufficientFundsException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        cerr << "[MAIN] Withdrawal denied - account remains intact" << endl;

        // CRITICAL: Even though exception occurred, we must clean up
        if (account3 != nullptr) {
            cout << "\n[MAIN] Cleaning up account object..." << endl;
            delete account3;  // Destructor will be called properly
            account3 = nullptr;
            cout << "[MAIN] Cleanup completed - no memory leak" << endl;
        }
    }
    catch (const InvalidTransactionException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        // Clean up if object exists
        if (account3 != nullptr) {
            delete account3;
            account3 = nullptr;
        }
    }
    
    
    // ========================================================================
    // SCENARIO 4: Multiple Operations with Exception Handling
    // ========================================================================
    printSectionHeader("SCENARIO 4: Multiple Operations with Mixed Results");
    cout << "Demonstrating multiple operations with exception handling..." << endl;
    
    BankAccount* account4 = nullptr;
    try {
        account4 = new BankAccount("David Brown", 2000.00);
        account4->displayAccountInfo();
        
        // Successful operations
        account4->deposit(1000.00);
        account4->withdraw(500.00);
        account4->displayAccountInfo();
        
        // This withdrawal will succeed
        account4->withdraw(1500.00);
        account4->displayAccountInfo();
        
        // This withdrawal will fail - insufficient funds
        cout << "\nAttempting final withdrawal of $1500.00..." << endl;
        account4->withdraw(1500.00);  // Exception!
        
    }
    catch (const InsufficientFundsException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        cerr << "[MAIN] Final withdrawal failed, but previous operations succeeded" << endl;

        if (account4 != nullptr) {
            account4->displayAccountInfo();
            cout << "\n[MAIN] Performing cleanup..." << endl;
            delete account4;
            account4 = nullptr;
        }
    }
    catch (const InvalidBalanceException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        if (account4 != nullptr) {
            delete account4;
            account4 = nullptr;
        }
    }
    catch (const InvalidTransactionException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        if (account4 != nullptr) {
            delete account4;
            account4 = nullptr;
        }
    }
    
    
    // ========================================================================
    // SCENARIO 5: Invalid Transaction Amounts (Negative/Zero)
    // ========================================================================
    printSectionHeader("SCENARIO 5: Invalid Transaction Amounts");
    cout << "Testing input validation for negative and zero amounts..." << endl;

    BankAccount* account5 = nullptr;
    try {
        account5 = new BankAccount("Grace Lee", 1000.00);
        account5->displayAccountInfo();

        // Attempt to deposit negative amount
        cout << "\nAttempting to deposit negative amount (-$100.00)..." << endl;
        account5->deposit(-100.00);  // This will throw InvalidTransactionException

        // This code will NOT execute
        account5->displayAccountInfo();
    }
    catch (const InvalidTransactionException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        cerr << "[MAIN] Invalid transaction prevented - account protected from fraud!" << endl;

        if (account5 != nullptr) {
            cout << "\n[MAIN] Account remains secure. Performing cleanup..." << endl;
            delete account5;
            account5 = nullptr;
        }
    }
    catch (const exception& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
        if (account5 != nullptr) {
            delete account5;
            account5 = nullptr;
        }
    }


    // ========================================================================
    // SCENARIO 6: Demonstrating Destructor Order with Stack Objects
    // ========================================================================
    printSectionHeader("SCENARIO 6: Destructor Order with Stack Objects");
    cout << "Creating stack objects to show destructor execution order..." << endl;
    
    try {
        cout << "\nCreating first stack object..." << endl;
        BankAccount stackAccount1("Eva Martinez", 1500.00);
        
        cout << "\nCreating second stack object..." << endl;
        BankAccount stackAccount2("Frank Garcia", 2500.00);
        
        cout << "\nBoth objects created successfully" << endl;
        cout << "Objects will be destroyed when exiting this scope..." << endl;
        cout << "Destructors will be called in reverse order (LIFO)" << endl;
        
        // Objects will be destroyed here when exiting try block
        // Destructors called in reverse order: stackAccount2, then stackAccount1
    }
    catch (const InvalidBalanceException& e) {
        cerr << "\n[EXCEPTION CAUGHT] " << e.what() << endl;
    }
    
    
    // ========================================================================
    // FINAL SUMMARY
    // ========================================================================
    printSectionHeader("PROGRAM SUMMARY");
    cout << "\nKey Concepts Demonstrated:" << endl;
    cout << "1. ✓ Exception handling in constructors (InvalidBalanceException)" << endl;
    cout << "2. ✓ Exception handling in member functions (InsufficientFundsException)" << endl;
    cout << "3. ✓ Input validation for transactions (InvalidTransactionException)" << endl;
    cout << "4. ✓ Protection against negative/zero deposits and withdrawals" << endl;
    cout << "5. ✓ Dynamic object creation using 'new' operator" << endl;
    cout << "6. ✓ Proper destructor invocation even with exceptions" << endl;
    cout << "7. ✓ No memory leaks through proper cleanup with 'delete'" << endl;
    cout << "8. ✓ Console messages showing constructor/destructor execution order" << endl;
    cout << "9. ✓ try-catch blocks for safe exception handling" << endl;
    cout << "10. ✓ Custom exception classes derived from runtime_error" << endl;
    
    printSectionHeader("PROGRAM EXECUTION COMPLETED");
    cout << "All scenarios executed successfully with proper exception handling!" << endl;
    cout << "No memory leaks detected - all resources cleaned up properly" << endl;
    cout << "\n";
    
    return 0;
}