#include "player.h"
#include <iostream>

Player::Player(string name, int attack, int pass, int jump, int agility, int number)
{
    this->name = name;
    setAgility(agility);
    setAttack(attack);
    setJumping(jump);
    setPass(pass);
    this->number = number;
    move = 0;
    srand( time(0));
    status = LOOSE_BALL;
    team = 0;
}

void Player::setRole(int role)
{
    this->role = role;
    if(role == 1) //scorer
    {
        with_ball[0] = 70; with_ball[1] = 5; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 15;
        team_ball[0] = 75; team_ball[1] = 5; team_ball[2] = 10; team_ball[3] = 10;
        opp_ball[0] = 40; opp_ball[1] = 40; opp_ball[2] = 10; opp_ball[3] = 10;
        opp_in_square[0] = 40; opp_in_square[1] = 10; opp_in_square[2] = 10; opp_in_square[3] = 40;
        loose_ball[0] = 95; loose_ball[1] = 5;
    }
    else if(role == 2) //attacker
    {
        with_ball[0] = 60; with_ball[1] = 5; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 25;
        team_ball[0] = 80; team_ball[1] = 4; team_ball[2] = 8; team_ball[3] = 8;
        opp_ball[0] = 40; opp_ball[1] = 40; opp_ball[2] = 10; opp_ball[3] = 10;
        opp_in_square[0] = 5; opp_in_square[1] = 5; opp_in_square[2] = 5; opp_in_square[3] = 85;
        loose_ball[0] = 95; loose_ball[1] = 5;
    }
    else if(role == 3) // defender
    {
        with_ball[0] = 40; with_ball[1] = 4; with_ball[2] = 8; with_ball[3] = 8; with_ball[4] = 40;
        team_ball[0] = 60; team_ball[1] = 10; team_ball[2] = 15; team_ball[3] = 15;
        opp_ball[0] = 30; opp_ball[1] = 40; opp_ball[2] = 15; opp_ball[3] = 15;
        opp_in_square[0] = 10; opp_in_square[1] = 10; opp_in_square[2] = 10; opp_in_square[3] = 70;
        loose_ball[0] = 75; loose_ball[1] = 25;
    }
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
    if(status > 0 && status < 5)
    {
        this->status=status;
    }
}

void Player::setMove(int move)
{
    this->move = move;
}

void Player::setPosX(int x)
{
    if(x >= 0 && x <= 6 )
    {
        position[0] = x;
    }
}

void Player::setPosY(int y)
{
    if(y >= 0 && y <= 6 )
    {
        position[1] = y;
    }
}

void Player::setTeam(int team)
{
    this->team = team;
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

    //cout << "RANDOM: " << n << endl;
    if(status == HAS_BALL)
    {
        if( n < with_ball[0])
        {
            action = MOVE_UP;
        }
        else if(n < with_ball[0] + with_ball[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2] + with_ball[3])
        {
            action = MOVE_RIGHT;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2] + with_ball[3] + with_ball[4])
        {
            action = PASS;
        }
    }
    else if (status == TEAM_WITH_BALL)
    {
        if( n < team_ball[0])
        {
            action = MOVE_UP;
        }
        else if(n < team_ball[0] + team_ball[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < team_ball[0] + team_ball[1] + team_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < team_ball[0] + team_ball[1] + team_ball[2] + team_ball[3])
        {
            action = MOVE_RIGHT;
        }
    }
    else if (status == WITHOUT_BALL)
    {
        if( n < opp_ball[0])
        {
            action = MOVE_UP;
        }
        else if(n < opp_ball[0] + opp_ball[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < opp_ball[0] + opp_ball[1] + opp_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < opp_ball[0] + opp_ball[1] + opp_ball[2] + opp_ball[3])
        {
            action = MOVE_RIGHT;
        }
    }
    else if (status == OPP_IN_SQUARE)
    {
        if( n < opp_in_square[0])
        {
            action = MOVE_DOWN;
        }
        else if(n < opp_in_square[0] + opp_in_square[1])
        {
            action = MOVE_LEFT;
        }
        else if(n < opp_in_square[0] + opp_in_square[1] + opp_in_square[2])
        {
            action = MOVE_RIGHT;
        }
        else if(n < opp_in_square[0] + opp_in_square[1] + opp_in_square[2] + opp_in_square[3])
        {
            action = ATTACK;
        }
    }
    else if (status == LOOSE_BALL)
    {
        if( n < loose_ball[0])
        {
            action = MOVE_TO_BALL;
        }
        else if(n < loose_ball[0] + loose_ball[1])
        {
            action = MOVE_LEFT;
        }
    }
    return action;
}

int Player::getTeam()
{
    return team;
}

string Player::getName()
{
    return name;
}

int Player::getMove()
{
    return move;
}

int Player::getAgility()
{
    return agility;
}

int Player::getNumber()
{
    return number;
}
