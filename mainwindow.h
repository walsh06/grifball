#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <dirent.h>
#include <string>
#include <vector>

#include "matchscreen.h"
#include "match.h"
#include "tacticscreen.h"

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

    void on_team_one_currentIndexChanged(int index);

    void on_team_two_currentIndexChanged(int index);

    void on_start_match_clicked();

    void closeEvent(QCloseEvent *);

    void changeScreen(int);

private:
    Ui::MainWindow *ui;
    void initHomeScreen();


    string teamOneName, teamTwoName;
    vector<string> teamNames;
};

#endif // MAINWINDOW_H
