#include "widgets.hpp"
#include "negyzet.hpp"
#include "applikacio.hpp"
#include "pont.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace genv;

class Amoba : public Applikacio
{
private: 
    vector<vector<int>> tabla;
    vector<vector<Negyzet*>> tabla_kep;
    bool feher_jatszik = true;
    int feher_pont=0;
    int sarga_pont=0;
    Pont * feherpont;
    Pont * sargapont;
public: 
    void ram_katt(int x, int y)
    {
        // printf("katt %d:%d\n", x, y);
        if (tabla[x][y] == 0)
        {
            if (feher_jatszik)
            {
                tabla[x][y] = feher;
                tabla_kep[x][y]->set_status(feher);
            }
            else
            {
                tabla[x][y] = sarga;
                tabla_kep[x][y]->set_status(sarga);
            }
            feher_jatszik = !feher_jatszik;
            pont_frissites();
        }
    }
    void pont_frissites()
    {
        printf("frissitsd a pontot, RITA <3 \n");
    }
    Amoba() 
    {
        tabla = vector<vector<int>>(15, vector<int>(15, 0));
        tabla_kep = vector<vector<Negyzet*>>(15, vector<Negyzet*>(15, 0));
        for (int i=0; i < 15; i++){
            for (int j=0; j < 15; j++){
                Negyzet * aij = new Negyzet (50+19*i, 50+19*j, i, j, [=](int x, int y){ ram_katt(x,y); });
                tabla_kep[i][j] = aij;
                widgets.push_back(aij);
            }
        }
        feherpont =new Pont(5,10,100,30,"0");
        widgets.push_back(feherpont);
        sargapont =new Pont(295,10,100,30,"0");
        widgets.push_back(sargapont);
    }

};



int main()
{
    Amoba jatek;
    jatek.fut(400,400);
    return 0;
}