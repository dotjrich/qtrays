#ifndef PLANE_HPP
#define PLANE_HPP

#include "geometricobject.hpp"
#include "../util/normal.hpp"
#include "../util/point3d.hpp"
#include "../util/ray.hpp"
#include "../util/shaderecord.hpp"

class Plane : public GeometricObject
{
public:
    Plane();
    Plane(const Point3D& _p, const Normal& _n);

    ~Plane();

    virtual bool hit(const Ray& ray, double& tmin, ShadeRecord& sr) const;

protected:
    static const double epsilon = 0.00001;

    Point3D p;
    Normal n;
};

#endif // PLANE_HPP
