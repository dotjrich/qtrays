#ifndef GEOMETRICOBJECT_HPP
#define GEOMETRICOBJECT_HPP

#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/shaderecord.hpp"

class GeometricObject
{
public:
    GeometricObject();

    virtual bool hit(const Ray& ray, double& tmin, ShadeRecord& sr) = 0;

protected:
    RGBColor color;
};

#endif // GEOMETRICOBJECT_HPP
