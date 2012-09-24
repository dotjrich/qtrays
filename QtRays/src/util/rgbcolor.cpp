#include "rgbcolor.hpp"

RGBColor::RGBColor()
    : r(0.0f), g(0.0f), b(0.0f)
{
}

// -----------------------------------------------------------------------

RGBColor::RGBColor(float c)
    : r(c), g(c), b(c)
{
}

// -----------------------------------------------------------------------

RGBColor::RGBColor(float _r, float _g, float _b)
    : r(_r), g(_g), b(_b)
{
}

// -----------------------------------------------------------------------

RGBColor::RGBColor(const RGBColor& c)
    : r(c.r), g(c.g), b(c.b)
{
}

// -----------------------------------------------------------------------

RGBColor::~RGBColor()
{
}