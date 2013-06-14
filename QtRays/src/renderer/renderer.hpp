#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../raytracer/raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/rgbcolor.hpp"

class Renderer
{
public:
    Renderer(RayTracer* _tracer, Scene* _scene);

    ~Renderer();

    void map_and_correct(const RGBColor& c, int dest[]);

protected:
    RayTracer* tracer;
    Scene* scene;
};

#endif // RENDERER_HPP
