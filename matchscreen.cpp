#include "matchscreen.h"
#include "ui_matchscreen.h"

MatchScreen::MatchScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchScreen)
{
    ui->setupUi(this);
}

MatchScreen::~MatchScreen()
{
    delete ui;
}

void MatchScreen::updateOutput(string message)
{
    ui->mainOutput->setText(QString::fromStdString(message));
}

