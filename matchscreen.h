#ifndef MATCHSCREEN_H
#define MATCHSCREEN_H

#include <QWidget>
#include <string>

#include <iostream>

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

    void updateOutput(string message);

private:
    Ui::MatchScreen *ui;
};

#endif // MATCHSCREEN_H
