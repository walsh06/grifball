#include "team.h"


Team::Team(int n)
{
    if(n == 1)
    {
        addPlayer(new Player("Church", 10, 10, 10, 10));
        addPlayer(new Player("Caboose", 10, 10, 10, 10));
        addPlayer(new Player("Tucker", 10, 10, 10, 10));
        addPlayer(new Player("Wash", 10, 10, 10, 10));
        addPlayer(new Player("Freckles", 10, 10, 10, 10));
        players[0]->setRole(1);
        players[1]->setRole(2);
        players[2]->setRole(2);
        players[3]->setRole(3);
        players[4]->setRole(1);
    }
    else
    {
        addPlayer(new Player("Sarge", 10, 10, 10, 10));
        addPlayer(new Player("Griff", 10, 10, 10, 10));
        addPlayer(new Player("Donut", 10, 10, 10, 10));
        addPlayer(new Player("Simmons", 10, 10, 10, 10));
        addPlayer(new Player("Lopez", 10, 10, 10, 10));
        players[0]->setRole(1);
        players[1]->setRole(2);
        players[2]->setRole(2);
        players[3]->setRole(3);
        players[4]->setRole(2);
    }

}

Player* Team::getPlayer(int playerNum)
{
    return players[playerNum];
}

void Team::addPlayer(Player *p)
{
    if(players.size() < 5)
    {
        players.push_back(p);
    }
}
