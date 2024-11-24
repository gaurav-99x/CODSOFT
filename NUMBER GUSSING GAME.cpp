#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessTheNumber() {
    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;

    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << numberToGuess << endl;
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}

