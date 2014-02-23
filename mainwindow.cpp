#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);

    ui->teamOneScore->display(0);
    ui->teamTwoScore->display(0);
    ui->teamOneName->setText(QString::fromStdString("Blues"));
    ui->teamTwoName->setText(QString::fromStdString("Reds"));

    ratings[0][0] = ui->one_att;ratings[0][1] = ui->one_agil;ratings[0][2] = ui->one_jump;ratings[0][3] = ui->one_pass;
    ratings[1][0] = ui->two_att;ratings[1][1] = ui->two_agil;ratings[1][2] = ui->two_jump;ratings[1][3] = ui->two_pass;
    ratings[2][0] = ui->three_att;ratings[2][1] = ui->three_agil;ratings[2][2] = ui->three_jump;ratings[2][3] = ui->three_pass;
    ratings[3][0] = ui->four_att;ratings[3][1] = ui->four_agil;ratings[3][2] = ui->four_jump;ratings[3][3] = ui->four_pass;
    ratings[4][0] = ui->five_att;ratings[4][1] = ui->five_agil;ratings[4][2] = ui->five_jump;ratings[4][3] = ui->five_pass;

    initHomeScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MatchScreen* MainWindow::getMatchScreen()
{
    return ui->matchWidget;
}

//======================
//Tactic Screen
//======================

void MainWindow::initTacticScreen()
{

    ui->roleOne->addItem(QString::fromStdString("Scorer"));
    ui->roleOne->addItem(QString::fromStdString("Attacker"));
    ui->roleOne->addItem(QString::fromStdString("Defender"));
    ui->roleTwo->addItem(QString::fromStdString("Scorer"));
    ui->roleTwo->addItem(QString::fromStdString("Attacker"));
    ui->roleTwo->addItem(QString::fromStdString("Defender"));
    ui->roleThree->addItem(QString::fromStdString("Scorer"));
    ui->roleThree->addItem(QString::fromStdString("Attacker"));
    ui->roleThree->addItem(QString::fromStdString("Defender"));
    ui->roleFour->addItem(QString::fromStdString("Scorer"));
    ui->roleFour->addItem(QString::fromStdString("Attacker"));
    ui->roleFour->addItem(QString::fromStdString("Defender"));
    ui->roleFive->addItem(QString::fromStdString("Scorer"));
    ui->roleFive->addItem(QString::fromStdString("Attacker"));
    ui->roleFive->addItem(QString::fromStdString("Defender"));

    ui->oneName->setText(QString::fromStdString(match->getTeamOne()->getPlayer(0)->getName()));
    ui->twoName->setText(QString::fromStdString(match->getTeamOne()->getPlayer(1)->getName()));
    ui->threeName->setText(QString::fromStdString(match->getTeamOne()->getPlayer(2)->getName()));
    ui->fourName->setText(QString::fromStdString(match->getTeamOne()->getPlayer(3)->getName()));
    ui->fiveName->setText(QString::fromStdString(match->getTeamOne()->getPlayer(4)->getName()));

    ui->roleOne->setCurrentIndex(match->getTeamOne()->getPlayer(0)->getRole() - 1);
    ui->roleTwo->setCurrentIndex(match->getTeamOne()->getPlayer(1)->getRole() - 1);
    ui->roleThree->setCurrentIndex(match->getTeamOne()->getPlayer(2)->getRole() - 1);
    ui->roleFour->setCurrentIndex(match->getTeamOne()->getPlayer(3)->getRole() - 1);
    ui->roleFive->setCurrentIndex(match->getTeamOne()->getPlayer(4)->getRole() - 1);

    ui->sub_box->clear();
    ui->player_box->clear();
    int n = match->getTeamOne()->getNumSubs();
    for(int i = 0; i < n; i++)
    {
        ui->sub_box->addItem(QString::fromStdString(match->getTeamOne()->getSub(i)->getName()));
    }
    for(int i = 0; i < 5; i++)
    {
        ui->player_box->addItem(QString::fromStdString(match->getTeamOne()->getPlayer(i)->getName()));
    }


    for(int i = 0; i < 5; i++)
    {
        vector<string> ratingLine = match->getTeamOne()->getPlayer(i)->getRatingLine();

        ratings[i][0]->setText(QString::fromStdString(ratingLine[0]));
        ratings[i][1]->setText(QString::fromStdString(ratingLine[1]));
        ratings[i][2]->setText(QString::fromStdString(ratingLine[2]));
        ratings[i][3]->setText(QString::fromStdString(ratingLine[3]));
    }
}

void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    match->sim(getMatchScreen());

    ui->stackedWidget->setCurrentIndex(1);
    ui->teamOneScore->display(match->getTeamOneScore());
    ui->teamTwoScore->display(match->getTeamTwoScore());
}


void MainWindow::on_roleOne_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(0)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);
}

void MainWindow::on_roleTwo_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(1)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);
}

void MainWindow::on_roleThree_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(2)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);
}

void MainWindow::on_roleFour_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(3)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);
}

void MainWindow::on_roleFive_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(4)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);
}

void MainWindow::on_player_box_currentIndexChanged(int index)
{
    playerIndex = index;
}

void MainWindow::on_sub_box_currentIndexChanged(int index)
{
    subIndex = index;
}

void MainWindow::on_sub_button_clicked()
{
    match->getTeamOne()->makeSub(playerIndex, subIndex);
    initTacticScreen();
}

//============================================

//===================================
//Home Screen
//===================================

void MainWindow::initHomeScreen()
{
    DIR*    dir;
    dirent* pdir;
    string path = "teams/";
    dir = opendir(path.c_str());

    while (pdir = readdir(dir)) {
        string name = pdir->d_name;
        if(name != "." && name != ".." && name != "")
        {
            int lastindex = name.find_last_of(".");
            string rawname = name.substr(0, lastindex);
            cout << rawname << endl;
            teamNames.push_back(rawname);
        }
    }

    for(int i = 0; i < teamNames.size(); i++)
    {
        ui->team_one->addItem(QString::fromStdString(teamNames[i]));
        ui->team_two->addItem(QString::fromStdString(teamNames[i]));
    }

    ui->team_one->setCurrentIndex(0);
    ui->team_two->setCurrentIndex(1);
    teamOneName = teamNames[0];
    teamTwoName = teamNames[1];
}

void MainWindow::on_team_one_currentIndexChanged(int index)
{
    teamOneName = teamNames[index];
}

void MainWindow::on_team_two_currentIndexChanged(int index)
{
    teamTwoName = teamNames[index];
}

void MainWindow::on_start_match_clicked()
{
    match = new Match(teamOneName, teamTwoName);
    initTacticScreen();
    ui->stackedWidget->setCurrentIndex(1);
}
