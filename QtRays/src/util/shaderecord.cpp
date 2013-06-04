#include "rgbcolor.hpp"
#include "shaderecord.hpp"
#include "../scene/scene.hpp"

ShadeRecord::ShadeRecord(Scene& _w)
    : hit_object(false), local_hit_point(), n(), color(BLACK), w(_w)
{
}

// -----------------------------------------------------------------------

ShadeRecord::ShadeRecord(const ShadeRecord& sr)
    : hit_object(sr.hit_object), local_hit_point(sr.local_hit_point), color(sr.color), w(sr.w)
{
}
