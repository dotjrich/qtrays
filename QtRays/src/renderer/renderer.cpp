#include "renderer.hpp"

#include "../raytracer/raytracer.hpp"
#include "../scene/scene.hpp"

Renderer::Renderer(RayTracer* _tracer, Scene* _scene)
    : tracer(_tracer), scene(_scene)
{
}

// -----------------------------------------------------------------------

Renderer::~Renderer()
{
}
