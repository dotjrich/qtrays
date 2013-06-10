#include "viewplane.hpp"

ViewPlane::ViewPlane(int _h, int _w, float _s, float _gamma)
    : h(_h), w(_w), s(_s), gamma(_gamma), inv_gamma(1,0f / _gamma)
{
}
