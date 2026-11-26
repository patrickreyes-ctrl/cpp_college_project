/*
    Header file for all structures and function prototypes
    easier to use test functions
*/

#pragma once

#include <string>

using namespace std;

const int MAX_PLAYERS = 10;
struct player {
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
  game match_stats;
};

/*struct team {
  int teamID;
  string teamName;
};*/

void readingInputfiles(string filename, player Players[], int* p_numPlayers);
void writeToOutputFile(string filename, player Players[], int numPlayers);
int searchForGame(const game Games[], int size, int mainID);


