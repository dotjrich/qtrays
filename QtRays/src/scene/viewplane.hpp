#ifndef VIEWPLANE_HPP
#define VIEWPLANE_HPP

class ViewPlane
{
public:
    ViewPlane();
    ViewPlane(int _hres, int _vres, float _s, float _gamma);

    void set_gamma(float _gamma);

    int hres;           // horiz resolution
    int vres;           // vert resolution
    float s;            // pixel size
    float gamma;        // gamma factor
    float inv_gamma;    // inverse gamma
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline void
ViewPlane::set_gamma(float _gamma)
{
    gamma = _gamma;
    inv_gamma = 1.0f / _gamma;
}

#endif // VIEWPLANE_HPP
