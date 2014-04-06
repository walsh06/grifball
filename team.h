#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include <algorithm>
#include <iostream>

#include "player.h"

using namespace std;
class Team
{
private:
    vector <Player*> players;
    vector <Player*> subs;
    vector <Player*> squad;
    int score;
    string name;

    void setTeam(int team);
    void initTeam();

public:
    Team(int);
    Team(vector<Player *> players, int teamNum, string name);
    Player* getPlayer(int playerNum);
    Player* getSub(int playerNum);
    void addPlayer(Player *p);

    int getScore();
    void addScore();
    void resetScore();
    void setPlayerRole(int playerNum, int role);
    void setPlayerMentality(int playerNum, int mentality);
    void startSpawn();
    void pickTeam();

    void makeSub(int playerIndex, int subIndex);
    int getNumSubs();
    string getName();

    vector<Player *> getPlayers();
};

#endif // TEAM_H
