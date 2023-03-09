#pragma once

#include "Shape.h"
#include "Light.h"
#include <vector>

/**
* C++ Initialize Helper
* By: Carter Thompson
* 
* Helper method file to return a vector of shapes
*/

struct Scene
{
    std::vector<Shape*> shapes;
    std::vector<Light*> lights;
};

Scene buildScene();
void destroyScene(Scene);
