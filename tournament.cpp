#include "tournament.h"
#include <iostream>

Tournament::Tournament()
{
    round = 2;

    Team *teamOne = new Team(Filehelper::getTeamFromFile("blah"), 1, "blah");
    Team *teamTwo = new Team(Filehelper::getTeamFromFile("reds"), 1, "reds");
    Team *teamThree = new Team(Filehelper::getTeamFromFile("blues"), 2, "blues");
    Team *teamFour = new Team(Filehelper::getTeamFromFile("freelancers"), 2, "freelancers");

    tournamentTree[0] = teamOne;
    tournamentTree[1] = teamTwo;
    tournamentTree[2] = teamThree;
    tournamentTree[3] = teamFour;

}

void Tournament::simRound()
{
    for(int i = 0; i < roundMatches[round - 1];i+=2)
    {
        string teamOneName = tournamentTree[i]->getName();
        string teamTwoName = tournamentTree[i + 1]->getName();

        Match match(teamOneName, teamTwoName);
        match.getTeamOne()->setTeam(1);
        match.getTeamTwo()->setTeam(2);
        while(match.getTeamOneScore() != 4 && match.getTeamTwoScore() != 4)
        {
            match.quickSim();
        }
        if(match.getTeamOneScore() == 4)
        {
            tournamentTree[i/2] = tournamentTree[i];
        }
        else
        {
            tournamentTree[i/2]= tournamentTree[i + 1];
        }
    }
    round--;
}

void Tournament::addTeam(Team *team)
{

}

int Tournament::getRound()
{
    return round;
}

string Tournament::toString()
{
    stringstream tournamentString;
    if(round == 0)
    {
        tournamentString << tournamentTree[0]->getName();
    }
    else
    {
        for(int i = 0; i < roundMatches[round - 1];i+=2)
        {
            tournamentString << tournamentTree[i]->getName() << " v " << tournamentTree[i + 1]->getName() << "\n";
        }
    }

    return tournamentString.str();
}
