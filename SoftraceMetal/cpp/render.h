#pragma once

#include "Shape.h"
#include "initialize.h"
#include <vector>

/**
* C++ Rendering Loop
* By: Carter Thompson
*
* Helper method file to render out the scene
* 
* Contains Main Render Loop
*/

// Scene Struct
struct UserSceneData
{
	int rWidth;
	int rHeight;
};

// Render Loop
void renderScene(Scene scene, UserSceneData details);
