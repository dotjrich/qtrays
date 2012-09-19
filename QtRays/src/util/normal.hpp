#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "vector3d.hpp"

class Normal
{
public:
    double x;
    double y;
    double z;

    Normal();
    Normal(double a);
    Normal(double _x, double _y, double _z);
    Normal(const Normal& n);
    Normal(const Vector3D& v);

    ~Normal();

    Normal& operator= (const Normal& rhs);
    Normal& operator+= (const Normal& rhs);

    Normal operator+ (const Normal& rhs) const;                         // normal + normal
    Vector3D operator+ (const Vector3D& rhs) const;                     // normal + vector
    friend Vector3D operator+ (const Vector3D& lhs, const Normal& rhs); // vector + normal
    Normal operator- () const;                                          // negate
    double operator* (const Vector3D& rhs) const;                       // normal dot vector
    friend double operator* (const Vector3D& lhs, const Normal& rhs);   // vector dot normal
    Normal operator* (double rhs) const;                                // normal * scalar
    friend Normal operator* (double lhs, const Normal& rhs);            // scalar * normal
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline Normal&
Normal::operator= (const Normal& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

// -----------------------------------------------------------------------

inline Normal&
Normal::operator+= (const Normal& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

// -----------------------------------------------------------------------

inline Normal
Normal::operator+ (const Normal& rhs) const
{
    return Normal(x + rhs.x, y + rhs.y, z + rhs.z);
}

// -----------------------------------------------------------------------

inline Vector3D
Normal::operator+ (const Vector3D& rhs) const
{
    return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

// -----------------------------------------------------------------------

inline Vector3D
operator+ (const Vector3D& lhs, const Normal& rhs)
{
    return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

// -----------------------------------------------------------------------

inline Normal
Normal::operator- () const
{
    return Normal(-x, -y, -z);
}

// -----------------------------------------------------------------------

inline double
Normal::operator* (const Vector3D& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

// -----------------------------------------------------------------------

inline double
operator* (const Vector3D& lhs, const Normal& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

// -----------------------------------------------------------------------

inline Normal
Normal::operator* (double rhs) const
{
    return Normal(x * rhs, y * rhs, z * rhs);
}

// -----------------------------------------------------------------------

inline Normal
operator* (double lhs, const Normal& rhs)
{
    return Normal(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

#endif // NORMAL_HPP
