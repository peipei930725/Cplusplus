#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include"Account.h"
#include<iostream>
#include<string>

using namespace std;

class SavingsAccount:public Account{
    public:
        SavingsAccount();
        SavingsAccount(double,double);
        void setInterestRate(double);
        double getInterestRate();
        double calculateInterest();
    private:
        double interestRate;
};

#endif