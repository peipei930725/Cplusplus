#include "SavingsAccount.h"
#include <iostream>

using namespace std;

double SavingsAccount::annualInterestRate = 0.0;

SavingsAccount::SavingsAccount(double balance) 
: savingsBalance(balance)
{
}
void SavingsAccount::calculateMonthlyInterest(){
    savingsBalance += savingsBalance *(annualInterestRate/12);
}
void SavingsAccount::modifyInterestRate(double newRate){
    annualInterestRate = newRate;
}
double SavingsAccount::getBalance() const{
    return savingsBalance;
}