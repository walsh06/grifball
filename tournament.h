#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <QObject>
#include <map>
#include <string>
#include <sstream>
#include "team.h"
#include "match.h"
#include "tacticscreen.h"

using namespace std;

class Tournament
{
private:

    map<int, Team *> tournamentTree;
    vector<string> results;

    int round;
    int numTeams;
    int userTeamIndex;
    int roundMatches[4] = {2, 4, 8, 16};

public:
    Tournament();
    void simRound(bool userTeam = false);
    void addTeam(Team *team);
    int getRound();
    int getUserTeamIndex();
    string toString();
    void addResult(string teamOneName, int teamOneScore, string teamTwoName, int teamTwoScore);
    vector<string> getResults();

    map<int, Team *> getTournamentTree();

    void updateEndMatch(Team *teamOne, Team *teamTwo, int i);

};

#endif // TOURNAMENT_H
