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
    void moveUp(Player *p);
    void moveBack(Player *p);
    void moveLeft(Player *p);
    void moveRight(Player *p);
    void attack(Player *p);


public:
    Match();
    void sim();
};

#endif // MATCH_H
