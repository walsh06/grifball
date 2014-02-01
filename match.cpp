#include "match.h"

Match::Match()
{
}

void Match::sim()
{
    Player p;

    for(int i = 0; i < 10; i++)
    {
        cout << i << ")";
        cout << p.getAction() << endl;
    }
}

void Match::pass(Player *p)
{

}

void Match::moveUp(Player *p, int team)
{
    if(team == 1)
    {
        p->setPosX(p->getPosX() + 1);
    }
    else if(team == 2)
    {
        p->setPosX(p->getPosX() - 1);
    }
}

void Match::moveBack(Player *p, int team)
{
    if(team == 1)
    {
        p->setPosX(p->getPosX() - 1);
    }
    else if(team == 2)
    {
        p->setPosX(p->getPosX() + 1);
    }
}

void Match::moveLeft(Player *p, int team)
{
    if(team == 1)
    {
        p->setPosY(p->getPosY() + 1);
    }
    else if(team == 2)
    {
        p->setPosY(p->getPosY() - 1);
    }
}


void Match::moveRight(Player *p, int team)
{
    if(team == 1)
    {
        p->setPosY(p->getPosY() - 1);
    }
    else if(team == 2)
    {
        p->setPosY(p->getPosY() + 1);
    }
}
