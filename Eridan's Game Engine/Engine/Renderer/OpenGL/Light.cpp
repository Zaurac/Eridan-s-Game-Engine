#include "Light.h"

Light::Light()
{
	
}

Light Light::CreateLight(glm::vec3 position, glm::vec3 color)
{
	boxLight.CreateBox();
	boxLight.SetPosition(position);

	return Light();
}

Light::~Light()
{
}
