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
            bool temp = false;
            
            glm::vec3 color = {0.0f, 0.0f, 0.0f};
            int sampleSize = 10;
            
            // Sample Size
            for(int sx = 0; sx < sampleSize; sx++)
            {
                for(int sy = 0; sy < sampleSize; sy++)
                {
                    for (Shape* s : scene.shapes)
                    {
                        if(s->boundingBox(cam.shootRay((float) x + (float) sx / (float)(sampleSize * sampleSize),
                                                       (float) y + (float) sy / (float)(sampleSize * sampleSize))))
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
                        glm::vec3 temp = {90.0f,255.0f,255.0f};
                        color = color + temp;
                    }
                }
            }
            
            color = color / ((float) sampleSize * sampleSize);
            printColor(singlefile, color);
		}
	}
}
