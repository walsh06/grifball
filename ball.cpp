#include "ball.h"

Ball::Ball()
{
    team = -1;
    player = -1;
    posX = 4;
    posY = 3;
}

int Ball::getPlayer()
{
    return player;
}

int Ball::getTeam()
{
    return team;
}

int Ball::getPosX()
{
    return posX;
}

int Ball::getPosY()
{
    return posY;
}

void Ball::setPosX(int x)
{
    if(x < 0)
    {
        posX = 0;
    }
    else if(x > 8)
    {
        posX = 8;
    }
    else
    {
        posX = x;
    }
}

void Ball::setPosY(int y)
{
    if(y < 0)
    {
        posY = 0;
    }
    else if(y > 6)
    {
        posY = 6;
    }
    else
    {
        posY = y;
    }
}

void Ball::setTeam(int teamNum)
{
    team = teamNum;
}

void Ball::setPlayer(int playerNum)
{
    player = playerNum;
}

void Ball::drop()
{
    team = -1;
    player = -1;
}

void Ball::reset()
{
    setPosX(4);
    setPosY(3);
    drop();
}
