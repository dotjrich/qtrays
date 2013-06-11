#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include "../scene/scene.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"

class RayTracer
{
public:
    RayTracer(Scene* _scene);

    virtual RGBColor trace_ray(const Ray& ray) const;

protected:
    Scene* scene;
};

#endif // RAYTRACER_HPP
