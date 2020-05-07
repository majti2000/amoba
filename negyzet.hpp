#ifndef NEGYZET_HPP_INCLUDED
#define NEGYZET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

enum statusok
{
    ures, feher, sarga
};

class Negyzet : public Widget {
protected:
    bool _checked;
    int koord_x, koord_y;
    statusok status = ures;
    std::function<void(int, int)> kattintasra;

public:
    Negyzet(int x, int y, int kx, int ky, std::function<void(int, int)> katt);
    void set_status(statusok s) { status = s; }
    statusok get_status() { return status; }
    virtual void draw();
    virtual void draw_mas();
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;

};


#endif 
