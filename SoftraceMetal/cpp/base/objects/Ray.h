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
};
