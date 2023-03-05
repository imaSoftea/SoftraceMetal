#include "initialize.h"
#include "base/objects/types/Box.h"

/**
* C++ Initialize Helper Source
* By: Carter Thompson
*
* Helper method file to return a vector of shapes
*/

std::vector<Shape*> buildScene()
{
	std::vector<Shape*> list;

	Shape* cube = new Box({-1.0f, -1.0f, 2.0f}, {1.0f, 1.0f, 3.0f});\
	list.push_back(cube);

	return list;
}