//Project: Guessing Game
//Author: Giancarlos A. Arenas-Barajas
//Date: 15Jan2024
//Description:
//  Computer will tell the user to guess a number between 1-100.
//  User gets 5 tries to guess the correct number.
//***************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void guessesLeft(int& guessCount){
    guessCount--;
    if(guessCount > 1){
        cout << "You have " << guessCount << " guesses left" << endl;
    }else{
        cout << "You have " << guessCount << " guess left" << endl;
    }
}

void validateGuess(int& guess, int& guessCount){
    if((guess < 1 || guess > 100 || cin.fail()) && guessCount != 1){
        cout << "ERROR: *** INCORRECT INPUT! ***" << endl << endl;
        cout << "You must enter a number between 1 and 100" << endl;
        guessesLeft(guessCount);

        //clears any error flags
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter your guess: " << endl;
        cin >> guess;
        cout << endl;

        validateGuess(guess, guessCount);
    }
    return;
}

void guessHigher(int& guess, int& guessCount){
    cout << "Try a lower number. Enter your guess: ";
    cin >> guess;
    cout << endl;
    validateGuess(guess, guessCount);
}

void guessLower(int& guess, int& guessCount){
    cout << "Try a higher number. Enter your guess: ";
    cin >> guess;
    cout << endl;
    validateGuess(guess, guessCount);
}

int main(){
    //start seed to generate a random number
    srand(static_cast<unsigned int>(time(0)));
    //generate random number
    int randNum = rand() % 100 + 1;

    //variables
    int userGuess;
    int guessCount = 5;

    //Game intro.
    cout << endl << endl << endl;
    cout << "Hello. Lets play a game." << endl;
    cout << "I will pick a number between 1 and 100." << endl;
    cout << "You have to guess the number in 5 guesses." << endl;

    //Get guess from user
    cout << endl << "Enter your guess: ";
    cin >> userGuess;
    cout << endl;

    validateGuess(userGuess, guessCount);

    //while loop to determin if guess is correct
    while(userGuess != randNum && guessCount != 1){
        cout << "Wrong guess." << endl;

        if(userGuess > randNum){
            guessesLeft(guessCount);
            guessHigher(userGuess, guessCount);
        } else{
            guessesLeft(guessCount);
            guessLower(userGuess, guessCount);
        }
    }
    
    if(guessCount == 1){
        cout << "Looks like you're all out of guesses :(" << endl;
        cout << "GAME OVER!" << endl;
    }

    if(userGuess == randNum){
        cout << "Congratulations!" << endl;
        cout << "You win :)" << endl;
        cout << "Heres some cake" << endl;
        cout << "    _____|______ " << endl;
        cout << "   |            | " << endl;
        cout << "   | *congrats* | " << endl;
        cout << " __|____________|__" << endl;
    }

    cout << endl << endl << endl;

    return 0;  
}