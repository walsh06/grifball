#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include "player.h"

using namespace std;
class Team
{
private:
    vector <Player*> players;

    void setTeam(int team);
    void startSpawn();

public:
    Team(int);
    Team(vector<Player *> players, int teamNum);
    Player* getPlayer(int playerNum);
    void addPlayer(Player *p);

    void setPlayerRole(int playerNum, int role);
};

#endif // TEAM_H
