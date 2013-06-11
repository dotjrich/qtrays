#ifndef SCENE_HPP
#define SCENE_HPP

#include "viewplane.hpp"
#include "../util/rgbcolor.hpp"

class Scene
{
public:
    Scene();

private:
    ViewPlane vp;
    RGBColor bgcolor;

    void map_and_correct(const RGBColor& c, int dest[]);
};

#endif // SCENE_HPP
