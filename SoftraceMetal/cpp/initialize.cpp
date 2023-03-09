#include "initialize.h"
#include "Box.h"

/**
* C++ Initialize Helper Source
* By: Carter Thompson
*
* Helper method file to return a vector of shapes
*/

std::vector<Shape*> buildScene()
{
	std::vector<Shape*> list;

	Shape* cube = new Box({-1.0f, -1.0f, 2.0f}, {1.0f, 1.0f, 3.0f});
	list.push_back(cube);
    
    Shape* cube2 = new Box({-3.0f, -3.0f, 0.0f}, {3.0f, -2.8f, 5.0f});
    list.push_back(cube2);
    
	return list;
}

void destroyScene(std::vector<Shape*> list)
{
    for(Shape* l : list)
    {
        free(l);
    }
}
