#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <dirent.h>
#include <string>
#include <vector>

#include "matchscreen.h"
#include "match.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MatchScreen* getMatchScreen();

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

    void on_team_one_currentIndexChanged(int index);

    void on_team_two_currentIndexChanged(int index);

    void on_start_match_clicked();

    void on_menOne_currentIndexChanged(int index);

    void on_menTwo_currentIndexChanged(int index);

    void on_menThree_currentIndexChanged(int index);

    void on_menFour_currentIndexChanged(int index);

    void on_menFive_currentIndexChanged(int index);

    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    void initTacticScreen();
    void initHomeScreen();
    void initRoleBox();
    void initMenBox();
    void loadSingleMenBox(int num);

    QLabel* ratings[5][4];
    int playerIndex, subIndex;
    Match *match;
    string teamOneName, teamTwoName;
    vector<string> teamNames;

    bool gameOver;
};

#endif // MAINWINDOW_H
