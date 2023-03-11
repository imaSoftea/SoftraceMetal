#pragma once

#include <glm/glm.hpp>

/**
* C++ Initialize Helper
* By: Carter Thompson
*
* Helper method file to return a vector of shapes
*/

class Ray
{
	public:
    
    glm::vec3 origin;
    glm::vec3 dir;

	Ray(glm::vec3 o, glm::vec3 d)
	{
		origin = o;
		dir = d;
	}
    
    Ray()
    {
        origin = {0.0f, 0.0f, 0.0f};
        dir = {0.0f, 0.0f, 0.0f};
    }
    
    //Random float from -1 to 1
    static float rFV()
    {
        return ((float)rand())/RAND_MAX * 2.0 - 1.0;
    }
    
};
