#include "Square.h"

Square::Square()
{
}

Square::~Square()
{
}

void Square::CreateQuad()
{
	CreateVertex(glm::vec3(1.f, 1.f, 0.f), glm::vec2(1.f,1.f));
	CreateVertex(glm::vec3(1.f, -1.f, 0.0f), glm::vec2(1.f, 0.f));
	CreateVertex(glm::vec3(-1.f, -1.f, 0.0f), glm::vec2(0.0f, 0.0f));
	CreateVertex(glm::vec3(-1.f, 1.f, 0.0f), glm::vec2(0.f, 1.f));

	

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
	
	CreateEntity();	
}

void Square::Update(float deltaTime)
{

}
