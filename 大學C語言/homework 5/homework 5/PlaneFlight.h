#pragma once
#include<iostream>
#include<string>

using namespace std;

class PlaneFlight {
private:
    double mCost = 0, mMileage = 0;
    string mFromCity = "NULL", mToCity = "NULL", mName = "NULL";

public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    }

    double getCost() {
        return mCost;
    }
    void setCost(double cost) {
        if (cost < 0)
            return;
    }

    double getMileage() {
        return mMileage;
    }
    void setMileage(double Mileage) {
        if (Mileage < 0)
            return;
    }

    string getName() {
        return mName;
    }
    void setName(string name) {
        if (name == "NULL")
            return;
    }

    string getFromCity() {
        return mFromCity;
    }
    void setFromCity(string from) {
        if (from == "NULL")
            return;
    }

    string getToCity() {
        return mToCity;
    }
    void setToCity(string to) {
        if (to == "NULL")
            return;
    }

};