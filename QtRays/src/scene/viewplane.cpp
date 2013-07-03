#include "viewplane.hpp"

ViewPlane::ViewPlane()
    : hres(0), vres(0), s(0), gamma(1.0f), inv_gamma(1.0f)
{
}

// -----------------------------------------------------------------------

ViewPlane::ViewPlane(int _hres, int _vres, float _s, float _gamma)
    : hres(_hres), vres(_vres), s(_s), gamma(_gamma), inv_gamma(1.0f / _gamma)
{
}
