#include <iostream>
#include <iomanip>
using namespace std;

class Person {
protected:
    int id;
    int age;

public:
    Person(int personId, int personAge) : id(personId), age(personAge) {}

    void showPersonDetails() {
        cout << "Person ID: " << id << "\nAge: " << age << endl;
    }
};

class BankAccount {
public:
    int accountNumber;
    float balance;

    BankAccount(int accNum, float bal = 0) : accountNumber(accNum), balance(bal) {}

    virtual void checkBalance() {
        cout << "Account Number: " << accountNumber << "\nBalance: $" 
             << fixed << setprecision(3) << balance << endl;
    }

    virtual void deposit(float amount) {
        balance += amount;
        cout << "$" << fixed << setprecision(3) << amount << " deposited. New balance: $" 
             << fixed << setprecision(3) << balance << endl;
    }

    virtual bool withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "$" << fixed << setprecision(3) << amount << " withdrawn. New balance: $" 
                 << fixed << setprecision(3) << balance << endl;
            return true;
        } else {
            cout << "Insufficient funds!" << endl;
            return false;
        }
    }
};

class SavingsAccount : public BankAccount {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float bal, float rate) : BankAccount(accNum, bal), interestRate(rate) {}

    void addInterest() {
        balance += (balance * interestRate / 100);
        cout << "Interest added. New balance: $" << fixed << setprecision(3) << balance << endl;
    }

    void checkBalance() override {
        cout << "Savings Account Number: " << accountNumber << "\nBalance: $" << fixed 
             << setprecision(3) << balance << "\nInterest Rate: " << interestRate << "%" << endl;
    }
};

class Overdraft {
protected:
    float overdraftLimit;

public:
    Overdraft(float limit) : overdraftLimit(limit) {}

    bool checkOverdraft(float amount, float& balance) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
};

class CurrentAccount : public BankAccount, public Overdraft {
public:
    CurrentAccount(int accNum, float bal, float limit) : BankAccount(accNum, bal), Overdraft(limit) {}

    bool withdraw(float amount) override {
        if (checkOverdraft(amount, balance)) {
            cout << "$" << fixed << setprecision(3) << amount << " withdrawn using overdraft. New balance: $" 
                 << fixed << setprecision(3) << balance << endl;
            return true;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
            return false;
        }
    }

    void checkBalance() override {
        cout << "Current Account Number: " << accountNumber << "\nBalance: $" << fixed 
             << setprecision(3) << balance << "\nOverdraft Limit: $" << overdraftLimit << endl;
    }
};

class PremiumAccount : public SavingsAccount {
public:
    PremiumAccount(int accNum, float bal, float rate) : SavingsAccount(accNum, bal, rate) {}

    void premiumServices() {
        cout << "Premium services are available for account number: " << accountNumber << endl;
    }
};

class ATM {
public:
    void performTransaction(BankAccount* account) {
        int choice;
        float amount;

        SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(account);

        do {
            cout << "\nATM Menu:\n1. Check Balance\n2. Deposit\n3. Withdraw";
            if (savingsAccount) {
                cout << "\n4. Add Interest";
            }
            cout << "\n5. Exit\n6. Return to Main Menu\nChoose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    account->checkBalance();
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                    break;
                case 3:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                    break;
                case 4:
                    if (savingsAccount) {
                        savingsAccount->addInterest();
                    } else {
                        cout << "Invalid option!" << endl;
                    }
                    break;
                case 5:
                    cout << "Exiting ATM..." << endl;
                    break;
                case 6:
                    cout << "Returning to Main Menu..." << endl;
                    return;
                    break;
                default:
                    cout << "Invalid option!" << endl;
            }
        } while (choice != 5);
    }
};

void showMainMenu() {
    cout << "Welcome to the ATM System\n";
    cout << "Select account type:\n";
    cout << "1. Savings Account\n2. Current Account\n3. Premium Account\n";
    cout << "Choose account type: ";
}

int main() {
    SavingsAccount savings1(101, 1000.0f, 2.5f);
    SavingsAccount savings2(102, 1500.0f, 3.0f);

    CurrentAccount current1(201, 500.0f, 300.0f);
    CurrentAccount current2(202, 750.0f, 500.0f);
    
    PremiumAccount premium1(301, 2000.0f, 3.5f);
    PremiumAccount premium2(302, 3000.0f, 4.0f);

    ATM atm;
    int accountChoice;
    int accountNumber;

    while (true) {
        cout << "Enter account number: ";
        cin >> accountNumber;

        showMainMenu();
        cin >> accountChoice;

        BankAccount* account = nullptr;

        switch (accountChoice) {
            case 1:
                if (accountNumber == savings1.accountNumber) {
                    account = &savings1;
                } else if (accountNumber == savings2.accountNumber) {
                    account = &savings2;
                } else {
                    cout << "Account number does not match any Savings Account!" << endl;
                    return 1;
                }
                break;
            case 2:
                if (accountNumber == current1.accountNumber) {
                    account = &current1;
                } else if (accountNumber == current2.accountNumber) {
                    account = &current2;
                } else {
                    cout << "Account number does not match any Current Account!" << endl;
                    return 1;
                }
                break;
            case 3:
                if (accountNumber == premium1.accountNumber) {
                    account = &premium1;
                } else if (accountNumber == premium2.accountNumber) {
                    account = &premium2;
                } else {
                    cout << "Account number does not match any Premium Account!" << endl;
                    return 1;
                }
                break;
            default:
                cout << "Invalid account type!" << endl;
                return 1;
        }

        atm.performTransaction(account);

        if (accountChoice == 3) {
            PremiumAccount* premiumAccount = dynamic_cast<PremiumAccount*>(account);
            if (premiumAccount) {
                premiumAccount->premiumServices();
            }
        }

        char restart;
        cout << "\nDo you want to perform another transaction? (Y/N): ";
        cin >> restart;

        if (restart == 'N' || restart == 'n') {
            cout << "Thank you for using the ATM System. Goodbye!" << endl;
            break;
        } else if (restart == 'Y' || restart == 'y') {
            cout << "Returning to main menu..." << endl;
            continue;
        } else {
            cout << "Invalid input, returning to main menu..." << endl;
            continue;
        }
    }

    return 0;
}