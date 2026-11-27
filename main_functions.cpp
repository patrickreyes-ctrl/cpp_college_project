#include "main_functions.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

// Defining the Functions : Files I/O and Searching (Linear Searching)

void readingInputfiles(string filename, player Players[], int* p_numPlayers) {
    ifstream inFile(filename); // Reads the file

    if(!inFile) {
        // Checks for errors incase the file won't open
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    else {
        string line;
        getline(inFile, line); // Skips the hearder line texts
        *p_numPlayers = 0; 

        // Reads the lines until the file ends or whent the array  is full
        while(getline(inFile,line)&& *p_numPlayers < MAX_PLAYERS) {
            stringstream ss(line); // turns the rows into a stream so the getline function can start reading the file
            string hold; // holds any number as text until it gets converted (int, floats)
            player list; // creates a new list which is empty to fill in the different structs

            // The player's ID is delcared as a int so it reads it as text then converts it
            getline(ss, hold, ',');
            list.PlayerID = stoi(hold); // the stoi function is what converts it into a int from a string
            
            // These structs are just strings so it reads the text fields and stores it straight into 
            //  the struct which is indicated by each ','
            getline(ss, list.real_name, ',');
            getline(ss, list.gamer_tag, ',');
            getline(ss, list.current_role, ',');

            

            getline(ss, hold, ',');
            list.rating = stoi(hold);

            // The winrate element is an float because of the decimal point
            getline(ss, hold,','); // Reads it as a string 
            list.winRate = stof(hold);  // Then the 'stof' function converts it into a float from a string

            getline(ss, hold,',');
            list.kdRatio = stof(hold);

            getline(ss, list.scout_status, ',');

            Players[* p_numPlayers] = list; // Stores all the player data onto the next free spot in the array
            (*p_numPlayers) ++;

        }
        inFile.close(); // Closes the file 
    }
}

void readingFixturesInputFiles(string filename, fixture Fixtures[], int*p_numFixtures) {
     ifstream inFile(filename);

    if(!inFile) {
        return;
    }
    else {
        string line;
        getline(inFile, line);
        *p_numFixtures = 0;

        while(getline(inFile,line)&& *p_numFixtures < MAX_FIXTURES) {
            stringstream ss(line);
            string hold;
            fixture list;

            getline(ss, hold, ',');
            list.fixture_id = stoi(hold);
            
            getline(ss, list.opponent, ',');
            getline(ss, list.matchdate,',');
           
            getline(ss, hold, ',');
            list.match_stats =stof(hold);

            Fixtures[* p_numFixtures] = list;
            (*p_numFixtures) ++;

        }
        inFile.close();
    }
    

}

 
void writeToOutputFile(string filename, const player Players[], int numPlayers) {
     ofstream outFile(filename);

    if(!outFile) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    outFile << "PlayerID,RealName,GamerTag,CurrentRole,Rating,WinRate,kdRatio,ScoutStatus\n"; // header row

    // Write one line per playlist, with commas inbetween the values
    for(int i = 0; i < numPlayers; i++) {
        outFile << Players[i].PlayerID << "," << Players[i].real_name << "," << Players[i].gamer_tag << "," << Players[i].current_role << "," << Players[i].rating << "," << Players[i].winRate << "," << Players[i].kdRatio << "," << Players[i].scout_status << "\n"; 
    }
    outFile.close();
    cout << "\nAll Availiable Player data are written to: " << filename << endl;


 }

 void writingToFixturesOutputFile(string filename, const fixture Fixtures[], int numFixtures) {
    ofstream outFile(filename);

    if(!outFile) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    outFile << "FixtureID,Oppenent,Match_Date,Match_Stats\n"; // header row

    for(int i = 0; i < numFixtures; i++) {
        outFile << Fixtures[i].fixture_id << "," << Fixtures[i].opponent << "," << Fixtures[i].matchdate << "\n"; 
    }
    outFile.close();
    cout << "\nAll Availiable Fixture data are written to: " << filename << endl;

 }

 // Linear Search: Searches the every element of the  array and checks if the ID inputted by the user matches from the I/O files
 int searchForPlayerID(const player Players[], int size, int playerID) {
    for(int i = 0; i < size; i++) { // Starts at index 0 of the array and starts looking at all the elements
        if(Players[i].PlayerID == playerID) {  // Compares the players ID from the struct and the inputted ID the user is looking for
            return i; // Stops the search when it finds the right match
        }
    }
    return -1;
}

   

   
 
  

    





