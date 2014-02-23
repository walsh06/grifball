#ifndef PLAYER_H
#define PLAYER_H
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

/*
 *with_ball {move_towards_goal, move_down, move_left, move_right, pass}
 *team_ball {move_up, move_down, move_left, move_right}
 *opp_ball {move_towards_ball, move_down, move_left, move_right}
 *opp_in_square {move_down, move_left, move_right, kill}
 *loose_ball{move_toward_ball, move_back}
 *ball_with_opp{move_towards_goal, move_down, move_left, move_right, pass}
 *
 *POS LAYOUT
 *
 */
using namespace std;

class Player
{
private:
    int attack, pass, agility, jumping;

    int with_ball[5];
    int team_ball[4];
    int opp_ball[4];
    int opp_in_square[4];
    int loose_ball[2];
    int ball_with_opp[5];

    int status;
    int position[2];
    int team;
    int role;
    int move;
    int number;

    int kills, deaths, scores;

    string name;

public:
    static const int MOVE_UP = 1, MOVE_DOWN = 2, MOVE_LEFT = 3, MOVE_RIGHT = 4, PASS = 5, ATTACK = 6, MOVE_TO_BALL = 7, MOVE_TO_GOAL = 8;
    static const int HAS_BALL = 1, TEAM_WITH_BALL = 2, WITHOUT_BALL = 3, OPP_IN_SQUARE = 4, LOOSE_BALL = 5, DEAD = 6, BALL_WITH_OPP = 7;
    static const int SCORER = 1, ATTACKER = 2, DEFENDER = 3;
    static const int maxRating = 20;

    Player(string name, int attack, int pass, int jump, int agility, int number);

    void setAttack(int attack);
    void setAgility(int agility);
    void setPass(int pass);
    void setJumping(int jumping);
    void setPosX(int x);
    void setPosY(int y);
    void setStatus(int status);
    void setRole(int role);
    void setMove(int move);
    void setTeam(int team);

    string getRoleString();
    int getRole();
    int getPass();
    int getStatus();
    int getJump();
    int getAttack();
    int getAgility();
    int getMove();
    int getPosX();
    int getPosY();
    int getAction();
    int getTeam();
    int getNumber();
    string getName();

    void addKill();
    void addDeath();
    void addScore();
    void resetKill();
    void resetDeath();
    void resetScore();

    vector<string> getStatString();
    vector<string> getRatingLine();

    void respawn();
    void kill();
};

#endif // PLAYER_H
