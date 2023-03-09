#pragma once

#include <glm/glm.hpp>
#include "Ray.h"

class Material
{
private:
    
    glm::vec3 color; //Maybe replaced with textures later
    float metallic;
    float roughness;
    
public:

    //Constructors
    Material()
    {
        color = {1.0f, 1.0f, 1.0f};
        metallic = 1.0f;
        roughness = 1.0f;
    }
    
    Material(glm::vec3 c, float m, float r)
    {
        color = c;
        metallic = m;
        roughness = r;
    }
    
    //Functions
    Ray GenerateRayDir();
    
};

