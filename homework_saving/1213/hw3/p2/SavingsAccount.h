#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
public:
    SavingsAccount(double balance);
    void calculateMonthlyInterest();
    static void modifyInterestRate(double newRate);
    double getBalance() const;
private:
    double savingsBalance;
    static double annualInterestRate;
};

#endif