#include "SavingsAccount.h"

double SavingsAccount::annualInterestRate = 0.0;

SavingsAccount::SavingsAccount(double balance) : savingsBalance(balance) {}

void SavingsAccount::calculateMonthlyInterest() {
    savingsBalance += (savingsBalance * annualInterestRate) / 12.0;
}

void SavingsAccount::modifyInterestRate(double newRate) {
    annualInterestRate = newRate;
}

double SavingsAccount::getBalance() const {
    return savingsBalance;
}