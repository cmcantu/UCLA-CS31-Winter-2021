//
//  PlaneFlight.cpp
//  Project 5
//
//  Created by Cassandra Cantu on 2/25/21.
//  Copyright © 2021 Cassandra Cantu. All rights reserved.
//

#include "PlaneFlight.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage)
{
    //name
    if (passengerName != "") //not empty string
        mName = passengerName;
    else
        mName = "?name?";
    
    //cost
    if (cost >= 0) {
        mCost = cost;
    }
    else {
        mCost = -1;
    }
    
    //from and to city
    if (fromCity != toCity) { //if different
        mFromCity = fromCity;
        mToCity = toCity;
    }
    else { //if same
        mFromCity = "?from?";
        mToCity = "?to?";
    }
    
    //mileage
    if (mileage > 0) {
        mMileage = mileage;
    }
    else {
        mMileage = -1;
    }
}

//accessors
//cost
    double PlaneFlight::getCost( )
    {
        return mCost;
    }

    void PlaneFlight::setCost(double cost)
    {
        if (cost >= 0) { //valid cost
            mCost = cost;
        }
        else
            mCost = -1.000000; //store -1 for invalid cost
    }

//mileage
    double PlaneFlight::getMileage()
    {
        return mMileage;
    }

    void PlaneFlight::setMileage(double mileage)
    {
        if (mileage > 0) { //valid mileage
            mMileage = mileage;
        }
        else
            mMileage = -1; //store -1 for invalid mileage
    }

//name
    string PlaneFlight::getName( )
    {
        return mName;
    }

    void PlaneFlight::setName(string name)
    {
        if (name != "") { //check for empty string
            mName = name;
        }
    }

//from city
    string PlaneFlight::getFromCity( )
    {
        return mFromCity;
    }

    void PlaneFlight::setFromCity(string from)
    {
        if (from != "") {  //check for empty string
            if (from != mToCity) { //check if different
                mFromCity = from;
            }
        }
    }

//to city
    string PlaneFlight::getToCity( )
    {
        return mToCity;
    }

    void PlaneFlight::setToCity(string to)
    {
        if (to != "") { //check for empty string
            if (to != mFromCity) { //check if different
            mToCity = to;
            }
        }
    }

