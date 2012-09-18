#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>

class Vector3D
{
public:
    Vector3D();
    Vector3D(double a);
    Vector3D(double _x, double _y, double _z);
    Vector3D(const Vector3D& v);

    ~Vector3D();

    Vector3D& operator= (const Vector3D& rhs);
    Vector3D& operator+= (const Vector3D& rhs);

    Vector3D operator+ (const Vector3D& rhs) const;                     // vec + vec
    Vector3D operator- (const Vector3D& rhs) const;                     // vec - vec
    Vector3D operator- () const;                                        // negate
    Vector3D operator/ (const double rhs) const;                        // vec / scalar
    Vector3D operator^ (const Vector3D& rhs) const;                     // cross product
    double operator* (const Vector3D& rhs) const;                       // dot product
    Vector3D operator* (const double rhs) const;                        // vec * scalar
    friend Vector3D operator* (const double lhs, const Vector3D& rhs);  // scalar * vec

    double length() const;                      // magnitude
    double length_squared() const;              // magnitude squared

    void normalize();
    Vector3D& hat(); // Normalize and return reference.

    double x;
    double y;
    double z;
};

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline Vector3D&
Vector3D::operator= (const Vector3D& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

// -----------------------------------------------------------------------

inline Vector3D&
Vector3D::operator+= (const Vector3D& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator+ (const Vector3D& rhs) const
{
    return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator- (const Vector3D& rhs) const
{
    return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator- () const
{
    return Vector3D(-x, -y, -z);
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator/ (const double rhs) const
{
    return Vector3D(x / rhs, y / rhs, z / rhs);
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator^ (const Vector3D& rhs) const
{
    return Vector3D(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

// -----------------------------------------------------------------------

inline double
Vector3D::operator* (const Vector3D& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

// -----------------------------------------------------------------------

inline Vector3D
Vector3D::operator* (const double rhs) const
{
    return Vector3D(x * rhs, y * rhs, z * rhs);
}

// -----------------------------------------------------------------------

inline Vector3D
operator* (const double lhs, const Vector3D& rhs)
{
    return Vector3D(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

// -----------------------------------------------------------------------

inline double
Vector3D::length() const
{
    return sqrt(x * x + y * y + z * z);
}

// -----------------------------------------------------------------------

inline double
Vector3D::length_squared() const
{
    return x * x + y * y + z * z;
}

// -----------------------------------------------------------------------

inline void
Vector3D::normalize()
{
    double length = sqrt(x * x + y * y + z * z);

    x /= length;
    y /= length;
    z /= length;
}

// -----------------------------------------------------------------------

inline Vector3D&
Vector3D::hat()
{
    double length = sqrt(x * x + y * y + z * z);

    x /= length;
    y /= length;
    z /= length;

    return *this;
}

#endif // VECTOR3D_HPP
