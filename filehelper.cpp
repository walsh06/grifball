#include "filehelper.h"

Filehelper::Filehelper()
{
}

vector<Player*> Filehelper::getTeamFromFile(string filename)
{
    Team* team;
    vector<Player *> players;
    string line;
    stringstream file;
    int att, agil, jump, pass, num;
    file <<"teams/" << filename << ".csv";
    ifstream myfile (file.str().c_str());
    if (myfile.is_open())
    {

      while (getline(myfile,line) )
      {
          istringstream ss(line);
          vector <string> player_data;
          while (ss)
          {
              string s;
              if (!getline( ss, s, ',' )) break;
              player_data.push_back( s );
          }
          std::istringstream(player_data[1]) >> att;
          std::istringstream(player_data[2]) >> pass;
          std::istringstream(player_data[3]) >> jump;
          std::istringstream(player_data[4]) >> agil;
          std::istringstream(player_data[5]) >> num;

          Player* p = new Player(player_data[0], att, pass,jump,agil,num);
          players.push_back(p);
      }

      myfile.close();
    }
    return players;
}
