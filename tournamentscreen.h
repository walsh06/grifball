#ifndef TOURNAMENTSCREEN_H
#define TOURNAMENTSCREEN_H

#include <QWidget>
#include "tournament.h"

namespace Ui {
class TournamentScreen;
}

class TournamentScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentScreen(QWidget *parent = 0);
    ~TournamentScreen();
    void updateDisplay();


private slots:
    void on_sim_clicked();

private:
    Ui::TournamentScreen *ui;
    Tournament* tournament;
};

#endif // TOURNAMENTSCREEN_H
