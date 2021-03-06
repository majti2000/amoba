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
    int xx=0; 
    int yy=0;
    Pont * feherpont;
    Pont * sargapont;
public: 
    void ram_katt(int x, int y)
    {
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
            betelt();
        }
    }
    void betelt()
    {
        int ikszeltek=0;
        for (int i=0; i < tabla_kep.size(); i++){
            for (int j=0; j < tabla_kep.size(); j++){
                if(tabla_kep[i][j]->get_status()!=ures){
                    ikszeltek++;
                }
            }
        }
        if (ikszeltek==225){
            for (int i=0; i < tabla.size(); i++){
                for (int j=0; j < tabla.size(); j++){
                    tabla[i][j]=ures;
                    tabla_kep[i][j]->set_status(ures);
                }
            }
        }
    }
    void pont_frissites()
    {
        for (int i=4; i < tabla.size()-4; i++){
            for (int j=4; j < tabla.size()-4; j++){
                if (tabla[i][j]==feher){
                    if (tabla[i][j+1]==feher && tabla[i][j+2]==feher && tabla[i][j+3]==feher && tabla[i][j+4]==feher){
                        feher_pont++;
                    }
                    if (tabla[i+1][j+1]==feher && tabla[i+2][j+2]==feher && tabla[i+3][j+3]==feher && tabla[i+4][j+4]==feher){
                        feher_pont++;
                    }
                    if (tabla[i+1][j]==feher && tabla[i+2][j]==feher && tabla[i+3][j]==feher && tabla[i+4][j]==feher){
                        feher_pont++;
                    }
                    if (tabla[i+1][j-1]==feher && tabla[i+2][j-2]==feher && tabla[i+3][j-3]==feher && tabla[i+4][j-4]==feher){
                        feher_pont++;
                    }
                    cout << feher_pont << endl;
                }
                if (tabla[i][j]==sarga){
                    if (tabla[i][j+1]==sarga && tabla[i][j+2]==sarga && tabla[i][j+3]==sarga && tabla[i][j+4]==sarga){
                        sarga_pont++;
                    }
                    if (tabla[i+1][j+1]==sarga && tabla[i+2][j+2]==sarga && tabla[i+3][j+3]==sarga && tabla[i+4][j+4]==sarga){
                        sarga_pont++;
                    }
                    if (tabla[i+1][j]==sarga && tabla[i+2][j]==sarga && tabla[i+3][j]==sarga && tabla[i+4][j]==sarga){
                        sarga_pont++;
                    }
                    if (tabla[i+1][j-1]==sarga && tabla[i+2][j-2]==sarga && tabla[i+3][j-3]==sarga && tabla[i+4][j-4]==sarga){
                        sarga_pont++;
                    }
                    cout << sarga_pont << endl;
                }
            }
        }
        feherpont->poont=feher_pont;
        sargapont->poont=sarga_pont;
        feherpont->atalakit(feher_pont);
        sargapont->atalakit(sarga_pont);
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
        feherpont =new Pont(5,10,100,30);
        widgets.push_back(feherpont);
        sargapont =new Pont(295,10,100,30);
        widgets.push_back(sargapont);
    }

};



int main()
{
    Amoba jatek;
    jatek.fut(400,400);
    return 0;
}