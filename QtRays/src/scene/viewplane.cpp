#include "viewplane.hpp"

ViewPlane::ViewPlane()
    : h(0), w(0), s(0), gamma(1.0f), inv_gamma(1.0f)
{
}

// -----------------------------------------------------------------------

ViewPlane::ViewPlane(int _h, int _w, float _s, float _gamma)
    : h(_h), w(_w), s(_s), gamma(_gamma), inv_gamma(1.0f / _gamma)
{
}

// -----------------------------------------------------------------------

void
ViewPlane::set_gamma(float _gamma)
{
    gamma = _gamma;
    inv_gamma = 1.0f / _gamma;
}
