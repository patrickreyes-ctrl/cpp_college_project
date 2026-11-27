/*
    Description:
    Esports team could scout for professional player for their team
*/

#include "main_functions.h"
#include <iostream>
using namespace std;

int main(void) { 
    player Players[MAX_PLAYERS];
    int numPlayers = 0;
    readingInputfiles("existingPlayers.csv", Players, &numPlayers); // Calls the reading input function
    
    int playerID = 0;

    // Prompts the user to input data and reads in the what the user typed
    cout << "\nEnter a Player's ID to Search for!";
    if(!(cin >> playerID)) {
        cout << "Number Inputted is Invalid!";
    } 

    // Calling the Linear Search Function
    int search = searchForPlayerID(Players, numPlayers, playerID); 

    if(search == -1) {
        cout << "Searching for Player ID: " << playerID << " Is Not Aviliable!"; // Checks every player but the ID doesn't match
    } else {
        // Prints only if the ID inputted matches the player tag from the player struct
        // Passing by elements
        cout << "\nSearching for Player ID: " << Players[search].gamer_tag << " (ID " << Players[search].PlayerID << ") is " << Players[search].scout_status << "," << endl;
        
    }

     writeToOutputFile("outputPlayers.csv",Players, numPlayers );
    return 0;
    
 }
 


