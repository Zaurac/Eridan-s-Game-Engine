#pragma once
#include <iostream>
#include <vector>



#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace EG
{
	struct Texture2D
	{
		unsigned int texture;
		int width, height, nrChannels;
	};

	struct Vertex
	{
		float x,y,z;
	};

	class Triangles
	{
	public:
		Triangles();
		~Triangles();
		void CreateTriangles(glm::vec3 position);
		void Draw();

	protected:
		unsigned int VAO, VBO;

		std::vector<Vertex> m_verticesArray;

	private:

	};
}

