#include "scene.hpp"

#include <vector>

#include "../geometry/geometricobject.hpp"

Scene::Scene()
{
}

// -----------------------------------------------------------------------

Scene::~Scene()
{
    std::vector<GeometricObject*>::iterator i;
    for (i = objects.begin(); i != objects.end(); ++i) {
        delete *i;
    }
}

// -----------------------------------------------------------------------

void
Scene::add_object(GeometricObject* o)
{
    objects.push_back(o);
}
