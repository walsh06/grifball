#ifndef MATCH_H
#define MATCH_H
#include "player.h"
#include "team.h"
#include "ball.h"
#include "filehelper.h"

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

    bool roundOver, gameOver;
    int winningTeam;

    void pass(Player *p);
    void moveUp(Player *p);
    void moveBack(Player *p);
    void moveLeft(Player *p);
    void moveRight(Player *p);
    void attack(Player *p);
    void moveTowardBall(Player *p);
    void moveTowardGoal(Player *p);

    void dodge(Player* p);

    void setMoveOrder();
    void setPlayerStatus(Player* p);
    void setAllStatus();

    int checkSquare(Player* p, int team);
    int findPlayer(Player *p);

    void checkBall(Player *p);
    void updateBall(Player *p);

    void checkWin(Player *p);

    Player* getTeammate(Player* p);
    void setMissPass(int x, int y);
    void printer();

public:
    Match(string teamOneName, string teamTwoName);
    void sim();
};

#endif // MATCH_H
