#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    int team;
    int player;
    int posX, posY;

public:
    Ball();

    void setTeam(int teamNum);
    void setPlayer(int playerNum);
    void setPosX(int x);
    void setPosY(int y);

    int getTeam();
    int getPlayer();
    int getPosX();
    int getPosY();
};

#endif // BALL_H
