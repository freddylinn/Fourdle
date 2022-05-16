#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "Letter.hpp"
using namespace std;

void displayMenu(Letter wordGrid[][4]){   // displays the menu and title

    cout << "\n-----\033[1;32m FOURDLE \033[0m-----\n"; // title

    for(int i  = 0; i < 7; i++){    // row loop

        cout << "      ";

        for(int j = 0; j < 4; j++){ // individual row

            if(wordGrid[i][j].getColor() == "GREEN"){
                cout << "\033[1;32m";   // bolded green
            }
            else if(wordGrid[i][j].getColor() == "YELLOW"){
                cout << "\033[1;33m";   // bolded yellow
            }

            cout << wordGrid[i][j].getActualLetter() << "\033[0m" << " ";

        }

        cout << endl;

    }
    cout << endl;

}

string toUpper(string word){    // converts all the words to uppercase so they can be typed in any format
    
    for(int i = 0; i < 4; i++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[i] -= 32;
        }
    }

    return word;

}

bool isValid(string word){  // checks if the inputted word is a real 4-letter word

    if(word.length() != 4){
        return false;
    }

    for(int i = 0; i < 4; i++){
        if(word[i] < 'A' || word[i] > 'z' || (word[i] > 'Z' && word[i] < 'a')){
            return false;
        }
    }

    return true;

}

void evaluate(string currWord, string randomWord, Letter wordGrid[][4], int row, bool &canPlay, bool &win){  // checks a word against the correct word
    
    int counter = 0; // counter for how many green letters there are
    vector<char> matchedLetters;
    vector<char> yellowLetters;
    char duplicate = '1';   // random char so it won't accidentally match
    
    currWord = toUpper(currWord);

    for(int i = 0; i < 4; i++){ // search for a duplicate letter, i.e 'O' in "FOOL"
        for(int j = 0; j < 4; j++){
            if(randomWord[i] == randomWord[j] && i != j){
                duplicate = randomWord[i];
                //cout << duplicate << endl;   // debugging line
            }
        }
    }

    for(int i = 0; i < 4; i++){ // set all green letters first

        wordGrid[row][i].setActualLetter(currWord[i]);

        if(currWord[i] == randomWord[i]){
            wordGrid[row][i].setColor("GREEN");
            counter++;
            matchedLetters.push_back(currWord[i]);
        }

    }

    for(int i = 0; i < 4; i ++){    // search for yellow letters
        for(int j = 0; j < 4; j++){

            if(currWord[i] == randomWord[j] && i != j){

                if(currWord[i] != duplicate){

                    bool found = false;

                    for(int k = 0; k < matchedLetters.size(); k++){
                        if(currWord[i] == matchedLetters[k]){
                            found = true;
                        }
                    }

                    for(int k = 0; k < yellowLetters.size(); k++){
                        if(currWord[i] == yellowLetters[k]){
                            found = true;
                        }
                    }

                    if(!found){
                        wordGrid[row][i].setColor("YELLOW");
                        yellowLetters.push_back(currWord[i]);
                    }

                }
                else{

                    bool found = false;
                    int dupeCounter = 0;
                    
                    for(int k = 0; k < matchedLetters.size(); k++){
                        if(currWord[i] == matchedLetters[k]){
                            dupeCounter++;
                        }
                    }

                    for(int k = 0; k < yellowLetters.size(); k++){
                        if(currWord[i] == yellowLetters[k]){
                            dupeCounter++;
                        }
                    }

                    if(dupeCounter >= 2){
                        found = true;
                    }

                    if(!found && wordGrid[row][i].getColor() != "GREEN"){
                        wordGrid[row][i].setColor("YELLOW");
                        yellowLetters.push_back(currWord[i]);
                    }

                }
            }

        }

    }

    if(counter == 4){
        canPlay = false;
        win = true;
    }

}


int main(){


    // Variable Declarations
    
    bool win = false;
    bool canPlay = true;    // boolean for if the game is still going or not
    int row = 0;    // current row #
    string currWord;    // current word that the user guessed
    Letter wordGrid[7][4];    // 2D array for the 7 by 4 grid
    string words[300];  // array for possible words to be guessed
    ifstream inputFile; // file that wil stream in all the words from a txt
    string line;    // storage variable for each line of the txt file
    string randomWord;  // the correct word the user is trying to find


    // Setting up the game

    inputFile.open("words.txt");    // opens the txt file 
    if(!inputFile.is_open()){
        cout << "File error accessing words. Please try again.";
        return 1;
    }

    for(int i = 0; i < 300; i++){
        getline(inputFile,line);
        words[i] = line;
    }

    srand(time(NULL));
    int randIndex = rand() % 300;
    randomWord = toUpper(words[randIndex]);
    //cout << endl << randomWord << endl;  // debugging - shows the random word

    cout << "\n\033[1mFour letters, seven tries. Good luck!\033[0m\n\n";    // Welcome Message


    // Main gameplay loop

    while(canPlay){

        displayMenu(wordGrid);

        do{
            cin >> currWord;
            if(cin.fail() || isValid(currWord) == false){
                cout << "Invalid word. Try again." << endl;
            }
        }while(cin.fail() || isValid(currWord) == false);

        currWord = toUpper(currWord);

        evaluate(currWord,randomWord,wordGrid,row,canPlay,win);

        if(!win){
            row++;
        }

        if(row > 6){
            canPlay = false;
        }

    }

    displayMenu(wordGrid);

    cout << endl << "The word was: " << randomWord << endl << endl;

    if(row > 6){
        cout << "X/7 - blame it on the word!" << endl << endl;
    }
    else{

        cout << row + 1 << "/7 - ";

        switch(row){

            case 0:
                cout << "you've mastered Fourdle";
            break;

            case 1:
                cout << "Impressive!";
            break;

            case 2:
                cout << "Great!";
            break;

            case 3:
                cout << "Well done!";
            break;

            case 4:
                cout << "Congrats!";
            break;

            case 5:
                cout << "Nice!";
            break;

            case 6:
                cout << "Close one!";
            break;

        }
        
    }

    cout << endl << endl;

    if(randomWord == "FRED"){
        cout << "Hey that\'s me!" << endl << endl;
    }
    if(randomWord == "FIVE"){
        cout << "Ironic..." << endl << endl;
    }



    return 0;
}
