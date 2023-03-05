#pragma once

#include "../Shape.h"

// CLASS USES BOUNDING BOX AS SHAPE (really only meant for testing)
class Box : public Shape
{
public:

	Box(glm::vec3 b1, glm::vec3 b2) : Shape{ "BOX", b1, b2 } {}

	Collision collisionCheck(Ray r) override
	{
		Collision TEMPORARY_TEST_DELETE_LATER;
		return TEMPORARY_TEST_DELETE_LATER;
	}

	bool boundingBox(Ray r) override
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
	
};