#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "finnish.h"
#include "Game.h"

using namespace std;

int maxNumber;

// Game CONSTRUCTOR
Game::Game (int targetNumber)
{
    maxNumber = targetNumber;
    srand(time(0)); // satunnaislukugen alustus
    randomNumber = rand() % targetNumber +1;
    playerGuess = -1;
    numOfGuesses = 0;


    cout << "Initialized " << targetNumber << " as a maxinum value for this game \n" ;
}

void Game::play ()
{
   while (playerGuess != randomNumber) {
       cout << "Give your guess between 1 - "<< maxNumber << "\n";
        //cout << "Place your guess between 1 - {}\n", this-> maxNumber;
       cin >> playerGuess;
       if (playerGuess < randomNumber) {
           cout << "Your guess is too small\n";
       }
       else if (playerGuess > randomNumber) {
           cout << "Your guess is too high\n";
       }
       numOfGuesses ++;
   }

   cout << "Your guess \" " << randomNumber << " \" is correct, congratulations! \n";
   cout << "You gave \" " << numOfGuesses << " \" answers in total.\n";
   void printGameResult();

}

// Game DESTRUCTOR
Game::~Game()
{
    cout << "Thank you for playing this game! \n";
}
