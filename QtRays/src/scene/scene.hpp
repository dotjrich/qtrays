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

    ViewPlane vp;
    RGBColor bgcolor;
    std::vector<GeometricObject*> objects;

    void map_and_correct(const RGBColor& c, int dest[]);
};

#endif // SCENE_HPP
