#pragma once

#include <glm/glm.hpp>

/**
* C++ Light Class
* By: Carter Thompson
*
* Used to contribute light to a scene...
* NOTE!!! CURRENTLY USED AS POINT LIGHT (SHOULD BE CHANGED TO BE ABSTRACT LATER)
*/
class Light
{
    
public:
    float strength;
    glm::vec3 color;
};
