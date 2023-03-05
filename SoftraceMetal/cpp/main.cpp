//
//  main.cpp
//  SoftraceMetal
//
//  Created by Carter Thompson on 3/4/23.
//

#include "main.h"

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include "render.h"
#include "initialize.h"

#include <iostream>

void renderMain()
{
    UserSceneData temp = { 800, 600 };

    // Initialize Program
    std::vector<Shape*> sceneShapes = buildScene();
    
    // Render Scene
    renderScene(sceneShapes, temp);
}
