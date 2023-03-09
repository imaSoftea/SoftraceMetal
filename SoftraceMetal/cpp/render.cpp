#include "render.h"
#include "Print.h"
#include "Camera.h"

void renderScene(std::vector <Shape*> shapeList, UserSceneData details)
{
	std::ofstream singlefile("o.ppm");
	
	printHeader(singlefile, details.rWidth, details.rHeight);
	Camera cam({0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 1.0f }, 1.0f, details.rWidth, details.rHeight);

	//Vertical Loop
	for (int y = 0; y < details.rHeight; y++)
	{
		//Horizontal Loop
		for (int x = 0; x < details.rWidth; x++)
		{
			for (Shape* s : shapeList)
			{
				if (s->boundingBox(cam.shootRay(x,y)) == true)
				{
					printColor(singlefile, { 0.0f, 0.0f, 255.0f });
				}
				else
				{
					printColor(singlefile, { 65.0f, 255.0f, 255.0f });
				}
			}
		}
	}
}
