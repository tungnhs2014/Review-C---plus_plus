#include <iostream>

class BankAccount {
private:
    double balance;  // Private member

public:
    BankAccount(double bal) : balance(bal) {}

    friend class AccountManager;  // Declare AccountManager as a friend class
};

// Friend class with access to private members of BankAccount
class AccountManager {
public:
    void showBalance(const BankAccount& account) {
        std::cout << "The balance is: " << account.balance << std::endl;  // Access private member
    }
};

int main() {
    BankAccount myAccount(5000.0);  // Create a BankAccount object
    AccountManager manager;  // Create an AccountManager object
    manager.showBalance(myAccount);  // Output: The balance is: 5000
    return 0;
}

/*
    The balance is: 5000
*/