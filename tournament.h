#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <map>
#include "team.h"

using namespace std;

class Tournament
{
private:
    map<Team *, int> tournamentTree;
    int round;
    int roundMatches[5] = {1, 2, 4, 8, 16};

public:
    Tournament();
    void simRound();

};

#endif // TOURNAMENT_H
