#ifndef MATCH_H
#define MATCH_H
#include "player.h"
#include "team.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Match
{
private:
    vector<Player *> playersToMove;
    Team *teamOne, *teamTwo;
    void pass(Player *p);
    void moveUp(Player *p);
    void moveBack(Player *p);
    void moveLeft(Player *p);
    void moveRight(Player *p);
    void attack(Player *p);
    void setMoveOrder();


public:
    Match();
    void sim();
};

#endif // MATCH_H
