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

    userTeamIndex = 0;

}

void Tournament::simRound(bool userTeam)
{
    int start;
    if(userTeam)
    {
        start = 2;
    }
    else
    {
        start = 0;
    }
    for(int i = start; i < roundMatches[round - 1];i+=2)
    {
        string teamOneName = tournamentTree[i]->getName();
        string teamTwoName = tournamentTree[i + 1]->getName();

        Match match(teamOneName, teamTwoName);
        if(i != userTeamIndex && (i + 1) != userTeamIndex)
        {
            match.getTeamOne()->setTeam(1);
            match.getTeamTwo()->setTeam(2);
            while(match.getTeamOneScore() != 4 && match.getTeamTwoScore() != 4)
            {
                match.quickSim();
            }

            updateEndMatch(match.getTeamOne(), match.getTeamTwo(), i);
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

void Tournament::addResult(string teamOneName, int teamOneScore, string teamTwoName, int teamTwoScore)
{
    stringstream result;

    result << teamOneName << " " << teamOneScore << "\n";
    result << teamTwoName << " " << teamTwoScore << "\n";
    result << "\n";

    results.push_back(result.str());
}

vector<string> Tournament::getResults()
{
    return results;
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

void Tournament::updateEndMatch(Team *teamOne, Team *teamTwo, int i)
{
    if(teamOne->getScore() == 4)
    {
        tournamentTree[i/2] = tournamentTree[i];
        if(i != userTeamIndex)
        {
            userTeamIndex = -1;
        }
    }
    else
    {
        tournamentTree[i/2]= tournamentTree[i + 1];
        if(i == userTeamIndex)
        {
            userTeamIndex = -1;
        }
    }
    addResult(teamOne->getName(), teamOne->getScore(), teamTwo->getName(), teamTwo->getScore());
}

int Tournament::getUserTeamIndex()
{
    return userTeamIndex;
}

map<int, Team *> Tournament::getTournamentTree()
{
    return tournamentTree;
}

