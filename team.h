#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include "player.h"

using namespace std;
class Team
{
private:
    vector <Player*> players;
    int score;

    void setTeam(int team);

public:
    Team(int);
    Team(vector<Player *> players, int teamNum);
    Player* getPlayer(int playerNum);
    void addPlayer(Player *p);

    int getScore();
    void addScore();
    void resetScore();
    void setPlayerRole(int playerNum, int role);
    void startSpawn();
};

#endif // TEAM_H
