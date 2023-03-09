#pragma once

#include "Ray.h"

/**
* C++ Camera Class
* By: Carter Thompson
*
* Used as a perspective of the scene
*/

class Camera
{
private:

	glm::vec3 origin;
	glm::vec3 dir; // KEEP NORMALIZED
	float fov;
	int width;
	int height;

public:

	Camera(glm::vec3 o, glm::vec3 d, float f, int w, int h)
	{
		origin = o;
		dir = d;
		fov = f;
		width = h;
		height = h;
	}

	Ray shootRay(int currentWidth, int currentHeight)
	{
		Ray ray = { origin, dir * fov};

		// L to R
		float horzDisplacement = 0.01f * (currentWidth - ((float) width / 2)) - 1;
		// T to B
		float verDisplacement = 0.01f * (((float) height) / 2 - currentHeight);

		ray.dir += glm::vec3(horzDisplacement, verDisplacement, 0);
		return ray;
	}
};

