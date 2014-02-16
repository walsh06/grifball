#include "match.h"

Match::Match()
{
    teamOne = new Team(1);
    teamTwo = new Team(2);
    ball = new Ball();
    srand( time(0));
}

void Match::sim()
{
    for(int timer = 0; timer < 24; timer+=3)
    {
        cout<< "TIME: " << timer << endl;
    setMoveOrder();
    setAllStatus();
    printer();
    int numPlayers = playersToMove.size();
    for(int i = 0; i < playersToMove.size(); i++)
    {
        Player* p = playersToMove[i];
        int act = p->getAction();

        checkBall(p);

        cout << p->getName();

        if(act == p->MOVE_UP)
        {
            moveUp(p);
        }
        else if(act == p->MOVE_DOWN)
        {
            moveBack(p);
        }
        else if(act == p->MOVE_LEFT)
        {
            moveLeft(p);
        }
        else if(act == p->MOVE_RIGHT)
        {
            moveRight(p);
        }
        else if(act == p->PASS)
        {
            pass(p);
        }
        else if(act == p->MOVE_TO_BALL)
        {
            moveToward(p);
        }
        else if(act == p->ATTACK)
        {
            attack(p);
        }
    }
    printer();
    }
}

void Match::attack(Player *p)
{
    cout << " Attacks";
    int n = p->getTeam(), oppTeam;
    Player *opp;
    if(n == 1)
    {
        oppTeam = 2;
        opp = teamTwo->getPlayer(checkSquare(p, 1));
    }
    else if(n == 2)
    {
        oppTeam = 1;
        opp = teamOne->getPlayer(checkSquare(p, 2));
    }
    int attackRoll = (rand()%11) + p->getAttack();
    int dodgeRoll = (rand()%11) + opp->getJump();

    if(attackRoll > dodgeRoll)
    {
        cout << " and Kills " << opp->getName() << endl;
        opp->setStatus(opp->DEAD);
        playersToMove.erase(playersToMove.begin()+ findPlayer(opp));
        ball->drop();
    }
    else
    {
        cout << " but misses " << opp->getName() << endl;
    }

}

void Match::pass(Player *p)
{
    cout << " Pass" << endl;
/*
    for(int i = 0;i < 20; i++)
    {
    int n=rand()%11 + 1;
    cout << "RAND: " << n << endl;
    }*/

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
    checkBall(p);
    if(p->getNumber() == ball->getPlayer())
    {
        updateBall(p);
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
    checkBall(p);
    if(p->getNumber() == ball->getPlayer())
    {
        updateBall(p);
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
    checkBall(p);
    if(p->getNumber() == ball->getPlayer())
    {
        updateBall(p);
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
    checkBall(p);
    if(p->getNumber() == ball->getPlayer())
    {
        updateBall(p);
    }
}

void Match::moveToward(Player *p)
{
    int x = ball->getPosX(), y =  ball->getPosY(), px = p->getPosX(), py = p->getPosY();
    int team = p->getTeam();
    if((py < y && team == 1) || (py > y && team == 2))
    {
        moveLeft(p);
    }
    else if((py < y && team == 2) || (py > y && team == 1))
    {
        moveRight(p);
    }
    else if((px < x && team == 1) || (px > x && team == 2))
    {
        moveUp(p);
    }
    else if((px < x && team == 2) || (px > x && team == 1))
    {
        moveBack(p);
    }
}

//=======================
//BALL
//=======================
void Match::checkBall(Player *p)
{
    int x = ball->getPosX(), y =  ball->getPosY(), px = p->getPosX(), py = p->getPosY();

    if(py == y && px == x && ball->getTeam() == -1)
    {
        ball->setPlayer(p->getNumber());
        ball->setTeam(p->getTeam());
        cout << "Picked up ball" << endl;
    }
}

void Match::updateBall(Player *p)
{
    ball->setPosX(p->getPosX());
    ball->setPosY(p->getPosY());
}

//=========================

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
        for(int j = 0;j < playersToMove.size() && currentPlayer->getMove() < playersToMove[j]->getMove(); j++)
        {
            ++it;
        }
        playersToMove.insert(it, currentPlayer);
    }
}
//=========================
//PLAYER STATUS
//=========================
void Match::setAllStatus()
{
    for(int i = 0; i < 5; i++)
    {
        Player* playerOne = teamOne->getPlayer(i);
        Player* playerTwo = teamTwo->getPlayer(i);
        setPlayerStatus(playerOne);
        setPlayerStatus(playerTwo);
    }
}

void Match::setPlayerStatus(Player* p)
{
    if(p->getStatus() == p->DEAD)
    {
        p->respawn();
    }
    int team = p->getTeam();
    if(ball->getTeam() == team)
    {
        if(p->getNumber() == ball->getPlayer())
        {
            p->setStatus(p->HAS_BALL);
        }
        else if(checkSquare(p, team) != -1)
        {
            p->setStatus(p->OPP_IN_SQUARE);
        }
        else
        {
            p->setStatus(p->TEAM_WITH_BALL);
        }
    }
    else if(ball->getTeam() == -1)
    {
        if(checkSquare(p, team) != -1)
        {
            p->setStatus(p->OPP_IN_SQUARE);
        }
        else
        {
            p->setStatus(p->LOOSE_BALL);
        }
    }
    else
    {
        if(checkSquare(p, team) != -1)
        {
            p->setStatus(p->OPP_IN_SQUARE);
        }
        else
        {
            p->setStatus(p->WITHOUT_BALL);
        }
    }
}

int Match::checkSquare(Player *p, int team)
{
    if(team == 1)
    {
        for(int i = 0; i < 5; i++)
        {
            Player opp = *teamTwo->getPlayer(i);
            if(opp.getPosX() == p->getPosX() && opp.getPosY() == p->getPosY())
            {
                return i;
            }
        }
    }
    else if(team == 2)
    {
        for(int i = 0; i < 5; i++)
        {
            Player opp = *teamOne->getPlayer(i);
            if(opp.getPosX() == p->getPosX() && opp.getPosY() == p->getPosY())
            {
                return i;
            }
        }
    }

    return -1;
}

int Match::findPlayer(Player *p)
{
    int team = p->getTeam(), num = p->getNumber();
    int checkTeam, checkNum;
    for(int i = 0; i < playersToMove.size(); i++)
    {
        checkTeam = playersToMove[i]->getTeam();
        checkNum = playersToMove[i]->getNumber();

        if(team == checkTeam && num == checkNum)
        {
            return i;
        }
    }

    return -1;
}

void Match::printer()
{
    for(int i = 0; i < 10; i++)
    {
        Player p = *playersToMove[i];
        cout<<"NAME: " << p.getName() << " X: " << p.getPosX() << " Y: " << p.getPosY() << " STATUS: " << p.getStatus() << endl;
    }
}
