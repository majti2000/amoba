#include "widgets.hpp"
#include "negyzet.hpp"
#include "pont.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace genv;

void fut (vector<Widget*>& widgets) {
    vector<Widget*> w_feher;
    vector<Widget*> w_sarga;
    int feher_pont=0;
    int sarga_pont=0;
    event ev;
    int focus = -1;
    bool iksz=false;
    int elozo=1000;
    while(gin >> ev) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->kival(ev.pos_x, ev.pos_y) && widgets[i]!=widgets[focus]){
                        focus = i;
                        iksz=!iksz;
                }
            }
        }
        if (iksz){
            if (focus!=-1) {
                widgets[focus]->handle(ev);
            }
            for (int j=0; j < widgets.size(); j++) {
                if (focus==j){
                widgets[j]->draw();
                w_feher.push_back(widgets[j]);
                }
        }
        }
        if (!iksz){
            if (focus!=-1) {
                widgets[focus]->handle(ev);
            }
            for (int k=0; k < widgets.size(); k++) {
                if (focus==k){
                    widgets[k]->draw_mas();
                    w_sarga.push_back(widgets[k]);
                }
            }  
        }
        for (int m=0; m < widgets.size(); m++){
                     if (find(w_feher.begin(), w_feher.end(), widgets[m])!=w_feher.end()){
                            if (find(w_feher.begin(), w_feher.end(), widgets[m+1])!=w_feher.end() 
                            && find(w_feher.begin(), w_feher.end(), widgets[m+2])!=w_feher.end()
                            && find(w_feher.begin(), w_feher.end(), widgets[m-1])!=w_feher.end()
                            && find(w_feher.begin(), w_feher.end(), widgets[m-2])!=w_feher.end()){
                                feher_pont++;
                                
                            }
                        
                        if (find(w_feher.begin(), w_feher.end(), widgets[m+15])!=w_feher.end() 
                           && find(w_feher.begin(), w_feher.end(), widgets[m+30])!=w_feher.end()
                           && find(w_feher.begin(), w_feher.end(), widgets[m-15])!=w_feher.end()
                           && find(w_feher.begin(), w_feher.end(), widgets[m-30])!=w_feher.end()){
                              feher_pont++;
                              
                        }
                    }
                
                for (int sar=0; sar < w_sarga.size(); sar++){
                    if (widgets[m]==w_sarga[sar]){
                        if (find(w_sarga.begin(), w_sarga.end(), widgets[m+1])!=w_sarga.end() 
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m+2])!=w_sarga.end()
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m-1])!=w_sarga.end()
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m-2])!=w_sarga.end()){
                               sarga_pont++;
                              for (int torl=0; torl < w_sarga.size(); torl++){
                                    if (w_sarga[torl]==widgets[m]){
                                        w_sarga[torl]=widgets[widgets.size()];
                                }
                              }
                            
                        }
                        if (find(w_sarga.begin(), w_sarga.end(), widgets[m+15])!=w_sarga.end() 
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m+30])!=w_sarga.end()
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m-15])!=w_sarga.end()
                           && find(w_sarga.begin(), w_sarga.end(), widgets[m-30])!=w_sarga.end()){
                            sarga_pont++;
                              
                        }
                    }
                }
        }
        
      gout << refresh;
    }
    
}

int main()
{
   genv:: gout.open(400,400);
    vector<Widget*> w;
    for (int i=0; i < 15; i++){
        for (int j=0; j < 15; j++){
        Negyzet * aij = new Negyzet (50+19*i, 50+19*j, 20, 20);
        w.push_back(aij);
        }
    }
    
    Pont * feherpont =new Pont(5,10,100,30, "0");
    w.push_back(feherpont);
    Pont * sargapont =new Pont(295,10,100,30, "0");
    w.push_back(sargapont);
    for (Widget * widg : w) {
        widg->draw();
    }
   genv:: gout << refresh;
    fut(w);
    return 0;
}