#include "scene.hpp"

#include <algorithm>

#include "../util/rgbcolor.hpp"

Scene::Scene()
{
}

// -----------------------------------------------------------------------

// Tone map, gamma correct, and integer map.
// QColor has the ability to integer map and stuff, but doesn't really handle
// colors out of gamut.

void
Scene::map_and_correct(const RGBColor &c, int dest[])
{
    RGBColor mapped_color(c);

    // Really simple tone map for now.
    float max = std::max(c.r, std::max(c.g, c.r));
    if (max > 1.0f) {
        mapped_color = mapped_color / max;
    }

    // Gamma correction... stick with gamma = 1.0 for now.
    if (vp.gamma != 1.0) {
        mapped_color = mapped_color ^ vp.inv_gamma;
    }

    // Integer map.
    dest[0] = static_cast<int>(mapped_color.r * 255);
    dest[1] = static_cast<int>(mapped_color.g * 255);
    dest[2] = static_cast<int>(mapped_color.b * 255);
}
