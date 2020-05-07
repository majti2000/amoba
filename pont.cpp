#include "pont.hpp"
#include "graphics.hpp"
#include <sstream>
using namespace genv;
using namespace std;

Pont::Pont(int x, int y, int sx, int sy, string pontt)
    : Widget(x,y,sx,sy), pontok(pontt)
{
   // pont=0;
}

void Pont::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+5, _y+_size_y/2) << color(255,255,255) << text(pontok);
}

void Pont::draw_mas()
{

}

void Pont::handle(event ev)
{

}

/*string Pont::pont_ad()
{
    pont++;
    stringstream ss;
    ss<<pont;
    ss>>pontok;
    return pontok;
}*/
