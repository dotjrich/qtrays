#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <QImage>
#include <QObject>

#include "../raytracer/raytracer.hpp"
#include "../scene/scene.hpp"
#include "../util/rgbcolor.hpp"

class Renderer : public QObject
{
    Q_OBJECT

public:
    Renderer(QImage** _img, QObject* parent = 0);

    ~Renderer();

    void build_scene();
    void render_scene();

signals:
    void render_started();
    void render_finished();

public slots:
    void start_render();

protected:
    QImage** img;
    RayTracer* tracer;
    Scene* scene;

    void map_and_correct(const RGBColor& c, int dest[]);
};

#endif // RENDERER_HPP
