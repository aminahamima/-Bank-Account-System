// System Bank Account Management System
// 3 actions: Display account, Deposit, Withdraw

#include <iostream>
#include <string>

using namespace std;

class BankAccount {

private: // Private because we don't want to allow direct access to these variables from outside the class
    string name;
    int accountNumber;
    double balance;

public: // Public can be accessed from outside the class

    // Constructor
    BankAccount(string n, int accNumber, double initialBalance) {
        name = n;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Display account information
    void displayAccount() {
        cout << "\n===== Account Information =====" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << " DH" << endl;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposit successful!" << endl;
            cout << "New balance: " << balance << " DH" << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        }
        else {
            balance = balance - amount;
            cout << "Withdrawal successful!" << endl;
            cout << "New balance: " << balance << " DH" << endl;
        }
    }
};

int main() {

    string name;
    int accountNumber;
    double initialBalance;

    cout << "===== Create Bank Account =====" << endl;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, accountNumber, initialBalance); // Create a BankAccount (object Class Object (parameters))

    int choice;
    double amount;

    do {

        cout << "\n===== BANK MENU =====" << endl;
        cout << "1. Display Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {

            case 1:
                account.displayAccount();
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                cout << "Thank you! Goodbye." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}