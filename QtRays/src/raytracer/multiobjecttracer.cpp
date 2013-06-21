#include "multiobjecttracer.hpp"

#include <vector>

#include "raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/shaderecord.hpp"

MultiObjectTracer::MultiObjectTracer(Scene* _scene)
    : RayTracer(_scene)
{
}

// -----------------------------------------------------------------------

RGBColor
MultiObjectTracer::trace_ray(const Ray& ray) const
{
    ShadeRecord sr(hit_all_objects(ray));

    if (sr.hit_object) {
        return sr.color;
    } else {
        return scene->bgcolor;
    }
}

// -----------------------------------------------------------------------

ShadeRecord
MultiObjectTracer::hit_all_objects(const Ray& ray) const
{
    ShadeRecord sr;
    double t;
    double tmin = 1000000.00;

    std::vector<GeometricObject*>::iterator i;
    for (i = scene->objects.begin(); i != scene->objects.end(); ++i) {
        if ((*i)->hit(ray, t, sr) && t < tmin) {
            sr.hit_object = true;
            tmin = t;
            sr.color = (*i)->get_color();
        }
    }

    return sr;
}
