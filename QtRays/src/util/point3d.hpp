#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <cmath>

#include "vector3d.hpp"

class Point3D
{
public:
    double x;
    double y;
    double z;

    Point3D();
    Point3D(double a);
    Point3D(double _x, double _y, double _z);
    Point3D(const Point3D& p);

    Point3D& operator= (const Point3D& rhs);

    Point3D operator+ (const Vector3D& rhs) const;                      // point + vec
    Point3D operator- (const Vector3D& rhs) const;                      // point - vec
    Vector3D operator- (const Point3D& rhs) const;                      // point - point
    Point3D operator* (const double rhs) const;                         // point * scalar
    friend Point3D operator* (const double lhs, const Point3D& rhs);    // scalar * point

    double distance(const Point3D& p) const;
    double distance_squared(const Point3D& p) const;
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline Point3D&
Point3D::operator= (const Point3D& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

// -----------------------------------------------------------------------

inline Point3D
Point3D::operator+ (const Vector3D& rhs) const
{
    return Point3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

// -----------------------------------------------------------------------

inline Point3D
Point3D::operator- (const Vector3D& rhs) const
{
    return Point3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

// -----------------------------------------------------------------------

inline Vector3D
Point3D::operator- (const Point3D& rhs) const
{
    return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

// -----------------------------------------------------------------------

inline Point3D
Point3D::operator* (const double rhs) const
{
    return Point3D(x * rhs, y * rhs, z * rhs);
}

// -----------------------------------------------------------------------

inline Point3D
operator* (const double lhs, const Point3D& rhs)
{
    return Point3D(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

// -----------------------------------------------------------------------

inline double
Point3D::distance(const Point3D &p) const
{
    return sqrt((x - p.x) * (x - p.x) +
                (y - p.y) * (y - p.y) +
                (z - p.z) * (z - p.z));
}

// -----------------------------------------------------------------------

inline double
Point3D::distance_squared(const Point3D &p) const
{
    return ((x - p.x) * (x - p.x) +
            (y - p.y) * (y - p.y) +
            (z - p.z) * (z - p.z));
}

#endif // POINT3D_HPP
