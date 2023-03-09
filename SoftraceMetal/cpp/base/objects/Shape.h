#pragma once

/**
* Abstract C++ Shape Class
* By: Carter Thompson
* 
* Acts as a upper level class for all different types of shapes for the program to go through.
*/

#include <iostream>
#include "Ray.h"
#include "Material.h"

class Shape
{

protected:

	//The name of the shape
	std::string name;
	glm::vec3 boundCorners[2];
    Material mat;

public:

	Shape(std::string n, glm::vec3 b1, glm::vec3 b2, Material m)
	{
		boundCorners[0] = b1;
		boundCorners[1] = b2;
        
        mat = m;
		name = n;
	}

	// Checks for collision with Ray r
	virtual Ray collisionCheck(Ray r) = 0;

	// Checks if Ray r is in bounding box
	bool boundingBox(Ray r)
    {
        glm::vec3 invdir = 1.0f / r.dir;

        float tx0 = 0;
        float tx1 = 0;

        if (invdir.x >= 0)
        {
            tx0 = (boundCorners[0].x - r.origin[0]) * invdir.x;
            tx1 = (boundCorners[1].x - r.origin[0]) * invdir.x;
        }
        else
        {
            tx0 = (boundCorners[1].x - r.origin[0]) * invdir.x;
            tx1 = (boundCorners[0].x - r.origin[0]) * invdir.x;
        }

        float ty0 = (boundCorners[0].y - r.origin[1]) * invdir.y;
        float ty1 = (boundCorners[1].y - r.origin[1]) * invdir.y;

        if (ty0 > ty1) std::swap(ty0, ty1);

        if (tx0 > ty1 || ty0 > tx1) return false;

        float tmin = (tx0 > ty0) ? tx0 : ty0;
        float tmax = (tx1 < ty1) ? tx1 : ty1;

        float tz0 = (boundCorners[0].z - r.origin[2]) * invdir.z;
        float tz1 = (boundCorners[1].z - r.origin[2]) * invdir.z;

        if (tz0 > tz1) std::swap(tz0 , tz1);
        
        if (tmin > tz1 || tz0 > tmax) return false;

        return true;
    }
    
    //Random float from -1 to 1
    float randomFloat()
    {
        return ((float)rand())/RAND_MAX * 2.0 - 1.0;
    }
    
    Ray generateBounce(Ray income, Ray norm)
    {
        //Reflect Current Ray on Normal
        Ray bounce;
        bounce.origin = norm.origin;
        bounce.dir = glm::reflect(income.dir, norm.dir);
        
        //Get Random Facing Outside
        glm::vec3 rand = {randomFloat(), randomFloat(), randomFloat()};
        glm::faceforward(rand, -1.0f * income.dir, norm.dir);
        
        //Combines random and relflected based on roughness
        bounce.dir =
            (mat.getRoughness() * glm::normalize(rand))
            + ((1 - mat.getRoughness()) * glm::normalize(bounce.dir));
        
        return bounce;
    }

};
