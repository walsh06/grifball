#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include "player.h"

using namespace std;
class Team
{
private:
    vector <Player*> players;
    vector <Player*> subs;
    vector <Player*> squad;
    int score;

    void setTeam(int team);
    void initTeam();

public:
    Team(int);
    Team(vector<Player *> players, int teamNum);
    Player* getPlayer(int playerNum);
    Player* getSub(int playerNum);
    void addPlayer(Player *p);

    int getScore();
    void addScore();
    void resetScore();
    void setPlayerRole(int playerNum, int role);
    void startSpawn();

    void makeSub(int playerIndex, int subIndex);
    int getNumSubs();
};

#endif // TEAM_H
