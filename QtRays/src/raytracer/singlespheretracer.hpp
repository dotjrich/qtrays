#ifndef SINGLESPHERETRACER_HPP
#define SINGLESPHERETRACER_HPP

#include "raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"

class SingleSphereTracer : public RayTracer
{
public:
    SingleSphereTracer(Scene* _scene);

    RGBColor trace_ray(const Ray& ray) const;
};

#endif // SINGLESPHERETRACER_HPP
