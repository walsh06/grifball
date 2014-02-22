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

private:
    Ui::MainWindow *ui;

    Match *match;
};

#endif // MAINWINDOW_H
