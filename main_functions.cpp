#include "main_functions.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;


void readingInputfiles(string filename, player Players[], int* p_numPlayers) {
    ifstream inFile(filename);

    if(!inFile) {
        return;
    }
    else {
        string line;
        getline(inFile, line);
        *p_numPlayers = 0;

        while(getline(inFile,line)&& *p_numPlayers < MAX_PLAYERS) {
            stringstream ss(line);
            string hold;
            player list;

            getline(ss, list.real_name, ',');
            getline(ss, list.gamer_tag, ',');
            getline(ss, list.current_role, ',');

            getline(ss, hold, ',');
            list.rating = stoi(hold);

            getline(ss, hold,',');
            list.winRate = stof(hold);

            getline(ss, hold,',');
            list.kdRatio = stof(hold);

            getline(ss, list.scout_status, ',');

            Players[* p_numPlayers] = list;
            (*p_numPlayers) ++;

        }
        inFile.close();
    }
}

 
void writeToOutputFile(string filename, player Players[], int numPlayers) {
     ofstream outFile(filename);

    if(!outFile) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    outFile << "RealName,GamerTag,CurrentRole,Rating,WinRate,kdRatio,ScoutStatus\n"; // header row

    // Write one line per playlist, with commas inbetween the values
    for(int i = 0; i < numPlayers; i++) {
        outFile << Players[i].real_name << "," << Players[i].gamer_tag << "," << Players[i].current_role << "," << Players[i].winRate << "," << Players[i].kdRatio << "," << Players[i].scout_status << "\n"; 
    }
    outFile.close();
    cout << "Sorted Playlists written to: " << filename << endl;


 }

 int searchForGame(const game Games[], int size, int gameID) {
    int low = 0;
    int high = size - 1;
    int target;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(Games[mid].gameID == gameID) {
            return mid;
        }
        else if(Games[mid].gameID < gameID) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    /* if(gameID != 1) {
        cout << "Found Game: " << Games[target].gameID << ", Name: " << Games[target].gameName << endl;
    }
    else {
        cout << "Game not Available!" << endl;
    } */

 }
  

    





