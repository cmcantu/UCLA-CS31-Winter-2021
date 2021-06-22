//
//  main.cpp
//  BeatThat
//
//

#include <iostream>
#include <string>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"


void clearScreen( );

int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
//assertions to test code
//Player
    Player p; //person
    Player c; //computer
    assert( p.getRoundsWon( ) == 0 ); // nothing won yet...
    p.wonARound( );
    assert( p.getRoundsWon( ) == 1 ); // won 1!
    p.roll( );   
    Die d1;
    d1.setValue(1);
    Die d6;
    d6.setValue(6);
    p.roll(d1,d6);
    assert( p.largestDie( ).getValue( ) == 6 ); 
    assert( p.smallestDie( ).getValue( ) == 1 );
    p.roll();
    string s = p.whatWasRolled(); //check for random
    cout << s << endl;
    p.roll(d1,d1); //roll 1 1 same number
    assert( p.largestDie( ).getValue( ) == 1 );
    assert( p.smallestDie( ).getValue( ) == 1 );
 //Board
    Board b;
    assert( b.getHumanRoundsWon( ) == 0 );
    assert( b.getComputerRoundsWon( ) == 0 );
    assert( b.getTurnsLeft( ) == 0 );
    assert( ! b.didHumanWin( ) );
    assert( ! b.didComputerWin( ) );
    assert( ! b.isGameOver() );

    b.setHumanRoundsWon( 1 );
    b.setComputerRoundsWon( 2 );
    b.setTurnsLeft( 3 );
    assert( b.getHumanRoundsWon( ) == 1 );
    assert( b.getComputerRoundsWon( ) == 2 );
    assert( b.getTurnsLeft( ) == 3 );

    b.markComputerAsWinner( );
    // b.markTied( );
    // b.markHumanAsWinner( );
    assert( ! b.didHumanWin( ) );
    assert( b.didComputerWin( ) );
    assert( b.isGameOver( ) );

 //BeatThat
    Die d2; d2.setValue( 2 );
    Die d3; d3.setValue( 3 );
    Die d4; d4.setValue( 4 );
    Die d5; d5.setValue( 5 ); //Note: have die 1 and 6 defined above
  //computer won
    BeatThat game;
    assert(game.turnsLeft()==5);
    assert(game.isGameOver( ) == false);
    game.humanPlay( d6, d2 );
    game.computerPlay( d3, d4 );
    game.endTurn( );  // human won this round...
    game.humanPlay( d5, d1 );
    game.computerPlay( d3, d4 );
    game.endTurn( );  // human won this round...
    game.humanPlay( d5, d2 );
    game.computerPlay( d6, d4 );
    game.endTurn( );  // computer won this round....
    assert( game.isGameOver() == false); //game not over at this point
    assert( game.determineGameOutcome( ) == BeatThat::GAMENOTOVER);
    game.humanPlay( d1, d1 );
    game.computerPlay( d3, d4 );
    game.endTurn( );  // computer won this round...
    game.humanPlay( d5, d4 );
    game.computerPlay( d3, d6 );
    game.endTurn( );  // computer won this round...
    assert( game.isGameOver() == true );
    assert( game.determineGameOutcome( ) != cs31::BeatThat::GAMENOTOVER ); //game over
    assert( game.determineGameOutcome( ) == BeatThat::COMPUTERWONGAME ); //computer won
    assert(game.getBoard().getHumanRoundsWon()==2);
    assert(game.getBoard().getComputerRoundsWon()==3);
    assert(game.getBoard().getTurnsLeft()==0); //no turns left
    assert(game.getBoard().didComputerWin() == true);
//human won
    BeatThat game2;
    game2.humanPlay( d3, d4 );
    game2.computerPlay( d6, d2 );
    game2.endTurn( );  // computer won this round...
    game2.humanPlay( d3, d4 );
    game2.computerPlay( d5, d1 );
    game2.endTurn( );  // computer won this round...
    game2.humanPlay( d6, d4 );
    game2.computerPlay( d5, d2 );
    game2.endTurn( );  // human won this round....
    game2.humanPlay( d3, d4 );
    game2.computerPlay( d1, d1 );
    game2.endTurn( );  // human won this round...
    assert( game2.isGameOver() == false); //game not over at this point
    assert( game2.determineGameOutcome( ) == BeatThat::GAMENOTOVER);
    game2.humanPlay( d3, d6 );
    game2.computerPlay( d5, d4 );
    game2.endTurn( );  // human won this round...
    assert( game2.isGameOver() == true );
    assert( game2.determineGameOutcome( ) != cs31::BeatThat::GAMENOTOVER );
    assert( game2.determineGameOutcome( ) == BeatThat::HUMANWONGAME ); //human won
    assert(game2.getBoard().getHumanRoundsWon()==3);
    assert(game2.getBoard().getComputerRoundsWon()==2);
    assert(game2.getBoard().getTurnsLeft()==0);
    assert(game2.getBoard().didHumanWin());
//tied game
    BeatThat game3;
    game3.humanPlay( d3, d4 );
    game3.computerPlay( d6, d2 );
    game3.endTurn( );  // computer won this round...
    assert( game3.isGameOver() == false); //game not over at this point
    assert( game3.determineGameOutcome( ) == BeatThat::GAMENOTOVER);
    game3.humanPlay( d3, d3 );
    game3.computerPlay( d3, d3 );
    game3.endTurn( );  // tied this round...
    game3.humanPlay( d6, d4 );
    game3.computerPlay( d5, d2 );
    game3.endTurn( );  // human won this round....
    game3.humanPlay( d3, d4 );
    game3.computerPlay( d3, d4 );
    game3.endTurn( );  // tied this round...
    game3.humanPlay( d3, d6 );
    game3.computerPlay( d3, d6 );
    game3.endTurn( );  // tied this round...
    assert( game3.isGameOver() == true ); //game over
    assert( game3.determineGameOutcome( ) != cs31::BeatThat::GAMENOTOVER );
    assert( game3.determineGameOutcome( ) == BeatThat::TIEDGAME );
    assert(game3.getBoard().getHumanRoundsWon()==1);
    assert(game3.getBoard().getComputerRoundsWon()==1);
    assert(game3.getBoard().getTurnsLeft()==0);
    
    cout << "all tests pass :)" << endl;
    cout << "~~~~~~~" << endl;
    
//end of tests
    
   // BeatThat game;
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;
        
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                game.humanPlay();
                game.computerPlay();
                game.endTurn();
                cout << game.display( message ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.endingMessage() << endl;

    return( 0 );
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


