#ifndef SCENE_HPP
#define SCENE_HPP

#include "viewplane.hpp"
#include "../util/rgbcolor.hpp"

class Scene
{
public:
    Scene();

    ViewPlane vp;
    RGBColor bgcolor;
};

#endif // SCENE_HPP
