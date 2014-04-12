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

    QObject::connect(ui->TacticWidget, SIGNAL(gameOverSignal(int)), this, SLOT(changeScreen(int)));
}

TournamentScreen::~TournamentScreen()
{
    delete ui;
}

void TournamentScreen::changeScreen(int mode)
{
    if(mode == 2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        tournament->updateEndMatch(ui->TacticWidget->getTeamOne(), ui->TacticWidget->getTeamTwo(), tournament->getUserTeamIndex());
        tournament->simRound(true);
        updateDisplay();
    }
}

void TournamentScreen::on_sim_clicked()
{
    if(tournament->getRound() == 0)
    {
        tournament = new Tournament();
    }
    else
    {
        if(tournament->getUserTeamIndex() != -1)
        {
            map<int, Team *> tree = tournament->getTournamentTree();

            string teamOneName = tree[0]->getName();
            string teamTwoName = tree[1]->getName();
            ui->TacticWidget->setTeamNames(teamOneName, teamTwoName);
            ui->TacticWidget->initScreen();
            ui->TacticWidget->setMode(2);
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            tournament->simRound();
        }
    }
    updateDisplay();
}

void TournamentScreen::updateDisplay()
{
    ui->results->setText("");
    ui->display->setText(QString::fromStdString(tournament->toString()));
    vector<string> results = tournament->getResults();
    for(int i=0; i < results.size();i++)
    {
        ui->results->append(QString::fromStdString(results[i]));
    }
}
