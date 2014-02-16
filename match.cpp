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
    for(int timer = 0; timer < 12; timer+=3)
    {
        cout<< "TIME: " << timer << endl;
    setMoveOrder();
    setPlayerStatus();
    printer();
    int numPlayers = playersToMove.size();
    for(int i = 0; i < numPlayers; i++)
    {
        Player* p = playersToMove[i];
        int act = p->getAction();
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
    }
    printer();
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

void Match::setPlayerStatus()
{
    if(ball->getTeam() == 1)
    {
        for(int i = 0; i < 5; i++)
        {
            Player* playerOne = teamOne->getPlayer(i);
            Player* playerTwo = teamTwo->getPlayer(i);

            if(playerOne->getNumber() == ball->getPlayer())
            {
                playerOne->setStatus(playerOne->HAS_BALL);
            }
            else
            {
                playerOne->setStatus(playerOne->TEAM_WITH_BALL);
            }
            playerTwo->setStatus(playerOne->WITHOUT_BALL);
        }
    }
    else if(ball->getTeam() == 2)
    {
        for(int i = 0; i < 5; i++)
        {
            Player* playerOne = teamOne->getPlayer(i);
            Player* playerTwo = teamTwo->getPlayer(i);

            if(playerTwo->getNumber() == ball->getPlayer())
            {
                playerTwo->setStatus(playerOne->HAS_BALL);
            }
            else
            {
                playerTwo->setStatus(playerOne->TEAM_WITH_BALL);
            }
            playerOne->setStatus(playerOne->WITHOUT_BALL);
        }
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            Player* playerOne = teamOne->getPlayer(i);
            Player* playerTwo = teamTwo->getPlayer(i);

            playerTwo->setStatus(playerOne->LOOSE_BALL);
            playerOne->setStatus(playerOne->LOOSE_BALL);
        }
    }
}

void Match::printer()
{
    for(int i = 0; i < 10; i++)
    {
        Player p = *playersToMove[i];
        cout<<"NAME: " << p.getName() << " X: " << p.getPosX() << " Y: " << p.getPosY() << endl;
    }
}
