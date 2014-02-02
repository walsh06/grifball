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
    Team();
    Player* getPlayer(int playerNum);
};

#endif // TEAM_H
