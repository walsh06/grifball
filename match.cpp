#include "match.h"

Match::~Match()
{

}

Match::Match(string teamOneName, string teamTwoName)
{
    teamOne = new Team(Filehelper::getTeamFromFile(teamOneName), 1, teamOneName);
    teamTwo = new Team(Filehelper::getTeamFromFile(teamTwoName), 2, teamTwoName);
    ball = new Ball();
    srand( time(0));
    roundOver = false;
    gameOver = false;
}

void Match::sim(MatchScreen* screen)
{
    this->screen = screen;
    resetRound();
    int timer;

    for(timer = 0; timer < 180 && roundOver == false; timer+=3)
    {
        screen->tick(timer);
        cout << teamOne->getPlayer(0)->getRole()<< endl;
        screen->resetKillFeed();
        cout<< "TIME: " << timer << endl;
        setMoveOrder();
        for(int i = 0; i < playersToMove.size() && roundOver == false; i++)
        {
            Player* p = playersToMove[i];
            checkBall(p);
            setPlayerStatus(p);
            int act = p->getAction();

            //cout << p->getName();

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
                moveTowardBall(p);
            }
            else if(act == p->ATTACK)
            {
                attack(p);
            }
            else if(act == p->MOVE_TO_GOAL)
            {
                moveTowardGoal(p);
            }
            else if(act == p->MOVE_TO_OWN_GOAL)
            {
                moveToOwnGoal(p);
            }
        }
    cout << "BALL TEAM: " << ball->getTeam() << " PLAYER: " << ball->getPlayer() << endl;
    screen->updateStatScreen(teamOne, teamTwo);

    QTime dieTime= QTime::currentTime().addSecs(1);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    cout << "GAME OVER TIME: " << timer << endl;
    if(winningTeam == 1 || winningTeam == 2)
    {
        cout << "WINNER: Team " << winningTeam << endl;
    }
    else
    {
        cout << "DRAW" << endl;
    }
    cout << teamOne->getScore() << "-" << teamTwo->getScore() << endl;
}

//===================================
//Win
//===================================

void Match::checkWin(Player *p)
{
    int team = p->getTeam();
    if(ball->getPlayer() == p->getNumber() && p->getPosY() == 3 && (((p->getPosX() == 6 && team == 1) || (team == 2 && p->getPosX() == 0))))
    {
        roundOver = true;
        winningTeam = p->getTeam();
        p->addScore();

        if(p->getTeam() == 1)
        {
            teamOne->addScore();
        }
        else if(p->getTeam() == 2)
        {
            teamTwo->addScore();
        }
    }
}

//===================================
//Attack
//===================================

void Match::attack(Player *p)
{
    int randRating = Player::maxRating + 1;
    //cout << " Attacks";
    int n = p->getTeam(), oppTeam;
    Player *opp;
    if(n == 1)
    {
        oppTeam = 2;
        opp = teamTwo->getPlayer(checkSquare(p, n));
    }
    else if(n == 2)
    {
        oppTeam = 1;
        opp = teamOne->getPlayer(checkSquare(p, n));
    }
    int attackRoll = (rand()%randRating) + p->getAttack();
    int dodgeRoll = (rand()%randRating) + opp->getJump();

    if(attackRoll > dodgeRoll)
    {
        //cout << " and Kills " << opp->getName() << endl;
        opp->kill();
        playersToMove.erase(playersToMove.begin()+ findPlayer(opp));
        screen->updateKillFeed(p, opp);

        if(ball->getPlayer() == opp->getNumber())
        {
            screen->updateKill(p, opp);
            ball->drop();
        }

    }
    else
    {
        if(ball->getPlayer() == opp->getNumber())
        {
            screen->updateDodge(p, opp);
            ball->drop();
        }
        //cout << " but misses " << opp->getName() << endl;
    }
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

void Match::dodge(Player *p)
{
    int randRating = Player::maxRating + 1;
    //cout << " Jumps";
    int team = p->getTeam(), oppTeam;
    Player *opp;
    if(team == 1)
    {
        oppTeam = 2;
        opp = teamTwo->getPlayer(checkSquare(p, 1));
    }
    else if(team == 2)
    {
        oppTeam = 1;
        opp = teamOne->getPlayer(checkSquare(p, 2));
    }
    int attackRoll = (rand()%randRating) + opp->getAttack();
    int dodgeRoll = (rand()%randRating) + p->getJump();

    if(attackRoll > dodgeRoll)
    {
        //cout << " but is killed by Kills " << opp->getName() << endl;
        p->kill();
        playersToMove.erase(playersToMove.begin()+ findPlayer(p));
        ball->drop();
        screen->updateKill(opp, p);
        screen->updateKillFeed(opp, p);
    }
    else
    {
        screen->updateDodge(opp, p);
        //cout << " and gets past" << opp->getName() << endl;
        if(team == 1)
        {
            p->setPosX(p->getPosX() + 1);
        }
        else if(team == 2)
        {
            p->setPosX(p->getPosX() - 1);
        }
        if(p->getNumber() == ball->getPlayer())
        {
            updateBall(p);
        }
    }

}

//====================================
//PASS
//======================================
void Match::pass(Player *p)
{
    int randRating = Player::maxRating + 1;
    //cout << " Pass ";
    int passRoll =(rand()%randRating + 1) + p->getPass();
    Player* target = getTeammate(p);

    if(passRoll > 21)
    {
        //cout << "To " << target->getName() << endl;

        screen->updatePass(p, target);
        updateBall(target);
        setPlayerStatus(target);
        setPlayerStatus(p);
    }
    else
    {
        stringstream message ;
        message << p->getName() << " missed with a bad pass to " << target->getName();
        screen->updateMissPass(p, target);
        //cout << "Misses pass to " << target->getName() << " , Loose Ball!!" << endl;
        ball->drop();
        setMissPass(target->getPosX(), target->getPosY());
        setAllStatus();
    }
}

Player* Match::getTeammate(Player* p)
{
    vector<Player *> teammates;
    vector<int> teammateProbs;
    int teamNum = p->getTeam();
    Team* team ;
    int total = 0;
    if(teamNum == 1)
    {
        team = teamOne;
    }
    else if(teamNum == 2)
    {
        team = teamTwo;
    }

    for(int i = 0; i < 5; i++)
    {
        Player* currentPlayer = team->getPlayer(i);
        if(currentPlayer->getNumber() != p->getNumber())
        {
            teammates.push_back(currentPlayer);
            if(currentPlayer->getRole() == 1)
            {
                teammateProbs.push_back(20);
                total+=20;
            }
            else if(currentPlayer->getRole() == 2)
            {
                teammateProbs.push_back(10);
                total+=10;
            }
            else if(currentPlayer->getRole() == 3)
            {
                teammateProbs.push_back(5);
                total+=5;
            }
        }
    }

    int teammatePick = rand()%total;
    int currentTotal = 0;
    for(int i = 0; i < 4; i++)
    {
        currentTotal+=teammateProbs[i];
        if(teammatePick < currentTotal)
        {
            return teammates[i];
        }
    }

    return NULL;
}

void Match::setMissPass(int x, int y)
{
    int ranX = -1, ranY = -1;
    bool finished = false;
    while(finished == false)
    {
        ranX = -1; ranY = -1;
        while(ranX < 0 || ranX > 6)
        {
            ranX = ((rand()% 3) -1) + x;
        }
        while(ranY < 0 || ranY > 6)
        {
            ranY = ((rand()% 3) -1) + y;
        }

        if(ranX != x && ranY != y)
        {
            finished = true;
        }
    }
    ball->setPosX(ranX);
    ball->setPosY(ranY);
}

//================================
//MOVE
//================================
void Match::moveUp(Player *p)
{
   // cout << " Moves Forward" << endl;

    if(p->getStatus() == p->BALL_WITH_OPP)
    {
        dodge(p);
    }
    else
    {
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
            screen->updateMove(p, p->MOVE_UP);
        }
    }

    checkWin(p);
}

void Match::moveBack(Player *p)
{
    //cout << " Moves Backward" << endl;

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
        screen->updateMove(p, p->MOVE_DOWN);
    }
}

void Match::moveLeft(Player *p)
{
    //cout << " Moves Left" << endl;

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
        screen->updateMove(p, p->MOVE_LEFT);
    }
}


void Match::moveRight(Player *p)
{
    //cout << " Moves Right" << endl;

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
        screen->updateMove(p, p->MOVE_RIGHT);
    }
}

void Match::moveTowardGoal(Player *p)
{
    int x, y;
    int team = p->getTeam();
    int px = p->getPosX(), py = p->getPosY();

    if(team == 1)
    {
        x = 6;
        y = 3;
    }
    else if(team == 2)
    {
        x = 0;
        y = 3;
    }

    if((px < x && team == 1) || (px > x && team == 2))
    {
        moveUp(p);
    }
    else if((px < x && team == 2) || (px > x && team == 1))
    {
        moveBack(p);
    }
    else if((py < y && team == 1) || (py > y && team == 2))
    {
        moveLeft(p);
    }
    else if((py < y && team == 2) || (py > y && team == 1))
    {
        moveRight(p);
    }
    else if(py == y && px == x)
    {
        moveUp(p);
    }
}

void Match::moveToOwnGoal(Player *p)
{
    int x, y;
    int team = p->getTeam();
    int px = p->getPosX(), py = p->getPosY();

    if(team == 1)
    {
        x = 0;
        y = 3;
    }
    else if(team == 2)
    {
        x = 6;
        y = 3;
    }

    if((px < x && team == 1) || (px > x && team == 2))
    {
        moveUp(p);
    }
    else if((px < x && team == 2) || (px > x && team == 1))
    {
        moveBack(p);
    }
    else if((py < y && team == 1) || (py > y && team == 2))
    {
        moveLeft(p);
    }
    else if((py < y && team == 2) || (py > y && team == 1))
    {
        moveRight(p);
    }
    else if(py == y && px == x)
    {
        moveUp(p);
    }
}

void Match::moveTowardBall(Player *p)
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
       updateBall(p);
       screen->updatePickup(p);
    }
}

void Match::updateBall(Player *p)
{
    if(ball->getTeam() == -1)
    {
        ball->setPlayer(p->getNumber());
        ball->setTeam(p->getTeam());
    }
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
            if(checkSquare(p, team) != -1)
            {
                p->setStatus(p->BALL_WITH_OPP);
            }
            else
            {
                p->setStatus(p->HAS_BALL);
            }
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

void Match::printer()
{
    for(int i = 0; i < 10; i++)
    {
        Player p = *playersToMove[i];
        cout<<"NAME: " << p.getName() << " X: " << p.getPosX() << " Y: " << p.getPosY() << " STATUS: " << p.getStatus() << endl;
    }
}

void Match::resetRound()
{
    teamOne->startSpawn();
    teamTwo->startSpawn();
    screen->clearMainOutput();
    ball->reset();
    roundOver = false;
}

int Match::getTeamOneScore()
{
    teamOne->getScore();
}

int Match::getTeamTwoScore()
{
    teamTwo->getScore();
}

Team* Match::getTeamOne()
{
    return teamOne;
}

Team* Match::getTeamTwo()
{
    return teamTwo;
}
