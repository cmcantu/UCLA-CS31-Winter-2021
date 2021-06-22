//
//  PlaneFlight.h
//  Project 5
//
//  Created by Cassandra Cantu on 2/24/21.
//  Copyright © 2021 Cassandra Cantu. All rights reserved.
//
//------------------------------------------------------------------
// INTERFACE FILE: baccount.h

//
//-------------------------------------------------------------------
// SAFEGUARDS AND INCLUDES
#ifndef PlaneFlight_h
#define PlaneFlight_h
#include <string>
using namespace std;

class PlaneFlight {
public: //class member functions
//constructors
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);

//accessors
    double getCost( );
    void setCost(double cost);
    
    double getMileage( );
    void setMileage(double mileage);
    
    string getName( );
    void setName(string name);
    
    string getFromCity( );
    void setFromCity(string from);
    
    string getToCity( );
    void setToCity(string to);

private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;

};

#endif /* PlaneFlight_h */
