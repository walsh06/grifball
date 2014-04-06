#include "player.h"
#include <iostream>

Player::Player(string name, int attack, int pass, int jump, int agility, int number)
{
    this->name = name;
    setAgility(agility);
    setAttack(attack);
    setJumping(jump);
    setPass(pass);
    this->number = number;
    move = 0;
    srand( time(0));
    status = LOOSE_BALL;
    team = 0;
    setRole(ATTACKER);
    resetKill();
    resetDeath();
    resetScore();
    mentality = 1;
}

void Player::kill()
{
    status = DEAD;
    position[0] = -1;
    position[1] = -1;
}

void Player::respawn()
{
    cout << "RESPAWN" << endl;
    int ranPos = rand()%3 + 2;
    if(team == 1)
    {
        setPosX(0);
        setPosY(ranPos);
    }
    else if(team == 2)
    {
        setPosX(6);
        setPosY(ranPos);
    }
}

void Player::setRole(int role)
{
    this->role = role;
    if(role == SCORER)
    {
        setMentality(mentality);
    }
    else if(role == ATTACKER)
    {
        setMentality(mentality);
    }
    else if(role == DEFENDER)
    {
        setMentality(mentality);
    }
}

void Player::setMentality(int mentality)
{
    /*
     *with_ball {move_towards_goal, move_down, move_left, move_right, pass}
     *team_ball {move_up, move_down, move_left, move_right}
     *opp_ball {move_towards_ball, move_down, move_left, move_right}
     *opp_in_square {move_down, move_left, move_right, kill}
     *loose_ball{move_toward_ball, move_back}
     *ball_with_opp{move_towards_goal, move_down, move_left, move_right, pass}
     **/
    this->mentality = mentality;
    if(role == ATTACKER)
    {
        if(mentality == 1)//Normal
        {
            with_ball[0] = 60; with_ball[1] = 5; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 25;
            team_ball[0] = 60; team_ball[1] = 4; team_ball[2] = 24; team_ball[3] = 24;
            opp_ball[0] = 85; opp_ball[1] = 5; opp_ball[2] = 5; opp_ball[3] = 5;
            opp_in_square[0] = 5; opp_in_square[1] = 5; opp_in_square[2] = 5; opp_in_square[3] = 85;
            loose_ball[0] = 95; loose_ball[1] = 5;
            ball_with_opp[0] = 40; ball_with_opp[1] = 10; ball_with_opp[2] = 15; ball_with_opp[3] = 15; ball_with_opp[4] = 20;
        }
        else if(mentality == 2)//Berserker
        {
            with_ball[0] = 60; with_ball[1] = 0; with_ball[2] = 0; with_ball[3] = 0; with_ball[4] = 40;
            team_ball[0] = 45; team_ball[1] = 5; team_ball[2] = 25; team_ball[3] = 25;
            opp_ball[0] = 100; opp_ball[1] = 0; opp_ball[2] = 0; opp_ball[3] = 0;
            opp_in_square[0] = 0; opp_in_square[1] = 0; opp_in_square[2] = 0; opp_in_square[3] = 100;
            loose_ball[0] = 100; loose_ball[1] = 0;
            ball_with_opp[0] = 60; ball_with_opp[1] = 0; ball_with_opp[2] = 7; ball_with_opp[3] = 7; ball_with_opp[4] = 26;
        }
        else if(mentality == 3)//Scoring
        {
            with_ball[0] = 70; with_ball[1] = 0; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 20;
            team_ball[0] = 45; team_ball[1] = 5; team_ball[2] = 25; team_ball[3] = 25;
            opp_ball[0] = 76; opp_ball[1] = 10; opp_ball[2] = 7; opp_ball[3] = 7;
            opp_in_square[0] = 10; opp_in_square[1] = 0; opp_in_square[2] = 0; opp_in_square[3] = 90;
            loose_ball[0] = 95; loose_ball[1] = 5;
            ball_with_opp[0] = 80; ball_with_opp[1] = 0; ball_with_opp[2] = 5; ball_with_opp[3] = 5; ball_with_opp[4] = 10;
        }
    }
    else if(role == DEFENDER)
    {
        if(mentality == 1)//Normal
        {
            with_ball[0] = 40; with_ball[1] = 4; with_ball[2] = 8; with_ball[3] = 8; with_ball[4] = 40;
            team_ball[0] = 50; team_ball[1] = 20; team_ball[2] = 15; team_ball[3] = 15;
            opp_ball[0] = 30; opp_ball[1] = 40; opp_ball[2] = 15; opp_ball[3] = 15;
            opp_in_square[0] = 10; opp_in_square[1] = 10; opp_in_square[2] = 10; opp_in_square[3] = 70;
            loose_ball[0] = 75; loose_ball[1] = 25;
            ball_with_opp[0] = 30; ball_with_opp[1] = 30; ball_with_opp[2] = 10; ball_with_opp[3] = 10; ball_with_opp[4] = 20;
        }
        else if(mentality == 2)//Dynamic
        {
            with_ball[0] = 40; with_ball[1] = 4; with_ball[2] = 8; with_ball[3] = 8; with_ball[4] = 40;
            team_ball[0] = 60; team_ball[1] = 10; team_ball[2] = 15; team_ball[3] = 15;
            opp_ball[0] = 40; opp_ball[1] = 40; opp_ball[2] = 10; opp_ball[3] = 10;
            opp_in_square[0] = 10; opp_in_square[1] = 5; opp_in_square[2] = 5; opp_in_square[3] = 80;
            loose_ball[0] = 85; loose_ball[1] = 15;
            ball_with_opp[0] = 30; ball_with_opp[1] = 20; ball_with_opp[2] = 5; ball_with_opp[3] = 5; ball_with_opp[4] = 40;
        }
        else if(mentality == 3)//Full Back
        {
            with_ball[0] = 30; with_ball[1] = 5; with_ball[2] = 10; with_ball[3] = 10; with_ball[4] = 45;
            team_ball[0] = 40; team_ball[1] = 30; team_ball[2] = 15; team_ball[3] = 15;
            opp_ball[0] = 0; opp_ball[1] = 60; opp_ball[2] = 20; opp_ball[3] = 20;
            opp_in_square[0] = 30; opp_in_square[1] = 5; opp_in_square[2] = 5; opp_in_square[3] = 60;
            loose_ball[0] = 50; loose_ball[1] = 50;
            ball_with_opp[0] = 0; ball_with_opp[1] = 40; ball_with_opp[2] = 10; ball_with_opp[3] = 10; ball_with_opp[4] = 50;
        }
    }
    else if(role == SCORER)
    {
        if(mentality == 1)//Normal
        {
            with_ball[0] = 70; with_ball[1] = 5; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 15;
            team_ball[0] = 75; team_ball[1] = 5; team_ball[2] = 10; team_ball[3] = 10;
            opp_ball[0] = 60; opp_ball[1] = 20; opp_ball[2] = 10; opp_ball[3] = 10;
            opp_in_square[0] = 40; opp_in_square[1] = 10; opp_in_square[2] = 10; opp_in_square[3] = 40;
            loose_ball[0] = 95; loose_ball[1] = 5;
            ball_with_opp[0] = 50; ball_with_opp[1] = 5; ball_with_opp[2] = 15; ball_with_opp[3] = 15; ball_with_opp[4] = 15;
        }
        else if(mentality == 2)//Full Forward
        {
            with_ball[0] = 90; with_ball[1] = 0; with_ball[2] = 0; with_ball[3] = 0; with_ball[4] = 10;
            team_ball[0] = 80; team_ball[1] = 0; team_ball[2] = 10; team_ball[3] = 10;
            opp_ball[0] = 75; opp_ball[1] = 15; opp_ball[2] = 5; opp_ball[3] = 5;
            opp_in_square[0] = 30; opp_in_square[1] = 20; opp_in_square[2] = 20; opp_in_square[3] = 30;
            loose_ball[0] = 100; loose_ball[1] = 0;
            ball_with_opp[0] = 80; ball_with_opp[1] = 0; ball_with_opp[2] = 3; ball_with_opp[3] = 3; ball_with_opp[4] = 14;
        }
        else if(mentality == 3)//Playmaker
        {
            with_ball[0] = 60; with_ball[1] = 0; with_ball[2] = 5; with_ball[3] = 5; with_ball[4] = 30;
            team_ball[0] = 90; team_ball[1] = 0; team_ball[2] = 5; team_ball[3] = 5;
            opp_ball[0] = 75; opp_ball[1] = 15; opp_ball[2] = 5; opp_ball[3] = 5;
            opp_in_square[0] = 30; opp_in_square[1] = 20; opp_in_square[2] = 20; opp_in_square[3] = 30;
            loose_ball[0] = 100; loose_ball[1] = 0;
            ball_with_opp[0] = 40; ball_with_opp[1] = 0; ball_with_opp[2] = 5; ball_with_opp[3] = 5; ball_with_opp[4] = 50;
        }
    }
}

void Player::setAttack(int attack)
{
    if(attack > maxRating)
    {
        this->attack = maxRating;
    }
    else
    {
        this->attack = attack;
    }
}

void Player::setAgility(int agility)
{
    if(agility > maxRating)
    {
        this->agility = maxRating;
    }
    else
    {
        this->agility = agility;
    }
}

void Player::setPass(int pass)
{
    if(pass > maxRating)
    {
        this->pass = maxRating;
    }
    else
    {
        this->pass = pass;
    }
}

void Player::setJumping(int jumping)
{
    if(jumping > maxRating)
    {
        this->jumping = maxRating;
    }
    else
    {
        this->jumping = jumping;
    }
}

void Player::setStatus(int status)
{
    if(status > 0 && status < 7)
    {
        this->status=status;
    }
}

void Player::setMove(int move)
{
    this->move = move;
}

void Player::setPosX(int x)
{
    if(x >= 0 && x <= 6 )
    {
        position[0] = x;
    }
}

void Player::setPosY(int y)
{
    if(y >= 0 && y <= 6 )
    {
        position[1] = y;
    }
}

void Player::setTeam(int team)
{
    this->team = team;
}

int Player::getPosX()
{
    return position[0];
}

int Player::getPosY()
{
    return position[1];
}

int Player::getAction()
{
    int n=rand()%100;
    int action = -1;

    if(status == HAS_BALL)
    {
        if( n < with_ball[0])
        {
            action = MOVE_TO_GOAL;
        }
        else if(n < with_ball[0] + with_ball[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2] + with_ball[3])
        {
            action = MOVE_RIGHT;
        }
        else if(n < with_ball[0] + with_ball[1] + with_ball[2] + with_ball[3] + with_ball[4])
        {
            action = PASS;
        }
    }
    else if (status == TEAM_WITH_BALL)
    {
        if( n < team_ball[0])
        {
            action = MOVE_UP;
        }
        else if(n < team_ball[0] + team_ball[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < team_ball[0] + team_ball[1] + team_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < team_ball[0] + team_ball[1] + team_ball[2] + team_ball[3])
        {
            action = MOVE_RIGHT;
        }
    }
    else if (status == WITHOUT_BALL)
    {
        if( n < opp_ball[0])
        {
            action = MOVE_TO_BALL;
        }
        else if(n < opp_ball[0] + opp_ball[1])
        {
            action = MOVE_TO_OWN_GOAL;
        }
        else if(n < opp_ball[0] + opp_ball[1] + opp_ball[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < opp_ball[0] + opp_ball[1] + opp_ball[2] + opp_ball[3])
        {
            action = MOVE_RIGHT;
        }
    }
    else if (status == OPP_IN_SQUARE)
    {
        if( n < opp_in_square[0])
        {
            action = MOVE_DOWN;
        }
        else if(n < opp_in_square[0] + opp_in_square[1])
        {
            action = MOVE_LEFT;
        }
        else if(n < opp_in_square[0] + opp_in_square[1] + opp_in_square[2])
        {
            action = MOVE_RIGHT;
        }
        else if(n < opp_in_square[0] + opp_in_square[1] + opp_in_square[2] + opp_in_square[3])
        {
            action = ATTACK;
        }
    }
    else if (status == LOOSE_BALL)
    {
        if( n < loose_ball[0])
        {
            action = MOVE_TO_BALL;
        }
        else if(n < loose_ball[0] + loose_ball[1])
        {
            action = MOVE_LEFT;
        }
    }
    else if(status == BALL_WITH_OPP)
    {
        if( n < ball_with_opp[0])
        {
            action = MOVE_TO_GOAL;
        }
        else if(n < ball_with_opp[0] + ball_with_opp[1])
        {
            action = MOVE_DOWN;
        }
        else if(n < ball_with_opp[0] + ball_with_opp[1] + ball_with_opp[2])
        {
            action = MOVE_LEFT;
        }
        else if(n < ball_with_opp[0] + ball_with_opp[1] + ball_with_opp[2] + ball_with_opp[3])
        {
            action = MOVE_RIGHT;
        }
        else if(n < ball_with_opp[0] + ball_with_opp[1] + ball_with_opp[2] + ball_with_opp[3] + ball_with_opp[4])
        {
            action = PASS;
        }
    }
    return action;
}

int Player::getTeam()
{
    return team;
}

string Player::getName()
{
    return name;
}

int Player::getMove()
{
    return move;
}

int Player::getPass()
{
    return pass + formModifier;
}

int Player::getAgility()
{
    return agility + formModifier;
}

int Player::getNumber()
{
    return number;
}

int Player::getAttack()
{
    return attack + formModifier;
}

int Player::getJump()
{
    return jumping + formModifier;
}

int Player::getStatus()
{
    return status;
}

int Player::getRole()
{
    return role;
}

void Player::addKill()
{
    kills++;
}

void Player::addDeath()
{
    deaths++;
}

void Player::addScore()
{
    scores++;
}

void Player::resetKill()
{
    kills = 0;
}

void Player::resetDeath()
{
    deaths = 0;
}

void Player::resetScore()
{
    scores = 0;
}

void Player::resetEnergy()
{
    energy = 20;
}

void Player::decreaseEnergy()
{
    energy = energy - (2 + (20 - stamina));
    if(energy < 0)
    {
        energy = 0;
    }
}

void Player::calculateFormModifier()
{
    formModifier = 0;
    int energyMod;
    int statMod;

    if(energy > 16)
    {
        energyMod = 0;
    }
    else if(energy > 12)
    {
        energyMod = 1;
    }
    else if(energy > 8)
    {
        energyMod = 2;
    }
    else if(energy > 4)
    {
        energyMod = 3;
    }
    else
    {
        energyMod = 4;
    }

    statMod = (kills - deaths)/2;

    formModifier = statMod - energyMod;
}

string Player::getRoleString()
{
    string roleString = "";
    if(role == ATTACKER)
    {
        roleString = "Attacker";
    }
    else if(role == DEFENDER)
    {
        roleString = "Defender";
    }
    else if(role == SCORER)
    {
        roleString = "Scorer";
    }

    return roleString;
}

vector<string> Player::getStatString()
{
    stringstream killStream, deathStream, scoreStream;
    killStream << kills;
    deathStream << deaths;
    scoreStream << scores;
    vector<string> statLine;
    statLine.push_back(name);
    statLine.push_back(killStream.str());
    statLine.push_back(deathStream.str());
    statLine.push_back(scoreStream.str());
    return statLine;
}

vector<string> Player::getRatingLine()
{
    stringstream attStream, agilStream, jumpStream, passStream;
    attStream << attack;
    agilStream << agility;
    jumpStream << jumping;
    passStream << pass;

    vector<string> ratingLine;
    ratingLine.push_back(attStream.str());
    ratingLine.push_back(agilStream.str());
    ratingLine.push_back(jumpStream.str());
    ratingLine.push_back(passStream.str());

    return ratingLine;
}
