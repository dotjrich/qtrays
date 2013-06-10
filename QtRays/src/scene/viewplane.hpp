#ifndef VIEWPLANE_HPP
#define VIEWPLANE_HPP

class ViewPlane
{
public:
    ViewPlane(int _h, int _w, float _s, float _gamma);

    int h;              // height
    int w;              // width
    float s;            // pixel size
    float gamma;        // gamma factor
    float inv_gamma;    // inverse gamma
};

#endif // VIEWPLANE_HPP
