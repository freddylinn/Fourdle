#ifndef LETTER_H
#define LETTER_H
#include <iostream>
using namespace std;

class Letter{
    public:
        Letter();
        char getActualLetter();
        string getColor();
        void setActualLetter(char ch);
        void setColor(string c);

    private:
        char actualLetter;
        string color;

};

#endif