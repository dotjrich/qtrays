#ifndef SHADERECORD_HPP
#define SHADERECORD_HPP

#include "normal.hpp"
#include "point3d.hpp"
#include "rgbcolor.hpp"

class ShadeRecord
{
public:
    ShadeRecord();
    ShadeRecord(const ShadeRecord& sr);

    bool hit_object;
    Point3D local_hit_point;
    Normal n;
    RGBColor color;
};

#endif // SHADERECORD_HPP
