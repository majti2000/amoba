#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy)
 : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::kival(int pontx, int ponty)
{
    return pontx>_x && pontx<_x+_size_x && ponty>_y && ponty<_y+_size_y;
}
