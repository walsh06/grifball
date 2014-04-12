#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(3);

    initHomeScreen();
    QObject::connect(ui->roundScreen, SIGNAL(gameOverSignal(int)), this, SLOT(changeScreen(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    //delete(match);
}



//====================================================================



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
    ui->roundScreen->setTeamNames(teamOneName, teamTwoName);
    ui->roundScreen->initScreen();
    ui->roundScreen->setMode(0);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::changeScreen(int mode)
{
    if(mode == 0)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
}
