#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    void initTacticScreen();

    Match *match;
};

#endif // MAINWINDOW_H
