#ifndef TACTICSCREEN_H
#define TACTICSCREEN_H

#include <QWidget>
#include <QLabel>
#include <string>
#include <vector>

#include "match.h"

namespace Ui {
class TacticScreen;
}

class TacticScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TacticScreen(QWidget *parent = 0);
    ~TacticScreen();

    void initScreen();
    void initTacticScreen();
    void initRoleBox();
    void initMenBox();
    void loadSingleMenBox(int num);
    void initStatScreen();
    MatchScreen* getMatchScreen();

    void setTeamNames(string teamOneName, string teamTwoName);
    void setMatch(Match userMatch);
    void setMode(int mode);

    Team* getTeamOne();
    Team* getTeamTwo();

private:
    Ui::TacticScreen *ui;
    QLabel* ratings[5][4];
    int playerIndex, subIndex;
    Match *match;
    string teamOneName, teamTwoName;
    bool gameOver;
    int mode;

private slots:

    void on_startButton_clicked();

    void on_roleOne_currentIndexChanged(int index);

    void on_roleTwo_currentIndexChanged(int index);

    void on_roleThree_currentIndexChanged(int index);

    void on_roleFour_currentIndexChanged(int index);

    void on_roleFive_currentIndexChanged(int index);

    void on_player_box_currentIndexChanged(int index);

    void on_sub_box_currentIndexChanged(int index);

    void on_sub_button_clicked();

    void on_menOne_currentIndexChanged(int index);

    void on_menTwo_currentIndexChanged(int index);

    void on_menThree_currentIndexChanged(int index);

    void on_menFour_currentIndexChanged(int index);

    void on_menFive_currentIndexChanged(int index);

    void on_changeRatings_currentIndexChanged(int index);

signals:

    void gameOverSignal(int);
};

#endif // TACTICSCREEN_H
