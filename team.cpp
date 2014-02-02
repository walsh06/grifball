#include "team.h"

Team::Team()
{
    players.push_back(new Player("Church", 10, 10, 10, 10));
    players.push_back(new Player("Griff", 10, 10, 10, 10));
    players.push_back(new Player("Tucker", 10, 10, 10, 10));
    players.push_back(new Player("Wash", 10, 10, 10, 10));
    players[0]->setRole(1);
    players[1]->setRole(2);
    players[2]->setRole(2);
    players[3]->setRole(3);

}

Player* Team::getPlayer(int playerNum)
{
    return players[playerNum];
}
