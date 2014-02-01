#ifndef PLAYER_H
#define PLAYER_H
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player
{
private:
    int attack, pass, agility, jumping;
   // int with_ball[3], team_ball[3], opp_ball[3];
    int with_ball[3] = {40, 25, 35};
    int team_ball[3] = {75, 28, 7};
    int opp_ball[3] = {93, 42, 1};
    int status;
    int position[2];
    const int HAS_BALL = 1, TEAM_WITH_BALL = 2, WITHOUT_BALL = 3;


public:
    Player();
    void setAttack(int attack);
    void setAgility(int agility);
    void setPass(int pass);
    void setJumping(int jumping);
    void setPosX(int x);
    void setPosY(int y);
    void setStatus(int status);

    int getPosX();
    int getPosY();
    int getAction();


};

#endif // PLAYER_H
