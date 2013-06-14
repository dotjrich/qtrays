#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../raytracer/raytracer.hpp"
#include "../scene/scene.hpp"

class Renderer
{
public:
    Renderer(RayTracer* _tracer, Scene* _scene);

    ~Renderer();

protected:
    RayTracer* tracer;
    Scene* scene;
};

#endif // RENDERER_HPP
