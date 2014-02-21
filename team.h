#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include "player.h"

using namespace std;
class Team
{
private:
    vector <Player*> players;

public:
    Team(int);
    Team(vector<Player *>);
    Player* getPlayer(int playerNum);
    void addPlayer(Player *p);
};

#endif // TEAM_H
