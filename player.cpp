#include "player.h"

Player::Player()
{

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
