#include "render.h"
#include "Print.h"
#include "Camera.h"
#include "initialize.h"

void renderScene(Scene scene, UserSceneData details)
{
    std::ofstream singlefile("test.ppm");
	
	printHeader(singlefile, details.rWidth, details.rHeight);
	Camera cam({0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 1.0f }, 1.0f, details.rWidth, details.rHeight);

	//Vertical Loop
	for (int y = 0; y < details.rHeight; y++)
	{
		//Horizontal Loop
		for (int x = 0; x < details.rWidth; x++)
		{
            glm::vec3 color = {0.0f, 0.0f, 0.0f};
            int sampleSize = 5;
            
            // Sample Size
            for(int sx = 0; sx < sampleSize; sx++)
            {
                for(int sy = 0; sy < sampleSize; sy++)
                {
                    float minTime = -1;
                    Shape* closestShape = nullptr;
                    
                    float rayX = (float) x + ((float) sx / (float)(sampleSize)) - 0.5f;
                    float rayY = (float) y + ((float) sy / (float)(sampleSize)) - 0.5f;
                    
                    Ray shot = cam.shootRay(rayX, rayY);
                    
                    for (Shape* s : scene.shapes)
                    {
                        //Checks for if an object is in the bounding box;
                        if(s->boundingBox(shot))
                        {
                            float time = s->getTime(shot);
                            if((minTime > time && time > 0) || minTime == -1)
                            {
                                closestShape = s;
                                minTime = time;
                            }
                        }
                    }
                    
                    if (minTime > 0)
                    {
                        color += closestShape->getColor(shot);
                    }
                    else
                    {
                        glm::vec3 bg = {60.0f, 20.0f, 20.0f};
                        color += bg;
                    }
                }
            }
            
            color = color / (float)(sampleSize * sampleSize);
            printColor(singlefile, color);
		}
	}
}
