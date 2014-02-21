#ifndef FILEHELPER_H
#define FILEHELPER_H

#include "team.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Filehelper
{
public:
    Filehelper();
    static Team * getTeamFromFile(string filename);
};

#endif // FILEHELPER_H
