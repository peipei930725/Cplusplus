#include "SavingsAccount.cpp"
#include<iostream>

using namespace std;

int main(){
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "Saver1's balance: " << saver1.getBalance() << "\n";
    cout << "Saver2's balance: " << saver2.getBalance() << "\n";

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "Saver1's balance: " << saver1.getBalance() << "\n";
    cout << "Saver2's balance: " << saver2.getBalance() << "\n";

    return 0;
}