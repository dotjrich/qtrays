#ifndef SHADERECORD_HPP
#define SHADERECORD_HPP

#include "normal.hpp"
#include "point3d.hpp"
#include "rgbcolor.hpp"
#include "../scene/scene.hpp"

class ShadeRecord
{
public:
    ShadeRecord(Scene& _w);
    ShadeRecord(const ShadeRecord& sr);

    bool hit_object;
    Point3D local_hit_point;
    Normal n;
    RGBColor color;
    Scene& w;
};

#endif // SHADERECORD_HPP
