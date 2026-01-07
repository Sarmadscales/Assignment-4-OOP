# OOP Assignment 4: Exception Handling with BankAccount

## 📋 Assignment Information

**Course:** Object-Oriented Programming (CP223-F25-BS-AI-F24-AC2)  
**Instructor:** Syed Atir Raza Shirazi  
**Student:** Muhammad Sarmad  
**Registration:** L1F24BSAI0059  
**Assignment Date:** January 08, 2026  
**Submission Date:** January 09, 2026  

---

## 🎯 Assignment Objective

Design a **simple resource-management class** named `BankAccount` that demonstrates **exception handling integrated with object lifecycle management**.

---

## 📚 Key Concepts Covered

1. **Exception Handling**
   - throw, try, catch keywords
   - Custom exception classes
   - Exception propagation

2. **Constructor Exception Handling**
   - Validation before resource allocation
   - Object creation failure
   - Memory leak prevention

3. **Dynamic Memory Management**
   - Proper use of new and delete
   - Exception-safe allocation
   - Deep copy implementation

4. **Object Lifecycle**
   - Constructor execution order
   - Destructor cleanup
   - Stack unwinding

---

## 📁 Project Structure

```
OOP-Assignment-4/
├── BankAccount.h          # Header file with class declaration
├── BankAccount.cpp        # Implementation of member functions
├── main.cpp               # Test program with 5 scenarios
├── README.md              # This file
└── Documentation.docx     # Professional documentation
```

---

## 🔧 Compilation & Execution

### Using g++:
```bash
g++ -std=c++11 -o assignment4 BankAccount.cpp main.cpp
./assignment4
```

### Using clang++:
```bash
clang++ -std=c++11 -o assignment4 BankAccount.cpp main.cpp
./assignment4
```

---

## 🎬 Demonstration Scenarios

### Scenario 1: Valid Account Creation
- Creates account with valid positive balance
- Performs deposits and withdrawals
- Shows normal flow without exceptions

### Scenario 2: Invalid Balance Exception
- Attempts to create account with negative balance
- Constructor throws `InvalidBalanceException`
- Object is never created, no destructor called

### Scenario 3: Insufficient Funds Exception
- Creates valid account
- Attempts withdrawal exceeding balance
- `withdraw()` throws `InsufficientFundsException`
- Object state preserved, proper cleanup

### Scenario 4: Dynamic Allocation Safety
- Uses `new` operator for dynamic allocation
- Demonstrates proper memory management
- Shows destructor triggering with `delete`

### Scenario 5: Exception Safety Demonstration
- Creates multiple objects
- Shows exception during third object creation
- Demonstrates stack unwinding
- Destructors called in reverse order

---

## 💡 Key Features

✅ **Custom Exception Classes**
- `InvalidBalanceException` - thrown for negative balance
- `InsufficientFundsException` - thrown for overdraft attempts

✅ **Safe Constructor Design**
- Validates parameters before allocating resources
- Prevents memory leaks on exception

✅ **Dynamic Memory**
- Demonstrates proper allocation/deallocation
- Shows deep copy in copy constructor
- Ensures no memory leaks

✅ **Detailed Console Output**
- Constructor messages show creation order
- Destructor messages show cleanup order
- Exception messages show error handling

---

## 📊 Program Output Highlights

The program produces detailed output showing:
- `[CONSTRUCTOR]` - Object creation and validation
- `[WITHDRAW]` - Transaction processing
- `[DEPOSIT]` - Balance updates
- `[DESTRUCTOR]` - Memory cleanup
- `[SCENARIO]` - Test case progress

---

## 🎓 Learning Outcomes

After completing this assignment, you will understand:

1. How exceptions interrupt normal program flow
2. When destructors are (and aren't) called
3. The critical importance of validation order in constructors
4. How to prevent memory leaks with exceptions
5. The concept of stack unwinding
6. Exception-safe resource management techniques

---

## 🔬 Technical Details

### Exception Classes:
```cpp
class InvalidBalanceException : public exception
class InsufficientFundsException : public exception
```

### BankAccount Class Members:
```cpp
private:
    string accountHolderName;
    double balance;
    int* accountID;  // Dynamic memory

public:
    BankAccount(const string& name, double initialBalance);
    ~BankAccount();
    void withdraw(double amount);
    void deposit(double amount);
    void displayAccount() const;
```

---

## 📝 Assignment Requirements Met

✅ Constructor validates balance and throws exception if negative  
✅ withdraw() throws exception if amount exceeds balance  
✅ Dynamic memory allocation using new  
✅ Destructors invoked correctly even with exceptions  
✅ No memory leaks in any scenario  
✅ Console messages show execution order  
✅ Demonstrates throw, try, catch  
✅ Exception handling in constructor  
✅ Safe cleanup using destructors  
✅ Clear understanding of exception flow  

---

## 👨‍💻 Author

**Muhammad Sarmad**  
Bachelor of Science in Artificial Intelligence  
University of Central Punjab, Lahore  
L1F24BSAI0059  

---

## 📄 License

This project is created for educational purposes as part of the OOP course curriculum.

---

## 🙏 Acknowledgments

Special thanks to **Sir Syed Atir Raza Shirazi** for excellent instruction and guidance throughout the Object-Oriented Programming course.

---


**Note:** This assignment demonstrates professional C++ programming practices including proper exception handling, memory management, and code organization. All scenarios have been tested and verified for correctness.

---

*Last Updated: January 08, 2026*
