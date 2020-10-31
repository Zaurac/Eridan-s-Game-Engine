#pragma once
#include "Include.h"
#include <GLFW/glfw3.h>

#include <iostream>

class ContextOpenGL
{
public:
	ContextOpenGL();
	virtual ~ContextOpenGL();
	int errorContext();

	void CreateContext(float width, float height, const char* title);

	inline GLFWwindow *GetWindow() {return window;};

	int width,height;
	const char *title;
	
protected:
	inline static void glfw_error_callback(int error, const char* description)
	{
		fprintf(stderr, "Glfw Error %d: %s\n", error, description);
	}

private:
	
	GLFWwindow* window;
	void openglHintDefault();

	int initGlad();
};