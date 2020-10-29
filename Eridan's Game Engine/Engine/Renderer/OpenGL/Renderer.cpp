#include "Renderer.h"

Renderer::Renderer(GLFWwindow *window, Camera &camera)
{
	this->window = window;
	this->camera = camera;
}

Renderer::~Renderer()
{
}

void Renderer::AddViewport(Entity& entity)
{
	entity.Draw(camera);
	camera.Update(window);
}

void Renderer::Destroy()
{
	for (size_t i = 0; i < entitys.size(); i++)
	{
		
	}
}
