#include <iostream>
#include "Letter.hpp"
using namespace std;

Letter::Letter(){
    actualLetter = '.';
    color = "WHITE";
}

char Letter::getActualLetter(){
    return actualLetter;
}

string Letter::getColor(){
    return color;
}

void Letter::setActualLetter(char ch){
    actualLetter = ch;
}

void Letter::setColor(string c){
    color = c;
}