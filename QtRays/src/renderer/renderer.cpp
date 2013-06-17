#include "renderer.hpp"

#include <algorithm>

#include <QImage>
#include <QObject>

#include "../geometry/sphere.hpp"
#include "../raytracer/raytracer.hpp"
#include "../raytracer/singlespheretracer.hpp"
#include "../scene/scene.hpp"
#include "../util/rgbcolor.hpp"

Renderer::Renderer(QImage*& _img, QObject* parent)
    : QObject(parent), img(_img), tracer(0), scene(0)
{
}

// -----------------------------------------------------------------------

Renderer::~Renderer()
{
    if (tracer) {
        delete tracer;
    }

    if (scene) {
        delete scene;
    }
}

// -----------------------------------------------------------------------

void
Renderer::start_render()
{
    emit render_started();
    qDebug("Rendering...");
    emit render_finished();
    qDebug("Rendering Complete...");
}

// -----------------------------------------------------------------------

// TODO: Have this build a scene via a text file...
void
Renderer::build_scene()
{
    scene = new Scene();
    scene->bgcolor = BLACK;
    scene->vp.h = 200;
    scene->vp.w = 200;
    scene->vp.s = 1.0f;
    scene->vp.set_gamma(1.0f);

    tracer = new SingleSphereTracer(scene);

    Sphere* sphere = new Sphere(0.0f, 85.0);
    scene->add_object(sphere);
}

// -----------------------------------------------------------------------

void
Renderer::render_scene()
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
