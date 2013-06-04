#include "plane.hpp"

Plane::Plane()
    : p(0.0), n(0.0)
{
}

// -----------------------------------------------------------------------

Plane::Plane(const Point3D& _p, const Normal& _n)
    : p(_p), n(_n)
{
}

// -----------------------------------------------------------------------

Plane::~Plane()
{
}

// -----------------------------------------------------------------------

bool
Plane::hit(const Ray& ray, double& tmin, ShadeRecord& sr) const
{
    double t = (p - ray.o) * n / (ray.d * n);

    if (t < epsilon) {
        tmin = t;
        sr.n = n;
        sr.local_hit_point = ray.o + (t * ray.d);

        return true;
    } else {
        return false;
    }
}
