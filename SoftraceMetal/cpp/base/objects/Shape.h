#pragma once

/**
* Abstract C++ Shape Class
* By: Carter Thompson
* 
* Acts as a upper level class for all different types of shapes for the program to go through.
*/

#include <iostream>
#include "Collision.h"
#include "Ray.h"

class Shape
{

protected:

	//The name of the shape
	std::string name;
	glm::vec3 boundCorners[2];

public:

	Shape(std::string n, glm::vec3 b1, glm::vec3 b2)
	{
		boundCorners[0] = b1;
		boundCorners[1] = b2;

		name = n;
	}

	// Checks for collision with Ray r
	virtual Collision collisionCheck(Ray r) = 0;

	// Checks if Ray r is in bounding box
	virtual bool boundingBox(Ray r) = 0;

};