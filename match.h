#ifndef MATCH_H
#define MATCH_H
#include "player.h"
#include "team.h"
#include "ball.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Match
{
private:
    Ball *ball;
    vector<Player *> playersToMove;
    Team *teamOne, *teamTwo;

    void pass(Player *p);
    void moveUp(Player *p);
    void moveBack(Player *p);
    void moveLeft(Player *p);
    void moveRight(Player *p);
    void attack(Player *p);
    void moveToward(Player *p);

    void setMoveOrder();
    void setPlayerStatus();

    void checkBall(Player *p);
    void updateBall(Player *p);

    void printer();
public:
    Match();
    void sim();
};

#endif // MATCH_H
