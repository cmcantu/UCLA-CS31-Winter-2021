//
//  FrequentFlyerAccount.h
//  Project 5
//
//  Created by Cassandra Cantu on 2/24/21.
//  Copyright © 2021 Cassandra Cantu. All rights reserved.
//

#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h
#include <string>
#include "PlaneFlight.h"
using namespace std;

class FrequentFlyerAccount {
public:
//constructors
    FrequentFlyerAccount(string name);
    
//accessors
    double getBalance();
    string getName();
    
//modifiers
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);

private:
    string mName;
    double mBalance;
};
#endif /* FrequentFlyerAccount_h */
