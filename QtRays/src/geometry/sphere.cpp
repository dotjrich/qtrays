#include "sphere.hpp"

#include <cmath>

#include "geometricobject.hpp"
#include "../util/ray.hpp"
#include "../util/shaderecord.hpp"
#include "../util/vector3d.hpp"

Sphere::Sphere()
    : GeometricObject(), center(0.0), radius(1.0)
{
}

// -----------------------------------------------------------------------

Sphere::Sphere(const Point3D& _center, double _radius)
    : GeometricObject(), center(_center), radius(_radius)
{
}

// -----------------------------------------------------------------------

Sphere::~Sphere()
{
}

// -----------------------------------------------------------------------

// intersection of ray and sphere:
// (d dot d)t^2 + [2(o - c) dot d]t + (o - c) dot (o - c) - r^2 = 0
// t = solve above using quadratic equation, using smaller discriminant first

bool
Sphere::hit(const Ray& ray, double& tmin, ShadeRecord& sr) const
{
    Vector3D tmp = ray.o - center;
    double a = ray.d * ray.d;
    double b = 2.0 * tmp * ray.d;
    double c = (tmp * tmp) - (radius * radius);
    double disc = (b * b) - (4.0 * a * c);

    if (disc < 0.0) {
        return false;
    } else {
        double e = ::sqrt(disc);
        double denom = 2.0 * a;

        // Test smaller root first.
        double t = (-b - e) / denom;
        if (t > epsilon) {
            tmin = t;
            sr.n = (tmp + (t * ray.d));
            sr.local_hit_point = ray.o + (t * ray.d);
            return true;
        }

        // No luck? Let's try the larger root.
        t = (-b + e) / denom;
        if (t > epsilon) {
            tmin = t;
            sr.n = (tmp + (t * ray.d));
            sr.local_hit_point = ray.o + (t * ray.d);
            return true;
        }
    }

    return false;
}
