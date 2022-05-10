#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void displayMenu(){
    cout << "\n-----\033[1;32m FOURDLE \033[0m-----\n";
    for(int i  = 0; i < 6; i++){
        cout << "      . . . .      " << endl;
    }
    cout << endl;
}

int main(){
    displayMenu();

    string word;

    if(word == "FRED"){
        cout << "Hey that\'s me!" << endl;
    }
    if(word == "FIVE"){
        cout << "Ironic..." << endl;
    }
    return 0;
}
