#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{

// +
public:
    //constructor
    Game (int maxNumber);
    //destructor ~
    ~Game ();

    void play ();

// -
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult ();

// #
protected:


};


#endif // ARVAUSPELI_H
