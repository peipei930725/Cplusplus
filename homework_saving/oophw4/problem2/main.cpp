#include"Account.cpp"
#include"CheckingAccount.cpp"
#include"SavingAccount.cpp"
#include<iostream>
#include<string>

using namespace std;

int main(){
    Account a(1000);
    CheckingAccount c(1000,5);
    SavingsAccount s(1000,0.1);
    
    cout << "Account balance: " << a.getBalance() << endl;
    cout << "Checking account balance: " << c.getBalance() << endl;
    cout << "Savings account balance: " << s.getBalance() << endl;
    
    cout << "Credit 100 to account" << endl;
    a.credit(100);
    cout << "Credit 100 to checking account" << endl;
    c.credit(100);
    cout << "Credit 100 to savings account" << endl;
    s.credit(100);
    
    cout << "Account balance: " << a.getBalance() << endl;
    cout << "Checking account balance: " << c.getBalance() << endl;
    cout << "Savings account balance: " << s.getBalance() << endl;
    
    cout << "Debit 100 from account" << endl;
    a.debit(100);
    cout << "Debit 100 from checking account" << endl;
    c.debit(100);
    cout << "Debit 100 from savings account" << endl;
    s.debit(100);
    
    cout << "Account balance: " << a.getBalance() << endl;
    cout << "Checking account balance: " << c.getBalance() << endl;
    cout << "Savings account balance: " << s.getBalance() << endl;
    
    cout << "Checking account fee: " << c.getFee() << endl;
    cout << "Credit 100 to checking account" << endl;
    c.credit(100);
    cout << "Debit 100 from checking account" << endl;
    c.debit(100);
    
    cout << "Checking account balance: " << c.getBalance() << endl;
    
    cout << "Savings account interest rate: " << s.getInterestRate() << endl;
    cout << "Calculate interest for savings account" << endl;
    cout << "Interest: " << s.calculateInterest() << endl;
    
    cout << "Savings account balance: " << s.getBalance() << endl;
    
    return 0;
}