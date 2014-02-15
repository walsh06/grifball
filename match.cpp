#include "match.h"

Match::Match()
{
    teamOne = new Team(1);
    teamTwo = new Team(2);
    srand( time(0));
}

void Match::sim()
{
    setMoveOrder();
    for(int i = 0; i < 10; i++)
    {
        Player p = *playersToMove[i];
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

void Match::setMoveOrder()
{
    playersToMove.clear();
    for(int i = 0; i < 5; i++)
    {
        Player* currentPlayer = teamOne->getPlayer(i);
        int n=rand()%10;
        currentPlayer->setMove(n + currentPlayer->getAgility());
        vector<Player *>::iterator it = playersToMove.begin();
        for(int j = 0;j < playersToMove.size() && currentPlayer->getMove() < playersToMove[j]->getMove(); j++)
        {
            ++it;
        }
        playersToMove.insert(it, currentPlayer);
    }

    for(int i = 0; i < 5; i++)
    {
        Player* currentPlayer = teamTwo->getPlayer(i);
        int n=rand()%10;
        currentPlayer->setMove(n + currentPlayer->getAgility());
        vector<Player *>::iterator it = playersToMove.begin();
        for(int j = 0; currentPlayer->getMove() < playersToMove[j]->getMove(); j++)
        {
            ++it;
        }
        playersToMove.insert(it, currentPlayer);
    }
}
