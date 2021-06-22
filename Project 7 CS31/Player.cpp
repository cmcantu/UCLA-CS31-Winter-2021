//
//  Player.cpp
//  BeatThat
//

#include "Player.h"
#include "RandomNumber.h" //use to get random number
#include <iostream>

namespace cs31
{
    // Each Player has two six-sided dies and tracks how many rounds have been won
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mRoundsWon(0)
    {
        
    }
    
    void Player::roll( Die d1, Die d2 )
    {
        // cheating...
        mDie1 = d1;
        mDie2 = d2;
    }

    // TODO: randomly roll each of the Player's die ok!
    void Player::roll( )
    {
        RandomNumber sidesofDie(1,6); //a side between 1-6
        int side1 = sidesofDie.random(); //generate random number
        int side2 = sidesofDie.random();
        mDie1.setValue(side1); //set value to random number
        mDie2.setValue(side2);
        
    }
    
    // trivial getter
    Die Player::getDie1() const
    {
        return( mDie1 );
    }

    // trivial getter
    Die Player::getDie2( ) const
    {
        return( mDie2 );
    }
    
    // TODO: called to indicate that this Player has won a round of play
    //       it should increment the RoundsWon counter
    void Player::wonARound( )
    {
        mRoundsWon++;
    }

    // TODO: trivial getter ok!
    int  Player::getRoundsWon( ) const
    {
        return(mRoundsWon);
    }

    // TODO: identify and return the die with the largest value ok!
    Die  Player::largestDie( ) const
    {
        Die max = mDie1; //initialize max die
        if (mDie2.getValue() > mDie1.getValue() ) //compare values of dice
            max = mDie2;
        return(max);
    }

    // TODO: identify and return the die with the largest value (smallest) ok!
    Die  Player::smallestDie( ) const
    {
        Die min = mDie1; //initialize min die
        if (mDie2.getValue() < mDie1.getValue() ) //compare values of dice
                min = mDie2;
        return(min);
    }

    // for testing purposes
    std::string Player::whatWasRolled()
    {
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        return( s );
    }
    
    

}
