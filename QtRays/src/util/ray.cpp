#include "ray.hpp"

Ray::Ray()
    : o(0.0), d(0.0)
{
}

// -----------------------------------------------------------------------

Ray::Ray(const Point3D &_o, const Vector3D &_d)
    : o(_o), d(_d)
{
}

// -----------------------------------------------------------------------

Ray::Ray(const Ray& ray)
    : o(ray.o), d(ray.d)
{
}

// -----------------------------------------------------------------------

Ray::~Ray()
{
}
