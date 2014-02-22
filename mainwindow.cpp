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
}

MainWindow::~MainWindow()
{
    delete ui;
}

MatchScreen* MainWindow::getMatchScreen()
{
    return ui->matchWidget;
}


void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    match->sim(getMatchScreen());

    ui->stackedWidget->setCurrentIndex(1);
    ui->teamOneScore->display(match->getTeamOneScore());
    ui->teamTwoScore->display(match->getTeamTwoScore());
}
