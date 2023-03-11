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
            int sampleSize = 10;
            
            // Sample Size
            for(int sx = 0; sx < sampleSize; sx++)
            {
                for(int sy = 0; sy < sampleSize; sy++)
                {
                    bool temp = false;
                    for (Shape* s : scene.shapes)
                    {
                        float rayX = (float) x + ((float) sx / (float)(sampleSize)) - 0.5f;
                        float rayY = (float) y + ((float) sy / (float)(sampleSize)) - 0.5f;
                        
                        if(s->boundingBox(cam.shootRay(rayX, rayY)))
                        {
                            temp = true;
                        }
                    }
                    
                    if (temp == true)
                    {
                        glm::vec3 temp = {0.0f,0.0f,255.0f};
                        color = color + temp;
                    }
                    else
                    {
                        glm::vec3 temp = {200.0f,200.0f,90.0f};
                        color = color + temp;
                    }
                }
            }
            
            color = color / (float)(sampleSize * sampleSize);
            printColor(singlefile, color);
		}
	}
}
