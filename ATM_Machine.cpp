//-----Personal Project-----//

#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a user account
struct Account {
    string accountNumber;
    string PIN;
    double balance;
};

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Set PIN: ";
    cin >> newAccount.PIN;
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to authenticate the user
bool authenticateUser(const vector<Account>& accounts, string accountNumber, string PIN) {
    for (const auto& account : accounts) {
        if (account.accountNumber == accountNumber && account.PIN == PIN) {
            return true;
        }
    }
    return false;
}

// Function to get the index of the user's account
int getAccountIndex(const vector<Account>& accounts, string accountNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Function to check account balance
void checkBalance(const vector<Account>& accounts, string accountNumber) {
    int index = getAccountIndex(accounts, accountNumber);
    if (index != -1) {
        cout << "Your current balance is: $" << accounts[index].balance << endl;
    } else {
        cout << "Invalid account number!" << endl;
    }
}

// Function to deposit money
void deposit(vector<Account>& accounts, string accountNumber, double amount) {
    int index = getAccountIndex(accounts, accountNumber);
    if (index != -1) {
        accounts[index].balance += amount;
        cout << "$" << amount << " deposited successfully!" << endl;
    } else {
        cout << "Invalid account number!" << endl;
    }
}

// Function to withdraw money
void withdraw(vector<Account>& accounts, string accountNumber, double amount) {
    int index = getAccountIndex(accounts, accountNumber);
    if (index != -1) {
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            cout << "$" << amount << " withdrawn successfully!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    } else {
        cout << "Invalid account number!" << endl;
    }
}

// Function to change PIN
void changePIN(vector<Account>& accounts, string accountNumber, string newPIN) {
    int index = getAccountIndex(accounts, accountNumber);
    if (index != -1) {
        accounts[index].PIN = newPIN;
        cout << "PIN changed successfully!" << endl;
    } else {
        cout << "Invalid account number!" << endl;
    }
}

int main() {
    vector<Account> accounts;
    int choice;
    string accountNumber, PIN, newPIN; // Move newPIN here
    
    do {
        cout << "Welcome to the ATM!" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter PIN: ";
                cin >> PIN;
                
                if (authenticateUser(accounts, accountNumber, PIN)) {
                    int userChoice;
                    do {
                        cout << "1. Check Balance" << endl;
                        cout << "2. Deposit" << endl;
                        cout << "3. Withdraw" << endl;
                        cout << "4. Change PIN" << endl;
                        cout << "5. Logout" << endl;
                        cout << "Enter your choice: ";
                        cin >> userChoice;
                        
                        switch (userChoice) {
                            case 1:
                                checkBalance(accounts, accountNumber);
                                break;
                            case 2:
                                double depositAmount;
                                cout << "Enter the amount to deposit: $";
                                cin >> depositAmount;
                                deposit(accounts, accountNumber, depositAmount);
                                break;
                            case 3:
                                double withdrawAmount;
                                cout << "Enter the amount to withdraw: $";
                                cin >> withdrawAmount;
                                withdraw(accounts, accountNumber, withdrawAmount);
                                break;
                            case 4:
                                cout << "Enter the new PIN: ";
                                cin >> newPIN;
                                changePIN(accounts, accountNumber, newPIN);
                                break;
                            case 5:
                                cout << "Logged out successfully!" << endl;
                                break;
                            default:
                                cout << "Invalid choice!" << endl;
                        }
                    } while (userChoice != 5);
                } else {
                    cout << "Authentication failed! Please try again." << endl;
                }
                break;
            case 3:
                cout << "Exiting the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}
