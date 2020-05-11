#ifndef PONT_HPP_INCLUDED
#define PONT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Pont : public Widget {
protected:
public:
    int poont;
    Pont (int x, int y, int sx, int sy);
    virtual void draw();
    virtual string atalakit(int pontok);
    virtual int pon_vissza();
    virtual void handle(genv::event ev);
};


#endif