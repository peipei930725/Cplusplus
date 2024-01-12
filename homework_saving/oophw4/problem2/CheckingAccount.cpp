#include"CheckingAccount.h"
#include<iostream>
#include<string>

using namespace std;

CheckingAccount::CheckingAccount()
:Account(),fee(0){

}

CheckingAccount::CheckingAccount(double bal,double f)
:Account(bal),fee(f){
    
}

void CheckingAccount::setFee(double f){
    fee = f;
}

double CheckingAccount::getFee(){
    return fee;
}

void CheckingAccount::credit(double amount){
    Account::credit(amount);
    Account::debit(fee);
    if (Account::getBalance() < 0){
        cout << "Your balance is negative. Please add funds to your account." << endl;
        Account::debit(amount);
        Account::credit(fee);
    }
}

void CheckingAccount::debit(double amount){
    Account::debit(amount);
    Account::debit(fee);
    if (Account::getBalance() < 0){
        cout << "Your balance is negative. Please add funds to your account." << endl;
        Account::credit(amount);
        Account::credit(fee);
    }
}
