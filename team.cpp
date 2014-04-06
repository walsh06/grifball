#include "team.h"


Team::Team(int n)
{
    if(n == 1)
    {
        addPlayer(new Player("Church", 10, 10, 10, 10, 1));
        addPlayer(new Player("Caboose", 10, 10, 10, 10, 2));
        addPlayer(new Player("Tucker", 10, 10, 10, 10, 3));
        addPlayer(new Player("Wash", 10, 10, 10, 10, 4));
        addPlayer(new Player("Freckles", 10, 10, 10, 10, 5));
        players[0]->setRole(1);
        players[1]->setRole(2);
        players[2]->setRole(2);
        players[3]->setRole(3);
        players[4]->setRole(1);
        players[0]->setPosX(0);players[0]->setPosY(1);
        players[1]->setPosX(0);players[1]->setPosY(2);
        players[2]->setPosX(0);players[2]->setPosY(3);
        players[3]->setPosX(0);players[3]->setPosY(4);
        players[4]->setPosX(0);players[4]->setPosY(5);
        players[0]->setTeam(1);
        players[1]->setTeam(1);
        players[2]->setTeam(1);
        players[3]->setTeam(1);
        players[4]->setTeam(1);


    }
    else
    {
        addPlayer(new Player("Sarge", 10, 10, 10, 10, 1));
        addPlayer(new Player("Griff", 10, 10, 10, 10, 2));
        addPlayer(new Player("Donut", 10, 10, 10, 10, 3));
        addPlayer(new Player("Simmons", 10, 10, 10, 10, 4));
        addPlayer(new Player("Lopez", 10, 10, 10, 10, 5));
        players[0]->setRole(1);
        players[1]->setRole(2);
        players[2]->setRole(2);
        players[3]->setRole(3);
        players[4]->setRole(2);
        players[0]->setPosX(6);players[0]->setPosY(1);
        players[1]->setPosX(6);players[1]->setPosY(2);
        players[2]->setPosX(6);players[2]->setPosY(3);
        players[3]->setPosX(6);players[3]->setPosY(4);
        players[4]->setPosX(6);players[4]->setPosY(5);
        players[0]->setTeam(2);
        players[1]->setTeam(2);
        players[2]->setTeam(2);
        players[3]->setTeam(2);
        players[4]->setTeam(2);
    }
}

Team::Team(vector<Player *> players, int teamNum, string name)
{
    this->squad = players;
    initTeam();
    setTeam(teamNum);
    startSpawn();

    this->name = name;

    resetScore();

    setPlayerRole(1, Player::ATTACKER);
    setPlayerRole(2, Player::ATTACKER);
    setPlayerRole(3, Player::SCORER);
    setPlayerRole(4, Player::SCORER);
    setPlayerRole(5, Player::DEFENDER);
}

//========================
// INIT
//============================
void Team::setTeam(int team)
{
    for(int i = 0; i < squad.size(); i++)
    {
        squad[i]->setTeam(team);
    }
}

void Team::initTeam()
{
    for(int i =0; i < 5; i++)
    {
        players.push_back(squad[i]);
    }

    for(int i = 5; i < squad.size(); i++)
    {
        subs.push_back(squad[i]);
    }
}

void Team::startSpawn()
{
    if(players[0]->getTeam() == 1)
    {
        players[0]->setPosX(0);players[0]->setPosY(1);
        players[1]->setPosX(0);players[1]->setPosY(2);
        players[2]->setPosX(0);players[2]->setPosY(3);
        players[3]->setPosX(0);players[3]->setPosY(4);
        players[4]->setPosX(0);players[4]->setPosY(5);
    }
    else if(players[0]->getTeam() == 2)
    {
        players[0]->setPosX(6);players[0]->setPosY(1);
        players[1]->setPosX(6);players[1]->setPosY(2);
        players[2]->setPosX(6);players[2]->setPosY(3);
        players[3]->setPosX(6);players[3]->setPosY(4);
        players[4]->setPosX(6);players[4]->setPosY(5);
    }
}

void Team::pickTeam()
{
    vector<int> indexUsed;
    players.clear();
    subs.clear();
    int firstRating = squad[0]->getAttack(), secondRating = squad[1]->getAttack();
    int firstIndex = 0, secondIndex = 1;

    for(int i = 2; i < squad.size(); i++)
    {
        if(squad[i]->getAttack() > firstRating )
        {
            secondRating = firstRating;
            secondIndex = firstIndex;
            firstRating = squad[i]->getAttack();
            firstIndex = i;
        }
        else if(squad[i]->getAttack() > secondRating)
        {
            secondRating = squad[i]->getAttack();
            secondIndex = i;
        }
    }

    indexUsed.push_back(firstIndex);
    indexUsed.push_back(secondIndex);

    Player *firstAttacker = squad[firstIndex], *secondAttacker = squad[secondIndex];
    firstAttacker->setRole(Player::ATTACKER);
    secondAttacker->setRole(Player::ATTACKER);

    players.push_back(firstAttacker);
    players.push_back(secondAttacker);
    firstIndex = -1;
    secondIndex = -1;

    for(int i = 0; i < 4; i++)
    {
        if(find(indexUsed.begin(), indexUsed.end(), i) == indexUsed.end()) {
            if(firstIndex == -1)
            {
                firstIndex = i;
            }
            else
            {
                secondIndex = i;
                break;
            }
        }
    }

    firstRating = squad[firstIndex]->getJump();
    secondRating = squad[secondIndex]->getJump();

    for(int i = 0; i < squad.size(); i++)
    {
        if(find(indexUsed.begin(), indexUsed.end(), i) == indexUsed.end())
        {
            if(squad[i]->getJump() > firstRating )
            {
                secondRating = firstRating;
                secondRating = firstIndex;
                firstRating = squad[i]->getJump();
                firstIndex = i;
            }
            else if(squad[i]->getJump() > secondRating)
            {
                secondRating = squad[i]->getJump();
                secondIndex = i;
            }
        }
    }

    indexUsed.push_back(firstIndex);
    indexUsed.push_back(secondIndex);
    Player *firstScorer = squad[firstIndex], *secondScorer = squad[secondIndex];
    firstScorer->setRole(Player::SCORER);
    secondScorer->setRole(Player::SCORER);

    players.push_back(firstScorer);
    players.push_back(secondScorer);

    firstIndex = -1;
    for(int i = 0; i < 6; i++)
    {
        if(std::find(indexUsed.begin(), indexUsed.end(), i) == indexUsed.end()) {
                firstIndex = i;
                break;
        }
    }

    firstRating = squad[firstIndex]->getAttack();
    secondRating = squad[firstIndex]->getAgility();
    for(int i = 0; i < squad.size(); i++)
    {
        if(squad[i]->getAttack() > firstRating && squad[i]->getAgility() > secondRating &&
             std::find(indexUsed.begin(), indexUsed.end(), i) == indexUsed.end())
        {
            firstIndex = i;
            firstRating = squad[i]->getAttack() ;
            secondRating = squad[i]->getAgility() ;
        }
    }

    indexUsed.push_back(firstIndex);
    Player *firstDefender = squad[firstIndex];
    firstDefender->setRole(Player::DEFENDER);

    players.push_back(firstDefender);

    for(int i = 0; i < squad.size(); i++)
    {
        if(std::find(indexUsed.begin(), indexUsed.end(), i) == indexUsed.end()) {
            subs.push_back(squad[i]);
        }
    }
}

//================================================

void Team::setPlayerRole(int playerNum, int role)
{
    Player *player;
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i]->getNumber() == playerNum)
        {
            player = players[i];
        }
    }

    if(player != NULL)
    {
        player->setRole(role);
    }
}

void Team::setPlayerMentality(int playerNum, int mentality)
{
    Player *player;
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i]->getNumber() == playerNum)
        {
            player = players[i];
        }
    }

    if(player != NULL)
    {
        player->setMentality(mentality);
    }
}

Player* Team::getPlayer(int playerNum)
{
    return players[playerNum];
}

Player* Team::getSub(int playerNum)
{
    return subs[playerNum];
}

void Team::addPlayer(Player *p)
{
    if(players.size() < 5)
    {
        players.push_back(p);
    }
}

int Team::getScore()
{
    return score;
}

void Team::addScore()
{
    score++;
}

void Team::resetScore()
{
    score = 0;
}

void Team::makeSub(int playerIndex, int subIndex)
{
    Player* player = players[playerIndex];
    Player* sub = subs[subIndex];

    players.erase(players.begin() + playerIndex);
    subs.erase(subs.begin() + subIndex);

    players.push_back(sub);
    subs.push_back(player);
}

int Team::getNumSubs()
{
    return subs.size();
}

string Team::getName()
{
    return name;
}

void Team::setEndRound()
{
    for(int i = 0; i < 5;i++)
    {
        subs[i]->resetEnergy();
        subs[i]->calculateFormModifier();
        players[i]->decreaseEnergy();
        players[i]->calculateFormModifier();
    }
}


