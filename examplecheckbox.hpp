#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    bool _checked;
//    bool _checked2;
public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw();
    virtual void draw_mas();
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
//    virtual bool is_checked2();
};


#endif 