#include "singlespheretracer.hpp"

#include "raytracer.hpp"
#include "../geometry/geometricobject.hpp"
#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/shaderecord.hpp"

SingleSphereTracer::SingleSphereTracer(Scene* _scene)
    : RayTracer(_scene)
{
}

// -----------------------------------------------------------------------

RGBColor
SingleSphereTracer::trace_ray(const Ray& ray) const
{
    double t;
    ShadeRecord sr;

    GeometricObject* sphere = scene->objects[0];

    if (sphere->hit(ray, t, sr)) {
        return RED;
    } else {
        return BLACK;
    }
}
