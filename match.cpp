#include "match.h"

Match::Match()
{
    teamOne = new Team();
}

void Match::sim()
{
    for(int i = 0; i < 4; i++)
    {
        Player p = *teamOne->getPlayer(i);
        int act = p.getAction();
        cout << p.getName();
        if(act == p.MOVE_UP)
        {
            moveUp(&p);
        }
        else if(act == p.MOVE_DOWN)
        {
            moveBack(&p);
        }
        else if(act == p.MOVE_LEFT)
        {
            moveLeft(&p);
        }
        else if(act == p.MOVE_RIGHT)
        {
            moveRight(&p);
        }
        else if(act == p.PASS)
        {
            pass(&p);
        }
    }
}

void Match::attack(Player *p)
{
    cout << " Attacks" << endl;
}

void Match::pass(Player *p)
{
    cout << " Pass" << endl;

}

void Match::moveUp(Player *p)
{
    cout << " Moves Forward" << endl;

    int team = p->getTeam();
    if(team == 1)
    {
        p->setPosX(p->getPosX() + 1);
    }
    else if(team == 2)
    {
        p->setPosX(p->getPosX() - 1);
    }
}

void Match::moveBack(Player *p)
{
    cout << " Moves Backward" << endl;

    int team = p->getTeam();

    if(team == 1)
    {
        p->setPosX(p->getPosX() - 1);
    }
    else if(team == 2)
    {
        p->setPosX(p->getPosX() + 1);
    }
}

void Match::moveLeft(Player *p)
{
    cout << " Moves Left" << endl;

    int team = p->getTeam();

    if(team == 1)
    {
        p->setPosY(p->getPosY() + 1);
    }
    else if(team == 2)
    {
        p->setPosY(p->getPosY() - 1);
    }
}


void Match::moveRight(Player *p)
{
    cout << " Moves Right" << endl;

    int team = p->getTeam();

    if(team == 1)
    {
        p->setPosY(p->getPosY() - 1);
    }
    else if(team == 2)
    {
        p->setPosY(p->getPosY() + 1);
    }
}
