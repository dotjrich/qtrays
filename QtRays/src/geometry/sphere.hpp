#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "geometricobject.hpp"
#include "../util/point3d.hpp"
#include "../util/ray.hpp"
#include "../util/shaderecord.hpp"

class Sphere : public GeometricObject
{
public:
    Sphere();
    Sphere(const Point3D& _center, double _radius);

    ~Sphere();

    virtual bool hit(const Ray& ray, double& tmin, ShadeRecord& sr) const;

protected:
    static const double epsilon = 0.00001;

    Point3D center;
    double radius;
};

#endif // SPHERE_HPP
