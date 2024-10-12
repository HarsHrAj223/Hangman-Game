#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to display the current state of the word being guessed
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the entire word has been guessed
bool isWordGuessed(const vector<bool>& guessed) {
    for (bool letterGuessed : guessed) {
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}

// Function to check if the guessed letter is in the word
bool guessLetter(const string& word, char letter, vector<bool>& guessed) {
    bool correctGuess = false;
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == letter && !guessed[i]) {
            guessed[i] = true;
            correctGuess = true;
        }
    }
    return correctGuess;
}

int main() {
    // List of words to guess from
    vector<string> wordList = {"computer", "science", "hangman", "programming", "cplusplus", "developer", "algorithm"};

    // Randomly select a word
    srand(time(0));
    string word = wordList[rand() % wordList.size()];

    vector<bool> guessed(word.length(), false);  // Keeps track of guessed letters
    int incorrectGuesses = 0;
    const int maxGuesses = 6;  // Number of incorrect guesses allowed

    cout << "Welcome to Hangman!" << endl;

    while (incorrectGuesses < maxGuesses && !isWordGuessed(guessed)) {
        cout << "\nCurrent word: ";
        displayWord(word, guessed);
        cout << "Incorrect guesses left: " << maxGuesses - incorrectGuesses << endl;

        // Get the user's guess
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        // Check if the guess is correct
        if (!guessLetter(word, guess, guessed)) {
            incorrectGuesses++;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Correct guess!" << endl;
        }
    }

    // Check the final outcome of the game
    if (isWordGuessed(guessed)) {
        cout << "\nCongratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\nGame over! The word was: " << word << endl;
    }

    return 0;
}
