#pragma once
#include "Include.h"
#include <GLFW/glfw3.h>
#include "Engine/Renderer/OpenGL/Camera.h"
#include "Engine/Renderer/OpenGL/Entity.h"

class Renderer
{
public:
	Renderer(GLFWwindow *window, Camera &camera);
	virtual ~Renderer();
	void AddViewport(Entity &entity);
	void Destroy();

protected:
	GLFWwindow* window;
	Camera camera;

	std::vector<Entity*> entitys;
};