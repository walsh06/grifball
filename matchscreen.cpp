#include "matchscreen.h"
#include "ui_matchscreen.h"

MatchScreen::MatchScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchScreen)
{
    ui->setupUi(this);
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
