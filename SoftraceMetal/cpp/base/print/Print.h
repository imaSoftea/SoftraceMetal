#pragma once

#include <glm/glm.hpp>
#include <fstream>

void printHeader(std::ofstream &file, int width, int height)
{
	file << "P3" << std::endl;
	file << width << " " << height << std::endl;
	file << "255" << std::endl;
}

void printColor(std::ofstream &file, glm::vec3 color)
{
	file << (int) color.x << " ";
	file << (int) color.y << " ";
	file << (int) color.z << " ";
	file << std::endl;
}
