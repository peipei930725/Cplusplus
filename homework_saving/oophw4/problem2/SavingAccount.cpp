#include"SavingAccount.h"
#include<iostream>
#include<string>

using namespace std;

SavingsAccount::SavingsAccount()
:Account(),interestRate(0){
    
}

SavingsAccount::SavingsAccount(double bal,double rate)
:Account(bal),interestRate(rate){
    
}

void SavingsAccount::setInterestRate(double rate){
    interestRate = rate;
}

double SavingsAccount::getInterestRate(){
    return interestRate;
}

double SavingsAccount::calculateInterest(){
    return Account::getBalance() * interestRate;
}