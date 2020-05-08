#ifndef PONT_HPP_INCLUDED
#define PONT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Pont : public Widget {
protected:
public:
    string pontok;
    Pont (int x, int y, int sx, int sy, string pontt);
    virtual void draw();
    virtual void draw_mas();
    virtual void handle(genv::event ev);
};


#endif