#include "match.h"

Match::Match()
{
}

void Match::sim()
{
    Player p;

    for(int i = 0; i < 10; i++)
    {
        cout << i << ")";
        cout << p.getAction() << endl;
    }
}
