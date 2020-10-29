#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

struct Texture2D
{
	unsigned int texture;
	int width, height, nrChannels;
};

class Texture2DLoaderOpenGL
{
public:
	Texture2DLoaderOpenGL();
	~Texture2DLoaderOpenGL();

	static Texture2D LoadTexture(const char* texturePath);
};

