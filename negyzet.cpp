#include "negyzet.hpp"
#include "graphics.hpp"
using namespace genv;

Negyzet::Negyzet(int x, int y, int kx, int ky, std::function<void(int, int)> katt)
    : Widget(x,y,20,20), koord_x(kx), koord_y(ky), kattintasra(katt)
{
    _checked=false;
}

void Negyzet::draw()
{
    gout << move_to(_x, _y) << color(180,180,180) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (status != ures)
    {
        if (status == feher) {
            gout << color(255,255,255);
        }
        else if (status == sarga)
        {
            gout << color(255, 255, 0);
        }

        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }


}

void Negyzet::handle(event ev)
{
    if (ev.button == btn_left)
    {
        kattintasra(koord_x, koord_y);
    }
}
bool Negyzet::is_checked() 
{
    return _checked;
}

