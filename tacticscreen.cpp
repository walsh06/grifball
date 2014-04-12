#include "tacticscreen.h"
#include "ui_tacticscreen.h"

TacticScreen::TacticScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TacticScreen)
{
    ui->setupUi(this);

    ui->teamOneScore->display(0);
    ui->teamTwoScore->display(0);


    ratings[0][0] = ui->one_att;ratings[0][1] = ui->one_agil;ratings[0][2] = ui->one_jump;ratings[0][3] = ui->one_pass;
    ratings[1][0] = ui->two_att;ratings[1][1] = ui->two_agil;ratings[1][2] = ui->two_jump;ratings[1][3] = ui->two_pass;
    ratings[2][0] = ui->three_att;ratings[2][1] = ui->three_agil;ratings[2][2] = ui->three_jump;ratings[2][3] = ui->three_pass;
    ratings[3][0] = ui->four_att;ratings[3][1] = ui->four_agil;ratings[3][2] = ui->four_jump;ratings[3][3] = ui->four_pass;
    ratings[4][0] = ui->five_att;ratings[4][1] = ui->five_agil;ratings[4][2] = ui->five_jump;ratings[4][3] = ui->five_pass;
}

TacticScreen::~TacticScreen()
{
    delete ui;
}

void TacticScreen::initScreen()
{
    ui->stackedWidget->setCurrentIndex(1);
    initRoleBox();
    match->getTeamTwo()->pickTeam();
    initTacticScreen();
    ui->teamOneScore->display(match->getTeamOneScore());
    ui->teamTwoScore->display(match->getTeamTwoScore());
    ui->teamOneName->setText(QString::fromStdString(match->getTeamOne()->getName()));
    ui->teamTwoName->setText(QString::fromStdString(match->getTeamTwo()->getName()));
    ui->changeRatings->addItem(QString::fromStdString("Ratings"));
    ui->changeRatings->addItem(QString::fromStdString("Stats"));
}

void TacticScreen::setTeamNames(string teamOneName, string teamTwoName)
{
    this->teamOneName = teamOneName;
    this->teamTwoName = teamTwoName;

    match = new Match(teamOneName, teamTwoName);
}

void TacticScreen::on_startButton_clicked()
{
    if(gameOver == true)
    {
        gameOver = false;
        ui->startButton->setText(QString::fromStdString("Start Round"));
        emit gameOverSignal(mode);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        match->sim(getMatchScreen());

        ui->stackedWidget->setCurrentIndex(1);
        ui->teamOneScore->display(match->getTeamOneScore());
        ui->teamTwoScore->display(match->getTeamTwoScore());

        if(match->getTeamOneScore() == 4 || match->getTeamTwoScore() == 4)
        {
            ui->startButton->setText(QString::fromStdString("Leave Game"));
            gameOver = true;
        }
    }
}


void TacticScreen::on_roleOne_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(0)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);

    loadSingleMenBox(0);
}

void TacticScreen::on_roleTwo_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(1)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);

    loadSingleMenBox(1);
}

void TacticScreen::on_roleThree_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(2)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);

    loadSingleMenBox(2);
}

void TacticScreen::on_roleFour_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(3)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);

    loadSingleMenBox(3);
}

void TacticScreen::on_roleFive_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(4)->getNumber();
    match->getTeamOne()->setPlayerRole(num, index+1);

    loadSingleMenBox(4);
}

void TacticScreen::on_menOne_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(0)->getNumber();
    match->getTeamOne()->setPlayerMentality(num, index+1);
}

void TacticScreen::on_menTwo_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(1)->getNumber();
    match->getTeamOne()->setPlayerMentality(num, index+1);
}

void TacticScreen::on_menThree_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(2)->getNumber();
    match->getTeamOne()->setPlayerMentality(num, index+1);
}

void TacticScreen::on_menFour_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(3)->getNumber();
    match->getTeamOne()->setPlayerMentality(num, index+1);
}

void TacticScreen::on_menFive_currentIndexChanged(int index)
{
    int num = match->getTeamOne()->getPlayer(4)->getNumber();
    match->getTeamOne()->setPlayerMentality(num, index+1);
}

void TacticScreen::on_player_box_currentIndexChanged(int index)
{
    playerIndex = index;
}

void TacticScreen::on_sub_box_currentIndexChanged(int index)
{
    subIndex = index;
}

void TacticScreen::on_sub_button_clicked()
{
    match->getTeamOne()->makeSub(playerIndex, subIndex);
    initTacticScreen();
}

//======================
//Tactic Screen
//======================

void TacticScreen::initRoleBox()
{
    ui->roleOne->clear();
    ui->roleTwo->clear();
    ui->roleThree->clear();
    ui->roleFour->clear();
    ui->roleFive->clear();

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
}

void TacticScreen::initMenBox()
{
    for(int i = 0; i < 5; i++)
    {
        loadSingleMenBox(i);
    }
}

void TacticScreen::loadSingleMenBox(int num)
{
    QComboBox* menBox [5];

    menBox[0] = ui->menOne;
    menBox[1] = ui->menTwo;
    menBox[2] = ui->menThree;
    menBox[3] = ui->menFour;
    menBox[4] = ui->menFive;

    if(num >= 0 && num < 5)
    {
        QComboBox* box = menBox[num];
        box->clear();
        Player* p = match->getTeamOne()->getPlayer(num);
        if(p->getRole() == p->ATTACKER)
        {
            menBox[num]->addItem(QString::fromStdString("Normal"));
            menBox[num]->addItem(QString::fromStdString("Berserker"));
            menBox[num]->addItem(QString::fromStdString("Scoring"));
        }
        else if(p->getRole() == p->SCORER)
        {
            menBox[num]->addItem(QString::fromStdString("Normal"));
            menBox[num]->addItem(QString::fromStdString("Full"));
            menBox[num]->addItem(QString::fromStdString("Playmaker"));
        }
        else if(p->getRole() == p->DEFENDER)
        {
            menBox[num]->addItem(QString::fromStdString("Normal"));
            menBox[num]->addItem(QString::fromStdString("Dynamic"));
            menBox[num]->addItem(QString::fromStdString("Full"));
        }
    }
}

void TacticScreen::initTacticScreen()
{
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

void TacticScreen::initStatScreen()
{
    for(int i = 0; i < 5; i++)
    {
        vector<string> statLine = match->getTeamOne()->getPlayer(i)->getStatLine();

        ratings[i][0]->setText(QString::fromStdString(statLine[0]));
        ratings[i][1]->setText(QString::fromStdString(statLine[1]));
        ratings[i][2]->setText(QString::fromStdString(statLine[2]));
        ratings[i][3]->setText(QString::fromStdString(statLine[3]));
    }
}

void TacticScreen::on_changeRatings_currentIndexChanged(int index)
{
    if(index == 0)
    {
        initTacticScreen();
        ui->headerOne->setText(QString::fromStdString("Attack"));
        ui->headerTwo->setText(QString::fromStdString("Agility"));
        ui->headerThree->setText(QString::fromStdString("Jump"));
        ui->headerFour->setText(QString::fromStdString("Pass"));
    }
    else if(index == 1)
    {
        initStatScreen();
        ui->headerOne->setText(QString::fromStdString("Kills"));
        ui->headerTwo->setText(QString::fromStdString("Deaths"));
        ui->headerThree->setText(QString::fromStdString("Scores"));
        ui->headerFour->setText(QString::fromStdString("Energy"));
    }
}

MatchScreen* TacticScreen::getMatchScreen()
{
    return ui->matchWidget;
}

void TacticScreen::setMode(int mode)
{
    this->mode = mode;
}

Team* TacticScreen::getTeamOne()
{
    return match->getTeamOne();
}

Team* TacticScreen::getTeamTwo()
{
    return match->getTeamTwo();
}
