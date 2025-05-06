#include<iostream>
#include<string>

using namespace std;

class Account {
    public:
    string name;
    string accountNumber;
    double balance;

    Account(string name, string accountNumber, double balance) : name(name), accountNumber(accountNumber), balance(balance) {};
    void setname( string name) {
        this->name = name;
    }
    void setaccountNumber(string accountNumber) {
        this->accountNumber = accountNumber;
    }

    void setbalance(int balance) {
        this->balance = balance;
    }

    string getname() {
        return name;
    }
    string getaccountNumber() {
        return accountNumber;
    }
    double getbalance() {
        return balance;
    }

    virtual void calculateInterest() = 0;
    virtual void displayAccountDetails() const = 0;

    virtual ~Account() {};
};

class SavingsAccount : public Account {
    public:
    SavingsAccount(string name, string accountNumber, double balance) : Account(name, accountNumber,balance){}
        void calculateInterest() {
            balance += balance * 0.05;
            }
            void displayAccountDetails() const override {
                cout << "Account Name: " << name << endl;
                cout << "Account Number: " << accountNumber << endl;
                cout << "Balance: " << balance << endl;
            }
        };

class CheckingAccount : public Account {
    public:
    CheckingAccount(string name, string accountNumber, int balance) : Account(name, accountNumber,balance){}
    void calculateInterest() {
        cout << "No interest is applied to checking accounts." << endl;
    }
    void displayAccountDetails() const override {
        cout << "Account Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }


};    

class BusinessAccount : public Account {
    private:
    static const double interestRate;
    public:
    BusinessAccount(string name, string accountNumber, double balance) : Account(name, accountNumber,balance) {}
    void calculateInterest() {
        balance += balance * interestRate;
        }
        void displayAccountDetails() const override {
            cout << "Account Name: " << name << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

const double BusinessAccount::interestRate = 0.03;

int main(){
    SavingsAccount savingsAccount("Muhammad Adil Saeed", "PKBHAL123456789", 1000.0);
    savingsAccount.calculateInterest();
    savingsAccount.displayAccountDetails();

    CheckingAccount checkingAccount("Muhammad Adil Saeed", "PKBHAL123456789", 1234.09);
    checkingAccount.calculateInterest();
    checkingAccount.displayAccountDetails();

    BusinessAccount businessAccount("Muhammad Adil Saeed", "PKBHAL123456789",1324.88);
    businessAccount.calculateInterest();
    businessAccount.displayAccountDetails();
    return 0;

    
}
