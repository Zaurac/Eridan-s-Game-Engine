#pragma once

#include "Engine/Renderer/OpenGL/Entity.h"
#include "Engine/BasicGeometry/OpenGL/Box.h"

class Light : public Box
{
public:
	Light();
	Light CreateLight(glm::vec3 position, glm::vec3 color);
	virtual ~Light();

private:
	Box boxLight;
};