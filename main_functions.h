/*
    Header file for all structures and function prototypes
    easier to use test functions
*/

#pragma once

#include <string>

using namespace std;

const int MAX_PLAYERS = 10;
const int MAX_FIXTURES = 3;
struct player {
  int PlayerID;
  string real_name;
  string gamer_tag;
  string current_role;
  int rating;
  float winRate;
  float kdRatio;
  string scout_status;
};

struct game {
  int gameID;
  string gameName;

};

struct fixture {
  int fixture_id;
  string opponent;
  string matchdate;
  float match_stats;
};

// Function Prototypes : FileI/O and Linear Search 
void readingInputfiles(string filename, player Players[], int* p_numPlayers);
void readingFixturesInputFiles(string filename, fixture Fixtures[], int*p_numFixtures);

void writeToOutputFile(string filename, const player Players[], int numPlayers);
void writingToFixturesOutputFile(string filename, const fixture Fixtures[], int numFixtures);

int searchForPlayerID(const player Players[], int size, int playerID);



