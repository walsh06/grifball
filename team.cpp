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

Team::Team(vector<Player *> players, int teamNum)
{
    this->squad = players;
    initTeam();
    setTeam(teamNum);
    startSpawn();

    resetScore();

    setPlayerRole(1, Player::ATTACKER);
    setPlayerRole(2, Player::ATTACKER);
    setPlayerRole(3, Player::SCORER);
    setPlayerRole(4, Player::SCORER);
    setPlayerRole(5, Player::DEFENDER);
}

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

void Team::setTeam(int team)
{
    for(int i = 0; i < squad.size(); i++)
    {
        squad[i]->setTeam(team);
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

