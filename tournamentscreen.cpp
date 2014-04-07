#include "tournamentscreen.h"
#include "ui_tournamentscreen.h"

TournamentScreen::TournamentScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentScreen)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    tournament = new Tournament();
    updateDisplay();
}

TournamentScreen::~TournamentScreen()
{
    delete ui;
}

void TournamentScreen::on_sim_clicked()
{
    if(tournament->getRound() == 0)
    {
        tournament = new Tournament();
    }
    else
    {
        tournament->simRound();
    }
    updateDisplay();
}

void TournamentScreen::updateDisplay()
{
    ui->display->setText(QString::fromStdString(tournament->toString()));
}
