#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <map>
#include <string>
#include <sstream>
#include "team.h"
#include "match.h"

using namespace std;

class Tournament
{
private:
    map<int, Team *> tournamentTree;

    int round;
    int numTeams;
    int roundMatches[4] = {2, 4, 8, 16};

public:
    Tournament();
    void simRound();
    void addTeam(Team *team);
    int getRound();
    string toString();

};

#endif // TOURNAMENT_H
