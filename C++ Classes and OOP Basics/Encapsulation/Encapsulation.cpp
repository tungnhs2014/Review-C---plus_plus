#include <iostream>
using namespace std;

// Define the Account class to demonstrate encapsulation
class Account {
private:
    // Private attribute: 'balance' cannot be accessed directly from outside the class
    double balance;

public:
    // Constructor to initialize the balance
    Account(double initialBalance) {
        // If the initial balance is non-negative, set it
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            // Otherwise, set balance to 0 and provide a warning
            balance = 0;
            cout << "Invalid initial balance. Setting balance to 0." << endl;
        }
    }

    // Public method to set the balance (Setter)
    void setBalance(double newBalance) {
        // Ensure the new balance is valid (non-negative)
        if (newBalance >= 0) {
            balance = newBalance;
        } else {
            // Print an error message if the new balance is negative
            cout << "Invalid balance. Balance cannot be negative." << endl;
        }
    }

    // Public method to get the balance (Getter)
    double getBalance() {
        return balance; // Return the current balance
    }

    // Method to deposit an amount into the account
    void deposit(double amount) {
        // Only allow deposits of positive amounts
        if (amount > 0) {
            balance += amount;  // Add the amount to the balance
        } else {
            // Print an error message if the deposit amount is not positive
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Method to withdraw an amount from the account
    void withdraw(double amount) {
        // Only allow withdrawals if the amount is positive and less than or equal to the current balance
        if (amount > 0 && amount <= balance) {
            balance -= amount;  // Subtract the amount from the balance
        } else {
            // Print an error message if the withdrawal is invalid
            cout << "Invalid withdraw amount. Withdrawal must be less than or equal to the current balance." << endl;
        }
    }
};

int main() {
    // Create an object of the Account class with an initial balance of 1000
    Account myAccount(1000);

    // Display the initial balance using the getter method
    cout << "Initial balance: $" << myAccount.getBalance() << endl;

    // Deposit money into the account
    myAccount.deposit(500);
    cout << "Balance after deposit: $" << myAccount.getBalance() << endl;

    // Withdraw money from the account
    myAccount.withdraw(300);
    cout << "Balance after withdrawal: $" << myAccount.getBalance() << endl;

    // Attempt to set an invalid balance
    myAccount.setBalance(-200);  // This should not change the balance
    cout << "Balance after setting invalid balance: $" << myAccount.getBalance() << endl;

    return 0;
}

/*
    Initial balance: $1000
    Balance after deposit: $1500
    Balance after withdrawal: $1200
    Invalid balance. Balance cannot be negative.
    Balance after setting invalid balance: $1200


*/