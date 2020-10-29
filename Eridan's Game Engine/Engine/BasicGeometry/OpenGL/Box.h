#pragma  once

#include "Engine/Renderer/OpenGL/Entity.h"

class Box : public Entity
{
public:
	Box();
	~Box();
	void CreateBox();
	void Update(float deltaTime) override;
private:

};