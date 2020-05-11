#include "pont.hpp"
#include "graphics.hpp"
#include <sstream>
using namespace genv;
using namespace std;

Pont::Pont(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    poont=0;
}

string Pont::atalakit(int po)
{
    string s;
    stringstream ss;
    ss<<po;
    ss>>s;
    return s;
}

void Pont::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+5, _y+_size_y/2) << color(255,255,255) << text(atalakit(poont));

}

void Pont::handle(event ev)
{
}

int Pont::pon_vissza(){
    return poont;
}
