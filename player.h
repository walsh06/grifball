#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int attack, pass, agility, jumping;

public:
    Player();
    void setAttack(int attack);
    void setAgility(int agility);
    void setPass(int pass);
    void setJumping(int jumping);
};

#endif // PLAYER_H
