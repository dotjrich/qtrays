#include "renderer.hpp"

#include "../raytracer/raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/rgbcolor.hpp"

Renderer::Renderer(RayTracer* _tracer, Scene* _scene)
    : tracer(_tracer), scene(_scene)
{
}

// -----------------------------------------------------------------------

Renderer::~Renderer()
{
}

// -----------------------------------------------------------------------

// Tone map, gamma correct, and integer map.
// QColor has the ability to integer map and stuff, but doesn't really handle
// colors out of gamut.

void
Renderer::map_and_correct(const RGBColor& c, int dest[])
{
    RGBColor mapped_color(c);

    // Really simple tone map for now.
    float max = std::max(c.r, std::max(c.g, c.b));
    if (max > 1.0f) {
        mapped_color = mapped_color / max;
    }

    // Gamma correction.
    if (scene->vp.gamma != 1.0) {
        mapped_color = mapped_color ^ scene->vp.inv_gamma;
    }

    // Integer map.
    dest[0] = static_cast<int>(mapped_color.r * 255);
    dest[1] = static_cast<int>(mapped_color.g * 255);
    dest[2] = static_cast<int>(mapped_color.b * 255);
}
