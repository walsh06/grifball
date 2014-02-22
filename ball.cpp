#include "ball.h"

Ball::Ball()
{
    team = -1;
    player = -1;
    posX = 3;
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
    posX = x;
}

void Ball::setPosY(int y)
{
    posY = y;
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
    setPosX(3);
    setPosY(3);
}
