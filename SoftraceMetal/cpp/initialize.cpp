#include "initialize.h"
#include "Box.h"
#include "Light.h"

/**
* C++ Initialize Helper Source
* By: Carter Thompson
*
* Helper method file to return a vector of shapes
*/

Scene buildScene()
{
    Scene scene;
    
	std::vector<Shape*> list;

    //Shapes go here
	Shape* cube = new Box({-1.0f, -2.0f, 2.0f}, {1.0f, 0.0f, 3.0f});
    cube->mat.setColor({90.0f, 90.0f , 255.0f});
	list.push_back(cube);
    
    Shape* cube2 = new Box({-3.0f, -3.0f, 0.0f}, {3.0f, -2.8f, 5.0f});
    list.push_back(cube2);
    
    //Lights go here
    scene.shapes = list;
    
    return scene;
}

void destroyScene(Scene s)
{
    for(Shape* shape : s.shapes)
    {
        free(shape);
    }
    
    for(Light* light : s.lights)
    {
        free(light);
    }
}
