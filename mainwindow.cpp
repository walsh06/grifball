#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

    match = new Match("blues", "reds");

    ui->teamOneScore->display(0);
    ui->teamTwoScore->display(0);
    ui->teamOneName->setText(QString::fromStdString("Blues"));
    ui->teamTwoName->setText(QString::fromStdString("Reds"));

    initTacticScreen();
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

    ui->roleOne->setCurrentIndex(Player::ATTACKER -1);
    ui->roleTwo->setCurrentIndex(Player::SCORER -1);
    ui->roleThree->setCurrentIndex(Player::SCORER -1);
    ui->roleFour->setCurrentIndex(Player::ATTACKER -1);
    ui->roleFive->setCurrentIndex(Player::DEFENDER -1);

}

//========================

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
