#ifndef NEGYZET_HPP_INCLUDED
#define NEGYZET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Negyzet : public Widget {
protected:
    bool _checked;

public:
    Negyzet(int x, int y, int sx, int sy);
    virtual void draw();
    virtual void draw_mas();
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;

};


#endif 
