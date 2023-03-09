#pragma once

#include "Shape.h"

// CLASS USES BOUNDING BOX AS SHAPE (really only meant for testing)
class Box : public Shape
{
public:

	Box(glm::vec3 b1, glm::vec3 b2) : Shape{ "BOX", b1, b2 , Material()} {}

	Ray collisionCheck(Ray r) override
	{
        Ray TEMPORARY_TEST_DELETE_LATER;
        return TEMPORARY_TEST_DELETE_LATER;
	}
	
};
