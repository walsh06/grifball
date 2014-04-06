#include "matchscreen.h"
#include "ui_matchscreen.h"

#include <iostream>
MatchScreen::MatchScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchScreen)
{
    ui->setupUi(this);

    statsOne[0][0] = ui->one_one;statsOne[1][0] = ui->one_one_kills;statsOne[2][0] = ui->one_one_deaths;statsOne[3][0] = ui->one_one_scores;
    statsOne[0][1] = ui->one_two;statsOne[1][1] = ui->one_two_kills;statsOne[2][1] = ui->one_two_deaths;statsOne[3][1] = ui->one_two_scores;
    statsOne[0][2] = ui->one_three;statsOne[1][2] = ui->one_three_kills;statsOne[2][2] = ui->one_three_deaths;statsOne[3][2] = ui->one_three_scores;
    statsOne[0][3] = ui->one_four;statsOne[1][3] = ui->one_four_kills;statsOne[2][3] = ui->one_four_deaths;statsOne[3][3] = ui->one_four_scores;
    statsOne[0][4] = ui->one_five;statsOne[1][4] = ui->one_five_kills;statsOne[2][4] = ui->one_five_deaths;statsOne[3][4] = ui->one_five_scores;

    statsTwo[0][0] = ui->two_one;statsTwo[1][0] = ui->two_one_kills;statsTwo[2][0] = ui->two_one_deaths;statsTwo[3][0] = ui->two_one_scores;
    statsTwo[0][1] = ui->two_two;statsTwo[1][1] = ui->two_two_kills;statsTwo[2][1] = ui->two_two_deaths;statsTwo[3][1] = ui->two_two_scores;
    statsTwo[0][2] = ui->two_three;statsTwo[1][2] = ui->two_three_kills;statsTwo[2][2] = ui->two_three_deaths;statsTwo[3][2] = ui->two_three_scores;
    statsTwo[0][3] = ui->two_four;statsTwo[1][3] = ui->two_four_kills;statsTwo[2][3] = ui->two_four_deaths;statsTwo[3][3] = ui->two_four_scores;
    statsTwo[0][4] = ui->two_five;statsTwo[1][4] = ui->two_five_kills;statsTwo[2][4] = ui->two_five_deaths;statsTwo[3][4] = ui->two_five_scores;

    redBrush = new QBrush(Qt::red);
    blueBrush = new QBrush(Qt::blue);
    yellowBrush = new QBrush(Qt::yellow);
    blackPen = new QPen(Qt::black);

    srand( time(0));
}

MatchScreen::~MatchScreen()
{
    delete ui;
}

/*
void MatchScreen::updateOutput(Player* main, Player* other)
{
    ui->mainOutput->setText(QString::fromStdString(message));
}*/

void MatchScreen::resetKillFeed()
{
    ui->killfeed->setText("");
}

void MatchScreen::updateKillFeed(Player* killer, Player* target)
{
    stringstream killMessage;

    killMessage << killer->getName() << " kills " << target->getName();
    killer->addKill();
    target->addDeath();
    ui->killfeed->append(QString::fromStdString(killMessage.str()));
}

void MatchScreen::updatePass(Player* p, Player* target)
{
    stringstream passMessage;

    passMessage << p->getName() << " passes to " << target->getName();

    ui->mainOutput->setText(QString::fromStdString(passMessage.str()));
}

void MatchScreen::updateMissPass(Player* p, Player* target)
{
    stringstream passMessage;

    passMessage << p->getName() << " misses with a bad pass to " << target->getName();

    ui->mainOutput->setText(QString::fromStdString(passMessage.str()));
}

void MatchScreen::updateMove(Player *p, int dir)
{
    stringstream moveMessage;

    if(dir == p->MOVE_DOWN)
    {
        moveMessage << p->getName() << " moves backwards ";
    }
    else if(dir == p->MOVE_LEFT)
    {
        moveMessage << p->getName() << " moves left ";
    }
    else if(dir == p->MOVE_RIGHT)
    {
        moveMessage << p->getName() << " moves right ";
    }
    else if(dir == p->MOVE_UP)
    {
        moveMessage << p->getName() << " moves forward";
    }

    ui->mainOutput->setText(QString::fromStdString(moveMessage.str()));
}

void MatchScreen::updateKill(Player* killer, Player* target)
{
    stringstream killMessage;

    killMessage << killer->getName() << " kills " << target->getName();
    ui->mainOutput->setText(QString::fromStdString(killMessage.str()));
}

void MatchScreen::updateDodge(Player* attacker, Player* target)
{
    stringstream dodgeMessage;

    dodgeMessage << target->getName() << " dodges the attack of " << attacker->getName();

    ui->mainOutput->setText(QString::fromStdString(dodgeMessage.str()));
}

void MatchScreen::updatePickup(Player *p)
{
    stringstream pickMessage;

    pickMessage << p->getName() << " picks up the ball";

    ui->mainOutput->setText(QString::fromStdString(pickMessage.str()));
}

void MatchScreen::updateStatScreen(Team* teamOne, Team* teamTwo)
{
    vector<string> statLine;
    for(int i = 0; i < 5; i++)
    {
        statLine = teamOne->getPlayer(i)->getStatString();
        statsOne[0][i]->setText(QString::fromStdString(statLine[0])) ;
        statsOne[1][i]->setText(QString::fromStdString(statLine[1])) ;
        statsOne[2][i]->setText(QString::fromStdString(statLine[2])) ;
        statsOne[3][i]->setText(QString::fromStdString(statLine[3])) ;
    }

    for(int i = 0; i < 5; i++)
    {
        statLine = teamTwo->getPlayer(i)->getStatString();
        statsTwo[0][i]->setText(QString::fromStdString(statLine[0])) ;
        statsTwo[1][i]->setText(QString::fromStdString(statLine[1])) ;
        statsTwo[2][i]->setText(QString::fromStdString(statLine[2])) ;
        statsTwo[3][i]->setText(QString::fromStdString(statLine[3])) ;
    }
}

void MatchScreen::tick(int time)
{
    ui->clock->display(time);
}

void MatchScreen::clearMainOutput()
{
    ui->mainOutput->setText("");
}

void MatchScreen::displayPlayers(Team *teamOne, Team *teamTwo)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    vector<Player *> playersOne = teamOne->getPlayers();
    vector<Player *> playersTwo = teamTwo->getPlayers();
    int x, y, drawX, drawY, posModX, posModY;

    for(int i = 0; i < 5; i++)
    {
        x = playersOne[i]->getPosX();
        y = playersOne[i]->getPosY();
        posModX = rand()%50;
        posModY = rand()%50;
        drawX = (x * 50) + posModX;
        drawY = (y * 50) + posModY;

        if(playersOne[i]->getStatus() == Player::HAS_BALL)
        {
            scene->addEllipse(drawX, drawY, 10, 10, *blackPen, *yellowBrush);
        }
        else
        {
            scene->addEllipse(drawX, drawY, 10, 10, *blackPen, *redBrush);
        }
        x = playersTwo[i]->getPosX();
        y = playersTwo[i]->getPosY();

        posModX = rand()%50;
        posModY = rand()%50;
        drawX = (x * 50) + posModX;
        drawY = (y * 50) + posModY;
        if(playersTwo[i]->getStatus() == Player::HAS_BALL)
        {
            scene->addEllipse(drawX, drawY, 10, 10, *blackPen, *yellowBrush);
        }
        else
        {
            scene->addEllipse(drawX, drawY, 10, 10, *blackPen, *blueBrush);
        }
    }

    ui->field->setScene(scene);
}
