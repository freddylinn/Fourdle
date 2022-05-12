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

    cout << "\n-----\033[1;32m FOURDLE \033[0m-----\n";

    for(int i  = 0; i < 7; i++){

        cout << "      ";

        for(int j = 0; j < 4; j++){
            cout << wordGrid[i][j].getActualLetter() << " ";
        }

        cout << endl;

    }
    cout << endl;

}

string toUpper(string word){    // converts all the words to uppercase so they can be typed in any format
    
    for(int i = 0; i < 4; i++){
        word[i] -= 32;
    }

    return word;

}

void evaluate(string currWord, string randomWord, Letter wordGrid[][4], int row, bool &canPlay){  // checks a word against the correct word
    
    if(currWord == randomWord){
        for(int i = 0; i < 4; i++){
            wordGrid[row][i] =  
        }
    }

}


int main(){


    // Variable Declarations

    bool canPlay = true;    // boolean for if the game is still going or not
    int row = 0;    // current row #
    string currWord;    // current word that the user guessed
    Letter wordGrid[7][4];    // 2D array for the 7 by 4 grid
    string words[150];  // array for possible words to be guessed
    ifstream inputFile; // file that wil stream in all the words from a txt
    string line;    // storage variable for each line of the txt file
    string randomWord;  // the correct word the user is trying to find


    // Setting up the game

    inputFile.open("words.txt");    // opens the txt file 
    if(!inputFile.is_open()){
        cout << "File error accessing words. Please try again.";
        return 1;
    }

    for(int i = 0; i < 150; i++){
        getline(inputFile,line);
        words[i] = line;
    }

    srand(time(NULL));
    int randIndex = rand() % 150;
    randomWord = toUpper(words[randIndex]);

    cout << "\n\033[1mFour letters, seven tries. Good luck!\033[0m\n\n";    // Welcome Message


    // Main gameplay loop

    while(canPlay){

        displayMenu(wordGrid);

        do{
            cin >> currWord;
            if(cin.fail() || currWord.length() != 4){
                cout << "Invalid word. Try again." << endl;
            }
        }while(cin.fail() || currWord.length() != 4);

        evaluate(currWord,randomWord,wordGrid,row,canPlay);

        row++;

        if(row > 6){
            canPlay = false;
        }

    }


    if(randomWord == "FRED"){
        cout << "Hey that\'s me!" << endl;
    }
    if(randomWord == "FIVE"){
        cout << "Ironic..." << endl;
    }
    return 0;
}
