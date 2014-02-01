#include "player.h"
#include <iostream>

Player::Player()
{
    srand( time(0));
    status = HAS_BALL;
}

void Player::setAttack(int attack)
{
    if(attack > 10)
    {
        this->attack = 10;
    }
    else
    {
        this->attack = attack;
    }
}

void Player::setAgility(int agility)
{
    if(agility > 10)
    {
        this->agility = 10;
    }
    else
    {
        this->agility = agility;
    }
}

void Player::setPass(int pass)
{
    if(pass > 10)
    {
        this->pass = 10;
    }
    else
    {
        this->pass = pass;
    }
}

void Player::setJumping(int jumping)
{
    if(jumping > 10)
    {
        this->jumping = 10;
    }
    else
    {
        this->jumping = jumping;
    }
}

void Player::setStatus(int status)
{
    if(status > 0 && status < 4)
    {
        this->status=status;
    }
}

void Player::setPosX(int x)
{
    if(x >= 0 || x <= 6 )
    {
        position[0] = x;
    }
}

void Player::setPosY(int y)
{
    if(y >= 0 || y <= 6 )
    {
        position[0] = y;
    }
}

int Player::getPosX()
{
    return position[0];
}

int Player::getPosY()
{
    return position[1];
}

int Player::getAction()
{
    int n=rand()%100;
    int action = -1;
    if(status == HAS_BALL)
    {
        int currentTotal = 0;
        for(int i = 0; i < 3; i++)
        {
            currentTotal += with_ball[i];
            if(n < currentTotal)
            {
                action = i;
                break;
            }
        }
    }
    else if (status == TEAM_WITH_BALL)
    {
        int currentTotal = 0;
        for(int i = 0; i < 3; i++)
        {
            currentTotal += team_ball[i];
            if(n < currentTotal)
            {
                action = i + 3;
                break;
            }
        }
    }
    else if (status == WITHOUT_BALL)
    {
        int currentTotal = 0;
        for(int i = 0; i < 3; i++)
        {
            currentTotal += opp_ball[i];
            if(n < currentTotal)
            {
                action = i + 6;
                break;
            }
        }
    }
    return action;
}
