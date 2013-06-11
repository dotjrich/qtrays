#ifndef GEOMETRICOBJECT_HPP
#define GEOMETRICOBJECT_HPP

#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/shaderecord.hpp"

class GeometricObject
{
public:
    GeometricObject();

    virtual bool hit(const Ray& ray, double& tmin, ShadeRecord& sr) const = 0;

    RGBColor get_color();
    void set_color(const RGBColor& _color);

protected:
    RGBColor color;
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline RGBColor
GeometricObject::get_color()
{
    return color;
}

// -----------------------------------------------------------------------

inline void
GeometricObject::set_color(const RGBColor& _color)
{
    color = _color;
}

#endif // GEOMETRICOBJECT_HPP
