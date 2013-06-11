#include "rgbcolor.hpp"
#include "shaderecord.hpp"

ShadeRecord::ShadeRecord()
    : hit_object(false), local_hit_point(), n(), color(BLACK)
{
}

// -----------------------------------------------------------------------

ShadeRecord::ShadeRecord(const ShadeRecord& sr)
    : hit_object(sr.hit_object), local_hit_point(sr.local_hit_point), color(sr.color)
{
}
