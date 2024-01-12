#include<iostream>
#include<string>
#include"Account.h"

using namespace std;

Account::Account()
:balance(0.0){
    
}
Account::Account(double bal)
:balance(bal){
    void checkBalance();    
}

void Account::checkBalance(){
    if(Account::getBalance() < 0){
        cout << "Your balance is negative. Please add funds to your account." << endl;
        Account::balance = 0.0;
    }
}

double Account::getBalance(){
    return balance;
}

void Account::credit(double amount){
    balance += amount;
}

void Account::debit(double amount){
    balance -= amount;
    if(balance < 0){
        cout << "Debit amount exceeded account balance." << endl;
        balance += amount;
    }
}
