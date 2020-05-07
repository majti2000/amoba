//#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
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
                                for (int torl=0; torl < w_feher.size(); torl++){
                                    if (w_feher[torl]==widgets[m]){
                                        w_feher[torl]=widgets[widgets.size()];
                                }
                                }
                            }
                        
                        if (find(w_feher.begin(), w_feher.end(), widgets[m+15])!=w_feher.end() 
                           && find(w_feher.begin(), w_feher.end(), widgets[m+30])!=w_feher.end()
                           && find(w_feher.begin(), w_feher.end(), widgets[m-15])!=w_feher.end()
                           && find(w_feher.begin(), w_feher.end(), widgets[m-30])!=w_feher.end()){
                              feher_pont++;
                              for (int torl=0; torl < w_feher.size(); torl++){
                                    if (w_feher[torl]==widgets[m+15]){
                                        w_feher[torl]=widgets[widgets.size()];
                                }
                              }
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
                              for (int torl=0; torl < w_sarga.size(); torl++){
                                    if (w_sarga[torl]==widgets[m+15]){
                                        w_sarga[torl]=widgets[widgets.size()];
                                }
                              }
                        }
                    }
                }
        }
        stringstream ss;
        ss<<feher_pont;
        string feh_pont;
        ss>>feh_pont;
        widgets[widgets.size()-2]=new Pont(5,10,100,30,feh_pont);
        widgets[widgets.size()-2]->draw();
        stringstream sss;
        sss<<sarga_pont;
        string sarg_pont;
        sss>>sarg_pont;
        widgets[widgets.size()-1]=new Pont(295,10,100,30,sarg_pont);
        widgets[widgets.size()-1]->draw();
      gout << refresh;
    }
    
}

int main()
{
   genv:: gout.open(400,400);
    vector<Widget*> w;
    for (int i=0; i < 15; i++){
        for (int j=0; j < 15; j++){
        ExampleCheckBox * aij = new ExampleCheckBox (50+20*i, 50+20*j, 20, 20);
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