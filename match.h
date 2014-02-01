#ifndef MATCH_H
#define MATCH_H
#include "player.h"
#include "team.h"
#include <iostream>

class Match
{
private:
    Team *teamOne, *teamTwo;
    void pass(Player *p);
    void moveUp(Player *p, int team);
    void moveBack(Player *p, int team);
    void moveLeft(Player *p, int team);
    void moveRight(Player *p, int team);

public:
    Match();
    void sim();
};

#endif // MATCH_H
