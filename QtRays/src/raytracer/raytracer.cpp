#include "raytracer.hpp"

#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"

RayTracer::RayTracer(Scene* _scene)
    : scene(_scene)
{
}

// -----------------------------------------------------------------------

RGBColor
RayTracer::trace_ray(const Ray& ray) const
{
    return BLACK;
}
