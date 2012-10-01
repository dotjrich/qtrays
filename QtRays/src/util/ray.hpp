#ifndef RAY_HPP
#define RAY_HPP

#include "point3d.hpp"
#include "vector3d.hpp"

class Ray
{
public:
    Point3D o;  // origin
    Vector3D d; // direction

    Ray();
    Ray(const Point3D& _o, const Vector3D& _d);
    Ray(const Ray& ray);

    ~Ray();

    Ray& operator= (const Ray& rhs);
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline Ray&
Ray::operator= (const Ray& rhs)
{
    o = rhs.o;
    d = rhs.d;

    return *this;
}

#endif // RAY_HPP
