#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
using namespace std;

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
//    virtual bool is_checked()=0;
//    virtual string pont_ad();
//    virtual bool is_checked2() = 0;
    virtual bool kival(int a, int b);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw_mas()=0;
};

#endif 