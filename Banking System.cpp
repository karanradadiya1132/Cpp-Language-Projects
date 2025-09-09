#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo = 0, string name = "", double bal = 0.0) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance() const { return balance; }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber
             << "\nHolder: " << accountHolderName
             << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }

    void displayAccountInfo() {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void displayAccountInfo() {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
    int term;
    double interestRate;
public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal), term(t), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * (interestRate / 100) * (term / 12.0);
        cout << "FD Interest (" << term << " months): " << interest << endl;
    }

    void displayAccountInfo() {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months, Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    BankAccount* accounts[10];
    int accountType[10];
    int accountCount = 0;

    int choice, accNo, term;
    string name;
    double balance, rate, limit, amount;

    while (true) {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Savings Account\n2. Create Checking Account\n3. Create Fixed Deposit\n";
        cout << "4. Deposit\n5. Withdraw\n6. Display Info\n7. Calculate Interest\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 8) break;

        switch (choice) {
            case 1:
                if (accountCount < 10) {
                    cout << "Enter AccNo, Name, Balance, InterestRate: ";
                    cin >> accNo >> name >> balance >> rate;
                    accounts[accountCount] = new SavingsAccount(accNo, name, balance, rate);
                    accountType[accountCount] = 1;
                    accountCount++;
                } else {
                    cout << "Account limit reached!" << endl;
                }
                break;

            case 2:
                if (accountCount < 10) {
                    cout << "Enter AccNo, Name, Balance, OverdraftLimit: ";
                    cin >> accNo >> name >> balance >> limit;
                    accounts[accountCount] = new CheckingAccount(accNo, name, balance, limit);
                    accountType[accountCount] = 2;
                    accountCount++;
                } else {
                    cout << "Account limit reached!" << endl;
                }
                break;

            case 3:
                if (accountCount < 10) {
                    cout << "Enter AccNo, Name, Balance, TermMonths, InterestRate: ";
                    cin >> accNo >> name >> balance >> term >> rate;
                    accounts[accountCount] = new FixedDepositAccount(accNo, name, balance, term, rate);
                    accountType[accountCount] = 3;
                    accountCount++;
                } else {
                    cout << "Account limit reached!" << endl;
                }
                break;

            case 4:
                cout << "Enter Account Index and Amount: ";
                cin >> accNo >> amount;
                if (accNo < accountCount) accounts[accNo]->deposit(amount);
                else cout << "Invalid account index!" << endl;
                break;

            case 5:
                cout << "Enter Account Index and Amount: ";
                cin >> accNo >> amount;
                if (accNo < accountCount) accounts[accNo]->withdraw(amount);
                else cout << "Invalid account index!" << endl;
                break;

            case 6:
                cout << "Enter Account Index: ";
                cin >> accNo;
                if (accNo < accountCount) {
                    if (accountType[accNo] == 1)
                        ((SavingsAccount*)accounts[accNo])->displayAccountInfo();
                    else if (accountType[accNo] == 2)
                        ((CheckingAccount*)accounts[accNo])->displayAccountInfo();
                    else if (accountType[accNo] == 3)
                        ((FixedDepositAccount*)accounts[accNo])->displayAccountInfo();
                } else cout << "Invalid account index!" << endl;
                break;

            case 7:
                cout << "Enter Account Index: ";
                cin >> accNo;
                if (accNo < accountCount) {
                    if (accountType[accNo] == 1)
                        ((SavingsAccount*)accounts[accNo])->calculateInterest();
                    else if (accountType[accNo] == 3)
                        ((FixedDepositAccount*)accounts[accNo])->calculateInterest();
                    else
                        cout << "No interest calculation for Checking Account!" << endl;
                } else cout << "Invalid account index!" << endl;
                break;
        }
    }

    for (int i = 0; i < accountCount; i++) {
        delete accounts[i];
    }
}
 
 
 
/*
     Output :-
     
     --- Banking System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit
4. Deposit
5. Withdraw
6. Display Info
7. Calculate Interest
8. Exit
Enter choice: 1
Enter AccNo, Name, Balance, InterestRate: 101 Karan 5000 5

--- Banking System ---
Enter choice: 2
Enter AccNo, Name, Balance, OverdraftLimit: 102 Raj 2000 1000

--- Banking System ---
Enter choice: 3
Enter AccNo, Name, Balance, TermMonths, InterestRate: 103 Dev 10000 12 7

--- Banking System ---
Enter choice: 4
Enter Account Index and Amount: 0 1000
Deposited: 1000, New Balance: 6000

--- Banking System ---
Enter choice: 5
Enter Account Index and Amount: 1 2500
Withdrawn: 2500, New Balance: -500

--- Banking System ---
Enter choice: 6
Enter Account Index: 2
Account Number: 103
Holder: Dev
Balance: 10000
Term: 12 months, Interest Rate: 7%

--- Banking System ---
Enter choice: 7
Enter Account Index: 0
Savings Interest: 300

--- Banking System ---
Enter choice: 7
Enter Account Index: 2
FD Interest (12 months): 700

--- Banking System ---
Enter choice: 8

*/