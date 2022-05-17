# Fourdle

## Summary

**Fourdle** is a terminal-based game written in C++ based on the popular game "Wordle". The difference between the two is that "Wordle" gives you 6 attempts to guess a 5 letter word, and in Fourdle you get 7 attempts to guess a 4 letter word.

## How to Play

1. Open a terminal
2. Navigate to the directory that the Fourdle folder is in using the `cd` command
3. Enter `./playFourdle` into the terminal
    - **WARNING**:  The executable was compiled on a silicon Mac which seems to cause issues with other terminals. Because of this, players may need to compile the program on their own machine.
        - To compile, enter the following command in Fourdle's directory: `g++ fourdle.cpp Letter.cpp`
            - If g++ is not installed, enter `g++` into the terminal first
        - After compiling, enter the command `./a.out`

## Game Rules

- A word is randomly selected when the program runs
- Players get 7 chances to guess the word
- When a guess is entered...
    - A **green** letter means that letter is in the correct spot
    - A **yellow** letter means that letter is in the word, but in the wrong spot
    - A **white** letter means that letter is not in the word
- The player wins if they correctly guess the word in 7 chances or less
- The player loses if they use up all 7 chances without guessing the word
- Inputting anything but a valid four-letter word will result in the program asking you to try again

## Notes

- The list of possible words to be used as the random word was manually created by me to avoid "annoying" words that have too many uncommon letters or are not well-known
    - The list is 300 words long

- The list of possible words to try as guesses includes all of the four-letter words in the dictionary

