#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "viewplane.hpp"
#include "../geometry/geometricobject.hpp"
#include "../util/rgbcolor.hpp"

class Scene
{
public:
    Scene();

    ~Scene();

    ViewPlane vp;
    RGBColor bgcolor;
    std::vector<GeometricObject*> objects;

    void add_object(GeometricObject* o);
};

#endif // SCENE_HPP
