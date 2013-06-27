#include "renderer.hpp"

#include <algorithm>

#include <QColor>
#include <QImage>
#include <QObject>

#include "../geometry/plane.hpp"
#include "../geometry/sphere.hpp"
#include "../raytracer/raytracer.hpp"
#include "../raytracer/multiobjecttracer.hpp"
#include "../scene/scene.hpp"
#include "../util/normal.hpp"
#include "../util/point3d.hpp"
#include "../util/ray.hpp"
#include "../util/rgbcolor.hpp"
#include "../util/vector3d.hpp"

Renderer::Renderer(QImage** _img, QObject* parent)
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
    qDebug("Building scene...");
    build_scene();

    emit render_started();
    qDebug("Rendering...");
    render_scene();

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
    scene->vp.h = 400;
    scene->vp.w = 400;
    scene->vp.s = 1.0f;
    scene->vp.set_gamma(1.0f);

    //tracer = new SingleSphereTracer(scene); //first render
    tracer = new MultiObjectTracer(scene);

    //Sphere* sphere = new Sphere(0.0, 85.0); //first render
    //scene->add_object(sphere); //first render

    Sphere* sphere = new Sphere(Point3D(0.0, -25.0, 0.0), 80.0);
    sphere->set_color(RED);
    scene->add_object(sphere);

    sphere = new Sphere(Point3D(0.0, 30.0, 0.0), 60.0);
    sphere->set_color(RGBColor(1.0, 1.0, 0.0));
    scene->add_object(sphere);

    Plane* plane = new Plane(0.0, Normal(0.0, 1.0, 1.0));
    plane->set_color(RGBColor(0.0, 0.3, 0.0));
    scene->add_object(plane);
}

// -----------------------------------------------------------------------

void
Renderer::render_scene()
{
    // Create QImage.
    *img = new QImage(scene->vp.w, scene->vp.h, QImage::Format_ARGB32);

    // Ray origin components... fixed Z for now.
    double x;
    double y;
    double z = 100.0;
    Ray ray(0.0, Vector3D(0.0, 0.0, -1.0));

    int final_pixel_color[3];

    for (int r = 0; r < scene->vp.h; ++r) {
        for (int c = 0; c < scene->vp.w; ++c) {
            // Calculate x and y, based on height, width, and pixel size.
            x = scene->vp.s * (c - 0.5 * (scene->vp.w - 1.0));
            y = scene->vp.s * (r - 0.5 * (scene->vp.h - 1.0));

            ray.o = Point3D(x, y, z);
            RGBColor pixel_color = tracer->trace_ray(ray);

            // Prepare color for display and set it in the image.
            // TODO: setPixel is expensive... we need to move to direct access via scanLine.
            map_and_correct(pixel_color, final_pixel_color);
            int adj_row = scene->vp.h - 1 - r; // QImage's origin is top left. Our origin is bottom left.
            (*img)->setPixel(c, adj_row, qRgba(final_pixel_color[0], final_pixel_color[1], final_pixel_color[2], 255));
        }
    }
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
