#ifndef MATCHSCREEN_H
#define MATCHSCREEN_H

#include <QWidget>
#include <string>
#include <sstream>
#include <iostream>

#include "player.h"

using namespace std;

namespace Ui {
class MatchScreen;
}

class MatchScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MatchScreen(QWidget *parent = 0);
    ~MatchScreen();

    void resetKillFeed();
    void updateKillFeed(Player* killer, Player* target);
    void updatePass(Player* p, Player* target);
    void updateMissPass(Player* p, Player* target);
    void updateMove(Player *p, int dir);
    void updateKill(Player* killer, Player* target);
    void updateDodge(Player* attacker, Player* target);
    void updatePickup(Player* p);

private:
    Ui::MatchScreen *ui;

    void updateOutput(string message);
};

#endif // MATCHSCREEN_H
