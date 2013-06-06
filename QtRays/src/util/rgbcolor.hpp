#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#include <cmath>

#include <QColor>

class RGBColor
{
public:
    float r;
    float g;
    float b;

    RGBColor();
    RGBColor(float c);
    RGBColor(float _r, float _g, float _b);
    RGBColor(const RGBColor& c);

    ~RGBColor();

    RGBColor& operator= (const RGBColor& rhs);
    RGBColor& operator+= (const RGBColor& rhs);

    RGBColor operator+ (const RGBColor& rhs) const;
    RGBColor operator* (const RGBColor& rhs) const;
    RGBColor operator* (const float rhs) const;
    friend RGBColor operator* (const float lhs, const RGBColor& rhs);
    RGBColor operator/ (const float rhs) const;
    RGBColor operator^ (const float rhs) const;

    QRgb qrgb() const;
};

// -----------------------------------------------------------------------
// Constant colors.
// -----------------------------------------------------------------------

const RGBColor BLACK(0.0f);
const RGBColor WHITE(1.0f);
const RGBColor RED(1.0f, 0.0f, 0.0f);
const RGBColor GREEN(0.0f, 1.0f, 0.0f);
const RGBColor BLUE(0.0f, 0.0f, 1.0f);

// -----------------------------------------------------------------------
// Inlined member/friend methods.
// -----------------------------------------------------------------------

inline RGBColor&
RGBColor::operator= (const RGBColor& rhs)
{
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;

    return *this;
}

// -----------------------------------------------------------------------

inline RGBColor&
RGBColor::operator+= (const RGBColor& rhs)
{
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;

    return *this;
}

// -----------------------------------------------------------------------

inline RGBColor
RGBColor::operator+ (const RGBColor& rhs) const
{
    return RGBColor(r + rhs.r, g + rhs.g, b + rhs.b);
}

// -----------------------------------------------------------------------

inline RGBColor
RGBColor::operator* (const RGBColor& rhs) const
{
    return RGBColor(r * rhs.r, g * rhs.g, b * rhs.b);
}

// -----------------------------------------------------------------------

inline RGBColor
RGBColor::operator* (const float rhs) const
{
    return RGBColor(r * rhs, g * rhs, b * rhs);
}

// -----------------------------------------------------------------------

inline RGBColor
operator* (const float lhs, const RGBColor& rhs)
{
    return RGBColor(rhs.r * lhs, rhs.g * lhs, rhs.b * lhs);
}

// -----------------------------------------------------------------------

inline RGBColor
RGBColor::operator/ (const float rhs) const
{
    return RGBColor(r / rhs, g / rhs, b / rhs);
}

// -----------------------------------------------------------------------

inline RGBColor
RGBColor::operator^ (const float rhs) const
{
    return RGBColor(pow(r, rhs), pow(g, rhs), pow(b, rhs));
}

// -----------------------------------------------------------------------

inline QRgb
RGBColor::qrgb() const
{
    return QColor::fromRgbF(r, g, b, 1.0f).rgba();
}

#endif // RGBCOLOR_HPP
