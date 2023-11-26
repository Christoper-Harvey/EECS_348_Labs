#include <iostream>
#include <string>

// Base class for all types of bank accounts
class Account {
public:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    // Create constructor
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    // Display account details
    virtual void displayDetails() const {
        std::cout << "Account Details for Account (ID: " << accountNumber << "):" << std::endl;
        std::cout << "   Holder: " << accountHolder << std::endl;
        std::cout << "   Balance: $" << balance << std::endl;
    }

    // Deposit money into the account
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " into the account." << std::endl;
    }

    // Withdraw money from the account
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from the account." << std::endl;
        } else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

    // Virtual destructor for proper cleanup
    virtual ~Account() {}

    // Overload + operator to allow transferring money between accounts
    friend Account operator+(const Account& lhs, const Account& rhs) {
        Account result("Transfer", "Transfer", 0);
        result += lhs;
        result += rhs;
        return result;
    }

    // Overload += operator to add two Account objects
    Account& operator+=(const Account& other) {
        this->balance += other.balance;
        return *this;
    }

    // Overload << operator to display account details
    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        os << "Account Details for Account (ID: " << account.accountNumber << "):" << std::endl;
        os << "   Holder: " << account.accountHolder << std::endl;
        os << "   Balance: $" << account.balance << std::endl;
        return os;
    }
};

// Derived class from the Account class
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Create constructor
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    // Display account details
    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Interest Rate: " << interestRate * 100 << "%" << std::endl;
    }

    // Override withdraw method to enforce a minimum balance
    void withdraw(double amount) override {
        if (balance - amount >= 100) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from the savings account." << std::endl;
        } else {
            std::cout << "Withdrawal not allowed. Minimum balance must be maintained." << std::endl;
        }
    }
};

// Derived class from the Account class
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    // Create constructor
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    // Display account details
    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Overdraft Limit: $" << overdraftLimit << std::endl;
    }

    // Override withdraw method to allow overdrafts up to the specified limit
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from the current account." << std::endl;
        } else {
            std::cout << "Withdrawal not allowed. Overdraft limit exceeded." << std::endl;
        }
    }
};

int main() {
    // Create instances of SavingsAccount and CurrentAccount
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    // Display initial account details
    savings.displayDetails();
    current.displayDetails();

    // Deposit $500 into the savings account and withdraw $1000 from the current account
    savings.deposit(500);
    current.withdraw(1000);

    // Display account details after deposit and withdrawal
    savings.displayDetails();
    current.displayDetails();

    // Transfer $300 from savings to current
    savings.withdraw(300);
    current.deposit(300);

    // Display account details after transfer
    savings.displayDetails();
    current.displayDetails();

    return 0;
}
