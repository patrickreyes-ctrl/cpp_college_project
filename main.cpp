/*
    Description:
    Esports team could scout for professional player for their team
*/

#include "main_functions.h"
#include <iostream>
using namespace std;

int main(void) { 
    const int SIZE = 4;
    game Games[SIZE] = {1,"Counter Strike_2",2,"DOTA",3,"LeagueOfLegends",4,"VALORANT"};

    int enterID = 0;
    cout << "\nEnter Game ID to Search for!";
    if(!(cin >> enterID)) {
        cout << "Number Inputted is Invalid!";
        return 1;
    } 

    int search = searchForGame(Games, SIZE, enterID);

    if(search != -1) {
        cout << "Game Selected: " << Games[search].gameName << " Is Aviliable!";
    } else {
        cout << "\nGame Selected: " << Games[search].gameName  << " Is Not Availiable!";
    }
    return 0;
 }
 


