//
//  FrequentFlyerAccount.cpp
//  Project 5
//
//  Created by Cassandra Cantu on 2/25/21.
//  Copyright © 2021 Cassandra Cantu. All rights reserved.
//

#include <string>
#include "FrequentFlyerAccount.h"
using namespace std;

//constructors
FrequentFlyerAccount::FrequentFlyerAccount(string name) //take in name
{
    mName = name;
    mBalance = 0; //start balance at 0
}
    
//accessors
double FrequentFlyerAccount::getBalance() //get balance of Frequent Flyer Account
{
    return mBalance;
}
string FrequentFlyerAccount::getName() //get name of Frequent Flyer Account
{
    return mName;
}

    
//modifiers
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) //add flight to Frequent Flyer Account
{
    bool b = false; //initialize var
    if (flight.getName() == mName) { //name matches account
        if (flight.getCost() > 0) { //paid for flight
            mBalance = mBalance + flight.getMileage(); //add flight to balance
             b = true;
        }
    }
    return b;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) //check if able to earn free flight
{
   
    bool b = false;
    if (mileage >0) { //must be greater than 0
        if (mBalance >= mileage) { //exceed or equal threshold for a free flight
            b = true;
        }
    }
    return b;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) //use earned free flight
{
    bool b = false;
    if (flight.getName() == mName) { //name matches account
        if (from != to) { //check if different
            string p1 = "p1"; //placeholder 1
            string p2 = "p2"; //placeholder 2
            flight.setToCity(p1); //reset to city
            flight.setFromCity(p2); //reset from city
            if (mBalance >= mileage) { //enough mileage to create a free flight
                b = true;
                mBalance = mBalance - mileage; //subtract flight from balance
                flight.setCost(0); //0 for cost bc free
                flight.setToCity(to); //to city of free flight
                flight.setFromCity(from); //from city of free flight
                flight.setMileage(mileage); //mileage of free flight
            }
        }
    }
    return b;
}
