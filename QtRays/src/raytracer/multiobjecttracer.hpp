#ifndef MULTIOBJECTTRACER_HPP
#define MULTIOBJECTTRACER_HPP

#include "raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/shaderecord.hpp"

class MultiObjectTracer : RayTracer
{
public:
    MultiObjectTracer(Scene* _scene);

    virtual RGBColor trace_ray(const Ray& ray) const;
    virtual ShadeRecord hit_all_objects(const Ray& ray) const;
};

#endif // MULTIOBJECTTRACER_HPP
