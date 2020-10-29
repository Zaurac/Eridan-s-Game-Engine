#pragma once
#include <iostream>
#include <vector>

#include "Engine/Renderer/OpenGL/Entity.h"

class Square : public Entity
{
public:
	Square();
	~Square();

	void CreateQuad();
	void Update(float deltaTime) override;
protected:
	

private:
};